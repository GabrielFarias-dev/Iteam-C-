#include <iostream>
#include <string>
using namespace std;

class aluno {
private:
    std::string nome;
public:
    aluno(std::string nome) {
        this->nome = nome;
    }

    void nota(int nota) {
        std::cout << this->nome << " tem nota " << nota << "." << std::endl;
    }
    
};
int main() {

aluno c1("João");
aluno c2("Maria");

c1.nota(8);
c2.nota(9);
return 0;
}