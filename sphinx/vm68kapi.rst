libvm68k API
============

<vm68k/data>
------------

.. cpp:namespace:: vm68k

.. cpp:class:: byte

   Byte data.
   A byte is 8-bit wide.

   This type SHALL be trivial and standard-layout.

.. cpp:function:: static constexpr std::size_t byte::size() noexcept

   Returns the size of a :cpp:class:`byte` value on the architecture,
   which is always 1.

.. cpp:function:: byte::byte() = default

.. cpp:class:: word

   Word data.
   A word is 16-bit wide.

   This type SHALL be trivial and standard-layout.

.. cpp:function:: static constexpr std::size_t word::size() noexcept

   Returns the size of a :cpp:class:`word` value on the architecture,
   which is always 2.

.. cpp:function:: word::word() = default

.. cpp:class:: long_word

   Long word data.
   A long word is 32-bit wide.

   This type SHALL be trivial and standard-layout.

.. cpp:function:: static constexpr std::size_t long_word::size() noexcept

   Returns the size of a :cpp:class:`long_word` value on the architecture,
   which is always 4.

.. cpp:function:: long_word::long_word() = default

<vm68k/memory>
--------------

.. cpp:namespace:: vm68k
