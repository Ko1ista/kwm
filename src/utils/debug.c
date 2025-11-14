#include <wlr/util/log.h>

#include "../../include/utils.h"

void info(const char *message) {
    if(message) wlr_log(WLR_INFO, "DEBUG: %s\n", message);
}

void warn(const char *message) {
    if(message) wlr_log(WLR_INFO, "WARN: %s\n", message);
}
