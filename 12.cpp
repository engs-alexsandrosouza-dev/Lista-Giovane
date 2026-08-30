#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, char origem, char destino, char auxiliar, int& contador) {

    if (n == 1) {
        cout << "Mover disco 1 de " << origem << " para " << destino << endl;
        contador++;
        return;
    }
    hanoi(n - 1, origem, auxiliar, destino, contador);
    cout << "Disco: " << n << " Torre " << origem << " -> Torre " << destino << endl << endl;
    contador++;
    hanoi(n - 1, auxiliar, destino, origem, contador);
}

int main() {
    int n, contador = 0;
    cout << "Digite o número de discos: ";
    cin >> n;

    hanoi(n, 'A', 'C', 'B', contador);
    cout << "Número total de movimentos: " << contador << endl;

    if (contador == pow(2, n) - 1) {
        cout << "O número de movimentos está correto." << endl;
    } 
    else {
        cout << "O número de movimentos está incorreto." << endl;
    }
    return 0;
}