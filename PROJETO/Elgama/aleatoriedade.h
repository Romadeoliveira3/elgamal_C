#ifndef ALEATORIEDADE_H
#define ALEATORIEDADE_H

#include <gmp.h>

// Declara a fun��o da inicializa��o
void inicializar_aleatoriedade(gmp_randstate_t& estado, unsigned long seed);

#endif //ALEATORIEDADE_H