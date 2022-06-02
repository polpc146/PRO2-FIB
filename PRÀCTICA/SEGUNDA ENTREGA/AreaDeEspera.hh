/**
 * @file AreaDeEspera.hh
 * @date 14/11/2020
 * @author Pérez Castillo, Pol
 * @brief Especificación de la clase Espera
 */

#ifndef AREA_DE_ESPERA
#define AREA_DE_ESPERA

#include "Contenedor.hh"
#include "Ubicacion.hh"
#include "Segmento.hh"
#include <list>

using namespace std;

/** 
 * @class Espera
 * @brief Representa un area de espera de una terminal de contenedores de carga
 */
class Espera {
    
private:
    
    list <Contenedor> AreaDeEspera;
    
public:
    
    //Constructoras
    
    /**
     * @brief Creadora sin argumentos
     *  \pre <em>Cierto</em>
     *  \post El resultado es un area de espera vacío
     */
    Espera();
    
     /**
     * @brief Creadora de copia
     *  \pre <em>Cierto</em>
     *  \post El resultado es un area de espera con los mismos atributos que <em>e</em>
     */
    Espera (const Espera& e);
    
    //Destructora
    
    /**
     * @brief Destructora
     *  \pre <em>Cierto</em>
     *  \post Destruye un objeto Espera
     */
    ~Espera();
    
    //Salida
    
    /**
     * @brief Operación de escritura del area de espera
     *  \pre <em>Cierto</em>
     *  \post Se escriben los Contenedores del area de espera en orden de salida uno encima de otro
     */
    void escribir_AreaDeEspera() const;
};

#endif

