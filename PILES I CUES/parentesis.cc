#include <iostream>
#include <stack>

using namespace std;

int main () {
    stack <char> pila;
    char c;
    bool si = true;
    while (cin >> c and c != '.' and si) {
        if (c == '(' or c == '[') {
            pila.push(c);
        }
        else if (c == ')') {
            if (pila.empty() or pila.top() == '[') si = false;
            else pila.pop();
        }
        else {
            if (pila.empty() or pila.top() == '(') si = false;
            else pila.pop();
        }
    }
    if (si and pila.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}
