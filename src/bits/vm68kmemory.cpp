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

#pragma hdrstop

#include "vm68kmemory.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace vm68k;

/*
 * memory_exception
 */

memory_exception::memory_exception() throw() {
}

memory_exception::memory_exception(const memory_exception &x) throw() {
}

memory_exception &memory_exception::operator =
    (const memory_exception & x) throw() {
    return *this;
}

const char *memory_exception::what() const throw() {
    return "vm68k::memory_exception";
}

/*
 * bus_error
 */

bus_error::bus_error() throw() {
}

bus_error::bus_error(const bus_error &x) throw() {
}

bus_error &bus_error::operator =(const bus_error & x) throw() {
    return *this;
}

const char *bus_error::what() const throw() {
    return "vm68k::bus_error";
}

/*
 * address_error
 */

address_error::address_error() throw() {
}

address_error::address_error(const address_error &x) throw() {
}

address_error &address_error::operator =(const address_error & x) throw() {
    return *this;
}

const char *address_error::what() const throw() {
    return "vm68k::address_error";
}

vm68k::device::~device() {
}

vm68k::memory_map::~memory_map()
{
}
