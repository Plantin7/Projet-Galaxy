#include <MLV/MLV_all.h>
#include "bodies.h"

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400
#define WIDTH_OF_REGION 4e4


void create_window();
void draw_body(body *B);
void draw_black_filled_rectangle();
void update();
void wait_milliseconds(int value);