#include <stdio.h>

#include "in_out.h"

int galaxy_import(const char* file /*,add array*/){
  FILE* f;

  f = fopen(file, "r");
  if (f == NULL){
    fprintf(stderr, "Erreur d'ouverture du fichier %s\n", file);
    return 0;
  }

  /*

  while(file != EOF){
    on remplit notre tableau des données du fichier
  }

  */
  return 1;
}
