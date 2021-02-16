// <bits/vm68k/execution_context.h>
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

#ifndef _VM68K_EXECUTION_CONTEXT_H
#define _VM68K_EXECUTION_CONTEXT_H 1

#include <bits/vm68kdef.h>
#include <vm68k/memory>
#include <vm68k/data>
#include <array>
#include <memory>
#include <cstddef>

namespace vm68k
{
    /*
     * Execution contexts.
     */
    class _VM68K_PUBLIC execution_context
    {
    public:

        /**
         * Data registers.
         */
        class data_register
        {
        private:

            long_word::uint_type _value;

        public:

            data_register &operator =(const long_word value)
            {
                _value = value.to_uint();
                return *this;
            }

            data_register &operator =(const word value)
            {
                auto unchanged = _value & 0xffff0000U;
                _value = unchanged | value.to_uint();
                return *this;
            }

            data_register &operator =(const byte value)
            {
                auto unchanged = _value & 0xffffff00U;
                _value = unchanged | value.to_uint();
                return *this;
            }


            /**
             * Converts the register value to a long word.
             */
            explicit operator long_word() const noexcept
            {
                return long_word(_value);
            }

            /**
             * Converts the register value to a word.
             */
            explicit operator word() const noexcept
            {
                return word(_value);
            }

            /**
             * Converts the register value to a byte.
             */
            explicit operator byte() const noexcept
            {
                return byte(_value);
            }
        };

        /**
         * Address registers.
         */
        class address_register
        {
        private:

            long_word::uint_type _value;

        public:

            address_register &operator =(const long_word value)
            {
                _value = value.to_int();
                return *this;
            }

            address_register &operator =(const word value)
            {
                // Word assignments shall be sign-extended.
                _value = value.to_int();
                return *this;
            }


            /**
             * Converts the register value to a long word.
             */
            explicit operator long_word() const noexcept
            {
                return long_word(_value);
            }

            /**
             * Converts the register value to a word.
             */
            explicit operator word() const noexcept
            {
                return word(_value);
            }
        };


        /**
         * Number of the data registers.
         */
        static const std::size_t DATA_REGISTER_MAX = 8;

        /**
         * Number of the address registers.
         */
        static const std::size_t ADDRESS_REGISTER_MAX = 8;

    private:

        std::shared_ptr<memory_map> _memory;

        /**
         * Array of the data registers.
         */
        std::array<data_register, DATA_REGISTER_MAX> _d;

        /**
         * Array of the address registers.
         */
        std::array<address_register, ADDRESS_REGISTER_MAX> _a;

        long_word _pc;

    public:

        // Constructors.

        explicit execution_context(const std::shared_ptr<memory_map> &memory);

        /**
         * Deleted copy constructor.
         */
        execution_context(const execution_context &) = delete;


        // Destructor.

        virtual ~execution_context();


        // Assignment operators.

        /**
         * Deleted copy assignment operator.
         */
        void operator =(const execution_context &) = delete;


        auto memory() const -> const std::shared_ptr<memory_map> &
        {
            return _memory;
        }

        /**
         * Returns a reference to a data register.
         */
        data_register &d(std::size_t regno);

        /**
         * Returns a const reference to a data register.
         */
        const data_register &d(std::size_t regno) const;

        /**
         * Returns a reference to an address register.
         */
        address_register &a(std::size_t regno);

        /**
         * Returns a const reference to an address register.
         */
        const address_register &a(std::size_t regno) const;

        long_word pc() const;

        void set_pc(long_word pc);

        /**
         * Reads data from an address.
         */
        template<class Data>
        void read(long_word address, Data &data) const
        {
            char bytes[Data::size()];
            _memory->read(memory_access_mode(),
                address.to_uint(), Data::size(), bytes);
            data.deserialize(bytes);
        }

        /**
         * Writes data to an address.
         */
        template<class Data>
        void write(long_word address, const Data &data) const
        {
            char bytes[Data::size()];
            data.serialize(bytes);
            _memory->write(memory_access_mode(),
                address.to_uint(), Data::size(), bytes);
        }

    protected:

        function_code memory_access_mode() const
        {
            return function_code::data; // FIXME
        }
    };
}

#endif
