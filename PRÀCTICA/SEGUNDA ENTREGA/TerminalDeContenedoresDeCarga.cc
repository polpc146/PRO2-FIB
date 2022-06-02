#include "TerminalDeContenedoresDeCarga.hh"
#include <iostream>

using namespace std;

//Constructoras

Terminal::Terminal() {
    
    AreaDeAlmacenaje = vector <Hilera>();
    almacenaje = Almacenaje();
    espera = Espera();
}

Terminal::Terminal (int N, int M, int H) {
    
    num_hileras = N;
    num_plazas = M;
    num_pisos = H;
    AreaDeAlmacenaje = vector <Hilera> (N);
    for (int i = 0; i < N; ++i) {
        
        Hilera hilera (H + 1, Piso (M + 2));
        for (int j = 0; j < H + 1; ++j) {
            
            for (int k = 0; k < M + 2; ++k) {
                
                hilera [j][k] = ' ';
                if (k == 0) {
                    
                    if (j == H) hilera [j][k] = ' ';
                    
                    else {
                        
                        int num = (H - 1 - j) % 10;
                        hilera [j][k] = num + '0';
                    }
                }
                
                if (j == H and k > 1) {
                    
                    int num = (k - 2) % 10;
                    hilera [j][k] = num + '0';
                }
            }
        }
        AreaDeAlmacenaje [i] = hilera;
    }
    
    almacenaje = Almacenaje (N, M);
    espera = Espera();
}

Terminal::Terminal (const Terminal& t) {
    
    num_hileras = t.num_hileras;
    num_pisos = t.num_pisos;
    num_plazas = t.num_plazas;
    AreaDeAlmacenaje = t.AreaDeAlmacenaje;
    almacenaje = t.almacenaje;
    espera = t.espera;
}

//Destructora

Terminal::~Terminal() {}

//Acciones privadas

void Terminal::buscar_huecos_i (const Ubicacion& u, int l) {
    
    Hilera h;
    h = AreaDeAlmacenaje [u.hilera()];
    vector <Segmento> vseg;
    vector <Segmento> velem;
    Segmento s;
    vseg.push_back(s);
    velem.push_back(s);
    int i = 0;
    int k = u.plaza() + 2 + l;
    int j = num_pisos - 1 - u.piso();
    while (k < (num_plazas + 2) and h[j][k] == ' ' and h[j + 1][k] != ' ') {
        
        ++i;
        ++k;
    }
    if (i > 0) {
            
        Ubicacion u1 (u.hilera(), u.plaza() + l, u.piso());
        s = Segmento (u1, i);
        vseg.push_back(s);
    }
    if (u.piso() < num_pisos - 1) {
            
        int izquierda = 0;
        int derecha = 0;
        j = num_pisos - 2 - u.piso();
        k = u.plaza() + 2 + l;
        while (k < (num_plazas + 2) and h[j][k] == ' ' and h[j + 1][k] != ' ') {
            
            ++derecha;
            ++k;
        }
        k = u.plaza() + 1;
        while (k > 1 and h[j][k] == ' ' and h[j + 1][k] != ' ') {
                
            ++izquierda;
            --k;
        }
        Ubicacion u2 (u.hilera(), u.plaza() - izquierda, u.piso() + 1);
        s = Segmento (u2, izquierda + l + derecha);
        vseg.push_back(s);
        if (derecha > 0) {
            Ubicacion u3 (u.hilera(), u.plaza() + l, u.piso() + 1);
            s = Segmento (u3, derecha);
            velem.push_back(s);
        }
        if (izquierda > 0) {
            Ubicacion u4 (u.hilera(), u.plaza() - izquierda, u.piso() + 1);
            s = Segmento (u4, izquierda);
            velem.push_back(s);
        }
    }
    almacenaje.actualizar_huecos (vseg, velem);
}

void Terminal::buscar_huecos_r (const Ubicacion& u, int l) {
    
    Hilera h;
    h = AreaDeAlmacenaje[u.hilera()];
    vector <Segmento> vseg;
    vector <Segmento> velem;
    Segmento s;
    vseg.push_back(s);
    velem.push_back(s);
    int derecha = 0;
    int izquierda = 0;
    int j = num_pisos - 1 - u.piso();
    int k = u.plaza() + 2 + l;
    while (k < (num_plazas + 2) and h[j][k] == ' ' and h[j + 1][k] != ' ') {
        
        ++derecha;
        ++k;
    }
    k = u.plaza() + 1;
    while (k > 1 and h[j][k] == ' ' and h[j + 1][k] != ' ') {
        
        ++izquierda;
        --k;
    }
    if (derecha > 0) {
        
        Ubicacion u1 (u.hilera(), u.plaza() + l, u.piso());
        s = Segmento (u1, derecha);
        velem.push_back(s);
    }
    Ubicacion u2 (u.hilera(), u.plaza() - izquierda, u.piso());
    if (izquierda > 0) {
        
        s = Segmento (u2, izquierda);
        velem.push_back(s);
    }
    s = Segmento (u2, izquierda + l + derecha);
    vseg.push_back(s);
    if (u.piso() < num_pisos - 1) {
    
        derecha = 0;
        izquierda = 0;
        j = num_pisos - 2 - u.piso();
        k = u.plaza() + 2 + l;
        while (k < (num_plazas + 2) and h[j][k] == ' ' and h[j + 1][k] != ' ') {
        
            ++derecha;
            ++k;
        }
        k = u.plaza() + 1;
        while (k > 1 and h[j][k] == ' ' and h[j + 1][k] != ' ') {
        
            ++izquierda;
            --k;
        }
        if (izquierda > 0) {
        
            Ubicacion u3 (u.hilera(), u.plaza() - izquierda, u.piso() + 1);
            s = Segmento (u3, izquierda + l + derecha);
            velem.push_back(s);
            s = Segmento (u3, izquierda);
            vseg.push_back(s);
            if (derecha > 0) {
            
                Ubicacion u4 (u.hilera(), u.plaza() + l, u.piso() + 1);
                s = Segmento (u4, derecha);
                vseg.push_back(s);
            }
        }
        else {
        
            Ubicacion u5 (u.hilera(), u.plaza(), u.piso() + 1);
            s = Segmento (u5, l + derecha);
            velem.push_back(s);
            if (derecha > 0) {
            
                Ubicacion u4 (u.hilera(), u.plaza() + l, u.piso() + 1);
                s = Segmento (u4, derecha);
                vseg.push_back(s);
            }
        }
    }
    almacenaje.actualizar_huecos (vseg, velem);
}

//Modificadoras

void Terminal::insertar_contenedor (const Contenedor& c) {
    
    Ubicacion u;
    int l = c.longitud();
    string m;
    m = c.matricula();
    u = almacenaje.hueco_mas_adecuado (c);
    u.print();
    cout << endl;
    Hilera hilera;
    hilera = AreaDeAlmacenaje [u.hilera()];
    for (int i = 0; i < l; ++i) {
    
        int j = num_pisos - 1 - u.piso();
        int k = u.plaza() + 2 + i;
        hilera[j][k] = m[0];
    }
    AreaDeAlmacenaje [u.hilera()] = hilera;
    buscar_huecos_i (u, c.longitud());
}

void Terminal::retirar_contenedor (const string& m) {
    
    Segmento s;
    s = almacenaje.donde(m);
    int l;
    l = s.longitud();
    Ubicacion u;
    u = s.ubic();
    Hilera hilera;
    hilera = AreaDeAlmacenaje[u.hilera()];
    for (int i = 0; i < l; ++i) {
        
        int j = num_pisos - 1 - u.piso();
        int k = u.plaza() + 2 + i;
        hilera[j][k] = ' ';
    }
    AreaDeAlmacenaje[u.hilera()] = hilera;
    buscar_huecos_r (u, l);
    almacenaje.retirar_contenedor (m);
}

//Consultoras

int Terminal::hileras() const {
    
    return num_hileras;
}

int Terminal::plazas() const {
    
    return num_plazas;
}

int Terminal::pisos() const {
    
    return num_pisos;
}

Ubicacion Terminal::donde (const string& m) const {
    
    Segmento s;
    Ubicacion u;
    s = almacenaje.donde (m);
    u = s.ubic();
    return u;
}

int Terminal::longitud (const string& m) const {
    
    int l;
    l = almacenaje.longitud (m);
    return l;
}

string Terminal::matricula (const Ubicacion& u) const {
    
    string s;
    Hilera h;
    h = AreaDeAlmacenaje[u.hilera()];
    if (h [num_pisos - 1 - u.piso()][u.plaza() + 2] == ' ') s = "-1";
    else s = almacenaje.matricula (u);
    return s;
}

bool Terminal::existe_contenedor (const string& m) const {
    
    bool existe;
    existe = almacenaje.existe_contenedor (m);
    return existe;
}
//Salidas

void Terminal::representar_AreaDeAlmacenaje() const {
    
    for (int i = 0; i < num_hileras; ++i) {
        
        cout << "hilera " << i << endl;
        Hilera hilera;
        hilera = AreaDeAlmacenaje[i];
        for (int j = 0; j < num_pisos + 1; ++j) {
            
            for (int k = 0; k < num_plazas + 2; ++k) {
                
                cout << hilera[j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}

void Terminal::escribir_ContenedoresAlmacenaje() const {
    
    almacenaje.escribir_ContenedoresAlmacenaje();
    cout << endl;
}

void Terminal::escribir_Huecos() const {
    
    almacenaje.escribir_Huecos();
    cout << endl;
}

void Terminal::escribir_AreaDeEspera() const {
    
    espera.escribir_AreaDeEspera();
    cout << endl;
}
