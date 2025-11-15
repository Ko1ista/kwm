#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <wlr/util/log.h>

#include "../include/wm.h"
#include "../include/utils.h"
#include "../include/config.h"

int main(int argc, char* argv[]) {
    wlr_log_init(WLR_DEBUG, NULL);
    config_t *config =  get_config_from_file(NULL);

    wm_t *wm = create_wm(config);
    if(!wm) {
        die(DIE_FAILURE, "Failed to initialize compositor\n");
    }

    run_wm(wm);
    destroy_wm(wm);

    return 0;
}
