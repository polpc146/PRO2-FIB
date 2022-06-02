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

Almacenaje::Almacenaje (const Almacenaje& a) {
    
    ContenedoresAlmacenaje = a.ContenedoresAlmacenaje;
    Huecos = a.Huecos;
}

//Destructora

Almacenaje::~Almacenaje() {}

//Modificadoras

void Almacenaje::retirar_contenedor (const string& m) {
    
    if (ContenedoresAlmacenaje.size() == 1) ContenedoresAlmacenaje = map <string, Segmento>();
    else ContenedoresAlmacenaje.erase (m);
}

void Almacenaje::actualizar_huecos (const vector<Segmento>& vseg, const vector<Segmento>& velem) {
    
    int t = vseg.size();
    Segmento s;
    for (int i = 1; i < t; ++i) {
        
        s = vseg[i];
        Huecos.insert (s);
    }
    t = velem.size();
    for (int i = 1; i < t; ++i) {
        
        s = velem[i];
        Huecos.erase (s);
    }
}

//Consultora

Segmento Almacenaje::donde (const string& m) const {
    
    Segmento s;
    map <string, Segmento>::const_iterator it = ContenedoresAlmacenaje.find(m);
    if (it != ContenedoresAlmacenaje.end()) s = it->second;
    return s;
}

int Almacenaje::longitud (const string& m) const {
    
    int l;
    map <string, Segmento>::const_iterator it = ContenedoresAlmacenaje.find(m);
    Segmento s;
    s = it->second;
    l = s.longitud();
    return l;
}

string Almacenaje::matricula (const Ubicacion& u) const {
    
    if (u.plaza() == 0) {
        
        for (map <string, Segmento>::const_iterator it = ContenedoresAlmacenaje.begin(); it != ContenedoresAlmacenaje.end(); ++it) {
            
            if (it->second.ubic() == u) return it->first;
        }
    }
    
    else if (u.plaza() == 1) {
        
        Ubicacion a (u.hilera(), u.plaza() - 1, u.piso());
        for (map <string, Segmento>::const_iterator it = ContenedoresAlmacenaje.begin(); it != ContenedoresAlmacenaje.end(); ++it) {
            
            if (it->second.ubic() == u) return it->first;
            else if (it->second.ubic() == a) {
                
                if (it->second.longitud() > 1) return it->first;
            }
        }
    }
    
    else {
        
        Ubicacion a (u.hilera(), u.plaza() - 1, u.piso());
        Ubicacion b (u.hilera(), u.plaza() - 2, u.piso());
        for (map <string, Segmento>::const_iterator it = ContenedoresAlmacenaje.begin(); it != ContenedoresAlmacenaje.end(); ++it) {
            
            if (it->second.ubic() == u) return it->first;
            else if (it->second.ubic() == a) {
                
                if (it->second.longitud() > 1) return it->first;
            }
            else if (it->second.ubic() == b) {
                
                if (it->second.longitud() > 2) return it->first;
            }
        }
    }
    return "-1";
}

Ubicacion Almacenaje::hueco_mas_adecuado (const Contenedor& c) {
    
    int l;
    l = c.longitud();
    string m;
    m = c.matricula();
    Ubicacion u (0,0,0);
    Segmento s (u, l);
    set <Segmento>::const_iterator it = Huecos.lower_bound (s);
    s = *it;
    u = s.ubic();
    Segmento s1 (u, l);
    ContenedoresAlmacenaje [c.matricula()] = s1;
    Huecos.erase (it);
    return u;
}

bool Almacenaje::existe_contenedor (const string& m) const {
    
    bool existe = true;
    map <string, Segmento>::const_iterator it = ContenedoresAlmacenaje.find(m);
    if (it == ContenedoresAlmacenaje.end()) existe = false;
    return existe;
}

//Salidas

void Almacenaje::escribir_ContenedoresAlmacenaje() const {
    
    Segmento s;
    for (map <string, Segmento>::const_iterator it = ContenedoresAlmacenaje.begin(); it != ContenedoresAlmacenaje.end(); ++it) {
        cout << it->first;
        s = it->second;
        s.print();
        cout << endl;
    }
}

void Almacenaje::escribir_Huecos() const {
    
    Segmento s;
    for (set <Segmento>::const_iterator it = Huecos.begin(); it != Huecos.end(); ++it) {
        
        s = *it;
        s.print();
        cout << endl;
    }
}
