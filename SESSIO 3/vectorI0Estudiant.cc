#include "vectorI0Estudiant.hh"

//leer vector
void leer_vector (vector<Estudiant>& estud) {
    int n;
    cin >> n;
    estud = vector<Estudiant>(n);
    for (int i = 0; i < n; ++i) estud[i].llegir();
}

//escribir
void escribir_vector (const vector<Estudiant>& estud) {
    int y = estud.size();
    for (int j = 0; j < y; ++j) estud[j].escriure();
}


