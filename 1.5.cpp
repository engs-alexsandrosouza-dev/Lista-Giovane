#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Pilha {
    int dados[MAX];
    int topo;
};

void push(Pilha* p, int valor) {
    p->topo++;
    p->dados[p->topo] = valor;
}

int pop(Pilha* p) {
    int valor = p->dados[p->topo];
    p->topo--;
    return valor;
}

int avaliar(string expressao) {
    Pilha p;
    p.topo = -1;

    string token = "";

    for (int i = 0; i <= expressao.length(); i++) {

        if (expressao[i] != ' ' && i < expressao.length()) {
            token += expressao[i];
        }
        else if (token != "") {

            if (token == "+") {
                int b = pop(&p);
                int a = pop(&p);
                push(&p, a + b);
            }
            else if (token == "-") {
                int b = pop(&p);
                int a = pop(&p);
                push(&p, a - b);
            }
            else if (token == "*") {
                int b = pop(&p);
                int a = pop(&p);
                push(&p, a * b);
            }
            else if (token == "/") {
                int b = pop(&p);
                int a = pop(&p);
                push(&p, a / b);
            }
            else {
                int numero = stoi(token);
                push(&p, numero);
            }

            token = "";
        }
    }

    return pop(&p);
}

int main() {

    string expressao;

    cout << "Digite a expressao pos-fixa: ";
    getline(cin, expressao);

    cout << "Resultado: " << avaliar(expressao) << endl;

    return 0;
}
```
