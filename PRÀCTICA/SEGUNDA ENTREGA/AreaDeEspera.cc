#include "AreaDeEspera.hh"
#include <iostream>

using namespace std;

//Constructoras

Espera::Espera() {
    
    AreaDeEspera = list <Contenedor>();
}

Espera::Espera (const Espera& e) {
    
    AreaDeEspera = e.AreaDeEspera;
}

//Destructora

Espera::~Espera() {}

//Salidas

void Espera::escribir_AreaDeEspera() const {
    
    Contenedor c;
    for (list <Contenedor>::const_iterator it = AreaDeEspera.begin(); it != AreaDeEspera.end(); ++it) {
        
        c = *it;
        c.print();
        cout << endl;
    }
}
