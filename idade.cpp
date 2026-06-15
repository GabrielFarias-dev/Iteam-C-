#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int idade;
    cout << "Digite a sua idade: ";
    cin >> idade;
    cout << "A sua idade é: " << idade << " anos." << endl;

    double pi= 3.14159;
    cout << setprecision(pi) <<endl;
    cout << fixed << setprecision(2) << pi <<endl;

}