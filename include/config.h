#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

typedef struct {
    uint8_t debug;
} config_t;

config_t *get_default_config();
config_t *get_config_from_file(const char *file_path);

#endif
