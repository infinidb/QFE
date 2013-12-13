/* Copyright (C) 2013 Calpont Corp.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#include <unistd.h>
#include <string>
#include <stdexcept>
using namespace std;

#include <boost/scoped_ptr.hpp>
using namespace boost;

#include "ddlpkg.h"
#include "sqlparser.h"
using namespace ddlpackage;

#include "bytestream.h"
#include "messagequeue.h"
using namespace messageqcpp;

#include "ddlstmts.h"

namespace qfe
{
extern string DefaultSchema;
}

namespace
{
using namespace qfe;

int processDDLStmt(const string& stmt, uint32_t sid)
{
	MessageQueueClient* mq=0;
	SqlParser parser;

	parser.setDefaultSchema(DefaultSchema);
	parser.Parse(stmt.c_str());
	if (parser.Good())
	{
		const ddlpackage::ParseTree& ptree = parser.GetParseTree();
		SqlStatement &ddlstmt = *ptree.fList[0];
		ddlstmt.fSessionID = sid;
		ddlstmt.fSql = stmt;
		ddlstmt.fOwner = DefaultSchema;
		ByteStream bytestream;
		bytestream << ddlstmt.fSessionID;
		ddlstmt.serialize(bytestream);
		mq = new MessageQueueClient("DDLProc");
		scoped_ptr<MessageQueueClient> smq(mq);
		ByteStream::byte b=0;
		mq->write(bytestream);
		bytestream = mq->read();
		bytestream >> b;
		string emsg;
		bytestream >> emsg;
		if (b != 0)
			throw runtime_error(emsg);
	}
	else
	{
		throw runtime_error("syntax error");
	}

	return 0;
}

}

namespace qfe
{

void processCreateStmt(const string& stmt, uint32_t sid)
{
	processDDLStmt(stmt, sid);
}

void processDropStmt(const string& stmt, uint32_t sid)
{
	processDDLStmt(stmt, sid);
}

} //namespace qfe

