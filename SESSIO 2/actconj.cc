#include <iostream>
#include <vector>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

using namespace std;

void actualizar_conjunto (Cjt_estudiants& c, const Cjt_estudiants& c2) {
    int tam = c.mida();
    for (int i=0; i<tam; ++i) {
        if (c.consultar_iessim(i+1).te_nota() and c2.consultar_iessim(i+1).te_nota()) {
            if (c2.consultar_iessim(i+1).consultar_nota() > c.consultar_iessim(i+1).consultar_nota()) {
                c.modificar_iessim(i+1, c2.consultar_iessim(i+1));
            }
        }
        else if (not c.consultar_iessim(i+1).te_nota()) {
            if (c2.consultar_iessim(i+1).te_nota()) c.modificar_iessim(i+1, c2.consultar_iessim(i+1));
        }
    }
}

int main () {
    Cjt_estudiants c, c2;
    c.llegir();
    c2.llegir();
    actualizar_conjunto (c, c2);
    c.escriure();
}
