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
#include <stdexcept>
#include <memory>
using namespace std;

#include <boost/scoped_ptr.hpp>
using namespace boost;

#include "calpontselectexecutionplan.h"
using namespace execplan;
#include "bytestream.h"
#include "messagequeue.h"
using namespace messageqcpp;

namespace qfe
{

MessageQueueClient* sendCSEP(CalpontSelectExecutionPlan* csep)
{
	scoped_ptr<CalpontSelectExecutionPlan> cleaner(csep);

	ByteStream bs;

	MessageQueueClient* mqc=0;

	mqc = new MessageQueueClient("ExeMgr1");
	auto_ptr<MessageQueueClient> smqc(mqc);

	bs.reset();
	ByteStream::quadbyte wantTuples=4;
	bs << wantTuples;
	mqc->write(bs);

	bs.reset();
	csep->serialize(bs);
	mqc->write(bs);

	SBS sbs;
	sbs = mqc->read();
	*sbs >> wantTuples;
	//cerr << "got flag: " << wantTuples << endl;
	string msg;
	sbs = mqc->read();
	*sbs >> msg;
	//cerr << "got msg: " << msg << endl;

	if (wantTuples != 0)
		throw runtime_error(msg);

	smqc.release();
	return mqc;
}

}

