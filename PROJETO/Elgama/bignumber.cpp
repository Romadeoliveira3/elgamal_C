#include "bignumber.h"

// Construtor a partir de string
bignumber::bignumber(const std::string& val) {
    mpz_init_set_str(value, val.c_str(), 10); // Inicializa com o valor fornecido em base 10
}


// Construtor para gerar um número aleatório com até N bits
bignumber::bignumber(size_t bits, gmp_randstate_t& estado) {
    if (bits == 0) {
        mpz_init_set_ui(value, 0); // Número 0
    }
    else {
        mpz_t max_value;          // Para armazenar 2^bits - 1
        mpz_init(value);          // Inicializa o número aleatório
        mpz_init(max_value);      // Inicializa o limite superior

        // Calcula 2^bits - 1
        mpz_ui_pow_ui(max_value, 2, bits); // max_value = 2^bits
        mpz_sub_ui(max_value, max_value, 1); // max_value = 2^bits - 1

        // Gera um número aleatório no intervalo [0, 2^bits - 1]
        mpz_urandomm(value, estado, max_value); // Gera value tal que 0 <= value <= max_value

        // Limpa a memória do limite superior
        mpz_clear(max_value);
    }
}


// Destrutor
bignumber::~bignumber() {
    mpz_clear(value); // Libera a memória alocada pelo GMP
}

// Retorna o tamanho do número em bits
size_t bignumber::tamanho() const {
    return mpz_sizeinbase(value, 2); // Retorna o tamanho em bits
}

// Adiciona dois bignumbers
bignumber bignumber::adicionar(const bignumber& outro) const {
    bignumber resultado;
    mpz_add(resultado.value, value, outro.value); // Soma dos valores
    return resultado;
}

// Multiplica dois bignumbers
bignumber bignumber::multiplicar(const bignumber& outro) const {
    bignumber resultado;
    mpz_mul(resultado.value, value, outro.value); // Multiplicação dos valores
    return resultado;
}

// Divide o bignumber por outro e retorna quociente e resto
std::pair<bignumber, bignumber> bignumber::dividir(const bignumber& divisor) const {
    bignumber quociente, resto;
    mpz_tdiv_qr(quociente.value, resto.value, value, divisor.value); // Divide e retorna quociente e resto
    return { quociente, resto };
}

// Reduz o bignumber módulo outro
bignumber bignumber::modulo(const bignumber& mod) const {
    bignumber resultado;
    mpz_mod(resultado.value, value, mod.value); // Calcula o módulo
    return resultado;
}

// Exibe o número no console
void bignumber::exibir(const std::string& mensagem) const {
    std::cout << mensagem << ": ";
    mpz_out_str(stdout, 10, value); // Exibe o valor em base 10
    std::cout << std::endl;
}

// Getter para o valor GMP
const mpz_t& bignumber::get_value() const {
    return value;
}

// Sobrecarga do operador de atribuição
bignumber& bignumber::operator=(const bignumber& outro) {
    if (this != &outro) {
        mpz_set(value, outro.value); // Copia o valor
    }
    return *this;
}

bool bignumber::validar_multiplicacao(const bignumber& a, const bignumber& b) {
    size_t tamanho_total = a.tamanho() + b.tamanho();
    return tamanho_total <= 2048;
}

bool bignumber::validar_adicao(const bignumber& a, const bignumber& b) {
    if (a.tamanho() != b.tamanho()) {
        throw std::invalid_argument("Os números devem ter o mesmo tamanho para validação.");
    }

    bignumber soma = a.adicionar(b);
    size_t tamanho_soma = soma.tamanho();
    return (tamanho_soma == a.tamanho() || tamanho_soma == a.tamanho() + 1);

}

bignumber bignumber::addmod(const bignumber& b, const bignumber& n) const {
    bignumber resultado;
    mpz_add(resultado.value, value, b.value); // Soma: a + b
    mpz_mod(resultado.value, resultado.value, n.value); // Módulo: (a + b) mod n
    return resultado;
}

bignumber bignumber::mulmod(const bignumber& b, const bignumber& n) const {
    bignumber resultado;
    mpz_mul(resultado.value, value, b.value); // Multiplicação: a * b
    mpz_mod(resultado.value, resultado.value, n.value); // Módulo: (a*b) mod n
    return resultado;
}

bignumber bignumber::expmod(const bignumber& b, const bignumber& n) const {
    bignumber resultado;
    mpz_powm(resultado.value, value, b.value, n.value); // Exponenciação modular
    return resultado;
}

bignumber bignumber::invmod(const bignumber& n) const {
    bignumber resultado;
    if (mpz_invert(resultado.value, value, n.value) == 0) {
        throw std::invalid_argument("Inverso modular não existe."); // Lança exceção se não houver inverso
    }
    return resultado;
}
