#include <stdio.h>
#include <time.h>

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
    /*clock_t start_t, end_t;
    double total_t;*/

    while (1) {
        /*start_t = clock();*/
        for (int i = 0; i < new_galaxy->number_body; i++){
            new_galaxy->body[i]->fx = 0.0;
            new_galaxy->body[i]->fy = 0.0;

            for (int j = 0; j < new_galaxy->number_body; j++){
                if(i != j){
                    compute_gravitational_force(new_galaxy->body[i], new_galaxy->body[j]);
                }
            }
            compute_position(new_galaxy->body[i], dt);
        }
        draw_black_filled_rectangle();
        draw_galaxy(new_galaxy);
        update_window();

        /*end_t = clock();
        total_t = (double)(end_t - start_t)/CLOCKS_PER_SEC;
        printf("%f\n", total_t);*/

        /* increment time */
        t += dt;
        wait_milliseconds(10);
    }
    free_galaxy(new_galaxy);
    free_window();

	return 0;
}
