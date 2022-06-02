#include <iostream>
#include <list>
#include "Estudiant.hh"
#include "LlistaIOEstudiant.hh"

using namespace std;

void busquedadelestudiante (const list<Estudiant>& lest, bool& trobat, double& nota, int DNI) {
    list<Estudiant>::const_iterator it = lest.begin();
    while (not trobat and it != lest.end()) {
        Estudiant est = *it;
        if (est.consultar_DNI() == DNI) {
            trobat = true;
            if (est.te_nota()) nota = est.consultar_nota();
        }
        ++it;
    }
}

int main() {
    int DNI;
    cin >> DNI;
    list<Estudiant> lest;
    LlegirLlistaEstudiant (lest);
    bool trobat = false;
    double nota = -1;
    busquedadelestudiante (lest, trobat, nota, DNI);
    if (not trobat) cout << "El estudiante no esta en la lista" << endl;
    else {
        if (nota == -1) cout << "El estudiante esta en la lista, pero no tiene nota" << endl;
        else cout << "El estudiante esta en la lista y su nota es " << nota << endl;
    }
}
