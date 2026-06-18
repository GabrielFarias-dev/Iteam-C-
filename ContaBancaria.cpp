#include <iostream>
#include <string>
using namespace std;

class ContaBancaria {
private: // Atributos PRIVADOS
    string titular;
    double saldo;

public: // Métodos PÚBLICOS
    // Construtor
    ContaBancaria(string t, double s) : titular(t), saldo(s) {}

    // Getters (leitura controlada)
    string getTitular() const { return titular; }
    double getSaldo() const { return saldo; }

    // Setters (escrita controlada com validação)
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Depósito de R$" << valor << " realizado." << endl;
        } else {
            cout << "Valor inválido para depósito!" << endl;
        }
    }
    
    bool sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << "Saque de R$" << valor << " realizado." << endl;
            return true;
        } else {
            cout << "Saldo insuficiente ou valor inválido!" << endl;
            return false;
        }
    }
};

int main() {
    ContaBancaria conta("João Silva", 1000.0);
    cout << "Titular: " << conta.getTitular() << endl;
    cout << "Saldo : R$" << conta.getSaldo() << endl;

    conta.depositar(500.0);
    conta.sacar(200.0);
    conta.sacar(2000.0); // Tentativa de saque maior que o saldo

    cout << "Saldo final: R$" << conta.getSaldo() << endl;
    return 0;
}