#include <iostream>
using namespace std;

int somaArray(int* arr, int n){
    int soma = 0;
    if (n <= 0) {
        return 0;
    }
    soma = *arr + somaArray(arr + 1, n - 1);
    return soma;
}

int main(){
    int n;


    int arr[5];
    cout << "Digite os elementos do array: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int resultado = somaArray(arr, 5);
    cout << "A soma dos elementos do array é: " << resultado << endl;

}