#include "cf_test_utils.h"

#include "cf.h"

#include <string.h>

/*
#include <stdlib.h>
#include <string.h>

static int
home_setup(void** state)
{
        char* home = getenv("HOME");
        if (!home)
                return -1;

        char* p = malloc(strlen(home) + 1);
        if (!p)
                return -1;

        strcpy(p, home);
        *state = p;

        return 0;
}

static int
home_teardown(void** state)
{
        free(*state);
        return 0;
}
*/

static void
get_home_test(void** state)
{
        const char* home = *(char**)state;

        struct cf_path p1 = { .path = "", .len = 0 };
        assert_non_null(cf_get_home(&p1));
        assert_false(p1.len == 0);
        assert_string_not_equal(p1.path, "");

        assert_string_equal(p1.path, home);
        assert_int_equal(p1.len, strlen(home));
}

int main(void)
{
        const struct CMUnitTest tests[] = {
                cmocka_unit_test_setup_teardown(get_home_test,
                                cf_home_su, cf_home_td),
        };

        return cmocka_run_group_tests(tests, NULL, NULL);
}
