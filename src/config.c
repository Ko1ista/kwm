#include <stdlib.h>
#include <stdio.h>

#include "../include/config.h"
#include "../include/utils.h"

config_t *get_default_config() {
    config_t *config = (config_t*)malloc(sizeof(config_t));
    if(!config) {
        die(DIE_FAILURE, "Failed to allocate memory for config");
    }

    config->debug = 1;

    return config;
}

config_t *get_config_from_file(const char *file_path) {
    // TODO: MAKE IT WORK

    FILE *file = fopen(file_path, "r");
    if(!file) {
        warn("Used default config");
        return get_default_config();
    }

    config_t *config = (config_t*)malloc(sizeof(config_t));
    if(!config) {
        die(DIE_FAILURE, "Failed to allocate memory for config");
    }

    return config;
}
