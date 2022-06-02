#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l) {
    list<Estudiant>::iterator it = l.end();
    Estudiant est;
    est.llegir();
    while (est.consultar_DNI() != 0) {
        l.insert(it, est);
        est.llegir();
    }
}

void EscriureLlistaEstudiant(const list<Estudiant>& l) {
    if (not l.empty()) {
        list<Estudiant>::const_iterator it;
        for (it=l.begin(); it!=l.end(); ++it) {
            Estudiant est = *it;
            est.escriure();
        }
    }
}
