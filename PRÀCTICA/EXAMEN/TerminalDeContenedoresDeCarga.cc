#include "TerminalDeContenedoresDeCarga.hh"
#include <iostream>

using namespace std;

//Constructoras

Terminal::Terminal (int N, int M, int H) {
    
    num_hileras = N;
    num_plazas = M;
    num_pisos = H;
    AreaDeAlmacenaje = vector <Hilera> (N, Hilera (H + 1, Piso (M + 2)));
    for (int i = 0; i < N; ++i) {
        
        for (int j = 0; j < H + 1; ++j) {
            
            for (int k = 0; k < M + 2; ++k) {
                
                AreaDeAlmacenaje[i][j][k] = " ";
                if (k == 0) {
                    
                    if (j == H) AreaDeAlmacenaje[i][j][k] = " ";
                    
                    else {
                        
                        int num = (H - 1 - j) % 10;
                        AreaDeAlmacenaje[i][j][k] = to_string(num);
                    }
                }
                
                if (j == H and k > 1) {
                    
                    int num = (k - 2) % 10;
                    AreaDeAlmacenaje[i][j][k] = to_string(num);
                }
            }
        }
    }
    almacenaje = Almacenaje (N, M);
    espera = Espera();
}

//Destructora

Terminal::~Terminal() {}

//Acciones privadas

void Terminal::buscar_huecos_i (const Ubicacion& u, int l) {
    
    Segmento s;
    int derecha = 0;
    int i = u.hilera();
    int k = u.plaza() + 2 + l;
    int j = num_pisos - 1 - u.piso();
    while (k < (num_plazas + 2) and AreaDeAlmacenaje[i][j][k] == " " and AreaDeAlmacenaje[i][j + 1][k] != " ") {
        
        ++derecha;
        ++k;
    }
    if (derecha > 0) {
            
        Ubicacion u1 (u.hilera(), u.plaza() + l, u.piso());
        s = Segmento (u1, derecha);
        almacenaje.nuevo_hueco (s);
    }
    if (u.piso() < num_pisos - 1) {
            
        int izquierda = 0;
        derecha = 0;
        j = num_pisos - 2 - u.piso();
        k = u.plaza() + 2 + l;
        while (k < (num_plazas + 2) and AreaDeAlmacenaje[i][j][k] == " " and AreaDeAlmacenaje[i][j + 1][k] != " ") {
            
            ++derecha;
            ++k;
        }
        k = u.plaza() + 1;
        while (k > 1 and AreaDeAlmacenaje[i][j][k] == " " and AreaDeAlmacenaje[i][j + 1][k] != " ") {
                
            ++izquierda;
            --k;
        }
        Ubicacion u2 (u.hilera(), u.plaza() - izquierda, u.piso() + 1);
        s = Segmento (u2, izquierda + l + derecha);
        almacenaje.nuevo_hueco (s);
        if (derecha > 0) {
            Ubicacion u3 (u.hilera(), u.plaza() + l, u.piso() + 1);
            s = Segmento (u3, derecha);
            almacenaje.eliminar_hueco (s);
        }
        if (izquierda > 0) {
            Ubicacion u4 (u.hilera(), u.plaza() - izquierda, u.piso() + 1);
            s = Segmento (u4, izquierda);
            almacenaje.eliminar_hueco (s);
        }
    }
}

void Terminal::buscar_huecos_r (const Ubicacion& u, int l) {
    
    Segmento s;
    int derecha = 0;
    int izquierda = 0;
    int i = u.hilera();
    int j = num_pisos - 1 - u.piso();
    int k = u.plaza() + 2 + l;
    while (k < (num_plazas + 2) and AreaDeAlmacenaje[i][j][k] == " " and AreaDeAlmacenaje[i][j + 1][k] != " ") {
        
        ++derecha;
        ++k;
    }
    k = u.plaza() + 1;
    while (k > 1 and AreaDeAlmacenaje[i][j][k] == " " and AreaDeAlmacenaje[i][j + 1][k] != " ") {
        
        ++izquierda;
        --k;
    }
    if (derecha > 0) {
        
        Ubicacion u1 (u.hilera(), u.plaza() + l, u.piso());
        s = Segmento (u1, derecha);
        almacenaje.eliminar_hueco (s);
    }
    Ubicacion u2 (u.hilera(), u.plaza() - izquierda, u.piso());
    if (izquierda > 0) {
        
        s = Segmento (u2, izquierda);
        almacenaje.eliminar_hueco (s);
    }
    s = Segmento (u2, izquierda + l + derecha);
    almacenaje.nuevo_hueco (s);
    if (u.piso() < num_pisos - 1) {
    
        derecha = 0;
        izquierda = 0;
        j = num_pisos - 2 - u.piso();
        k = u.plaza() + 2 + l;
        while (k < (num_plazas + 2) and AreaDeAlmacenaje[i][j][k] == " " and AreaDeAlmacenaje[i][j + 1][k] != " ") {
        
            ++derecha;
            ++k;
        }
        k = u.plaza() + 1;
        while (k > 1 and AreaDeAlmacenaje[i][j][k] == " " and AreaDeAlmacenaje[i][j + 1][k] != " ") {
        
            ++izquierda;
            --k;
        }
        if (izquierda > 0) {
        
            Ubicacion u3 (u.hilera(), u.plaza() - izquierda, u.piso() + 1);
            s = Segmento (u3, izquierda + l + derecha);
            almacenaje.eliminar_hueco (s);
            s = Segmento (u3, izquierda);
            almacenaje.nuevo_hueco (s);
            if (derecha > 0) {
            
                Ubicacion u4 (u.hilera(), u.plaza() + l, u.piso() + 1);
                s = Segmento (u4, derecha);
                almacenaje.nuevo_hueco (s);
            }
        }
        else {
        
            Ubicacion u5 (u.hilera(), u.plaza(), u.piso() + 1);
            s = Segmento (u5, l + derecha);
            almacenaje.eliminar_hueco (s);
            if (derecha > 0) {
            
                Ubicacion u4 (u.hilera(), u.plaza() + l, u.piso() + 1);
                s = Segmento (u4, derecha);
                almacenaje.nuevo_hueco (s);
            }
        }
    }
}

//Modificadoras

void Terminal::insertar_contenedor (const Contenedor& c) {
    
    int l = c.longitud();
    string m = c.matricula();
    Ubicacion u = almacenaje.hueco_mas_adecuado (c);
    u.print();
    cout << endl;
    Ubicacion uesp (-1,0,0);
    if (u == uesp) {
        
        espera.insertar_contenedor(c);
    }
    else {
        
        int i = u.hilera();
        int j = num_pisos - 1 - u.piso();
        int k = u.plaza() + 2;
        for (int x = 0; x < l; ++x) {
    
            AreaDeAlmacenaje[i][j][k] = m;
            ++k;
        }   
        buscar_huecos_i (u, l);
        if (espera.hay_contenedores()) {
        
            insertar_AreaDeEspera();
        }
    }
}

void Terminal::retirar_contenedor (const string& m) {
    
    Segmento s = almacenaje.donde(m);
    Ubicacion uesp(-1,0,0);
    int l = s.longitud();
    if (s.ubic() == uesp) {
        
        Contenedor c (m, l);
        espera.eliminar_contenedor(c);
    }
    else {
        
        Ubicacion u = s.ubic();
        if (u.piso() < num_pisos - 1) {
            
            piso_superior (u, l, m);
        }
        int i = u.hilera();
        int j = num_pisos - 1 - u.piso();
        int k = u.plaza() + 2;
        for (int x = 0; x < l; ++x) {
        
            AreaDeAlmacenaje[i][j][k] = " ";
            ++k;
        }
        buscar_huecos_r (u, l);
        if (espera.hay_contenedores()) {
            
            insertar_AreaDeEspera();
        }
    }
    almacenaje.retirar_contenedor (m);
}

void Terminal::piso_superior (const Ubicacion& u, int l, const string& m) {
    
    if (u.piso() < num_pisos - 1) {
        
        int i = u.hilera();
        int j = num_pisos - 2 - u.piso();
        int k = u.plaza() + 2;
        for (int x = 0; x < l; ++x) {
        
            if (AreaDeAlmacenaje[i][j][k] != " ") {
                
                Ubicacion u2 (u.hilera(), u.plaza() + x, u.piso() + 1);
                string s = AreaDeAlmacenaje[i][j][k];
                Segmento seg = almacenaje.donde (s);
                piso_superior (seg.ubic(), seg.longitud(), m);
            }
            ++k;
        }
    }
    string mat = AreaDeAlmacenaje[u.hilera()][num_pisos - 1 - u.piso()][u.plaza() + 2];
    if (mat != m) {
        
        int i = u.hilera();
        int j = num_pisos - 1 - u.piso();
        int k = u.plaza() + 2;
        for (int x = 0; x < l; ++x) {
    
            AreaDeAlmacenaje[i][j][k] = " ";
            ++k;
        }
        buscar_huecos_r (u, l);
        almacenaje.modificar_ubicacion (mat, l);
        Contenedor c (mat, l);
        espera.insertar_contenedor (c);
    }
}

void Terminal::insertar_AreaDeEspera() {
    
    Contenedor c, d;
    d = espera.primer_contenedor();
    bool b = true;
    d = espera.contenedor_disponible(d,b);
    Ubicacion u, uesp(-1,0,0);
    while (d != c) {
        
        u = almacenaje.hueco_mas_adecuado (d);
        if (u == uesp) {
            
            b = false;
        }
        else {
            
            int i = u.hilera();
            int j = num_pisos - 1 - u.piso();
            int k = u.plaza() + 2;
            string m = d.matricula();
            int l = d.longitud();
            for (int x = 0; x < l; ++x) {
    
                AreaDeAlmacenaje[i][j][k] = m;
                ++k;
            }   
            buscar_huecos_i (u, l);
            espera.eliminar_contenedor (d);
            Segmento seg (u, l);
            almacenaje.actualizar_ubicacion (m, seg);
            b = true;
        }
        d = espera.contenedor_disponible(d, b);     
    }
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
    
    Segmento s = almacenaje.donde (m);
    return s.ubic();
}

int Terminal::longitud (const string& m) const {
    
    return almacenaje.longitud (m);
}

string Terminal::matricula (const Ubicacion& u) const {
    
    string s = AreaDeAlmacenaje[u.hilera()][num_pisos - 1 - u.piso()][u.plaza() + 2];
    if (s == " ") s = "-1";
    return s;
}

bool Terminal::existe_contenedor (const string& m) const {
    
    return almacenaje.existe_contenedor (m);
}
//Salidas

void Terminal::representar_AreaDeAlmacenaje() const {
    
    for (int i = 0; i < num_hileras; ++i) {
        
        cout << "hilera " << i << endl;
        for (int j = 0; j < num_pisos + 1; ++j) {
            
            for (int k = 0; k < num_plazas + 2; ++k) {
                
                cout << AreaDeAlmacenaje[i][j][k][0];
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
