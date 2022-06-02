#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    if (nest < MAX_NEST) {
        int i = nest-1;
        b = false;
        bool afegit = false;
        while (i>=0 and not b and not afegit) {
            if (est.consultar_DNI() > vest[i].consultar_DNI()) afegit = true;
            else if (est.consultar_DNI() == vest[i].consultar_DNI()) b = true;
            else {
                vest[i+1] = vest[i];
                --i;
            }
        }
        if (not b) {
            vest[i+1] = est;
            ++nest;
            if (est.te_nota()) {
                ++nest_amb_nota;
                suma_notes += est.consultar_nota();
            }
        }
        else {
            for (int j=i+1; j<nest; ++j) vest[j] = vest[j+1];
        }
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    b = false;
    int i = cerca_dicot (vest, 0, nest-1, dni);
    if (i != -1) {
        b = true;
        if (vest[i].te_nota()) {
            --nest_amb_nota;
            suma_notes -= vest[i].consultar_nota();
        }
        for (int j=i; j<nest; ++j) if (j<nest-1) vest[j] = vest[j+1];
        --nest;
    }
}
