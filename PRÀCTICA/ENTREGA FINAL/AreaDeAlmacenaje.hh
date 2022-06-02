/**
 * @file AreaDeAlmacenaje.hh
 * @date 14/11/2020
 * @author Pérez Castillo, Pol
 * @brief Especificación de la clase Almacenaje
 */

#ifndef AREA_DE_ALMACENAJE
#define AREA_DE_ALMACENAJE

#include "Contenedor.hh"
#include "Segmento.hh"
#include <map>
#include <set>
#include <vector>

using namespace std;

/** 
 * @class Almacenaje
 * @brief Representa un área de almacenaje de una terminal de contenedores de carga
 */
class Almacenaje {
    
private:
    
    /**
     * @brief Diccionario para guardar todos los contenedores con su respectiva ubicación de la terminal
     */
    map <string, Segmento> ContenedoresAlmacenaje;
    
    /**
     * @brief Conjunto para guardar los huecos que hay en cada momento del área de almacenaje
     */
    set <Segmento> Huecos;

public:
    
    //Constructoras
    
    /**
     * @brief Creadora sin argumentos
     *  \pre <em>Cierto</em>
     *  \post El resultado es un área de almacenaje vacío
     */
    Almacenaje();
    
    /**
     * @brief Creadora con atributos
     *  \pre <em>Cierto</em>
     *  \post El resultado es un área de almacenaje vacío con un conjunto de los primeros huecos inicializado
     */
    Almacenaje (int N, int M);
    
    //Destructora
    
    /**
     * @brief Destructora
     *  \pre <em>Cierto</em>
     *  \post Destruye un objeto Almacenaje
     */
    ~Almacenaje();

    //Modificadoras   
    
    /**
     * @brief Retira un Contenedor del área de almacenaje
     *  \pre Existe el Contenedor con matrícula <em>m</em> en el área de almacenaje
     *  \post Se ha retirado el Contenedor con matrícula <em>m</em> del área de almacenaje
     */
    void retirar_contenedor (const string& m);
    
    /**
     * @brief Actualiza los huecos del área de almacenaje
     *  \pre <em>s</em> no existe en el conjunto
     *  \post Añade el elemento <em>s</em> al conjunto Huecos
     */
    void nuevo_hueco (const Segmento& s);
    
    /**
     * @brief Actualiza los huecos del área de almacenaje
     *  \pre <em>s</em> existe en el conjunto
     *  \post Elemina el elemento <em>s</em> al conjunto Huecos
     */
    void eliminar_hueco (const Segmento& s);
    
    /**
     * @brief Modifica la ubicacion de un Contenedor
     *  \pre <em>m</em> existe en la terminal
     *  \post El contenedor con matricula <em>m</em> se actualiza con la ubicación del área de espera
     */
    void modificar_ubicacion (const string& m, int l);
    
    /**
     * @brief Modifica la ubicación de un Contenedor
     *  \pre <em>m</em> existe en la terminal y la ubicacion de <em>s</em> pertenece al área de almacenaje
     *  \post El contenedor con matrícula <em>m</em> está actualizado con su nueva ubicación
     */
    void actualizar_ubicacion (const string& m, const Segmento& s);
    
    //Consultoras
    
    /**
     * @brief Consultora del Segmento de una matrícula
     *  \pre <em>Cierto</em>
     *  \post El resultado es la Ubicacion <<em>-1</em>,<em>0</em>,<em>0</em>> y su longitud si está en el área de espera, es <<em>-1</em>,<em>-1</em>,<em>-1</em>> y longitud 0 si no está en el area de espera ni en el área de almacenaje, o es la ubicación con menor número de plaza que ocupa el Contenedor con matrícula <em>m</em> y su longitud
     */
    Segmento donde (const string& m) const;
    
    /**
     * @brief Consultora de longitud
     *  \pre Existe un Contenedor con matrícula <em>m</em> en la terminal
     *  \post El resultado es la longitud del Contenedor con matrícula <em>m</em>
     */
    int longitud (const string& m) const;

    /**
     * @brief Encuentra el hueco más adecuado según la estrategia BEST_FIT para insertar un Contenedor
     *  \pre La lista de huecos <em>h</em> no está vacía y 1<=l<=3
     *  \post El resultado es la ubicación <<em>-1</em>,<em>0</em>,<em>0</em>> si no hay un hueco disponible en el área de almacenaje y, por lo tanto, se colocará el Contenedor en el área de espera; en caso contrario el resultado es la ubicación dónde empieza el hueco con menor <em>longitud</em>, número menor de <em>hilera</em> y número menor de <em>plaza</em> posible en la que es posible insertar el contenedor 
     */
    Ubicacion hueco_mas_adecuado (const Contenedor& c);
    
    /**
     * @brief Consultora de la existencia del Contenedor con matricula <em>m</em> en el área de almacenaje
     *  \pre <em>Cierto</em>
     *  \post El resultado indica <em>Cierto</em> si existe un Contenedor con matrícula <em>m</em> en el área de almacenaje o área de espera, en caso contrario indica <em>Falso</em>
     */
    bool existe_contenedor (const string& m) const;
    
    //Salidas
    
    /**
     * @brief Operación de escritura de los contenedores del área de almacenaje
     *  \pre <em>Cierto</em>
     *  \post Se escribe la matrícula del Contenedor seguida de su Ubicación y su longitud en orden ascendente de matrícula y una encima de otra
     */
    void escribir_ContenedoresAlmacenaje() const;
    
    /**
     * @brief Operación de escritura de los huecos del área de almacenaje
     *  \pre <em>Cierto</em>
     *  \post Se escriben los Segmentos de los huecos que hay en el área de almacenaje uno encima de otro
     */
    void escribir_Huecos() const;
};

#endif
