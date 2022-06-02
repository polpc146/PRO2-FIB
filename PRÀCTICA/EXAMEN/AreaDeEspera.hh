/**
 * @file AreaDeEspera.hh
 * @date 14/11/2020
 * @author Pérez Castillo, Pol
 * @brief Especificación de la clase Espera
 */

#ifndef AREA_DE_ESPERA
#define AREA_DE_ESPERA

#include "Contenedor.hh"
#include "Segmento.hh"
#include <list>

using namespace std;

/** 
 * @class Espera
 * @brief Representa un área de espera de una terminal de contenedores de carga
 */
class Espera {
    
private:
    
    /**
     * @brief Lista para guardar los contenedores que hay en el área de espera
     */
    list <Contenedor> AreaDeEspera;
    
public:
    
    //Constructoras
    
    /**
     * @brief Creadora sin argumentos
     *  \pre <em>Cierto</em>
     *  \post El resultado es un área de espera vacío
     */
    Espera();
    
    //Destructora
    
    /**
     * @brief Destructora
     *  \pre <em>Cierto</em>
     *  \post Destruye un objeto Espera
     */
    ~Espera();
    
    //Modificadoras
    
    /**
     * @brief Añade un Contenedor al área de espera
     *  \pre <em>c</em> no existe en el área de espera
     *  \post El Contenedor <em>c</em> ocupa la primera posicion de la lista AreaDeEspera
     */
    void insertar_contenedor (const Contenedor& c);
    
    /**
     * @brief Elimina un Contenedor del área de espera
     *  \pre <em>c</em> existe en el área de espera
     *  \post El Contenedor <em>c</em> no esta en la lista AreaDeEspera
     */
    void eliminar_contenedor (const Contenedor& c);
    
    //Consultoras
    
    /**
     * @brief Consultora de si hay contenedores en el área de espera
     *  \pre <em>Cierto</em>
     *  \post <em>Cierto</em> si hay almenos un contenedor, <em>falso</em> en caso contrario
     */
    bool hay_contenedores() const;
    
    /**
     * @brief Consultora del primer contenedor del área de espera
     *  \pre La lista <em>AreaDeEspera</em> no está vacía
     *  \post Devuelve el primer contenedor del área de espera
     */
    Contenedor primer_contenedor() const;
    
    /**
     * @brief Consultora de los contenedores que hay en el área de espera esperando a ser insertados
     *  \pre <em>b</em> se pasa como <em>Cierto</em> si anteriormente se ha podido insertar un contenedor del área de espera o si es el primera vez que se consulta, se pasa como <em>Falso</em> si no se ha podido ubicar un contenedor anterior, <em>c</em> es el primer contenedor de la lista si es la primera llamada a la funcion o es el ultimo contenedor de la lista que se ha consultado
     *  \post <em>c</em> es el siguiente contenedor que tocará observar si cabe en el área de almacenaje o es un contenedor vacío si ya no hay más contenedores que analizar
     */
    Contenedor contenedor_disponible (const Contenedor& c, bool b) const;
    
    //Salida
    
    /**
     * @brief Operación de escritura del área de espera
     *  \pre <em>Cierto</em>
     *  \post Se escriben los Contenedores del área de espera en orden de salida uno encima de otro
     */
    void escribir_AreaDeEspera() const;
};

#endif

