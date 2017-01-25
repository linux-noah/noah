/*
 *  alpm_list.h
 *
 *  Copyright (c) 2006-2016 Pacman Development Team <pacman-dev@archlinux.org>
 *  Copyright (c) 2002-2006 by Judd Vinet <jvinet@zeroflux.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _ALPM_LIST_H
#define _ALPM_LIST_H

#include <stdlib.h> /* size_t */

/* Note: alpm_list.{c,h} are intended to be standalone files. Do not include
 * any other libalpm headers.
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Linked list type used by libalpm.
 *
 * It is exposed so front ends can use it to prevent the need to reimplement
 * lists of their own; however, it is not required that the front end uses
 * it.
 */
typedef struct __alpm_list_t {
	/** data held by the list node */
	void *data;
	/** pointer to the previous node */
	struct __alpm_list_t *prev;
	/** pointer to the next node */
	struct __alpm_list_t *next;
} alpm_list_t;

#define FREELIST(p) do { alpm_list_free_inner(p, free); alpm_list_free(p); p = NULL; } while(0)

typedef void (*alpm_list_fn_free)(void *); /* item deallocation callback */
typedef int (*alpm_list_fn_cmp)(const void *, const void *); /* item comparison callback */

/* allocation */
void alpm_list_free(alpm_list_t *list);
void alpm_list_free_inner(alpm_list_t *list, alpm_list_fn_free fn);

/* item mutators */
alpm_list_t *alpm_list_add(alpm_list_t *list, void *data);
alpm_list_t *alpm_list_append(alpm_list_t **list, void *data);
alpm_list_t *alpm_list_add_sorted(alpm_list_t *list, void *data, alpm_list_fn_cmp fn);
alpm_list_t *alpm_list_join(alpm_list_t *first, alpm_list_t *second);
alpm_list_t *alpm_list_mmerge(alpm_list_t *left, alpm_list_t *right, alpm_list_fn_cmp fn);
alpm_list_t *alpm_list_msort(alpm_list_t *list, size_t n, alpm_list_fn_cmp fn);
alpm_list_t *alpm_list_remove_item(alpm_list_t *haystack, alpm_list_t *item);
alpm_list_t *alpm_list_remove(alpm_list_t *haystack, const void *needle, alpm_list_fn_cmp fn, void **data);
alpm_list_t *alpm_list_remove_str(alpm_list_t *haystack, const char *needle, char **data);
alpm_list_t *alpm_list_remove_dupes(const alpm_list_t *list);
alpm_list_t *alpm_list_strdup(const alpm_list_t *list);
alpm_list_t *alpm_list_copy(const alpm_list_t *list);
alpm_list_t *alpm_list_copy_data(const alpm_list_t *list, size_t size);
alpm_list_t *alpm_list_reverse(alpm_list_t *list);

/* item accessors */
alpm_list_t *alpm_list_nth(const alpm_list_t *list, size_t n);
alpm_list_t *alpm_list_next(const alpm_list_t *list);
alpm_list_t *alpm_list_previous(const alpm_list_t *list);
alpm_list_t *alpm_list_last(const alpm_list_t *list);

/* misc */
size_t alpm_list_count(const alpm_list_t *list);
void *alpm_list_find(const alpm_list_t *haystack, const void *needle, alpm_list_fn_cmp fn);
void *alpm_list_find_ptr(const alpm_list_t *haystack, const void *needle);
char *alpm_list_find_str(const alpm_list_t *haystack, const char *needle);
alpm_list_t *alpm_list_diff(const alpm_list_t *lhs, const alpm_list_t *rhs, alpm_list_fn_cmp fn);
void alpm_list_diff_sorted(const alpm_list_t *left, const alpm_list_t *right,
		alpm_list_fn_cmp fn, alpm_list_t **onlyleft, alpm_list_t **onlyright);
void *alpm_list_to_array(const alpm_list_t *list, size_t n, size_t size);

#ifdef __cplusplus
}
#endif
#endif /* _ALPM_LIST_H */

/* vim: set noet: */
