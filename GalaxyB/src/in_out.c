#include <stdio.h>
#include <stdlib.h>

#include "../header/in_out.h"

galaxy* galaxy_import(const char* file){
  FILE* f;

  f = fopen(file, "r");
  if (f == NULL){
    fprintf(stderr, "Erreur d'ouverture du fichier %s\n", file);
    return 0;
  }

  int number_body;
  double width_region;
  double px, py, vx, vy, mass;


  fscanf(f,"%d",&number_body);
  fscanf(f,"%lf",&width_region);

  galaxy* new_galaxy = create_galaxy(number_body, width_region);

  printf("Number body %d\n", new_galaxy->number_body);
  printf("Number region %lf\n", new_galaxy->width_region);


  for (int i = 0; i < number_body; i++) {
    fscanf(f,"%lf %lf %lf %lf %lf", &px, &py, &vx, &vy, &mass);
    new_galaxy->body[i] = create_body(px, py, vx, vy, mass);

  }
  fclose(f);

  return new_galaxy;
}
