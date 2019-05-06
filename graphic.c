#include "graphic.h"


void create_window() {
    MLV_create_window("Window", "Window", WINDOW_WIDTH, WINDOW_HEIGHT);
}

void draw_body(body *B) {
    int window_x = WINDOW_WIDTH*(0.5+0.5*(B->px/WIDTH_OF_REGION));
    int window_y = WINDOW_HEIGHT*(0.5+0.5*(B->py/WIDTH_OF_REGION));
    
    MLV_draw_filled_circle(window_x, window_y, 10, MLV_COLOR_WHITE);
}

void draw_black_filled_rectangle() {
	 MLV_draw_filled_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, MLV_COLOR_BLACK);
}

void update() {
	MLV_update_window();
}

void wait_milliseconds(int value) {
	MLV_wait_milliseconds(value);
}

