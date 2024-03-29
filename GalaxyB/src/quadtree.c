#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../header/quadtree.h"
#include "../header/graphic.h"

Quad* create_quad(Region r){
	Quad* new_quad = (Quad*)malloc(sizeof(Quad));

	new_quad->region = r;
	new_quad->body = NULL;

	new_quad->mass = 0;
	new_quad->center_mass = create_point(0,0);

	new_quad->quad_NW = NULL;
	new_quad->quad_NE = NULL;
	new_quad->quad_SW = NULL;
	new_quad->quad_SE = NULL;

	return new_quad;
}

Point create_point(double x, double y){
	return (Point){x, y};
}

Region create_region(Point topLeft, Point bottomRight){
	return (Region){topLeft, bottomRight};
}

int is_in_region(Region r, body b){
	return b.px >= r.topLeft.x &&
		   b.px <= r.bottomRight.x &&
		   b.py >= r.topLeft.y &&
		   b.py <= r.bottomRight.y ;
}

Region quad_NW(Region r){
	return create_region(create_point(r.topLeft.x, r.topLeft.y), 
						 create_point((r.topLeft.x + r.bottomRight.x) / 2, (r.topLeft.y + r.bottomRight.y)/ 2));
}

Region quad_NE(Region r){
	return create_region(create_point((r.topLeft.x + r.bottomRight.x) / 2, r.topLeft.y), 
						 create_point(r.bottomRight.x, (r.topLeft.y + r.bottomRight.y)/2));
}

Region quad_SW(Region r){
	return create_region(create_point(r.topLeft.x , (r.topLeft.y + r.bottomRight.y) / 2), 
		                 create_point((r.topLeft.x + r.bottomRight.x) / 2, r.bottomRight.y));
}

Region quad_SE(Region r){
	return create_region(create_point((r.topLeft.x + r.bottomRight.x)/2, (r.topLeft.y + r.bottomRight.y)/2), 
						 create_point(r.bottomRight.x, r.bottomRight.y));
}

int is_leaf(Quad* qt){
	return qt->quad_NW == NULL && 
		   qt->quad_NE == NULL && 
		   qt->quad_SW == NULL && 
		   qt->quad_SE == NULL;
}

void insert_quad(Quad* qt, body* b){
	if(b == NULL){
		return;
	}
	if(!is_in_region(qt->region, *b)){
		return;
	}

	if(!is_leaf(qt)){
		double new_mass = qt->mass + b->mass;
		double tmp_x = ((qt->center_mass.x * qt->mass) + (b->px * b->mass))/new_mass;
		double tmp_y = ((qt->center_mass.y * qt->mass) + (b->py * b->mass))/new_mass;
		qt->center_mass.x = tmp_x;
		qt->center_mass.y = tmp_y;
		qt->mass = new_mass;
		insert_quad(search_quad(qt, b), b);
	}
	else {
		if(qt->body == NULL){
			qt->body = b;
		}
		else {
			qt->quad_NW = create_quad(quad_NW(qt->region));
			qt->quad_NE = create_quad(quad_NE(qt->region));
			qt->quad_SW = create_quad(quad_SW(qt->region));
			qt->quad_SE = create_quad(quad_SE(qt->region));
			
			qt->mass = 0.0;
			qt->center_mass.x = 0.0;
			qt->center_mass.y = 0.0;

			insert_quad(qt, b);
			insert_quad(qt, qt->body);
			qt->body = NULL;
			
		}
	}
}

Quad* search_quad(Quad* qt, body* b){
	if(is_in_region(qt->quad_NW->region, *b)){
		return qt->quad_NW;
	}
	if(is_in_region(qt->quad_NE->region, *b)){
		return qt->quad_NE;
	}
	if(is_in_region(qt->quad_SW->region, *b)){
		return qt->quad_SW;
	}
	if(is_in_region(qt->quad_SE->region, *b)){
		return qt->quad_SE;
	}
	return NULL;
}

double compute_distance(Point center_mass, body* b) {
	double x = center_mass.x - b->px ;
	double y = center_mass.y - b->py ;

	return sqrt((x*x) + (y*y));
}

void compute_gravitational_force_quad(Quad* qt, body* b){
	if(is_leaf(qt) && qt->body != NULL){
		if(qt->body != b){
			double dx = qt->body->px - b->px;
			double dy = qt->body->py - b->py;
			double d = sqrt((dx*dx) + (dy*dy));
			b->fx += (G * b->mass * qt->body->mass/ (d*d+(C*C)))*(dx/d); 
    		b->fy += (G * b->mass * qt->body->mass/ (d*d+(C*C)))*(dy/d);
    		return;
		}
	}

	if(!is_leaf(qt)){
		double dist = compute_distance(qt->center_mass, b);
		double s = (qt->region.bottomRight.y - qt->region.topLeft.y);

		if(s < (dist / 2)){
				double dx = qt->center_mass.x - b->px;
				double dy = qt->center_mass.y - b->py;

			    b->fx += (G * b->mass * qt->mass/ (dist*dist+(C*C)))*(dx/dist); 
    			b->fy += (G * b->mass * qt->mass/ (dist*dist+(C*C)))*(dy/dist); 
		}
		else {
			compute_gravitational_force_quad(qt->quad_NW, b);
			compute_gravitational_force_quad(qt->quad_NE, b);
			compute_gravitational_force_quad(qt->quad_SW, b);
			compute_gravitational_force_quad(qt->quad_SE, b);
		}
	}
}


void free_quad(Quad* qt){
	if(qt){
		free_quad(qt->quad_NW);
		free_quad(qt->quad_NE);
		free_quad(qt->quad_SW);
		free_quad(qt->quad_SE);
		free(qt);
	}
}
