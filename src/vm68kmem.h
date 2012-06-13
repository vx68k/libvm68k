/*
 * Memory components.
 * Copyright (C) 2012  Kaz Sasa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef vm68kmemH
#define vm68kmemH

#include <vm68kdef.h>

#if _WIN32 && !_VM68K
#pragma comment(lib, "vm68k.lib")
#endif

namespace vm68k
{
    /**
     * <author>Kaz Sasa</author>
     * <since>2.0</since>
     */
    class VM68K_EXPORT device
    {
    protected:
        /**
         * <stereotype>constructor</stereotype>
         */
        device()
        {
        }

    public:
        /**
         * <stereotype>destructor</stereotype>
         */
        virtual ~device();
    };

    /**
     * <author>Kaz Sasa</author>
     * <since>2.0</since>
     */
    class VM68K_EXPORT memory_map
    {
    public:
        /**
         * <stereotype>constructor</stereotype>
         */
        memory_map()
        {
        }

        /**
         * <stereotype>destructor</stereotype>
         */
        virtual ~memory_map();
    };
}

#endif /* once */
