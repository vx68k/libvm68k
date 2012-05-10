//---------------------------------------------------------------------------

#ifndef vm68kdefH
#define vm68kdefH
//---------------------------------------------------------------------------

#include <vm68kint.h>

namespace vm68k
{
    class byte
    {
    public:
        typedef int_least8_t int_type;
        typedef uint_least8_t uint_type;
    private:
        uint_least8_t value;
    };

    class word
    {
    public:
        typedef int_least16_t int_type;
        typedef uint_least16_t uint_type;
    private:
        uint_least16_t value;
    };

    class long_word
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
