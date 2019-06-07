#ifndef __BODIES_H__
#define __BODIES_H__

#define G  6.674e-11 /* the gravitational constant */
#define dt 0.1       /* time step */
#define C 1e4

typedef struct _body {
    double px;   /* x position */
    double py;   /* y position */
    double vx;   /* x velocity */
    double vy;   /* y velocity */
    double fx;   /* x force */
    double fy;   /* y force */
    double mass; /* mass */
   /*struct _body* next;*/
} body;

typedef struct _galaxy {
    int number_body;      /*Number of body in file*/
    double width_region;  /*witdth of the region*/
    body** body;       /*Array of body*/
} galaxy;

body* create_body(double px, double py, double vx, double vy, double mass);

galaxy* create_galaxy(int number_body, double width_region);

void update_body(body* B1, body* B2, double delt);

double distance(body* B1, body* B2, double* dx, double* dy);

void compute_gravitational_force(body* B1, body* B2);

void compute_velocity(body* B, double delt);

void compute_position (body* B, double delt);

void free_galaxy(galaxy* new_galaxy);

void free_body(body* body);

#endif
