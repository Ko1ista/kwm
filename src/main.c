#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <wlr/util/log.h>

#include "../include/wm.h"
#include "../include/utils.h"

int main(int argc, char* argv[]) {
    wlr_log_init(WLR_DEBUG, NULL);

    wm_t *wm = create_wm();
    if(!wm) {
        die(DIE_FAILURE, "Failed to initialize compositor\n");
    }
    
    destroy_wm(wm);

    return 0;
}
