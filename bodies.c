#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bodies.h"

/*create Body*/
body* create_body(double px, double py, double vx, double vy, double mass){

    body* new_body = (body*)malloc(sizeof(body));

    new_body->px = px;
    new_body->py = py;

    new_body->vx = vx;
    new_body->vy = vy;

    new_body->mass = mass;

    new_body->fx = 0.0;
    new_body->fy = 0.0;

    return new_body;
}

void update_body(body* B1, body* B2, double delt){
    compute_gravitational_force(B1, B2);
    compute_position(B1, delt);
    compute_position(B2, delt);
}

/* compute the vector from body_1 to body_2 and the distance */

double distance(body* B1, body* B2, double* dx, double* dy){

    *dx = B1->px - B2->px;
    *dy = B1->py - B2->py;

    return sqrt((*dx) * (*dx) + (*dy) * (*dy)); /* distance between body_1 and body_2 */
}

/* compute the gravitational force acting on B1 from B2 */

void compute_gravitational_force(body* B1, body* B2) {
    double dx, dy, dist;

    dist = distance(B2, B1, &dx, &dy);

    B1->fx = (G * B1->mass * B2->mass/ (dist*dist)) * (dx/dist);
    B1->fy = (G * B1->mass * B2->mass/ (dist*dist)) * (dy/dist);

    dist = distance(B1, B2, &dx, &dy);

    B2->fx = (G * B1->mass * B2->mass/ (dist*dist)) * (dx/dist);
    B2->fy = (G * B1->mass * B2->mass/ (dist*dist)) * (dy/dist);
}

/* compute bodies's new velocity */
void compute_velocity(body* B, double delt) {

    B->vx += (delt * B->fx / B->mass);
    B->vy += (delt * B->fy / B->mass);
}

/* compute bodies's new position */
void compute_position (body* B, double delt) {
    compute_velocity(B, delt);
    B->px += (delt* B->vx);
    B->py += (delt* B->vy);
}

void free_body(body* body){
    free(body);
}
