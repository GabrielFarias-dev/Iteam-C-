#include <iostream>
#include <iomanip>
using namespace std;

const string TC0 = "BRA", TF0 = "EGT"; const int RC0 = 3, RF0 = 0;
const string TC1 = "RSA", TF1 = "MAR"; const int RC1 = 1, RF1 = 1;
const string TC2 = "FRA", TF2 = "ARG"; const int RC2 = 1, RF2 = 2;
const string TC3 = "GER", TF3 = "COS"; const int RC3 = 4, RF3 = 2;

int calcularPontos(int bc, int bf, int rc, int rf) {
    if (bc == rc && bf == rf) return 10;
    bool bcV = bc > bf, rcV = rc > rf, bcE = bc == bf, rcE = rc == rf;
    if ((bcV && rcV) || (!bcV && !bcE && !rcV && !rcE) || (bcE && rcE)) return 5;
    return 0;
}

int calcularTotal(int b0c, int b0f, int b1c, int b1f,
                  int b2c, int b2f, int b3c, int b3f) {
    return calcularPontos(b0c, b0f, RC0, RF0)
         + calcularPontos(b1c, b1f, RC1, RF1)
         + calcularPontos(b2c, b2f, RC2, RF2)
         + calcularPontos(b3c, b3f, RC3, RF3);
}

void coletarPalpites(string& nome,
                     int& b0c, int& b0f,
                     int& b1c, int& b1f,
                     int& b2c, int& b2f,
                     int& b3c, int& b3f) {
    cout << "Nome: ";
    getline(cin, nome);

    cout << "\n  Jogo 1: " << TC0 << " x " << TF0 << endl;
    try {
        cout << "  Quantos gols o " << TC0 << " vai fazer? "; cin >> b0c;
        cout << "  Quantos gols o " << TF0 << " vai fazer? "; cin >> b0f;
        if (b0c < 0 || b0f < 0) throw "Placar nao pode ser negativo!";
    } catch (const char* e) { cout << "  ERRO: " << e << " Usando 0." << endl; b0c = b0f = 0; }

    cout << "\n  Jogo 2: " << TC1 << " x " << TF1 << endl;
    try {
        cout << "  Quantos gols o " << TC1 << " vai fazer? "; cin >> b1c;
        cout << "  Quantos gols o " << TF1 << " vai fazer? "; cin >> b1f;
        if (b1c < 0 || b1f < 0) throw "Placar nao pode ser negativo!";
    } catch (const char* e) { cout << "  ERRO: " << e << " Usando 0." << endl; b1c = b1f = 0; }

    cout << "\n  Jogo 3: " << TC2 << " x " << TF2 << endl;
    try {
        cout << "  Quantos gols o " << TC2 << " vai fazer? "; cin >> b2c;
        cout << "  Quantos gols o " << TF2 << " vai fazer? "; cin >> b2f;
        if (b2c < 0 || b2f < 0) throw "Placar nao pode ser negativo!";
    } catch (const char* e) { cout << "  ERRO: " << e << " Usando 0." << endl; b2c = b2f = 0; }

    cout << "\n  Jogo 4: " << TC3 << " x " << TF3 << endl;
    try {
        cout << "  Quantos gols o " << TC3 << " vai fazer? "; cin >> b3c;
        cout << "  Quantos gols o " << TF3 << " vai fazer? "; cin >> b3f;
        if (b3c < 0 || b3f < 0) throw "Placar nao pode ser negativo!";
    } catch (const char* e) { cout << "  ERRO: " << e << " Usando 0." << endl; b3c = b3f = 0; }
}

void exibirApostador(string nome,
                     int b0c, int b0f,
                     int b1c, int b1f,
                     int b2c, int b2f,
                     int b3c, int b3f) {
    int p0 = calcularPontos(b0c, b0f, RC0, RF0);
    int p1 = calcularPontos(b1c, b1f, RC1, RF1);
    int p2 = calcularPontos(b2c, b2f, RC2, RF2);
    int p3 = calcularPontos(b3c, b3f, RC3, RF3);

    cout << "\n  " << nome << ":" << endl;

    cout << "    Jogo 1 (" << TC0 << " x " << TF0 << "): " << b0c << " x " << b0f;
    if (p0 == 10) cout << "  [EXATO     +10]" << endl;
    else if (p0 == 5) cout << "  [Vencedor  +5]" << endl;
    else cout << "  [Errou      +0]" << endl;

    cout << "    Jogo 2 (" << TC1 << " x " << TF1 << "): " << b1c << " x " << b1f;
    if (p1 == 10) cout << "  [EXATO     +10]" << endl;
    else if (p1 == 5) cout << "  [Vencedor  +5]" << endl;
    else cout << "  [Errou      +0]" << endl;

    cout << "    Jogo 3 (" << TC2 << " x " << TF2 << "): " << b2c << " x " << b2f;
    if (p2 == 10) cout << "  [EXATO     +10]" << endl;
    else if (p2 == 5) cout << "  [Vencedor  +5]" << endl;
    else cout << "  [Errou      +0]" << endl;

    cout << "    Jogo 4 (" << TC3 << " x " << TF3 << "): " << b3c << " x " << b3f;
    if (p3 == 10) cout << "  [EXATO     +10]" << endl;
    else if (p3 == 5) cout << "  [Vencedor  +5]" << endl;
    else cout << "  [Errou      +0]" << endl;

    cout << "  Total: " << (p0 + p1 + p2 + p3) << " / 40 pts" << endl;
}

int main() {
    string n0="", n1="", n2="", n3="";

    int b00c=0,b00f=0, b01c=0,b01f=0, b02c=0,b02f=0, b03c=0,b03f=0;
    int b10c=0,b10f=0, b11c=0,b11f=0, b12c=0,b12f=0, b13c=0,b13f=0;
    int b20c=0,b20f=0, b21c=0,b21f=0, b22c=0,b22f=0, b23c=0,b23f=0;
    int b30c=0,b30f=0, b31c=0,b31f=0, b32c=0,b32f=0, b33c=0,b33f=0;

    int total0=0, total1=0, total2=0, total3=0;
    int qtd = 0;
    char continuar = 'Y';

    cout << "================================" << endl;
    cout << "      BOLAO DA COPA 2026        " << endl;
    cout << "================================" << endl;

    // Coleta palpites de todos os apostadores
    do {
        if (qtd > 0) cin.ignore();

        cout << "\n--- Apostador " << (qtd + 1) << " ---" << endl;

        if (qtd == 0) {
            coletarPalpites(n0, b00c,b00f, b01c,b01f, b02c,b02f, b03c,b03f);
            total0 = calcularTotal(b00c,b00f, b01c,b01f, b02c,b02f, b03c,b03f);
        } else if (qtd == 1) {
            coletarPalpites(n1, b10c,b10f, b11c,b11f, b12c,b12f, b13c,b13f);
            total1 = calcularTotal(b10c,b10f, b11c,b11f, b12c,b12f, b13c,b13f);
        } else if (qtd == 2) {
            coletarPalpites(n2, b20c,b20f, b21c,b21f, b22c,b22f, b23c,b23f);
            total2 = calcularTotal(b20c,b20f, b21c,b21f, b22c,b22f, b23c,b23f);
        } else {
            coletarPalpites(n3, b30c,b30f, b31c,b31f, b32c,b32f, b33c,b33f);
            total3 = calcularTotal(b30c,b30f, b31c,b31f, b32c,b32f, b33c,b33f);
        }

        qtd++;

        if (qtd < 4) {
            cout << "\nHa mais algum apostador? (Y/N): ";
            cin >> continuar;
        } else {
            continuar = 'N';
        }

    } while (continuar == 'Y' || continuar == 'y');

    cout << "\n\n================================" << endl;
    cout << "      RESULTADOS OFICIAIS       " << endl;
    cout << "================================" << endl;
    cout << "  Jogo 1: " << TC0 << " " << RC0 << " x " << RF0 << " " << TF0 << endl;
    cout << "  Jogo 2: " << TC1 << " " << RC1 << " x " << RF1 << " " << TF1 << endl;
    cout << "  Jogo 3: " << TC2 << " " << RC2 << " x " << RF2 << " " << TF2 << endl;
    cout << "  Jogo 4: " << TC3 << " " << RC3 << " x " << RF3 << " " << TF3 << endl;

    cout << "\n================================" << endl;
    cout << "    PALPITES E PONTUACAO        " << endl;
    cout << "================================" << endl;

    if (qtd >= 1) exibirApostador(n0, b00c,b00f, b01c,b01f, b02c,b02f, b03c,b03f);
    if (qtd >= 2) exibirApostador(n1, b10c,b10f, b11c,b11f, b12c,b12f, b13c,b13f);
    if (qtd >= 3) exibirApostador(n2, b20c,b20f, b21c,b21f, b22c,b22f, b23c,b23f);
    if (qtd >= 4) exibirApostador(n3, b30c,b30f, b31c,b31f, b32c,b32f, b33c,b33f);

    cout << "\n================================" << endl;
    cout << "           RANKING              " << endl;
    cout << "================================" << endl;

    bool u0=false, u1=false, u2=false, u3=false;

    for (int pos = 1; pos <= qtd; pos++) {
        int maxT = -1, best = -1;

        if (!u0 && total0 > maxT) { maxT = total0; best = 0; }
        if (qtd >= 2 && !u1 && total1 > maxT) { maxT = total1; best = 1; }
        if (qtd >= 3 && !u2 && total2 > maxT) { maxT = total2; best = 2; }
        if (qtd >= 4 && !u3 && total3 > maxT) { maxT = total3; best = 3; }

        string bestNome; int bestTotal;
        if (best == 0) { bestNome = n0; bestTotal = total0; u0 = true; }
        else if (best == 1) { bestNome = n1; bestTotal = total1; u1 = true; }
        else if (best == 2) { bestNome = n2; bestTotal = total2; u2 = true; }
        else               { bestNome = n3; bestTotal = total3; u3 = true; }

        cout << "  " << setw(2) << pos << ". "
             << setw(20) << left  << bestNome
             << setw(3)  << right << bestTotal << " pts" << endl;
    }

    string campeao = n0; int maxTotal = total0;
    if (qtd >= 2 && total1 > maxTotal) { maxTotal = total1; campeao = n1; }
    if (qtd >= 3 && total2 > maxTotal) { maxTotal = total2; campeao = n2; }
    if (qtd >= 4 && total3 > maxTotal) { maxTotal = total3; campeao = n3; }

    cout << "\n  Campeao do Bolao: " << campeao << "!" << endl;
    cout << "================================" << endl;

    return 0;
}