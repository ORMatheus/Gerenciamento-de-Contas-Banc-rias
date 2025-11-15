#include <iostream>
#include <iomanip>    // Para std::fixed, std::setprecision
#include <string>
#include <vector>     // Para armazenar a lista de contas
#include <limits>     // Para limpar o buffer de entrada (std::numeric_limits)

#include "Conta.h"    // Inclui nossa classe

//usar o std::vector para armazenar os dados
std::vector<Conta> contas;

void exibirMenu() {
    std::cout << "\n--- Sistema de Gerenciamento Bancário ---" << std::endl;
    std::cout << "1. Criar nova conta" << std::endl;
    std::cout << "2. Fazer depósito" << std::endl;
    std::cout << "3. Fazer saque" << std::endl;
    std::cout << "4. Consultar saldo/detalhes" << std::endl;
    std::cout << "5. Listar todas as contas" << std::endl;
    std::cout << "0. Sair do sistema" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Escolha uma opção: ";
}

void limparBufferEntrada(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

Conta*encontrarConta(int numeroConta){
    for(int i =0 ; i<contas.size(); i++){
        if(contas[i].getNumeroConta()== numeroConta){
            return &contas[i];
        }
    }
    return nullptr;//caso não encontre
}


int main(){
    std::cout << "=== Bem-vindo ao Sistema Bancário (Teste de Classe) ===" << std::endl;

    return 0;
}