#include <iostream>
using namespace std;

int potencia (int base, int expoente = 2) {
    int resultado = 1;
    if (expoente == 0) {
        return 1;
    }
    for (int i = 0; i < expoente; i++) {
        resultado = resultado * base;
    }
    return resultado;
}

int main (){
    int base, expoente, resultado;
    cout << "Digite a base: ";
    cin >> base;
    cout << "Digite o expoente: ";
    cin >> expoente;

    resultado = potencia(base, expoente);
    cout << base << " elevado a " << expoente << " é: " << resultado << endl;

    return 0;
}