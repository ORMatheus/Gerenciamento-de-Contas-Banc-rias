#ifndef CONTA_H
#define CONTA_H

#include <string>
class Conta{    
    private:
    int numeroConta;
    std::string NomeTitular;
    double saldo;

    public:
    Conta(int numero, std::string nome, double depositoinicial );
    void depositar(double valor);
    bool sacar(double valor);

    //metodo getters
    double getSaldo()const;
    std::string getNomeTitular() const;
    int getNumeroConta() const ;
};

#endif