#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include "bodies.h"

typedef struct _point{
	double x;
	double y;
}Point;


typedef struct _region {
	Point topLeft;
	Point bottomRight;
} Region;


typedef struct _quad {
	Region region;
	
	body* body;

	double mass;
	Point center_mass;

	struct _quad* quad_NW;
	struct _quad* quad_NE;
	struct _quad* quad_SW;
	struct _quad* quad_SE;
}Quad;


Quad* create_quad(Region r);
Point create_point(double x, double y);
Region create_region(Point topLeft, Point bottomRight);

void insert_quad(Quad* qt, body* b);
Quad* search_quad(Quad* qt, body* b);
int is_in_region(Region r, body b);

void compute_gravitational_force_quad(Quad* qt, body* b);

Region quad_NW(Region r);
Region quad_NE(Region r);
Region quad_SW(Region r);
Region quad_SE(Region r);


void free_quad(Quad* qt);

/*

on va avoir : 
- une fonction de creation
- une foncton insert
- une fonction de recherche
- une fonction d'extraction
- une structure region qui represente une region rectangulaire
- une fonction de creation d'un quadrant, (region quad_NW(region R))
- une fonction pour savoir si un corps est dans une région (is_in_region(region r, body B))


un noeud contiendra une région, et un pointeur sur un corps ainsi que des pointeurs sur ses quatres fils
si c'est une feuille, le corps 



*/

#endif