#include <iostream>
using namespace std;

int buscaBinaria(int* arr, int esq, int dir, int alvo, int& contador){
    if (esq > dir) {
        cout << "Elemento não encontrado. Número de comparações: " << contador << endl;
        return -1;
    }

    int meio = esq + (dir - esq) / 2;

    if (arr[meio] == alvo) {
        contador++;
        cout << "Elemento encontrado na posição: " << meio << ". Número de comparações: " << contador << endl;
        return meio;
    }

    if (arr[meio] > alvo) {
        contador += 2;
        return buscaBinaria(arr, esq, meio - 1, alvo, contador);
    } 
    else {
        contador += 2;
        return buscaBinaria(arr, meio + 1, dir, alvo, contador);
    } 

}

int buscaSequencial(int* arr, int n, int alvo, int& contador) {
    contador = 0;
    for (int i = 0; i < n; i++) {
        contador++;
        if (arr[i] == alvo) {
            cout << "Elemento encontrado na posição: " << i << ". Número de comparações: " << contador << endl;
            return i;
        }
    }
    cout << "Elemento não encontrado. Número de comparações: " << contador << endl;
    return -1;
}
int main() {
    int n = 0, alvo, binario, sequencial, contadorBinario, contadorSequencial;
    cout << "Digite o tamanho do array: ";
    cin >> n;
    if(n ==100){
        n = 100;
    }
    else if(n == 1000){
        n = 1000;
    }
    else{
        cout << "Tamanho inválido. O programa será encerrado." << endl;
        return 1;
    }

    int* arr = new int[n];
    cout << "Digite os elementos do array em ordem crescente:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Digite o elemento a ser buscado: ";
    cin >> alvo;

    contadorBinario = 0;
    binario = buscaBinaria(arr, 0, n - 1, alvo, contadorBinario);
    
    contadorSequencial = 0;
    sequencial = buscaSequencial(arr, n, alvo, contadorSequencial);

    if (contadorBinario < contadorSequencial) {
        cout << "A busca binária foi mais eficiente." << endl;
    } 
    else if (contadorBinario > contadorSequencial) {
        cout << "A busca sequencial foi mais eficiente." << endl;
    } 
    else {
        cout << "Ambas as buscas tiveram o mesmo número de comparações." << endl;
    }

    delete[] arr;

    return 0;
}