/**
 * @file AreaDeAlmacenaje.hh
 * @date 14/11/2020
 * @author Pérez Castillo, Pol
 * @brief Especificación de la clase Almacenaje
 */

#ifndef AREA_DE_ALMACENAJE
#define AREA_DE_ALMACENAJE

#include "Contenedor.hh"
#include "Ubicacion.hh"
#include "Segmento.hh"
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

/** 
 * @class Almacenaje
 * @brief Representa un area de almacenaje de una terminal de contenedores de carga
 */
class Almacenaje {
    
private:
    
    map <string, Segmento> ContenedoresAlmacenaje;
    
    set <Segmento> Huecos;

public:
    
    //Constructoras
    
    /**
     * @brief Creadora sin argumentos
     *  \pre <em>Cierto</em>
     *  \post El resultado es un area de almacenaje vacío
     */
    Almacenaje();
    
    /**
     * @brief Creadora con atributos
     *  \pre <em>Cierto</em>
     *  \post El resultado es un area de almacenaje vacío con un conjunto de los primeros huecos inicializado
     */
    Almacenaje (int N, int M);
    
     /**
     * @brief Creadora de copia
     *  \pre <em>Cierto</em>
     *  \post El resultado es un area de almacenaje con los mismos atributos que <em>a</em>
     */
    Almacenaje (const Almacenaje& a);
    
    //Destructora
    
    /**
     * @brief Destructora
     *  \pre <em>Cierto</em>
     *  \post Destruye un objeto Almacenaje
     */
    ~Almacenaje();

    //Modificadoras   
    
    /**
     * @brief Retira un Contenedor del area de almacenaje
     *  \pre Existe el Contenedor con matrícula <em>m</em> en el area de almacenaje
     *  \post Se ha retirado el Contenedor con matrícula <em>m</em> del area de almacenaje
     */
    void retirar_contenedor (const string& m);

    /**
     * @brief Actualiza los huecos del area de almacenaje
     *  \pre <em>/Cierto</em>
     *  \post Añade los elementos de <em>vseg</em> y elemina los de <em>velem</em> de Huecos
     */
    void actualizar_huecos (const vector<Segmento>& vseg, const vector<Segmento>& velem); 
    
    //Consultoras
    
    /**
     * @brief Consultora del Segmento de una matrícula
     *  \pre <em>Cierto</em>
     *  \post El resultado es la Ubicacion <<em>-1</em>,<em>0</em>,<em>0</em>> y su longitud si está en el area de espera, es <<em>-1</em>,<em>-1</em>,<em>-1</em>> y longitud 0 si no está en el area de espera ni en el area de almacenaje, o es la Ubicacion con menor número de plaza que ocupa el Contenedor con matrícula <em>m</em> y su longitud
     */
    Segmento donde (const string& m) const;
    
    /**
     * @brief Consultora de longitud
     *  \pre Existe un Contenedor con matrícula <em>m</em>
     *  \post El resultado es la longitud del Contenedor con matrícula <em>m</em>
     */
    int longitud (const string& m) const;
    
    /**
     * @brief Consultora de una matrícula según su Ubicacion
     *  \pre La Ubicacion <em>u</em> pertenece al area de almacenaje y hay un contenedor en esa Ubicacion
     *  \post El resultado es la matrícula del Contenedor
     */
    string matricula (const Ubicacion& u) const;

    /**
     * @brief Encuentra el hueco más adecuado según la estrategia BEST_FIT para insertar un Contenedor
     *  \pre La lista de huecos <em>h</em> no está vacía y 1<=l<=3
     *  \post El resultado es la Ubicacion <<em>-1</em>,<em>0</em>,<em>0</em>> si no hay un hueco disponible en el area de almacenaje y, por lo tanto, se colocará el Contenedor en el area de espera; en caso contrario el resultado es la Ubicacion dónde empieza el hueco con menor <em>longitud</em>, número menor de <em>hilera</em> y número menor de <em>plaza</em> posible en la que es posible insertar el contenedor 
     */
    Ubicacion hueco_mas_adecuado (const Contenedor& c);
    
    /**
     * @brief Consultora de la existencia del Contenedor con matricula <em>m</em> en el area de almacenaje
     *  \pre <em>Cierto</em>
     *  \post El resultado indica <em>Cierto</em> si existe un Contenedor con matrícula <em>m</em> en el area de almacenaje, en caso contrario indica <em>Falso</em>
     */
    bool existe_contenedor (const string& m) const;
    
    //Salidas
    
    /**
     * @brief Operación de escritura de los contenedores del area de almacenaje
     *  \pre <em>Cierto</em>
     *  \post Se escribe la matrícula del Contenedor seguida de su Ubicacion y su longitud en orden ascendente de matrícula y una encima de otra
     */
    void escribir_ContenedoresAlmacenaje() const;
    
    /**
     * @brief Operación de escritura de los huecos del area de almacenaje
     *  \pre <em>Cierto</em>
     *  \post Se escriben los Segmentos de los huecos que hay en el area de almacenaje uno encima de otro
     */
    void escribir_Huecos() const;
};

#endif
