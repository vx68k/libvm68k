// <bits/vm68k/memory.h>
// Copyright (C) 2012-2020 Kaz Nishimura
//
// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <http://www.gnu.org/licenses/>.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef _VM68K_MEMORY_H
#define _VM68K_MEMORY_H 1

#include <bits/vm68kcore.h>
#include <vm68k/memory>
#include <memory>

namespace vm68k
{
    /// Read-write memory.
    class _VM68K_PUBLIC read_write_memory: public paged_memory_map::memory
    {
        using inherited = memory;

    protected:
        using byte_type = unsigned char;

    protected:
        static std::unique_ptr<byte_type []> allocate(size_type size);

    private:
        const size_type _size;
        std::unique_ptr<byte_type []> _data;

    public:
        explicit read_write_memory(size_type size);

    public:
        virtual ~read_write_memory();

    public:
        size_type size() const noexcept override final;

        void read(mode m, address_type address, size_type n,
            void *bytes) override final;

        void write(mode m, address_type address, size_type n,
            const void *bytes) override final;

    protected:
        /// Checks read access on a region.
        ///
        /// This implementation does nothing.
        virtual void check_read_access(mode m, address_type address,
            size_type n);

        /// Checks write access on a region.
        ///
        /// This implementation does nothing.
        virtual void check_write_access(mode m, address_type address,
            size_type n);
    };
}

#endif
