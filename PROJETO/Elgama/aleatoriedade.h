#ifndef ALEATORIEDADE_H
#define ALEATORIEDADE_H

#include <gmp.h>

// Declara a função da inicialização
void inicializar_aleatoriedade(gmp_randstate_t& estado, unsigned long seed);

#endif //ALEATORIEDADE_H