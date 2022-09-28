#pragma once

/*
 * CMocka Headers
 */
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include <stdlib.h>
#include <string.h>

/*
 * Setup and Teardown Functions
 */
int
cf_home_su(void** state)
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

int
cf_home_td(void** state)
{
        free(*state);
        return 0;
}
