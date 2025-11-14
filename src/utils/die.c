#include <stdlib.h>
#include <wlr/util/log.h>

#include "../../include/utils.h"

void die(int status, const char *message) {
    if(message) wlr_log(WLR_ERROR, "Died: %s\n", message);

    exit(status);
}
