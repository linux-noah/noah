#ifndef NOAH_MALLOC
#define NOAH_MALLOC

#include <stddef.h>

void init_malloc(void);
void *shm_malloc(size_t nbytes);
void shm_free(void *);

#endif
