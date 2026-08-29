#include <iostream>
using namespace std;

double AreaRetangulo(double base, double altura) {
    return base * altura;
}

int main() {
    double base, altura, area;
    cout << "Digite a base do retângulo: ";
    cin >> base;
    cout << "Digite a altura do retângulo: ";
    cin >> altura;


    area = AreaRetangulo(base, altura);
    cout << "A área do retângulo é: " << area << endl;

    
}
