#include <stdio.h>
#include <math.h>
#include "bodies.h"

/* compute the vector from body_1 to body_2 and the distance */

double distance(body body_1, body body_2, double* dx, double* dy){

    *dx = body_2.px - body_1.px;
    *dy = body_2.py - body_1.py;

    return sqrt((*dx)*(*dx)+(*dy)*(*dy)); /* distance between body_1 and body_2 */
}

/* compute the gravitational force acting on B1 from B2 */

double gravitational_force(double mass_1, double mass_2, double d, double dist) {
    return (G*mass_1 * mass_2 / (dist*dist)) * (d/dist); 
}

/* compute bodies's new velocity */
double velocity(double delt, double force, double mass) {
    return (delt * force / mass);
}

/* compute bodies's new position */
double position (double delt, double velocity) {
    return (delt* velocity);
}
