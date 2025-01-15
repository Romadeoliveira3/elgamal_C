# Implementação Eficiente do Criptossistema ElGamal em C/C++

## Descrição do Projeto
Este projeto visa o desenvolvimento de uma implementação eficiente do criptossistema ElGamal utilizando a linguagem C/C++. O trabalho aborda operações com números grandes, geração de primos seguros, raízes primitivas e validação de segurança e desempenho do sistema para aplicações práticas.

## Área de Concentração
- **Matemática Discreta e Criptografia**
- **Linha de Pesquisa:** Criptografia e Algoritmos de Segurança

## Autor
- **Romário J. O. Veloso** (Bacharelando em Engenharia Eletrônica)

## Resumo Técnico
O criptossistema ElGamal é baseado no problema do logaritmo discreto, proporcionando alta segurança na transmissão de dados. Este projeto aborda desafios como:
- Processamento de números grandes.
- Geração e validação de primos seguros e raízes primitivas.
- Desenvolvimento de funções para geração de chaves, criptografia e descriptografia.

## Palavras-chave
ElGamal, Criptografia, Logaritmo Discreto, C++, Números Grandes

## Objetivos

### Geral
Implementar o criptossistema ElGamal com foco em eficiência computacional e segurança.

### Específicos
1. Desenvolver uma biblioteca para operações com números grandes.
2. Validar primos seguros e raízes primitivas.
3. Criar funções para geração de chaves, criptografia e descriptografia.
4. Validar a implementação com testes funcionais e de desempenho.

## Metodologia
1. **Configuração do Ambiente**:
   - Instalação de bibliotecas para operações com números grandes (ex.: GMP).
   - Configuração de ferramentas de desenvolvimento e teste.

2. **Desenvolvimento de Biblioteca de Números Grandes**:
   - Implementação de operações básicas (adição, subtração, multiplicação).
   - Implementação de operações modulares (exponenciação, inverso modular).

3. **Algoritmos de Primalidade e Raízes Primitivas**:
   - Testes de primalidade (Miller-Rabin).
   - Validação de primos seguros e suas raízes primitivas.

4. **Implementação do Criptossistema ElGamal**:
   - Gerar chaves públicas e privadas.
   - Criar funções de criptografia e descriptografia.

5. **Validação e Testes**:
   - Avaliar desempenho com diferentes tamanhos de chaves.
   - Verificar segurança e correção funcional.

## Cronograma de Atividades
| Atividade                                     | Semana 1 | Semana 2 | Semana 3 | Semana 4 |
|-----------------------------------------------|----------|----------|----------|----------|
| Revisão bibliográfica e configuração do ambiente | X        |          |          |          |
| Desenvolvimento da biblioteca de números grandes | X        | X        |          |          |
| Geração de primos e raízes primitivas          |          | X        |          |          |
| Implementação do sistema ElGamal              |          |          | X        |          |
| Validação e testes                             |          |          |          | X        |
| Escrita e revisão do relatório final          |          |          |          | X        |

## Estrutura Modular do Projeto

O projeto foi desenvolvido com uma estrutura modular para garantir organização, facilidade de manutenção e extensibilidade. Abaixo, descrevemos os principais componentes:

### Arquivos de Cabeçalho (`Header Files`):
- **`aleatoriedade.h`**: Contém funções para geração de números aleatórios, primos seguros e valores relacionados.
- **`bignumber.h`**: Define a estrutura e as operações para números grandes, incluindo operações aritméticas e modulares.

### Arquivos de Implementação (`Source Files`):
- **`aleatoriedade.cpp`**: Implementa as funções descritas no arquivo `aleatoriedade.h`.
- **`bignumber.cpp`**: Implementa as funções descritas no arquivo `bignumber.h`.
- **`main.cpp`**: Arquivo principal que integra as funcionalidades do sistema ElGamal, realiza testes e validações.

### Como Rodar o Projeto
1. Certifique-se de ter os seguintes requisitos instalados:
   - **[GMP (GNU Multiple Precision Library)](https://gmplib.org/)**: Necessário para realizar operações com números grandes.
   - **[Boost](https://www.boost.org/)**: Biblioteca auxiliar para operações avançadas.
   - **[vcpkg](https://github.com/microsoft/vcpkg)**: Gerenciador de pacotes para configuração de dependências.

2. Compile o projeto utilizando o arquivo principal `main.cpp`. Esse arquivo executa as funções do sistema ElGamal e realiza testes de validação.

#### Ambiente Integrado (Ex.: Visual Studio)
- Configure corretamente as dependências no gerenciador de pacotes.
- Compile e execute o projeto diretamente na IDE.

#### Linha de Comando
- Use o comando abaixo para compilar o projeto, incluindo as bibliotecas necessárias:
  ```bash
  g++ -o elgamal main.cpp bignumber.cpp aleatoriedade.cpp -lgmp -lboost_system





## Referências
1. ElGamal, T. *A Public Key Cryptosystem and a Signature Scheme Based on Discrete Logarithms*. Advances in Cryptology, CRYPTO 1984.
2. Hussein, H. I.; Abduallah, W. M. *An Efficient ElGamal Cryptosystem Scheme*. International Journal of Computers and Applications, 2019.
3. Burton, D. *Elementary Number Theory*. 6ª ed., McGraw-Hill, 2007.

## Observações
- **Requisitos:** A implementação requer bibliotecas para operações de alta precisão, como GMP.
- **Aviso:** Validar números primos e raízes primitivas utilizando algoritmos recomendados, como Miller-Rabin.
