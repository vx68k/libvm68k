// <bits/vm68k/read_write_memory.h>
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

#ifndef _VM68K_READ_WRITE_MEMORY_H
#define _VM68K_READ_WRITE_MEMORY_H 1

#include <bits/vm68kcore.h>
#include <vm68k/memory>
#include <memory>

namespace vm68k
{
    /*
     * Read-write memory objects.
     */
    class _VM68K_PUBLIC read_write_memory: public paged_memory_map::memory
    {
    protected:
        using byte_type = unsigned char;

    protected:
        class _VM68K_PUBLIC bytes_delete
        {
        private:
            size_t _size;

        public:
            explicit constexpr bytes_delete(const std::size_t size) noexcept
            :
                _size {size}
            {
                // Nothing more to do.
            }

        public:
            void operator ()(byte_type *ptr) const;
        };

    protected:
        static auto allocate_bytes(size_t size)
            -> std::unique_ptr<byte_type [], bytes_delete>;

    private:
        const size_type _size;

    private:
        std::unique_ptr<byte_type [], bytes_delete> _bytes;

    public:
        explicit read_write_memory(size_type size);

    public:
        virtual ~read_write_memory();

    public:
        size_type size() const noexcept override final;

        void read(mode mode, address_type address, size_type n,
            void *bytes) final override;

        void write(mode mode, address_type address, size_type n,
            const void *bytes) final override;

    protected:
        /// Checks read access on a region.
        ///
        /// This implementation does nothing.
        virtual void check_read_access(mode mode, address_type address,
            size_type n);

        /// Checks write access on a region.
        ///
        /// This implementation does nothing.
        virtual void check_write_access(mode mode, address_type address,
            size_type n);
    };
}

#endif
