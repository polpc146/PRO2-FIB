#include "AreaDeAlmacenaje.hh"
#include <iostream>

using namespace std;

//Constructoras

Almacenaje::Almacenaje() {
    
    ContenedoresAlmacenaje = map <string, Segmento>();
    Huecos = set <Segmento>();
}

Almacenaje::Almacenaje (int N, int M) {
    
    ContenedoresAlmacenaje = map <string, Segmento>();
    for (int i = 0; i < N; ++i) {
        
        Ubicacion u (i, 0, 0);
        Segmento s (u, M);
        Huecos.insert (s);
    }
}

//Destructora

Almacenaje::~Almacenaje() {}

//Modificadoras

void Almacenaje::retirar_contenedor (const string& m) {
    
    ContenedoresAlmacenaje.erase (m);
}

void Almacenaje::nuevo_hueco (const Segmento& s) {
    
    Huecos.insert (s);
}

void Almacenaje::eliminar_hueco (const Segmento& s) {
    
    Huecos.erase (s);
}

void Almacenaje::modificar_ubicacion (const string& m, int l) {
    
    Ubicacion u (-1,0,0);
    Segmento s1 (u, l);
    ContenedoresAlmacenaje [m] = s1;
}

void Almacenaje::actualizar_ubicacion (const string& m, const Segmento& s) {
    
    ContenedoresAlmacenaje [m] = s;
}

//Consultoras

Segmento Almacenaje::donde (const string& m) const {
    
    Segmento s;
    map <string, Segmento>::const_iterator it = ContenedoresAlmacenaje.find(m);
    if (it != ContenedoresAlmacenaje.end()) s = it->second;
    return s;
}

int Almacenaje::longitud (const string& m) const {
    
    map <string, Segmento>::const_iterator it = ContenedoresAlmacenaje.find(m);
    return it->second.longitud();
}

Ubicacion Almacenaje::hueco_mas_adecuado (const Contenedor& c) {
    
    int l;
    l = c.longitud();
    string m;
    m = c.matricula();
    Ubicacion u (0,0,0);
    Segmento s (u, l);
    set <Segmento>::const_iterator it = Huecos.lower_bound (s);
    if (it == Huecos.end()) {
        
        Ubicacion uesp (-1,0,0);
        Segmento s1 (uesp,l);
        ContenedoresAlmacenaje [c.matricula()] = s1;
        return uesp;
    }
    s = *it;
    u = s.ubic();
    Segmento s1 (u, l);
    ContenedoresAlmacenaje [c.matricula()] = s1;
    Huecos.erase (it);
    return u;
}

bool Almacenaje::existe_contenedor (const string& m) const {
    
    map <string, Segmento>::const_iterator it = ContenedoresAlmacenaje.find(m);
    if (it == ContenedoresAlmacenaje.end()) return false;
    return true;
}

//Salidas

void Almacenaje::escribir_ContenedoresAlmacenaje() const {
    
    for (map <string, Segmento>::const_iterator it = ContenedoresAlmacenaje.begin(); it != ContenedoresAlmacenaje.end(); ++it) {
        cout << it->first;
        it->second.print();
        cout << endl;
    }
}

void Almacenaje::escribir_Huecos() const {
    
    for (set <Segmento>::const_iterator it = Huecos.begin(); it != Huecos.end(); ++it) {
        
        (*it).print();
        cout << endl;
    }
}
