#include <stdlib.h>
#include <wayland-server-core.h>
#include <wlr/util/log.h>

#include "../include/wm.h"
#include "../include/utils.h"
#include "../include/config.h"

wm_t *create_wm(config_t *config) {
    wm_t *wm = (wm_t*)malloc(sizeof(wm_t));
    if(!wm) {
        die(DIE_FAILURE, "Failed to allocate memory for wm");
    }

    wm->display = wl_display_create();
    if(!wm->display) {
        free(wm);
        die(DIE_FAILURE, "Failed to allocate memory for display");
    }

    wm->backend = wlr_backend_autocreate(wm->display, NULL);
    if(!wm->backend) {
        free(wm->display);
        free(wm);
        die(DIE_FAILURE, "Failed to allocate memory for wlr backend");
    }

    wm->renderer = wlr_renderer_autocreate(wm->backend);
    if(!wm->renderer) {
        free(wm->display);
        free(wm->backend);
        free(wm);
        die(DIE_FAILURE, "Failed to allocate memory for wlr renderer");
    }

    wm->allocator = wlr_allocator_autocreate(wm->backend, wm->renderer);
    if(!wm->allocator) {
        free(wm->display);
        free(wm->backend);
        free(wm->renderer);
        free(wm);
        die(DIE_FAILURE, "Failed to allocate memory for wlr allocator");
    }

    wm->compositor = wlr_compositor_create(wm->display, 1, wm->renderer);
    if(!wm->compositor) {
        free(wm->display);
        free(wm->backend);
        free(wm->renderer);
        free(wm->allocator);
        free(wm);
        die(DIE_FAILURE, "Failed to allocate memory for wlr compositor");
    }

    if(config->debug) info("wm successefully created");
    return wm;
}

void run_wm(wm_t *wm) {
    if(!wm) {
        destroy_wm(wm);
        die(DIE_FAILURE, "wm is null");
    }

    wm->event_loop = wl_display_get_event_loop(wm->display);
    wl_display_run(wm->display);
}

void destroy_wm(wm_t *wm) {
    if(wm) {
        if(wm->event_loop) free(wm->event_loop);

        free(wm->display);
        free(wm->backend);
        free(wm->allocator);
        free(wm->renderer);
        free(wm->compositor);
        free(wm);
    }
}
