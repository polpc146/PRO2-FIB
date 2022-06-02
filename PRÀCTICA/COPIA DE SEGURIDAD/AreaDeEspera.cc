#include "AreaDeEspera.hh"
#include <iostream>

using namespace std;

//Constructoras

Espera::Espera() {
    
    AreaDeEspera = list <Contenedor>();
}

//Destructora

Espera::~Espera() {}

//Modificadoras

void Espera::insertar_contenedor (const Contenedor& c) {
    
    AreaDeEspera.push_front(c);
}

void Espera::eliminar_contenedor (const Contenedor& c) {
    
    for (list<Contenedor>::const_iterator it = AreaDeEspera.begin(); it != AreaDeEspera.end(); ++it) {
        
        if (*it == c) {
            
            it = AreaDeEspera.erase (it);
            return;
        }
    }
}

//Consultoras

bool Espera::hay_contenedores() const {
    
    return not AreaDeEspera.empty();
}

Contenedor Espera::primer_contenedor() const {
    
    return *AreaDeEspera.begin();
}

Contenedor Espera::contenedor_disponible (const Contenedor& c, bool b) const {
    
    Contenedor cont;
    if (not AreaDeEspera.empty()) {
        
        if (b) {
            
            cont = *AreaDeEspera.begin();
        }
        else {
            
            list<Contenedor>::const_iterator it = AreaDeEspera.begin();
            while (*it != c) {
                
                ++it;
            }
            ++it;
            if (it != AreaDeEspera.end()) {
                
                cont = *it;
            }
        }
    }
    return cont;
}

//Salidas

void Espera::escribir_AreaDeEspera() const {
    
    for (list <Contenedor>::const_iterator it = AreaDeEspera.begin(); it != AreaDeEspera.end(); ++it) {
        
        (*it).print();
        cout << endl;
    }
}
