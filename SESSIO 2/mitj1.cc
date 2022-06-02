#include <iostream>
#include <vector>
#include "Estudiant.hh"

using namespace std;

int main () {
    int M, N, S;
    cin >> M >> N >> S;
    vector<int> seleccio (S);
    for (int i=0; i<S; ++i) cin >> seleccio[i];
    vector<Estudiant> vest (M);
    int dni;
    vector<double> notes (N);
    for (int i=0; i<M; ++i) {
        cin >> dni;
        vest[i] = Estudiant(dni);
        for (int j=0; j<N; ++j) cin >> notes[j];
        double suma = 0;
        for (int k=0; k<S; ++k) {
            suma += notes[seleccio[k]-1];
        }
        vest[i].afegir_nota (suma/S);
        vest[i].escriure();
    }
}
