#include "cf_test_utils.h"

#include "cf.h"

#include <stdlib.h>
#include <string.h>

const char* cf_test_config = "cftest.conf";

static int
cf_home_setup(void** state)
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
cf_home_teardown(void** state)
{
        free(*state);
        return 0;
}

static void
get_config_default_home_test(void** state)
{
        const char* home = *(char**)state;
        struct cf_path p1;
        cf_path_init(&p1);
        cf_path_append(&p1, home);
        cf_path_append(&p1, ".config");
        cf_path_append(&p1, cf_test_config);

        struct cf_path p2;
        cf_path_init(&p2);
        assert_non_null(cf_get_config(&p2, cf_test_config));
        assert_string_equal(p1.path, p2.path);
}

int main(void)
{
        const struct CMUnitTest tests[] = {
                /*
                cmocka_unit_test_setup_teardown(get_config_default_home_test,
                                home_setup, home_teardown),
                                */
                cmocka_unit_test(get_config_default_home_test),
        };

        return cmocka_run_group_tests(tests, cf_home_setup, cf_home_teardown);
}
