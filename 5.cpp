#include <iostream>
using namespace std;

int fatorial(int num){
    if (num == 0){
    return 1;
        
    }
    return num * fatorial(num-1);
    
}
int main(){
    int num, total;
    
    cout << "informe um valor: ";
    cin >> num;
    total = fatorial(num);
    cout << "O total desse fatorial é: " << total << endl;
}

