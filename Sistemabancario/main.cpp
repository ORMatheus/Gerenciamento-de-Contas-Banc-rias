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
//criar conta
void criarConta(){
    int numero;
    std::string nome;
    double depositoInicial;

    std::cout << "\n--- Criar Nova Conta ---"<< std::endl;
    std::cout << "Digite o numero desejado para sua Conta:";
    std::cin >> numero;

    //logica de validação do numero fornecido 
    if(std::cin.fail()){
        std::cout << "Erro: número da conta invalida." << std::cout << endl;
        std::cin.clear();//limpar o buffer do cin
        limparBufferEntrada();
        return;
    }
    //validação caso a conta ja exista
    if(encontrarConta(numero) !=nullptr){ //caso a conta ja exista ele vai encontrar uma posição no vector de contas 
        std::cout << "Erro:já Exsite uma conta com esse número ." << std:: endl;
        limparBufferEntrada();
        return;
    }

    std::cout << "Digite no nome do titular:";
    limparBufferEntrada() ; //limpar o enter deixado pelo cin anterior do >>numero
    std::getline(std::cin,nome);

    std::cout << "Digite o depósito inicial (0 se não houver)";
    std::cin >> depositoInicial;

    if(std::cin.fail()){
        std::cout << "Erro:Valor de déposito invalido ." <<std::endl;
        std::cin.clear();
        limparBufferEntrada();
        return;
    }

    //criação do objeto Conta
    Conta novaConta(numero,nome,depositoInicial){
        contas.push_back(novaConta);    //adiciona o objeto nova conta ao final do vetor
        std::cout << "\nConta nova para "<<nome << " '(N." << numero << ") Criada com Sucesso !!"std::endl;
        
    }
}


int main(){
    std::cout << "=== Bem-vindo ao Sistema Bancário (Teste de Classe) ===" << std::endl;

    return 0;
}