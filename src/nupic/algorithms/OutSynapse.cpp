/* ---------------------------------------------------------------------
 * Numenta Platform for Intelligent Computing (NuPIC)
 * Copyright (C) 2013, Numenta, Inc.  Unless you have an agreement
 * with Numenta, Inc., for a separate license for this software code, the
 * following terms and conditions apply:
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses.
 *
 * http://numenta.org/licenses/
 * ---------------------------------------------------------------------
 */


#include <nupic/algorithms/OutSynapse.hpp>
#include <nupic/algorithms/Cells4.hpp>
using namespace nupic::algorithms::Cells4;
using namespace nupic;

bool OutSynapse::invariants(Cells4* cells) const
{
  bool ok = true;
  if (cells) {
    ok &= _dstCellIdx < cells->nCells();
    ok &= _dstSegIdx < cells->__nSegmentsOnCell(_dstCellIdx);
  }
  return ok;
}

namespace nupic {
  namespace algorithms {
    namespace Cells4 {
      bool operator==(const OutSynapse& a, const OutSynapse& b)
      {
        return a.equals(b);
      }
    }
  }
}
