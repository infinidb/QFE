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

#ifndef QFE_CSEPUTILS_H__
#define QFE_CSEPUTILS_H__

#include <string>
#include <boost/shared_ptr.hpp>

namespace execplan
{
class ConstantColumn;
class SimpleFilter;
class ParseTree;
class SimpleColumn;
}
#include "calpontsystemcatalog.h"

namespace qfe
{
namespace utils
{
execplan::ConstantColumn* createConstCol(const std::string& valstr);

template <typename T>
execplan::ConstantColumn* createConstCol(const std::string& valstr, T val);

execplan::SimpleFilter* createSimpleFilter
				(
				boost::shared_ptr<execplan::CalpontSystemCatalog> csc,
				const execplan::CalpontSystemCatalog::TableColName& tcn,
				const std::string& opstr,
				execplan::ConstantColumn* cc
				);

void appendSimpleFilter
				(
				execplan::ParseTree*& ptree,
				execplan::SimpleFilter* filter
				);

void updateParseTree(boost::shared_ptr<execplan::CalpontSystemCatalog>,
	execplan::CalpontSelectExecutionPlan*&,
	execplan::SimpleColumn*,
	const std::string&, pair<int, string>);

} //namespace qfe::utils
} //namespace qfe
#endif

