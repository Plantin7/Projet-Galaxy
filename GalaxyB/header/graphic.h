#include <MLV/MLV_all.h>
#include "bodies.h"
#include "quadtree.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WIDTH_OF_REGION 4e4


void create_window();
void draw_body(body *B, int width_region);
void draw_galaxy(galaxy* new_galaxy);
void draw_black_filled_rectangle();
void update_window();
void wait_milliseconds(int value);
void free_window();


/*Quadtree Part*/

void draw_region(Region r, int width_region);
void draw_quadtree(Quad* qt, int width_region);
void draw_whole_quadtree(Quad*qt, int width_region);
