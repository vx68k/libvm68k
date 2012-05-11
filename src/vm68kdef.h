//---------------------------------------------------------------------------

#ifndef vm68kdefH
#define vm68kdefH
//---------------------------------------------------------------------------

#include <vm68kint.h>

#ifndef VM68K_EXPORT
#if _WIN32
#define VM68K_EXPORT __declspec(dllimport)
#else
#define VM68K_EXPORT
#endif
#endif /* !defined VM68K_EXPORT */

namespace vm68k
{
    class VM68K_EXPORT byte
    {
    public:
        typedef int_least8_t int_type;
        typedef uint_least8_t uint_type;

        /**
         * <stereotype>constructor</stereotype>
         */
        byte();

        /**
         * <stereotype>constructor</stereotype>
         */
        byte(uint_fast8_t x);

        operator int_fast8_t() const ;

    private:
        uint_least8_t value;
    };

    class VM68K_EXPORT word
    {
    public:
        typedef int_least16_t int_type;
        typedef uint_least16_t uint_type;

        /**
         * <stereotype>constructor</stereotype>
         */
        word();

        /**
         * <stereotype>constructor</stereotype>
         */
        word(uint_fast16_t x);

        operator int_fast16_t() const;

    private:
        uint_least16_t value;
    };

    class VM68K_EXPORT long_word
    {
    public:
        typedef int_least32_t int_type;
        typedef uint_least32_t uint_type;

        /**
         * <stereotype>constructor</stereotype>
         */
        long_word();

        /**
         * <stereotype>constructor</stereotype>
         */
        long_word(uint_fast32_t x);

        operator int_fast32_t() const;

    private:
        uint_least32_t value;
    };

    typedef long_word lword;

    /* Inline implementations.  */

    inline byte::byte()
    {
    }

    inline byte::byte(uint_fast8_t x)
    {
        value = x & 0xff;
    }

    inline byte::operator int_fast8_t() const
    {
        return value;
    }

    inline word::word()
    {
    }

    inline word::word(uint_fast16_t x)
    {
        value = x & 0xffff;
    }

    inline word::operator int_fast16_t() const
    {
        return value;
    }

    inline long_word::long_word()
    {
    }

    inline long_word::long_word(uint_fast32_t x)
    {
        value = x;
    }

    inline long_word::operator int_fast32_t() const
    {
        return value;
    }
}

#endif
