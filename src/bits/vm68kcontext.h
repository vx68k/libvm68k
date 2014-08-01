/*
 * vm68kcontext - execution contexts (interface)
 * Copyright (C) 2012 Kaz Nishimura
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

#ifndef vm68kcontextH
#define vm68kcontextH 1

#include <bits/vm68kdef.h>
#include <bits/vm68kmemory.h>
#include <memory>
#include <utility>

namespace vm68k {
    using std::shared_ptr;

    /*
     * Execution context.
     */
    class _VM68K_PUBLIC context {
    public:
        explicit context(shared_ptr<memory_map> memory);
        context(const context &) = default;

        /*
         * Move constructor.
         */
        context(context &&__c) {
            _memory = std::move(__c._memory);
        }

        virtual ~context();

        const shared_ptr<memory_map> &memory() const noexcept {
            return _memory;
        }

    private:
        shared_ptr<memory_map> _memory;
    };
}

#endif
