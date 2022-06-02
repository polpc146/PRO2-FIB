#include <iostream>
#include "vectorIOint.hh"
using namespace std;

void intercambiar_vect (vector<int>& v, int i, int j) {
    int x= v[j];
    v[j]=v[i];
    v[i]=x;
}

int main () {
    vector<int> v;
    leer_vector_int (v);
    cout << "Escriba posiciones a intercambiar" << endl;
    int i, j;
    cin >> i >> j;
    intercambiar_vect (v, i-1, j-1);
    escribir_vector_int (v);
}
