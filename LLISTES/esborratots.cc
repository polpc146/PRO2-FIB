#include "LlistaIOEstudiant.hh"

using namespace std;

void esborra_tots(list<Estudiant> &t, int x) {
    list<Estudiant>::iterator it = t.begin();
    while (it != t.end()) {
        Estudiant est = *it;
        if (est.consultar_DNI() == x) it = t.erase(it);
        else ++it;
    }
}
