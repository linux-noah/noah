#ifndef NOAH_DARWIN_SELECT_H
#define NOAH_DARWIN_SELECT_H

#define DARWIN_FD_SETSIZE 1024

/*
 * Internal fd_set definition in Darwin
 *
typedef struct {
  uint32_t fds_bits[DARWIN_FD_SETSIZE / 8 / sizeof(uint32_t)];
} fd_set;

*/

#endif
