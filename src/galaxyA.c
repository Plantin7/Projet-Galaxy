#include <stdio.h>

#include "../header/bodies.h"
#include "../header/graphic.h"
#include "../header/in_out.h"

int main(int argc, char* argv[]){

    /* Open the window */
    create_window();

    if(argc != 2){
    	fprintf(stderr, "Il me faut une galaxy ! (Vous pouvez les trouver dans le dossier data/ )\n");
    	return 0;
    }
    
    galaxy* new_galaxy = galaxy_import(argv[1]);

    double t = 0.0;
    while (1) {
    	body* tmp = new_galaxy->body;
    	while (tmp != NULL){
    		tmp->fx = 0.0f;
    		tmp->fy = 0.0f;

    		body* next_body = tmp;
    		while (next_body != NULL){
    			if (tmp != next_body){
    				compute_gravitational_force(tmp, next_body);
    			}
    				next_body = next_body->next;
    		}
    		compute_position (tmp, dt);
    		tmp = tmp->next;
    	}
    	/*printf("Current %d------%lf %lf %lf %lf %lf \n", i, current->px, current->py, current->vx, current->vy, current->mass);*/
        /* draw */
        draw_black_filled_rectangle();
        draw_galaxy(new_galaxy);
        update_window();

        /* increment time */
        t += dt;
        wait_milliseconds(10);
    }
    free_galaxy(new_galaxy);
    free_window();

	return 0;
}