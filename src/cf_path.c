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
#include "cf_path.h"

#include <string.h>

void*
cf_path_init(struct cf_path* p)
{
        p->path[0] = '\0';
        p->len = 0;

        return p;
}

void*
cf_path_append(struct cf_path* p, const char* s)
{
        int len = strlen(s);
        if (PATH_MAX < p->len + 1 + len + 1)    // p->path + '/' + s + '\0'
                return NULL;

        p->path[p->len++] = '/';
        strcat(p->path, s);
        p->len += len;

        return p;
}

void*
cf_path_set(struct cf_path* p, const char* s)
{
        int len = strlen(s);
        if (PATH_MAX < len + 1)                 // s + '\0'
                return NULL;

        strcpy(p->path, s);
        p->len = len;
        return p;
}
