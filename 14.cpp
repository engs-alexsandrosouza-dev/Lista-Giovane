#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void merge(int* arr, int inicio, int meio, int fim) {
    int tamanho = fim - inicio + 1;
    int* temp = new int[tamanho];

    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= fim) {
      
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } 
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= fim) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = 0; x < tamanho; x++) {
        arr[inicio + x] = temp[x];
    }

    delete[] temp;
}

void mergeSort(int* arr, int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }

    int meio = inicio + (fim - inicio) / 2;

    mergeSort(arr, inicio, meio);
    mergeSort(arr, meio + 1, fim);

    merge(arr, inicio, meio, fim);
}

void preencherArray(int* arr, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 100000;
    }
}

void testar(int tamanho) {
    int* arr = new int[tamanho];

    preencherArray(arr, tamanho);

    auto inicio = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, tamanho - 1);
    auto fim = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tempo = fim - inicio;
    cout << "Tamanho: " << tamanho << endl;
    cout << "Tempo: " << tempo.count() << " ms" << endl;

    delete[] arr;
}
int main() {
    srand(time(NULL));
    testar(10);
    testar(100);
    testar(10000);
}

