#include <iostream>
using namespace std;

int dobrar(int x) {
    return x * 2;
}

int quadrado(int x) {
    return x * x;
}

int absoluto(int x) {
    if (x < 0) {
        return -x;
    } 
    else {
        return x;
    }
}

void aplicar(int* arr, int tamanho, int (*func)(int)) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = func(arr[i]);
    }
}

int main() {
    int tamanho, escolha;
    cout << "Digite o tamanho do array: ";
    cin >> tamanho; 

    switch (tamanho) {
        case 0:
            cout << "O tamanho do array não pode ser zero." << endl;
            return 1;
            break;
        case 1:
            cout << "O tamanho do array não pode ser um." << endl;
            return 1;
            break;
        default:
            break;
    }

    int* arr = new int[tamanho];
    cout << "Digite os elementos do array: ";
    for (int i = 0; i < tamanho; i++) {
        cin >> arr[i];
    }

    cout << "Escolha uma função para aplicar aos elementos do array:" << endl;
    cout << "1 - Dobrar" << endl;
    cout << "2 - Quadrado" << endl;
    cout << "3 - Absoluto" << endl;
    cin >> escolha;

    switch (escolha) {
        case 1:
            aplicar(arr, tamanho, dobrar);
            break;
        case 2:
            aplicar(arr, tamanho, quadrado);
            break;
        case 3:
            aplicar(arr, tamanho, absoluto);
            break;
        default:
            cout << "Escolha inválida." << endl;
            return 1;
            break;
    }

    cout << "O vetor formado após a aplicação da função é:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
}