// <bits/vm68k/read_write_memory.h>
// Copyright (C) 2012-2021 Kaz Nishimura
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

#include <bits/vm68kdef.h>
#include <vm68k/memory>
#include <memory>

namespace vm68k
{
    /*
     * Read-write memory objects.
     */
    class _VM68K_PUBLIC read_write_memory: public memory_map::memory
    {
    protected:

        using byte_type = unsigned char;

        class _VM68K_PUBLIC bytes_delete
        {
        private:

            size_t _size;

        public:

            // Constructors.

            explicit constexpr bytes_delete(const std::size_t size) noexcept
            :
                _size {size}
            {
                // Nothing more to do.
            }


            void operator ()(byte_type *ptr) const;
        };

    private:

        const size_type _size;

        address_type _base_address = 0;

        std::unique_ptr<byte_type [], bytes_delete> _bytes;

    protected:

        static auto allocate_bytes(size_t size)
            -> std::unique_ptr<byte_type [], bytes_delete>;

    public:

        // Constructors.

        explicit read_write_memory(size_type size);


        // Destructor.

        ~read_write_memory() override;


        size_type size() const noexcept final override;

        void relocate(address_type base_address) final override;

        void read(function_code fc, address_type address, size_type n,
            void *buffer) final override;

        void write(function_code fc, address_type address, size_type n,
            const void *buffer) final override;

    protected:

        /// Checks read access on a region.
        ///
        /// This implementation does nothing.
        virtual void check_read_access(function_code fc,
            address_type address, size_type n);

        /// Checks write access on a region.
        ///
        /// This implementation does nothing.
        virtual void check_write_access(function_code fc,
            address_type address, size_type n);
    };
}

#endif
