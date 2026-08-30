#include <iostream>
using namespace std;    

void minMax(int* arr, int n, int* minVal, int* maxVal) {
    *minVal = arr[0];
    *maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < *minVal) {
            *minVal = arr[i];
        }
        if (arr[i] > *maxVal) {
            *maxVal = arr[i];
        }
    }
}

int main(){
    int tam = 5, minVal, maxVal;
    int arr[tam];
    cout << "Digite os elementos do vetor: ";
    for (int i = 0; i < tam; i++) {
        cin >> arr[i];
    }

   
    minMax(arr, tam, &minVal, &maxVal);
    cout << "O menor valor é: " << minVal << endl;
    cout << "O maior valor é: " << maxVal << endl;

    return 0;
}