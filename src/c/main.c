#include <pebble.h>
#include "main.h"

// Declare static pointers
static Window *s_main_window;
static TextLayer *s_time_layer;

static void init() {
  s_main_window = window_create();
  
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  
  window_stack_push(s_main_window, true);
}

static void deinit() {
  window_destroy(s_main_window);
}

static void main_window_load(Window *window) {
  // Get information about the Window
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // Create text layer with specific bounds
  s_time_layer = text_layer_create(
    GRect(0, PBL_IF_BW_ELSE(58, 52), bounds.size.w, 50));
  
  text_layer_set_background_color(s_time_layer, GColorCyan);
  text_layer_set_text_color(s_time_layer, GColorBlack);
  text_layer_set_text(s_time_layer, "00:00");
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_MEDIUM_NUMBERS));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  
  // Add the layer as a child of the Window's root layer
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
}

static void main_window_unload(Window *window) {
  text_layer_destroy(s_time_layer);
}

int main(void) {
  // Set up
  init();
  
  // Main event loop
  app_event_loop();
  
  // Clean up
  deinit();
}

