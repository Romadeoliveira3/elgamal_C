#include "bignumber.h"
#include "aleatoriedade.h"
#include <iostream>
#include <ctime>


int main() {
    std::cout << "Testando a classe bignumber com validacoes:\n" << std::endl;
    // Inicializar o gerador dé números aleatórios baseado no tempo
    gmp_randstate_t estado;
    unsigned long seed = static_cast<unsigned long>(std::time(nullptr));
    inicializar_aleatoriedade(estado, seed); // Chama a função para inicializar

    // Criar dois números grandes com exatamente 1024 bits
    bignumber numero1(2048, estado);
    bignumber numero2(2048, estado);
    bignumber modulo(2048, estado);

    // Exibir os números
    numero1.exibir("Número 1");
    numero2.exibir("Número 2");
    modulo.exibir("Módulo (2048 bits)");

    // Soma
    bignumber soma = numero1.adicionar(numero2);
    soma.exibir("Soma");
    std::cout << "Tamanho da soma: " << soma.tamanho() << " bits\n";

    // Multiplicação
    bignumber produto = numero1.multiplicar(numero2);
    produto.exibir("Produto");
    std::cout << "Tamanho do produto: " << produto.tamanho() << " bits\n";

    // Validação da multiplicação
    if (bignumber::validar_multiplicacao(numero1, numero2)) {
        std::cout << "A multiplicação é válida como bignumber (≤ 2048 bits)." << std::endl;
    }
    else {
        std::cout << "A multiplicação excede o limite de 2048 bits." << std::endl;
    }

    // Validação da adição
    try {
        if (bignumber::validar_adicao(numero1, numero2)) {
            std::cout << "A adição é válida com tamanho N ou N+1." << std::endl;
        }
        else {
            std::cout << "A adição não é válida." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Erro na validação da adição: " << e.what() << std::endl;
    }

    std::cout << "Testando Operações Modulares:\n" << std::endl;

    
    // Soma Modular
    bignumber add_res = numero1.addmod(numero2, modulo);
    add_res.exibir("Soma Modular (A + B)% Modulo");
    std::cout << "Tamanho da Soma Modular: " << add_res.tamanho() << "bits\n";

    // Multiplicação Modular
    bignumber mult_res = numero1.mulmod(numero2, modulo);
    mult_res.exibir("Multiplicação modular (a*b)mod n");
    std::cout << "Tamanho da Multiplicação Modular: " << mult_res.tamanho() << "bits\n";

    // Exponenciação Modular
    bignumber exp_res = numero1.expmod(numero2, modulo);
    exp_res.exibir("Exponenciação modular (a^b)mod n: ");
    std::cout << "Tamanho da Exponenciação Modular: " << exp_res.tamanho() << "bits\n";

    // Inverso modular
    bignumber inv_res = numero1.invmod(numero2);
    inv_res.exibir("Inveso Modular a*x=1(mod n)");
    std::cout << "Tamanho do Inverso Modular: " << inv_res.tamanho() << "bits\n";

    // Liberar o estado do gerador
    gmp_randclear(estado);
    

    return 0;
}
