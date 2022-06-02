#include <iostream>
#include <vector>
#include "Estudiant.hh"
#include "vectorIOEstudiant.hh"

using namespace std;

void redondear_e_a(Estudiant& est) {
    est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
}

int main () {
    vector<Estudiant> vest;
    llegir_vector_est (vest);
    int tam = vest.size();
    for (int i=0; i<tam; ++i) {
        if (vest[i].te_nota()) redondear_e_a (vest[i]);
    }
    escriure_vector_est (vest);
}
