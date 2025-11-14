#ifndef UTILS_H
#define UTILS_H

typedef enum {
    DIE_SUCCESS = 0,
    DIE_FAILURE = 1
} die_status_t;

void die(int status, const char *message);

#endif
