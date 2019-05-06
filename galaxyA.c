#include <stdio.h>

#include "bodies.h"
#include "graphic.h"
#include "in_out.h"



int main(int argc, char* argv[]){

    /* Open the window */
    create_window();

    /* Initialise two bodies */
    body B1 = {.px = 1e4, .py = -1e4, .vx = 2.5e3, .vy = 0.0, .mass = 4e21};
    body B2 = {.px = -1e4, .py = 1e4, .vx = -2.5e3, .vy = 0.0, .mass = 4e21};

    double t = 0.0;
    while (1) {
        double dist, dx, dy;
        
        /* compute the gravitational forces */

        /* compute the vector from B1 to B2 and the distance */

        dist = distance(B1, B2, &dx, &dy);

        /* compute the gravitational force acting on B1 from B2 */
        B1.fx = gravitational_force(B1.mass, B2.mass, dx, dist);  
        B1.fy = gravitational_force(B1.mass, B2.mass, dy, dist);

        /* compute the vector from B2 to B1 and the distance */
        dist = distance(B2, B1, &dx, &dy);

        /* compute the gravitational force acting on B2 from B1 */
        B2.fx = gravitational_force(B1.mass, B2.mass, dx, dist);
        B2.fy = gravitational_force(B1.mass, B2.mass, dy, dist);

        /* compute new velocities and positions */

        /* compute B1's new velocity */
        B1.vx += velocity(dt, B1.fx, B1.mass);
        B1.vy += velocity(dt, B1.fy, B1.mass);
        /* compute B1's new position */
        B1.px += position(dt, B1.vx);
        B1.py += position(dt, B1.vy);

        /* compute B2's new velocity */
        B2.vx += velocity(dt, B2.fx, B2.mass);
        B2.vy += velocity(dt, B2.fy, B2.mass);
        /* compute B2's new position */
        B2.px += position(dt, B2.vx);
        B2.py += position(dt, B2.vy);

        /* draw */
        draw_black_filled_rectangle();
        draw_body(&B1);
        draw_body(&B2);
        update();

        /* increment time */
        t += dt;
        wait_milliseconds(20);
    }

	return 0;
}