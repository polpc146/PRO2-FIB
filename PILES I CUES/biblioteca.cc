#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct Llibre {
    string nom;
    int categoria;
};

void treure_llibres (stack<string>& st, int quants) {
    for (int i=quants; i>0; --i) st.pop();
}

void escriure (stack<string>& st) {
    while (not st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}

int main () {
    int n;
    cin >> n;
    vector<stack<string>> vstack (n);
    int instruccio;
    while (cin >> instruccio and instruccio!=-4) {
        if (instruccio==-1) {
            Llibre llibre;
            cin >> llibre.nom >> llibre.categoria;
            vstack[llibre.categoria-1].push(llibre.nom);
        }
        else if (instruccio==-2) {
            int quants, donde;
            cin >> quants >> donde;
            if (quants <= vstack[donde-1].size()) treure_llibres (vstack[donde-1], quants);
        }
        else if (instruccio==-3) {
            int cual;
            cin >> cual;
            cout << "Pila de la categoria " << cual << endl;
            escriure (vstack[cual-1]);
        }
    }
}
