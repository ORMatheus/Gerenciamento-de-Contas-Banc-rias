#include "Conta.h"
#include <iostream>
#include <iomanip>

Conta::Conta(int numero, std::string nome, double depositoInicial){
    numeroConta=numero;
    nomeTitular=nome;

    //validação do deposito
    if(depositoInicial >=0){
        saldo=depositoInicial;
    }else{
        saldo =0.0;
        std::cout << "Deposito Negativo ignorado.\nSaldo inicial da conta esta em 0."
    }

    
}