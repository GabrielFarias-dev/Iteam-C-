#include <iostream>
#include <memory>
#include <string>

using namespace std;

// ============================================================
// Classe base: Personagem
// ============================================================
class Personagem {
public:
    string nome;
    int nivel_poder;
    string tipo;  // ex: "Animal", "Mago"

    Personagem(string nome, int nivel_poder, string tipo)
        : nome(nome), nivel_poder(nivel_poder), tipo(tipo) {}

    // virtual para permitir polimorfismo (Chefe sobrescreve)
    virtual void exibir_info() const {
        cout << "Nome: " << nome
             << " | Poder: " << nivel_poder
             << " | Tipo: " << tipo;
    }

    // destrutor virtual: obrigatório quando há herança + ponteiros
    virtual ~Personagem() = default;
};

// ============================================================
// Classe derivada: ChefeDaFloresta (herda de Personagem)
// ============================================================
class ChefeDaFloresta : public Personagem {
public:
    string reino;  // atributo extra dos Chefes

    ChefeDaFloresta(string nome, int nivel_poder, string tipo, string reino)
        : Personagem(nome, nivel_poder, tipo), reino(reino) {}

    // sobrescreve exibir_info para incluir o reino
    void exibir_info() const override {
        Personagem::exibir_info();
        cout << " | Reino: " << reino << " [CHEFE DA FLORESTA]";
    }
};

// ============================================================
// Nó da árvore (guarda um Personagem via ponteiro inteligente,
// permitindo armazenar tanto Personagem quanto ChefeDaFloresta)
// ============================================================
struct No {
    unique_ptr<Personagem> personagem;
    unique_ptr<No> esquerda;
    unique_ptr<No> direita;

    No(unique_ptr<Personagem> p) : personagem(move(p)) {}
};

// ============================================================
// Árvore Binária de Busca da Floresta Encantada
// Ordenada pelo nível de poder:
//   menor poder -> esquerda
//   maior poder -> direita
// ============================================================
class ArvoreFloresta {
private:
    unique_ptr<No> raiz;

    // Insere recursivamente respeitando a propriedade da BST
    unique_ptr<No>& inserir_rec(unique_ptr<No>& atual, unique_ptr<Personagem> p) {
        if (!atual) {
            atual = make_unique<No>(move(p));
            return atual;
        }

        if (p->nivel_poder < atual->personagem->nivel_poder) {
            inserir_rec(atual->esquerda, move(p));
        } else {
            inserir_rec(atual->direita, move(p));
        }
        return atual;
    }

    // Percurso em ordem: esquerda -> nó -> direita
    // (do menos poderoso para o mais poderoso)
    void em_ordem_rec(const unique_ptr<No>& atual) const {
        if (!atual) return;

        em_ordem_rec(atual->esquerda);
        atual->personagem->exibir_info();
        cout << endl;
        em_ordem_rec(atual->direita);
    }

public:
    // Adiciona um Personagem comum
    void adicionar_personagem(string nome, int nivel_poder, string tipo) {
        auto p = make_unique<Personagem>(nome, nivel_poder, tipo);
        inserir_rec(raiz, move(p));
    }

    // Adiciona um Chefe da Floresta
    void adicionar_chefe(string nome, int nivel_poder, string tipo, string reino) {
        auto p = make_unique<ChefeDaFloresta>(nome, nivel_poder, tipo, reino);
        inserir_rec(raiz, move(p));
    }

    // Percorre do menos poderoso ao mais poderoso, exibindo tudo
    void percorrer_em_ordem() const {
        em_ordem_rec(raiz);
    }
};

// ============================================================
// Programa principal
// ============================================================
int main() {
    ArvoreFloresta floresta;

    // Pelo menos 6 personagens, sendo pelo menos 2 Chefes
    floresta.adicionar_personagem("Lupi", 30, "Animal");
    floresta.adicionar_chefe("Mago Merlin", 85, "Mago", "Reino das Brumas");
    floresta.adicionar_chefe("Chefe Dragao", 95, "Animal", "Reino das Chamas");
    floresta.adicionar_personagem("Pipsqueak", 10, "Animal");
    floresta.adicionar_personagem("Feiticeira Lyra", 60, "Mago");
    floresta.adicionar_personagem("Urso Groff", 45, "Animal");

    cout << "=== Personagens da Floresta Encantada ===" << endl;
    cout << "(do menos poderoso para o mais poderoso)" << endl << endl;

    floresta.percorrer_em_ordem();

    return 0;
}