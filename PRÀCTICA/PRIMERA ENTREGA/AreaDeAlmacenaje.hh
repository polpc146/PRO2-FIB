#ifndef AREA_DE_ALMACENAJE
#define AREA_DE_ALMACENAJE

#include "Contenedor.hh"
#include "Ubicacion.hh"
#include "Segmento.hh"
#include <map>
#include <list>

using namespace std;

class Almacenaje {
    
private:
    
    map <string, Segmento> ContenedoresAlmacenaje;
    
    list <Segmento> Huecos;
    
    void actualizar_huecos();
    
public:
    
    //Constructoras
    
    Almacenaje();
    
    Almacenaje (int N, int M, int H);
    
    Almacenaje (const Almacenaje& a);
    
    //Destructora
    
    ~Almacenaje();
};

#endif
