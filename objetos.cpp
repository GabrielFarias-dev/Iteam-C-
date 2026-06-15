#include <iostream>
#include <string>
using namespace std;

class Pessoa {
private:
    std::string nome;
public:
    Pessoa(std::string nome) {
        this->nome = nome;
    }

    void idade(int idade) {
        std::cout << this->nome << " tem " << idade << " anos." << std::endl;

    } 
    
};
int main() {

Pessoa c1("João");
Pessoa c2("Maria");

c1.idade(25);
c2.idade(30);
return 0;
}