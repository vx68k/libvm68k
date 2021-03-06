libvm68k API
============

Data types
----------

Header <vm68k/data> defines fundamental data types on the VM68000 architecture.

.. cpp:namespace:: vm68k

.. cpp:class:: byte

   This represents byte data on the VM68000 architecture.
   A byte is 8-bit wide.

   This type is trivial and standard-layout.

   .. cpp:type:: int_type = std::int8_t
                 uint_type = std::uint8_t

      Signed and unsigned integer types this class can store values, respectively.

   .. cpp:function:: static constexpr std::size_t size() noexcept

      Returns the size of a :cpp:class:`byte` value on the architecture,
      which is always 1.

   .. cpp:function:: byte() = default

      Constructs a :cpp:class:`byte` object with its default value.

      This constructor is explicitly defaulted.

   .. cpp:function:: constexpr explicit byte(std::uint8_t value) noexcept

      Constructs a :cpp:class:`byte` object with an initial value.

   .. cpp:function:: void swap(byte &other) noexcept

      This function swaps the value of the object with another one.

   .. cpp:function:: constexpr std::int8_t to_int() const noexcept
                     constexpr std::uint8_t to_uint() const noexcept

      These functions return the interpretations of the object as signed and
      unsigned integers respectively.

   .. cpp:function:: template<class Iterator> \
                     Iterator serialize(Iterator i) const

      This function serializes the value of the object to a sequence of bytes.

   .. cpp:function:: template<class Iterator> \
                     Iterator deserialize(Iterator i)

      This function deserializes the value of the object from a sequence of bytes.

.. cpp:function:: bool operator ==(byte x, byte y) noexcept
.. cpp:function:: bool operator !=(byte x, byte y) noexcept

   Tests equality of :cpp:class:`byte` values.

   *These functions are not implemented yet*.

.. cpp:class:: word

   This represents word data on the VM68000 architecture.
   A word is 16-bit wide.

   This type is trivial and standard-layout.

   .. cpp:type:: int_type = std::int16_t
                 uint_type = std::uint16_t

      Signed and unsigned integer types this class can store values, respectively.

   .. cpp:function:: static constexpr std::size_t size() noexcept

      Returns the size of a :cpp:class:`word` value on the architecture,
      which is always 2.

   .. cpp:function:: word() = default

      Constructs a :cpp:class:`word` object with its default value.

      This constructor is explicitly defaulted.

   .. cpp:function:: constexpr explicit word(std::uint16_t value) noexcept

      Constructs a :cpp:class:`word` object with an initial value.

   .. cpp:function:: void swap(word &other) noexcept

      This function swaps the value of the object with another one.

   .. cpp:function:: constexpr std::int16_t to_int() const noexcept
                     constexpr std::uint16_t to_uint() const noexcept

      These functions return the interpretations of the object as signed and
      unsigned integers respectively.

   .. cpp:function:: template<class Iterator> \
                     Iterator serialize(Iterator i) const

      This function serializes the value of the object to a sequence of bytes.

   .. cpp:function:: template<class Iterator> \
                     Iterator deserialize(Iterator i)

      This function deserializes the value of the object from a sequence of bytes.

.. cpp:function:: bool operator ==(word x, word y) noexcept
.. cpp:function:: bool operator !=(word x, word y) noexcept

   Tests equality of :cpp:class:`word` values.

   *These functions are not implemented yet*.

.. cpp:class:: long_word

   This represents long word data on the VM68000 architecture.
   A long word is 32-bit wide.

   This type is trivial and standard-layout.

   .. cpp:type:: int_type = std::int32_t
                 uint_type = std::uint32_t

      Signed and unsigned integer types this class can store values, respectively.

   .. cpp:function:: static constexpr std::size_t size() noexcept

      Returns the size of a :cpp:class:`long_word` value on the architecture,
      which is always 4.

   .. cpp:function:: long_word() = default

      Constructs a :cpp:class:`long_word` object with its default value.

      This constructor is explicitly defaulted.

   .. cpp:function:: constexpr explicit long_word(std::uint32_t value) noexcept

      Constructs a :cpp:class:`long_word` object with an initial value.

   .. cpp:function:: void swap(long_word &other) noexcept

      This function swaps the value of the object with another one.

   .. cpp:function:: constexpr std::int32_t to_int() const noexcept
                     constexpr std::uint32_t to_uint() const noexcept

      These functions return the interpretations of the object as signed and
      unsigned integers respectively.

   .. cpp:function:: template<class Iterator> \
                     Iterator serialize(Iterator i) const

      This function serializes the value of the object to a sequence of bytes.

   .. cpp:function:: template<class Iterator> \
                     Iterator deserialize(Iterator i)

      This function deserializes the value of the object from a sequence of bytes.

.. cpp:function:: bool operator ==(long_word x, long_word y) noexcept
.. cpp:function:: bool operator !=(long_word x, long_word y) noexcept

   Tests equality of :cpp:class:`long_word` values.

   *These functions are not implemented yet*.


<vm68k/memory>
--------------

.. cpp:namespace:: vm68k

.. cpp:class:: memory_map

   .. cpp:type:: address_type = std::uint32_t

   .. cpp:type:: size_type = std::uint32_t

   .. cpp:enum-class:: mode: char

   .. cpp:function:: protected \
                     memory_map() = default

   .. cpp:function:: memory_map(const memory_map &) = delete

      The copy constructor is deleted.

   .. cpp:function:: void operator =(const memory_map &) = delete

      The copy-assignment operator is deleted.

   .. cpp:function:: virtual ~memory_map() = default

   .. cpp:function:: virtual read(mode mode, address_type address, size_type n, void *buffer) = 0

   .. cpp:function:: virtual write(mode mode, address_type address, size_type n, const void *buffer) = 0

.. cpp:class:: paged_memory_map: public memory_map

   .. cpp:class:: memory

      Abstract base class of memory objects that is mappable in a paged memory map.

      .. cpp:type:: protected address_type = memory_map::address_type
                    protected size_type = memory_map::size_type

      .. cpp:function:: protected memory() = default
                        protected memory(const memory &) = delete

         Prohibits copy construction.

      .. cpp:function:: void operator =(const memory &) = delete

         Prohibits assignment.

      .. cpp:function:: virtual ~memory() = default

      .. cpp:function:: virtual size_type size() const noexcept = 0

         Returns the size of this memory object.
