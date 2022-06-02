#ifndef AREA_DE_ESPERA
#define AREA_DE_ESPERA

#include "Contenedor.hh"
#include "Ubicacion.hh"
#include "Segmento.hh"
#include <list>

using namespace std;

class Espera {
    
private:
    
    list <Contenedor> AreaDeEspera;
    
public:
    
    //Constructoras
    
    Espera();
    
    Espera (const Espera& e);
    
    //Destructora
    
    ~Espera();
};

#endif

