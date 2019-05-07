#include <stdio.h>

#include "bodies.h"
#include "graphic.h"
#include "in_out.h"

int main(int argc, char* argv[]){

    /* Open the window */
    create_window();

    /* Initialize two bodies */
    body* B1 = create_body(1e4, -1e4, 2.5e3, 0.0,  4e21);
    body* B2 = create_body(-1e4, 1e4, -2.5e3, 0.0,  4e21);

    double t = 0.0;
    while (1) {
        update_body(B1, B2, dt);

        /* draw */
        draw_black_filled_rectangle();
        draw_body(B1);
        draw_body(B2);
        update_window();

        /* increment time */
        t += dt;
        wait_milliseconds(20);
    }

    free_body(B2);
    free_body(B1);
    free_window();

	return 0;
}