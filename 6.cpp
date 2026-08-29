#include <iostream>
using namespace std;

void trocar (int &a, int &b){
    int aux;
    aux = a;
    a = b;
    b = aux;
    cout << "a = " << a  << " b = " << b << endl;
}

void trocaPorValor (int a, int b){
    int aux;
    aux = a;
    a = b;
    b = aux;
    cout << "a = " << a  << " b = " << b << endl;
}

int main(){
    int x = 10;
    int y = 20;
    
    cout << "Antes da troca: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    
    trocar(x, y);
    
    cout << "Depois da troca: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    trocaPorValor(x, y);

    cout << "Depois da troca por valor: " << endl;
    cout << "x = " << x << endl;    
    cout << "y = " << y << endl;
    
    return 0;
}