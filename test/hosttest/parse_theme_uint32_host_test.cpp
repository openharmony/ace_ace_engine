#include "parse_theme_uint32.h"
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <stdexcept>
#include <string>

static void ExpectOk(const char *s, uint32_t want)
{
    uint32_t out = 7;
    assert(ParseThemeUint32(s, out));
    assert(out == want);
}

static void ExpectFail(const char *s)
{
    uint32_t out = 42;
    assert(!ParseThemeUint32(s, out));
}

static bool StoulThrows(const std::string &s)
{
    try {
        (void)std::stoul(s);
        return false;
    } catch (const std::out_of_range &) {
        return true;
    } catch (const std::invalid_argument &) {
        return true;
    }
}

int main()
{
    ExpectOk("0", 0);
    ExpectOk("1", 1);
    ExpectOk("42", 42);
    ExpectOk("4294967295", 4294967295u);
    ExpectFail("");
    ExpectFail("-1");
    ExpectFail("12a");
    ExpectFail("a12");
    ExpectFail(" 1");
    ExpectFail("1 ");
    ExpectFail("4294967296");
    ExpectFail("9999999999");

    /* leftover: regex [0-9]+ then bare stoul on overflow */
    const std::string overflow(20, '9');
    assert(StoulThrows(overflow));
    ExpectFail(overflow.c_str());

    std::puts("parse_theme_uint32_host_test OK");
    return 0;
}
