/* 
 * contact_list.h
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

#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include "contact.h"

struct contact_t {
    char *name;
    char *show;
    char *status;
};

struct contact_node_t {
    PContact contact;    
    struct contact_node_t *next;
};

void contact_list_clear(void);
void reset_search_attempts(void);
int contact_list_add(const char * const name, const char * const show,
    const char * const status);
int contact_list_remove(const char * const name);
struct contact_node_t * get_contact_list(void);
char * find_contact(char *search_str);
int get_size(struct contact_node_t *list);
void destroy_list(struct contact_node_t *list);

#endif
