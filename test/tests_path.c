#include "cmocka_headers.h"

#include "cf_path.h"

static void
path_init_test(void** state)
{
        (void)state;

        struct cf_path p1;
        assert_non_null(cf_path_init(&p1));
        assert_string_equal(p1.path, "");
        assert_int_equal(p1.len, 0);
}

int main(void)
{
        const struct CMUnitTest tests[] = {
                cmocka_unit_test(path_init_test),
        };

        return cmocka_run_group_tests(tests, NULL, NULL);
}
