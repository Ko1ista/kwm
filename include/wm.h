#ifndef WM_H
#define WM_H

#include <wayland-server-core.h>
#include <wlr/backend.h>
#include <wlr/render/wlr_renderer.h>
#include <wlr/render/allocator.h>
#include <wlr/types/wlr_compositor.h>

#include "./config.h"

typedef struct {
    struct wl_display *display;
    struct wl_event_loop *event_loop;

    struct wlr_backend *backend;
    struct wlr_renderer *renderer;
    struct wlr_allocator *allocator;

    struct wlr_compositor *compositor;

} wm_t;

wm_t *create_wm(config_t *config);
void destroy_wm(wm_t *wm);

#endif
