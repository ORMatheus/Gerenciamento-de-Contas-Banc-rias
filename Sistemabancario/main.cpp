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