#include <iostream>
#include <list>
#include "Estudiant.hh"
#include "LlistaIOEstudiant.hh"

using namespace std;

int cuantosestudiantesrepes (const list<Estudiant>& lest, int DNI) {
    list<Estudiant>::const_iterator it;
    int repetidos = 0;
    for (it=lest.begin(); it!=lest.end(); ++it) {
        Estudiant est = *it;
        if (est.consultar_DNI() == DNI) ++repetidos;
    }
    return repetidos;
}

int main() {
    list<Estudiant> lest;
    LlegirLlistaEstudiant (lest);
    int DNI;
    cin >> DNI;
    int repetidos = cuantosestudiantesrepes (lest, DNI);
    cout << DNI << " " << repetidos << endl;
}
