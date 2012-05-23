/* 
 * contact_list.c
 *
 * Copyright (C) 2012 James Booth <boothj5@gmail.com>
 * 
 * This file is part of Profanity.
 *
 * Profanity is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Profanity is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Profanity.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glib.h>

#include "contact.h"
#include "contact_list.h"
#include "prof_autocomplete.h"

static PAutocomplete ac;

void contact_list_init(void)
{
    ac = p_obj_autocomplete_new((PStrFunc)p_contact_name, 
                            (PCopyFunc)p_contact_copy,
                            (GDestroyNotify)p_contact_free);
}

void contact_list_clear(void)
{
    p_autocomplete_clear(ac);
}

void reset_search_attempts(void)
{
    p_autocomplete_reset(ac);
}

gboolean contact_list_remove(const char * const name)
{
    return p_autocomplete_remove(ac, name);
}

gboolean contact_list_add(const char * const name, const char * const show, 
    const char * const status)
{
    return p_autocomplete_add(ac, p_contact_new(name, show, status));
}

GSList * get_contact_list(void)
{
    return p_autocomplete_get_list(ac);
}

char * find_contact(char *search_str)
{
    return p_autocomplete_complete(ac, search_str);
}
