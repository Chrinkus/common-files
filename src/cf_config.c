/*
 * GNU GENERAL PUBLIC LICENSE
 * Version 3, 29 June 2007
 * 
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or(at your
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "cf.h"

#include "cf_defs.h"

#include <stdlib.h>     // getenv, NULL

static void*
get_default_config_home(struct cf_path* out)
{
        const char* home = getenv("HOME");
        if (!home)
                return NULL;

        if (!cf_path_append(out, home) || !cf_path_append(out, def_conf))
                return NULL;

        return out;
}

void*
cf_get_config(struct cf_path* out, const char* fname)
{
        const char* xdg = getenv(xdg_conf);
        if (xdg) {
                if (!cf_path_append(out, xdg))
                        return NULL;
        } else if (!get_default_config_home(out)) {
                return NULL;
        }
        return cf_path_append(out, fname);
}

