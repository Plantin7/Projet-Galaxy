#include <stdio.h>

#include "../header/bodies.h"
#include "../header/graphic.h"
#include "../header/in_out.h"
#include "../header/quadtree.h"


int main2(int argc, char* argv[]){
    create_window();
    int width_region = 2.83800e+06;
    Region test = create_region(create_point(-width_region, -width_region), create_point(width_region, width_region));
    Quad* new_quad = create_quad(test);

    body* a = create_body(-70.30668e+04, -63.34133e+04, -2.71234e+04, -3.49596e+04, 1.00000e+19);
    body* b = create_body(-70.30668e+04, 10.34133e+04, -2.71234e+04, -3.49596e+04, 1.00000e+19);
    body* c = create_body(3.85883e+04, 81.25883e+04, 3.09988e+04, -1.44838e+04, 1.00000e+19);
    body* d = create_body(-20.69350e+04, 43.61705e+04, 2.89615e+04, 1.57746e+04, 1.00000e+19);
    body* e = create_body(22.89300e+05, 13.46216e+05, 1.18019e+04, -9.86171e+03, 1.00000e+19);

    body* tab[5] ={a,b,c,d,e};

    draw_region(test, width_region);
    update_window();
    wait_milliseconds(2000);
    draw_body(a, width_region);
    update_window();
    wait_milliseconds(1000);
    insert_quad(new_quad, a);

    draw_body(b, width_region);
    update_window();
    wait_milliseconds(1000);
    insert_quad(new_quad, b);

    draw_body(c, width_region);
    update_window();
    wait_milliseconds(1000);
    insert_quad(new_quad, c);

    draw_body(d, width_region);
    update_window();
    wait_milliseconds(1000);
    insert_quad(new_quad, d);

    draw_body(e, width_region);
    update_window();
    wait_milliseconds(1000);
    insert_quad(new_quad, e);


    update_window();


    wait_milliseconds(10000);
    char fake; 
    scanf("%c", &fake);
    free_window();
    return 0;
}

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
    while (1) {
    
        Quad* new_quad = create_quad(region);
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
        draw_galaxy(new_galaxy);
        update_window();

        /* increment time */
        t += dt;
        wait_milliseconds(10);
    }
    printf("Je sors\n");
    free_galaxy(new_galaxy);
    free_window();

	return 0;
}