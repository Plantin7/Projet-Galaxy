#include <stdio.h>

#include "../header/bodies.h"
#include "../header/graphic.h"
#include "../header/in_out.h"
#include "../header/quadtree.h"

int main(int argc, char* argv[]){

    /* Open the window */
    create_window();

    if(argc != 2){
    	fprintf(stderr, "Il me faut une galaxy ! (Vous pouvez les trouver dans le dossier data/ )\n");
    	return 0;
    }
    
    galaxy* new_galaxy = galaxy_import(argv[1]);


    double t = 0.0;
    Region region = create_region(create_point(-new_galaxy->width_region, -new_galaxy->width_region), 
                                  create_point(new_galaxy->width_region, new_galaxy->width_region));
    Quad* new_quad;
    int switchMode = 0;
    while (1) {
        MLV_Button_state state = MLV_NONE;
        MLV_Keyboard_button keyboard_button = MLV_NONE;
        MLV_get_event(&keyboard_button, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &state);
        new_quad = create_quad(region);
    
        for (int i = 0; i < new_galaxy->number_body; i++){
            insert_quad(new_quad, new_galaxy->body[i]);
        }
        for (int i = 0; i < new_galaxy->number_body; i++){
            new_galaxy->body[i]->fx = 0.0;
            new_galaxy->body[i]->fy = 0.0;
            compute_gravitational_force_quad(new_quad, new_galaxy->body[i]);
        }
        for (int i = 0; i < new_galaxy->number_body; i++){
            compute_position(new_galaxy->body[i], dt);
        }
        draw_black_filled_rectangle();
        if(keyboard_button == MLV_KEYBOARD_SPACE && state == MLV_RELEASED){
            switchMode = switchMode == 0 ? 1 : 0;
        }

        if(switchMode == 0){
          draw_galaxy(new_galaxy);
        }
        else {
            draw_whole_quadtree(new_quad, new_galaxy->width_region);
        }
        update_window();
        free_quad(new_quad);

        /* increment time */
        t += dt;
        wait_milliseconds(10);
    }
    free_galaxy(new_galaxy);
    free_window();

	return 0;
}