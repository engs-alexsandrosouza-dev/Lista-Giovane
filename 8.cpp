#include <iostream>
using namespace std;

int somaDigitos(int num){
    if (num == 0) {
        return 0;
    }
    return (num % 10) + somaDigitos(num / 10);
}

int main (){
    int num, resultado = 0;
    cout << "Digite um número inteiro: ";
    cin >> num;

    resultado = somaDigitos(num);
    cout << "A soma dos dígitos de " << num << " é: " << resultado << endl;

}