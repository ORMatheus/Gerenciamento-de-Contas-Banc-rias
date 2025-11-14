# 🏦 Sistema de Gerenciamento de Contas Bancárias em C++

Este é um projeto de console simples, escrito em C++, que simula as operações básicas de um sistema de gerenciamento de contas bancárias. O objetivo principal é aplicar e demonstrar conceitos fundamentais de Programação Orientada a Objetos (POO) e manipulação de dados em memória.

Este projeto foi criado como parte do meu portfólio de desenvolvimento.

## ✨ Funcionalidades

O sistema permite ao usuário interagir através de um menu de console para realizar as seguintes operações:

* **Criar Nova Conta:** Permite ao usuário criar uma conta com um número de identificação, nome do titular e um depósito inicial.
* **Depositar:** Adiciona um valor ao saldo de uma conta existente.
* **Sacar:** Retira um valor do saldo de uma conta, com verificação para não permitir saques que deixem o saldo negativo.
* **Verificar Saldo:** Exibe o nome do titular, número da conta e o saldo atual.
* **(Opcional) Listar Contas:** Mostra um resumo de todas as contas cadastradas no sistema.

## 🛠️ Tecnologias Utilizadas

* **C++:** Linguagem principal do projeto.
* **Programação Orientada a Objetos (POO):** O projeto é estruturado em torno de classes (como `Conta` e talvez `Cliente`) para gerenciar os dados de forma encapsulada.
* **STL (Standard Template Library):** Uso de `std::cout`, `std::cin` para interação com o usuário, e `std::vector` para armazenar as contas em memória.

## 🚀 Como Compilar e Executar

Você precisará de um compilador C++ (como G++, Clang ou o compilador do Visual Studio) instalado em sua máquina.

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/SEU-USUARIO/SEU-REPOSITORIO.git](https://github.com/SEU-USUARIO/SEU-REPOSITORIO.git)
    cd SEU-REPOSITORIO
    ```

2.  **Compile o projeto:**
    O método de compilação pode variar um pouco dependendo de como você estruturou seus arquivos (.h e .cpp).

    *Se você usou arquivos separados (ex: `main.cpp`, `Conta.cpp`, `Conta.h`):*
    ```bash
    g++ main.cpp Conta.cpp -o sistema_bancario -std=c++11
    ```

    *Se todo o seu código estiver em um único arquivo `main.cpp`:*
    ```bash
    g++ main.cpp -o sistema_bancario -std=c++11
    ```

3.  **Execute o programa:**

    *No Linux/macOS:*
    ```bash
    ./sistema_bancario
    ```

    *No Windows:*
    ```bash
    sistema_bancario.exe
    ```

## 📂 Estrutura do Projeto (Sugestão)

Uma sugestão de estrutura de arquivos para manter o projeto organizado: