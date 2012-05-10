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
    private:
        uint_least8_t value;
    };

    class VM68K_EXPORT word
    {
    public:
        typedef int_least16_t int_type;
        typedef uint_least16_t uint_type;
    private:
        uint_least16_t value;
    };

    class VM68K_EXPORT long_word
    {
    public:
        typedef int_least32_t int_type;
        typedef uint_least32_t uint_type;
    private:
        uint_least32_t value;
    };
    typedef long_word lword;
}

#endif
