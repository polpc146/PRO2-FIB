#include <iostream>
#include "matrizIOint.hh"
using namespace std;

void producto (const Matriz& m1, const Matriz& m2, Matriz& prod) {
    int fil = m1.size();
    int col = m2[0].size();
    int same = m2.size();
    
    for (int i=0; i<fil; ++i) {
        for (int j=0; j<col; ++j) {
            for (int k=0; k<same; ++k) {
                prod [i][j] += m1 [i][k] * m2 [k][j];
            }
        }
    }
    
}

int main () {
    cout << "Primera matriz" << endl;
    Matriz m1;
    leer_matriz_int (m1);
    cout << "Segunda matriz" << endl;
    Matriz m2;
    leer_matriz_int (m2);
    Matriz prod (m1.size(), vector<int> (m2[0].size()));
    
    producto (m1, m2, prod);
    
    escribir_matriz_int (prod);
}
