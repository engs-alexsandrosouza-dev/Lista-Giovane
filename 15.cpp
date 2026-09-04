#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Pilha {
    int* dados;
    int topo;
    int capacidade;
};

void push(Pilha* p, int valor) {
    p->dados[p->topo] = valor;
    p->topo++;
}

int pop(Pilha* p) {
    p->topo--;
    return p->dados[p->topo];
}

bool ehNumero(string token) {
    if (token.empty()) {
        return false;
    }

    int inicio = 0;

    if (token[0] == '-') {
        inicio = 1;
    }

    for (int i = inicio; i < token.length(); i++) {
        if (token[i] < '0' || token[i] > '9') {
            return false;
        }
    }

    return true;
}

int avaliar(string expressao) {
    Pilha p;

    p.capacidade = 100;
    p.dados = new int[p.capacidade];
    p.topo = 0;

    string token;
    stringstream ss(expressao);

    while (ss >> token) {

        if (ehNumero(token)) {
            push(&p, stoi(token));
        }
        else {
            int b = pop(&p);
            int a = pop(&p);
            int resultado;

            if (token == "+") {
                resultado = a + b;
            }
            else if (token == "-") {
                resultado = a - b;
            }
            else if (token == "*") {
                resultado = a * b;
            }
            else if (token == "/") {
                resultado = a / b;
            }

            push(&p, resultado);
        }
    }

    int resultado = pop(&p);

    delete[] p.dados;

    return resultado;
}

int main() {
    string expressao;

    cout << "Digite a expressao posfixa: ";
    getline(cin, expressao);

    cout << "Resultado: " << avaliar(expressao) << endl;

    return 0;
}
