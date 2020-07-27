libvm68k API
============

Data types
----------

.. cpp:namespace:: vm68k

.. cpp:class:: byte

   Byte class on the architecture.
   A byte is 8-bit wide.

   This type is trivial and standard-layout.

   .. cpp:function:: static constexpr std::size_t size() noexcept

      Returns the size of a :cpp:class:`byte` value on the architecture,
      which is always 1.

   .. cpp:function:: byte() = default

      Constructs a :cpp:class:`byte` object with its default value.

      This constructor is explicitly defaulted.

   .. cpp:function:: constexpr byte(std::uint8_t value) noexcept

      Constructs a :cpp:class:`byte` object with an initial value.

.. cpp:function:: bool operator ==(byte x, byte y) noexcept
.. cpp:function:: bool operator !=(byte x, byte y) noexcept

   Tests equality of :cpp:class:`byte` values.

   *These functions are not implemented yet*.

.. cpp:class:: word

   Word class on the architecture.
   A word is 16-bit wide.

   This type is trivial and standard-layout.

   .. cpp:function:: static constexpr std::size_t size() noexcept

      Returns the size of a :cpp:class:`word` value on the architecture,
      which is always 2.

   .. cpp:function:: word() = default

      Constructs a :cpp:class:`word` object with its default value.

      This constructor is explicitly defaulted.

   .. cpp:function:: constexpr word(std::uint16_t value) noexcept

      Constructs a :cpp:class:`word` object with an initial value.

.. cpp:function:: bool operator ==(word x, word y) noexcept
.. cpp:function:: bool operator !=(word x, word y) noexcept

   Tests equality of :cpp:class:`word` values.

   *These functions are not implemented yet*.

.. cpp:class:: long_word

   Long word class on the architecture.
   A long word is 32-bit wide.

   This type is trivial and standard-layout.

   .. cpp:function:: static constexpr std::size_t size() noexcept

      Returns the size of a :cpp:class:`long_word` value on the architecture,
      which is always 4.

   .. cpp:function:: long_word() = default

      Constructs a :cpp:class:`long_word` object with its default value.

      This constructor is explicitly defaulted.

   .. cpp:function:: constexpr long_word(std::uint32_t value) noexcept

      Constructs a :cpp:class:`long_word` object with an initial value.

.. cpp:function:: bool operator ==(long_word x, long_word y) noexcept
.. cpp:function:: bool operator !=(long_word x, long_word y) noexcept

   Tests equality of :cpp:class:`long_word` values.

   *These functions are not implemented yet*.


<vm68k/memory>
--------------

.. cpp:namespace:: vm68k
