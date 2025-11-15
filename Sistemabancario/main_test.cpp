#include "Conta.h"
#include <iostream>
#include <iomanip>
using namespace std;
//função auxiliar 

void exibirDetalhes(const Conta& conta){
    cout << "----------------------------------------" << std::endl;
    cout << "Titular: \t " << conta.getNomeTitular() << endl;
    cout << "Conta N.:\t" << conta.getNumeroConta()<< endl;
    cout << "Saldo atual da sua conta:\t" << "R$ " << fixed<< setprecision(2) << conta.getSaldo() << endl;
    cout << "----------------------------------------" << std::endl;    
}

int main(){
    cout << "Seja Bem Vindo Ao Sistema Bancário ===" << endl;

    //teste 1 criação de conta.
    cout << "\n Criando Conta para 'Fernando ' (N.1001) Com deposito Inicial de R$ 500.00\n";
    Conta conta1(1001,"Fernando", 500.00);
    exibirDetalhes(conta1);

 // --- Teste 2: Depósito Válido ---
    std::cout << "\n Depositando R$ 250.50 na conta de Fernando...\n";
    conta1.depositar(250.50);
    exibirDetalhes(conta1); // Saldo esperado: R$ 750.50

    // --- Teste 3: Saque Válido ---
    std::cout << "\n Sacando R$ 150.00 da conta de Fernando..\n";
    conta1.sacar(150.00);
    exibirDetalhes(conta1); // Saldo esperado: R$ 600.50

    // --- Teste 4: Saque Inválido (Saldo Insuficiente) ---
    std::cout << "\n Tentando sacar R$ 1000.00 (saldo insuficiente)...\n";
    conta1.sacar(1000.00); // Deve falhar e imprimir uma mensagem de erro
    exibirDetalhes(conta1); // Saldo esperado: R$ 600.50 (não deve mudar)

    // --- Teste 5: Depósito Inválido (Valor Negativo) ---
    std::cout << "\n Tentando depositar R$ -50.00 (valor negativo)...\n";
    conta1.depositar(-50.00); // Deve falhar e imprimir uma mensagem de erro
    exibirDetalhes(conta1); // Saldo esperado: R$ 600.50 (não deve mudar)

    // --- Teste 6: Saque Inválido (Valor Negativo) ---
    std::cout << "\n Tentando sacar R$ -10.00 (valor negativo)...\n";
    conta1.sacar(-10.00); // Deve falhar e imprimir uma mensagem de erro
    exibirDetalhes(conta1); // Saldo esperado: R$ 600.50 (não deve mudar)

    // --- Teste 7: Criação da Conta 2 (com depósito inicial zero) ---
    std::cout << "\n Criando conta para 'Beto' (N. 1002) com depósito inicial de R$ 0.00...\n";
    Conta conta2(1002, "Beto", 0.00);
    exibirDetalhes(conta2);

    // --- Teste 8: Tentativa de Saque em Conta Zerada ---
    std::cout << "\n Tentando sacar R$ 50.00 da conta de Beto (zerada)...\n";
    conta2.sacar(50.00); // Deve falhar (saldo insuficiente)
    exibirDetalhes(conta2); // Saldo esperado: R$ 0.00

    std::cout << "\n=== Testes concluídos! ===" << std::endl;
    system("Pause");
    return 0;
}