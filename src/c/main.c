#include <pebble.h>
#include "main.h"

static Window *s_main_window;

static void init() {
  s_main_window = window_create();
  
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
}

static void deinit() {
  
}

static void main_window_load(Window *window) {
  
}

static void main_window_unload(Window *window) {
  
}

int main(void) {
  // Set up
  init();
  
  // Main event loop
  app_event_loop();
  
  // Clean up
  deinit();
}

