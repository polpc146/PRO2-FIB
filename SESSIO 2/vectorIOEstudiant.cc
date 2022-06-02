#include "vectorIOEstudiant.hh"

void llegir_vector_est (vector<Estudiant>& vest) {
    cout << "Escribe el tamaño del vector" << endl;
    int n;
    cin >> n;
    vest = vector<Estudiant> (n);
    
    for (int i=0; i<n; ++i) {
        vest[i].llegir();
    }
}

void escriure_vector_est (const vector<Estudiant>& vest) {
    int tam = vest.size();
    for (int i=0; i<tam; ++i) {
        vest[i].escriure();
    }
}
