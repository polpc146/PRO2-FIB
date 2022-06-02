#include <iostream>
#include <vector>
#include <algorithm>
#include "Estudiant.hh"

using namespace std;

bool comp (const Estudiant& est1, const Estudiant& est2) {
    if (est2.consultar_nota() == est1.consultar_nota()) return est1.consultar_DNI() < est2.consultar_DNI();
    else return est1.consultar_nota() > est2.consultar_nota();
}

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
    }
    sort (vest.begin(), vest.end(), comp);
    for (int i=0; i<M; ++i) vest[i].escriure();
}
