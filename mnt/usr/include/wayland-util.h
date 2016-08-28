/*
 * Copyright © 2008 Kristian Høgsberg
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/** \file wayland-util.h
 *
 * \brief Utility classes, functions, and macros.
 */

#ifndef WAYLAND_UTIL_H
#define WAYLAND_UTIL_H

#include <math.h>
#include <stddef.h>
#include <inttypes.h>
#include <stdarg.h>

#ifdef  __cplusplus
extern "C" {
#endif

/* GCC visibility */
#if defined(__GNUC__) && __GNUC__ >= 4
#define WL_EXPORT __attribute__ ((visibility("default")))
#else
#define WL_EXPORT
#endif

/* Deprecated attribute */
#if defined(__GNUC__) && __GNUC__ >= 4
#define WL_DEPRECATED __attribute__ ((deprecated))
#else
#define WL_DEPRECATED
#endif

/* Printf annotation */
#if defined(__GNUC__) && __GNUC__ >= 4
#define WL_PRINTF(x, y) __attribute__((__format__(__printf__, x, y)))
#else
#define WL_PRINTF(x, y)
#endif

struct wl_message {
	const char *name;
	const char *signature;
	const struct wl_interface **types;
};

struct wl_interface {
	const char *name;
	int version;
	int method_count;
	const struct wl_message *methods;
	int event_count;
	const struct wl_message *events;
};

/** \class wl_list
 *
 * \brief doubly-linked list
 *
 * The list head is of "struct wl_list" type, and must be initialized
 * using wl_list_init().  All entries in the list must be of the same
 * type.  The item type must have a "struct wl_list" member. This
 * member will be initialized by wl_list_insert(). There is no need to
 * call wl_list_init() on the individual item. To query if the list is
 * empty in O(1), use wl_list_empty().
 *
 * Let's call the list reference "struct wl_list foo_list", the item type as
 * "item_t", and the item member as "struct wl_list link".
 *
 * The following code will initialize a list:
 * \code
 * struct wl_list foo_list;
 *
 * struct item_t {
 * 	int foo;
 * 	struct wl_list link;
 * };
 * struct item_t item1, item2, item3;
 *
 * wl_list_init(&foo_list);
 * wl_list_insert(&foo_list, &item1.link);	// Pushes item1 at the head
 * wl_list_insert(&foo_list, &item2.link);	// Pushes item2 at the head
 * wl_list_insert(&item2.link, &item3.link);	// Pushes item3 after item2
 * \endcode
 *
 * The list now looks like [item2, item3, item1]
 *
 * Iterate the list in ascending order:
 * \code
 * item_t *item;
 * wl_list_for_each(item, foo_list, link) {
 * 	Do_something_with_item(item);
 * }
 * \endcode
 */
struct wl_list {
	struct wl_list *prev;
	struct wl_list *next;
};

void
wl_list_init(struct wl_list *list);

void
wl_list_insert(struct wl_list *list, struct wl_list *elm);

void
wl_list_remove(struct wl_list *elm);

int
wl_list_length(const struct wl_list *list);

int
wl_list_empty(const struct wl_list *list);

void
wl_list_insert_list(struct wl_list *list, struct wl_list *other);

/**
 * Retrieves a pointer to the containing struct of a given member item.
 *
 * This macro allows conversion from a pointer to a item to its containing
 * struct. This is useful if you have a contained item like a wl_list,
 * wl_listener, or wl_signal, provided via a callback or other means and would
 * like to retrieve the struct that contains it.
 *
 * To demonstrate, the following example retrieves a pointer to
 * `example_container` given only its `destroy_listener` member:
 *
 * \code
 * struct example_container {
 *     struct wl_listener destroy_listener;
 *     // other members...
 * };
 *
 * void example_container_destroy(struct wl_listener *listener, void *data)
 * {
 *     struct example_container *ctr;
 *
 *     ctr = wl_container_of(listener, ctr, destroy_listener);
 *     // destroy ctr...
 * }
 * \endcode
 *
 * \param ptr A valid pointer to the contained item.
 *
 * \param sample A pointer to the type of content that the list item
 * stores. Sample does not need be a valid pointer; a null or
 * an uninitialised pointer will suffice.
 *
 * \param member The named location of ptr within the sample type.
 *
 * \return The container for the specified pointer.
 */
#define wl_container_of(ptr, sample, member)				\
	(__typeof__(sample))((char *)(ptr) -				\
			     offsetof(__typeof__(*sample), member))
/* If the above macro causes problems on your compiler you might be
 * able to find an alternative name for the non-standard __typeof__
 * operator and add a special case here */

#define wl_list_for_each(pos, head, member)				\
	for (pos = wl_container_of((head)->next, pos, member);	\
	     &pos->member != (head);					\
	     pos = wl_container_of(pos->member.next, pos, member))

#define wl_list_for_each_safe(pos, tmp, head, member)			\
	for (pos = wl_container_of((head)->next, pos, member),		\
	     tmp = wl_container_of((pos)->member.next, tmp, member);	\
	     &pos->member != (head);					\
	     pos = tmp,							\
	     tmp = wl_container_of(pos->member.next, tmp, member))

#define wl_list_for_each_reverse(pos, head, member)			\
	for (pos = wl_container_of((head)->prev, pos, member);	\
	     &pos->member != (head);					\
	     pos = wl_container_of(pos->member.prev, pos, member))

#define wl_list_for_each_reverse_safe(pos, tmp, head, member)		\
	for (pos = wl_container_of((head)->prev, pos, member),	\
	     tmp = wl_container_of((pos)->member.prev, tmp, member);	\
	     &pos->member != (head);					\
	     pos = tmp,							\
	     tmp = wl_container_of(pos->member.prev, tmp, member))

struct wl_array {
	size_t size;
	size_t alloc;
	void *data;
};

#define wl_array_for_each(pos, array)					\
	for (pos = (array)->data;					\
	     (const char *) pos < ((const char *) (array)->data + (array)->size); \
	     (pos)++)

void
wl_array_init(struct wl_array *array);

void
wl_array_release(struct wl_array *array);

void *
wl_array_add(struct wl_array *array, size_t size);

int
wl_array_copy(struct wl_array *array, struct wl_array *source);

typedef int32_t wl_fixed_t;

static inline double
wl_fixed_to_double (wl_fixed_t f)
{
	union {
		double d;
		int64_t i;
	} u;

	u.i = ((1023LL + 44LL) << 52) + (1LL << 51) + f;

	return u.d - (3LL << 43);
}

static inline wl_fixed_t
wl_fixed_from_double(double d)
{
	union {
		double d;
		int64_t i;
	} u;

	u.d = d + (3LL << (51 - 8));

	return u.i;
}

static inline int
wl_fixed_to_int(wl_fixed_t f)
{
	return f / 256;
}

static inline wl_fixed_t
wl_fixed_from_int(int i)
{
	return i * 256;
}

/**
 * \brief A union representing all of the basic data types that can be passed
 * along the wayland wire format.
 *
 * This union represents all of the basic data types that can be passed in the
 * wayland wire format.  It is used by dispatchers and runtime-friendly
 * versions of the event and request marshaling functions.
 */
union wl_argument {
	int32_t i; /**< signed integer */
	uint32_t u; /**< unsigned integer */
	wl_fixed_t f; /**< fixed point */
	const char *s; /**< string */
	struct wl_object *o; /**< object */
	uint32_t n; /**< new_id */
	struct wl_array *a; /**< array */
	int32_t h; /**< file descriptor */
};

/**
 * \brief A function pointer type for a dispatcher.
 *
 * A dispatcher is a function that handles the emitting of callbacks in client
 * code.  For programs directly using the C library, this is done by using
 * libffi to call function pointers.  When binding to languages other than C,
 * dispatchers provide a way to abstract the function calling process to be
 * friendlier to other function calling systems.
 *
 * A dispatcher takes five arguments:  The first is the dispatcher-specific
 * implementation data associated with the target object.  The second is the
 * object on which the callback is being invoked (either wl_proxy or
 * wl_resource).  The third and fourth arguments are the opcode the wl_message
 * structure corresponding to the callback being emitted.  The final argument
 * is an array of arguments received from the other process via the wire
 * protocol.
 */
typedef int (*wl_dispatcher_func_t)(const void *, void *, uint32_t,
				    const struct wl_message *,
				    union wl_argument *);

typedef void (*wl_log_func_t)(const char *, va_list) WL_PRINTF(1, 0);

#ifdef  __cplusplus
}
#endif

#endif
