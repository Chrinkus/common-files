#include "cmocka_headers.h"

#include "cf.h"

static void
get_home_test(void** state)
{
        (void)state;

        struct cf_path p1 = { .path = "", .len = 0 };
        assert_non_null(cf_get_home(&p1));
        assert_false(p1.len == 0);
}

int main(void)
{
        const struct CMUnitTest tests[] = {
                cmocka_unit_test(get_home_test),
        };

        return cmocka_run_group_tests(tests, NULL, NULL);
}
