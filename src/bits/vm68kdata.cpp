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

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include "vm68kdata.h"
#if __BORLANDC__
#pragma package(smart_init)
#endif

namespace vm68k {
    /*
     * Explicit instantiations.
     */
    template class basic_data<1>;
    template class basic_data<2>;
    template class basic_data<4>;
}
