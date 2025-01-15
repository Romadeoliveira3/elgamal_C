#include "aleatoriedade.h"

void inicializar_aleatoriedade(gmp_randstate_t& estado, unsigned long seed) {
	gmp_randinit_default(estado); // Inicializa o gerador
	gmp_randseed_ui(estado, seed); // Defnine a seed do gerador
}