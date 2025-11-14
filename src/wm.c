#include <stdlib.h>

#include "../include/wm.h"
#include "../include/utils.h"

wm_t *create_wm() {
    wm_t *wm = (wm_t*)malloc(sizeof(wm_t));
    if(!wm) {
        die(DIE_FAILURE, "Failed to allocate memory for wm");
    }



    return wm;
}

void destroy_wm(wm_t *wm) {
    if(wm) {
        free(wm);
    }
}
