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
        std::cout << "Deposito Negativo ignorado.\nSaldo inicial da conta esta em 0.";
    }


}

void Conta::depositar(double valor){
    if(valor > 0){
        saldo=saldo+valor;
        std::cout << "Deposito em R$ "<< std::fixed << std::setprecision(2) << valor
        << " realizado com sucesso." << std::endl;
    }else{
        std::cout << "ERRO: Valor de depósito invalido, deposite um valor posito." << std::endl;
    }
}

bool Conta::sacar(double valor){
    if(valor <=0){
        std::cout <<"ERRO:Para realizar um saque o valor precisa ser positivo."<<std::endl;
        return false;
    }
    if(valor > saldo){
        std::cout << "ERRO: Saldo insuficiente ." << std::endl;
        std::cout << "Seu saldo atual : R$ "<< std::fixed << std::setprecision(2) << getSaldo() << std::endl;
        return false;
    }
    saldo=saldo-valor;
    std::cout << "Saque no Valor de R$" <<std::fixed << std::setprecision(2) << valor 
    <<"Realizado com sucesso." << std::endl;
    std::cout <<"Seu saldo Atual esta no valor de R$"
    << std::fixed << std::setprecision(2) << getSaldo() << std::endl;
    return true;
}


double Conta::getSaldo()const {
    return saldo;
}