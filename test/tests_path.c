#include "cf_test_utils.h"

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

static void
path_append_test(void** state)
{
        (void)state;

        struct cf_path p1;
        cf_path_init(&p1);

        assert_non_null(cf_path_append(&p1, "home"));
        assert_int_equal(p1.len, 5);
        assert_string_equal(p1.path, "/home");

        assert_non_null(cf_path_append(&p1, "user"));
        assert_int_equal(p1.len, 10);
        assert_string_equal(p1.path, "/home/user");

        assert_non_null(cf_path_append(&p1, "Documents"));
        assert_int_equal(p1.len, 20);
        assert_string_equal(p1.path, "/home/user/Documents");
}
static void
path_set_test(void** state)
{
        (void)state;

        struct cf_path p1;
        assert_non_null(cf_path_set(&p1, "/usr/local/lib"));
        assert_int_equal(p1.len, 14);
        assert_string_equal(p1.path, "/usr/local/lib");
}

int main(void)
{
        const struct CMUnitTest tests[] = {
                cmocka_unit_test(path_init_test),
                cmocka_unit_test(path_append_test),
                cmocka_unit_test(path_set_test),
        };

        return cmocka_run_group_tests(tests, NULL, NULL);
}
