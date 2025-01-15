#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <gmp.h>
#include <string>
#include <iostream>

class bignumber {
private:
    mpz_t value; // Número armazenado como um inteiro grande do GMP

public:
    // Construtores
    bignumber(const std::string& val = "0"); // Construtor a partir de string
    bignumber(size_t bits, gmp_randstate_t& estado);                  // Construtor para gerar um número com N bits

    // Destrutor
    ~bignumber();


    // Métodos

    // Retorna o tamanho do número em bits
    size_t tamanho() const; 

    // Soma
    bignumber adicionar(const bignumber& outro) const;

    // Multiplicação
    bignumber multiplicar(const bignumber& outro) const;

    // Divisão
    std::pair<bignumber, bignumber> dividir(const bignumber& divisor) const;

    // Módulo
    bignumber modulo(const bignumber& mod) const;

    // Exibe o número
    void exibir(const std::string& mensagem) const;

    // Getter para o valor GMP (se necessário para cálculos internos)
    const mpz_t& get_value() const;

    // Operadores úteis
    bignumber& operator=(const bignumber& outro);

    // Validações
    static bool validar_multiplicacao(const bignumber& a, const bignumber& b);
    static bool validar_adicao(const bignumber& a, const bignumber& b);

    // Operações Modular
    
    // Adição modular addmod(a,b,n): (a + b) mod n
    bignumber addmod(const bignumber& b, const bignumber& n) const;

    // Multiplicação modular mulmod(a,b,n): (a*b) mod n
    bignumber mulmod(const bignumber& b, const bignumber& n) const;

    //Exponenciação modular expmod(a,b,n): (a^b)mod n
    bignumber expmod(const bignumber& b, const bignumber& n) const;

    // Inverso Modular O numero x tal que a*x≡1(mod n) invmod(a, n)
    bignumber invmod(const bignumber& n) const;

};

#endif // BIGNUMBER_H
