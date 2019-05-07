#ifndef __BODIES_H__
#define __BODIES_H__

#define G  6.674e-11 /* the gravitational constant */
#define dt 0.1       /* time step */

typedef struct _body {
    double px;   /* x position */
    double py;   /* y position */
    double vx;   /* x velocity */
    double vy;   /* y velocity */
    double fx;   /* x force */
    double fy;   /* y force */
    double mass; /* mass */
} body;


body* create_body(double px, double py, double vx, double vy, double mass);

void update_body(body* B1, body* B2, double delt);

void free_body(body* body);

#endif