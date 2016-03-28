#include <pebble.h>

static Window *s_window;
static TextLayer *s_text_layer;

static void init(void) {
	// Create window
	s_window = window_create();
  Layer *window_layer = window_get_root_layer(s_window);
  GRect bounds = layer_get_bounds(window_layer);
	
  //text
	s_text_layer = text_layer_create(bounds);
	text_layer_set_text(s_text_layer, "P:/ Error: main.c not found P:/ Trying again...                  P:/ Error: main.c not found P:/ Trying again...                  P:/ Error: main.c not found P:/ Exceeded retries              P:/ Reboot to try to launch P:/ Input disconnected      P:/ Error: Data Corrupted    P:/ _                                                                                     Pebble Terminal v 3.9.2");
  
  //font
	text_layer_set_font(s_text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14));
	text_layer_set_text_alignment(s_text_layer, GTextAlignmentLeft);

	//ad layer
	layer_add_child(window_get_root_layer(s_window), text_layer_get_layer(s_text_layer));
  
  //indent
  text_layer_enable_screen_text_flow_and_paging(s_text_layer, 2);

	//window animation
	window_stack_push(s_window, false);
	
	// App Logs
	APP_LOG(APP_LOG_LEVEL_DEBUG, "'crashed'");
}

static void deinit(void) {
	// Destroy layer
	text_layer_destroy(s_text_layer);
	
	// Destroy window
	window_destroy(s_window);
}

int main(void) {
	init();
	app_event_loop();
	deinit();
}
