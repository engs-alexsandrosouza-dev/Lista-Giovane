#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciMemo(int n, int* memo) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    return memo[n];
}

int main() {
    int n, resultadoMemo, resultadoRecursivo;
    cout << "Digite um número inteiro: ";
    cin >> n;
    resultadoRecursivo = fibonacci(n);
    cout << "O " << n << "º número da sequência de Fibonacci é: " << resultadoRecursivo << endl;

    int* memo = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    resultadoMemo = fibonacciMemo(n, memo);
    cout << "O " << n << "º número da sequência de Fibonacci é: " << resultadoMemo << endl;

    delete[] memo;
}