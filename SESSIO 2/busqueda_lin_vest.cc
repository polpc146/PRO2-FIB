#include <iostream>
#include <vector>
#include "Estudiant.hh"
#include "vectorIOEstudiant.hh"

using namespace std;

pair<bool,Estudiant> busqueda_lin_vest (const vector<Estudiant>& vest, int DNI) {
    int tam = vest.size();
    bool trobat = false;
    pair<bool,Estudiant> solucio;
    int i=0;
    while (i<tam and not trobat) {
        if (vest[i].consultar_DNI() == DNI) trobat = true;
        else ++i;
    }
    solucio.first = trobat;
    solucio.second = vest[i];
    return solucio;
}

int main () {
    vector<Estudiant> vest;
    llegir_vector_est (vest);
    pair<bool,Estudiant> solucio;
    int DNI;
    cin >> DNI;
    solucio = busqueda_lin_vest (vest, DNI);
    if (not solucio.first) cout << "El estudiante no está en el vector" << endl;
    else {
        if (solucio.second.te_nota()) cout << "El estudiante está en el vector y su nota es " << solucio.second.consultar_nota() << endl;
        else cout << "El estudiante está en el vector, pero no tiene nota" << endl;
    }
}
