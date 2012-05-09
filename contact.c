/* 
 * contact.c
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

#include <stdlib.h>
#include <string.h>

#include "contact.h"

struct p_contact_t {
    char *name;
    char *show;
    char *status;
};

PContact p_contact_new(const char * const name, const char * const show, 
    const char * const status)
{
    PContact contact = malloc(sizeof(struct p_contact_t));
    contact->name = strdup(name);

    if (show == NULL || (strcmp(show, "") == 0))
        contact->show = strdup("online");
    else
        contact->show = strdup(show);

    if (status != NULL)
        contact->status = strdup(status);
    else
        contact->status = NULL;

    return contact;
}

void p_contact_free(PContact contact)
{
    free(contact->name);

    if (contact->show != NULL) {
        free(contact->show);
        contact->show = NULL;
    }
    if (contact->status != NULL) {
        free(contact->status);
        contact->status = NULL;
    }

    free(contact);
    contact = NULL;
}

const char * p_contact_name(const PContact contact)
{
    return contact->name;
}

const char * p_contact_show(const PContact contact)
{
    return contact->show;
}

const char * p_contact_status(const PContact contact)
{
    return contact->status;
}
