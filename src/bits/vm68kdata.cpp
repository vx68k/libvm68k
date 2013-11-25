/*
 * Target data (implementation)
 * Copyright (C) 2012-2013 Kaz Nishimura
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "vm68kdata.h"
#if __BORLANDC__
#pragma package(smart_init)
#endif

namespace vm68k {
    /*
     * Explicit instantiations.
     */
    template class data_size<std::int8_t,  std::int_fast8_t>;
    template class data_size<std::int16_t, std::int_fast16_t>;
    template class data_size<std::int32_t, std::int_fast32_t>;
    template class basic_data<byte>;
    template class basic_data<word>;
    template class basic_data<lword>;
}
