#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../header/bodies.h"

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

galaxy* create_galaxy(int number_body, double width_region){
    galaxy* new_galaxy = (galaxy*)malloc(sizeof(galaxy));
    new_galaxy->number_body = number_body;
    new_galaxy->width_region = width_region;
    new_galaxy->body = (body**)malloc(number_body*sizeof(body*));

    return new_galaxy;
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

    return sqrt(((*dx) * (*dx)) + ((*dy) * (*dy))); /* distance between body_1 and body_2 */
}

/* compute the gravitational force acting on B1 from B2 */

void compute_gravitational_force(body* B1, body* B2) {
    double dx = B2->px - B1->px;
    double dy = B2->py - B1->py;

    double dist = sqrt(dx*dx +dy*dy);

    B1->fx += (G * B1->mass * B2->mass/ (dist*dist+(C*C)))*(dx/dist); 
    B1->fy += (G * B1->mass * B2->mass/ (dist*dist+(C*C)))*(dy/dist); 
}

/* compute bodies's new velocity */
void compute_velocity(body* B, double delt) {

    B->vx += (delt * B->fx) / B->mass;
    B->vy += (delt * B->fy) / B->mass;
}

/* compute bodies's new position */
void compute_position (body* B, double delt) {
    compute_velocity(B, delt);
    B->px += delt* B->vx;
    B->py += delt* B->vy;
}

void free_galaxy(galaxy* new_galaxy){
    for (int i = 0; i < new_galaxy->number_body; i++){
        free_body(new_galaxy->body[i]);
    }

    free(new_galaxy->body);
    free(new_galaxy);
}

void free_body(body* body){
    free(body);
}
