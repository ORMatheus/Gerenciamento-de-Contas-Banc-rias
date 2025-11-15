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

    //teste 2
    std::cout << "\n[AÇÃO] Depositando R$ 250.50 na conta de Fernando...\n";
    conta1.depositar(250.50);
    exibirDetalhes(conta1); // Saldo esperado: R$ 750.50

    system("Pause");
    return 0;
}