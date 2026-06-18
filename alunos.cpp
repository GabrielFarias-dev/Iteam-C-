#include <iostream>
#include <string>
using namespace std;

class Aluno {
private:
    string nome;
    double nota1;
    double nota2;

public:
    Aluno(const string& nome, double nota1, double nota2)
        : nome(nome), nota1(nota1), nota2(nota2) {}

    double media() const {
        return (nota1 + nota2) / 2.0;
    }

    void mostrarSituacao() const {
        double m = media();
        cout << nome << " - nota1: " << nota1 << ", nota2: " << nota2
             << ", media: " << m;
        if (m >= 7.0) {
            cout << " -> Aprovado"; 
        } else {
            cout << " -> Reprovado";
        }
        cout << endl;
    }
};

int main() {
    Aluno c1("João", 8.0, 7.0);
    Aluno c2("Maria", 9.0, 4.0);

    c1.mostrarSituacao();
    c2.mostrarSituacao();

    return 0;
}