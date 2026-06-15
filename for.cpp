#include <iostream>
#include <string>

using namespace std;

int main() {
    string usuario_correto = "admin";
    string senha_correta = "1234";

    string usuario, senha;

    int tentativas = 0;
    const int MAX_TENTATIVAS = 3;

    cout << "Sistema de Login";

    while (tentativas < MAX_TENTATIVAS) {
        cout << "Digite o usuario: ";
        cin >> usuario;

        cout << "Digite a senha: ";
        cin >> senha;

        if (usuario == usuario_correto && senha == senha_correta) {
            cout << "Login realizado com sucesso!";
            break;
        } else {
            tentativas++;
            cout << " Usuario ou senha incorretos!";

            if (tentativas < MAX_TENTATIVAS) {
                cout << "Tentativas restantes: " 
                     << (MAX_TENTATIVAS - tentativas) << endl;
            }
        }
    }
    if (tentativas == MAX_TENTATIVAS) {
        cout << "Limite de tentativas atingido! Acesso bloqueado.\n";
    }

    return 0;
}
