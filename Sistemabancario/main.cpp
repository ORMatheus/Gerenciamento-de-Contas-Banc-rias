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
        std::cout << "Erro: número da conta invalida." <<std::endl;
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
    Conta novaConta(numero, nome, depositoInicial);
    // Adiciona o objeto ao nosso vetor
    contas.push_back(novaConta);

    std::cout << "\nConta para '" << nome << "' (N. " << numero
              << ") criada com sucesso!" << std::endl;
}

void fazerDeposito(){
    int numero;
    double valor;
    std::cout <<"\n--- Fazer Depósito ---"<< std::endl;
    std::cout << "Digite o número da conta:";
    std::cin >> numero;
    Conta*conta=encontrarConta(numero);
    if(conta==nullptr){
        std::cout << "Erro:Conta não encontrada." <<std::endl;
    }else {
        std::cout << "Valor a ser depositado:"<< valor;
        if(std::cin.fail()){
            std::cout << "Erro:Valor digitado invalido.";
            std::cin.clear();
            limparBufferEntrada();
        }else{
            conta->depositar(valor);
        }
    }
}

void fazerSaque(){
    int numero;
    double valor;
    std::cout << "\nFazer Saque---";
    std::cout << "Digite o número da sua conta:";
    std::cin >>numero;
    Conta* conta=encontrarConta(numero);
    if(conta==nullptr){
        std::cout<< "Erro:conta não encontrada." << std::endl;
    }else {
        std::cout << "Digite o valor a sacar :";
        std::cin >> valor;
        if(std::cin.fail()){
            std::cout << "Erro:Valor digitado invalido.";
            std::cin.clear();
            limparBufferEntrada();
        }else{
            conta->sacar(valor);
        }
    }
}

void consultarSaldo(){
   int numero;
    std::cout << "\n--- Consultar Saldo ---" << std::endl;
    std::cout << "Digite o número da conta: ";
    std::cin >> numero;

    Conta* conta=encontrarConta(numero);
    if(conta==nullptr){
        std::cout <<"Erro:Conta não encontrada." << std::endl;
    }else{
        std::cout << "\n--- Detalhes da conta ---"<<std::endl;
        std::cout <<"Titular" <<conta->getNomeTitular()<<std::endl;
        std::cout << "Conta N." << conta->getNumeroConta() << std::endl;
        std::cout << "Saldo atual da conta:" << "R$" << std::fixed <<std::setprecision(2) << conta->getSaldo()<<std::endl;
        std::cout << "-------------------------" << std::endl;
    }
}

void listarTodasAsContas(){
    std::cout << "\n--- Lista com todas as contas ---" << std::endl;
    if(contas.empty()){
        std::cout << "Nenhuma conta cadastrada no sistema." << std::endl;
        return ;
    }

    for (const Conta& conta : contas) {
        std::cout << "-------------------------" << std::endl;
        std::cout << "Titular: \t" << conta.getNomeTitular() << std::endl;
        std::cout << "Conta N.: \t" << conta.getNumeroConta() << std::endl;
        std::cout << "Saldo: \t\t" << "R$ " << std::fixed
        << std::setprecision(2) << conta.getSaldo() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}


int main(){
    int opcao;

    while(true){
        exibirMenu();
        std::cin >>opcao;

        //se a entrada não for um número
        if(std::cin.fail()){
            std::cout << "Opção invalida. Por Favor , digite um novo numero:" << std::endl;
            std::cin.clear();// limpa o estado atual do cin 
            limparBufferEntrada(); //Limpa o buffer
            continue;
        }

     switch (opcao) {
            case 1:
                criarConta();
                break;
            case 2:
                fazerDeposito();
                break;
            case 3:
                fazerSaque();
                break;
            case 4:
                consultarSaldo();
                break;
            case 5:
                listarTodasAsContas();
                break;
            case 0:
                std::cout << "Saindo do sistema... Obrigado!" << std::endl;
                return 0; // Termina o programa
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    }

    return 0;
}