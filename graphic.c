#include "graphic.h"


void create_window() {
    MLV_create_window("Window", "Window", WINDOW_WIDTH, WINDOW_HEIGHT);
}

void draw_body(body *B, int width_region) {
    int window_x = WINDOW_WIDTH*(0.5+0.5*(B->px/ width_region));
    int window_y = WINDOW_HEIGHT*(0.5+0.5*(B->py/ width_region));

    MLV_draw_filled_circle(window_x, window_y, 0.8, MLV_COLOR_WHITE);
}

void draw_galaxy(galaxy* new_galaxy){
	body* current = new_galaxy->body;
	while(current != NULL){
		draw_body(current, new_galaxy->width_region / 2);
		current = current->next;
	}
}

void draw_black_filled_rectangle() {
	 MLV_draw_filled_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, MLV_COLOR_BLACK);
}

void update_window() {
	MLV_update_window();
}

void wait_milliseconds(int value) {
	MLV_wait_milliseconds(value);
}

void free_window(){
	MLV_free_window();
}

