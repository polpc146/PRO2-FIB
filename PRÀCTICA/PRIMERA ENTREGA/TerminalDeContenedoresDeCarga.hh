/**
 * @file TerminalDeContenedoresDeCarga.hh
 * @date 31/10/2020
 * @author Pérez Castillo, Pol
 * @brief Especificación de la clase Terminal
 */

#ifndef TERMINAL_DE_CONTENEDORES_DE_CARGA
#define TERMINAL_DE_CONTENEDORES_DE_CARGA

#include "AreaDeAlmacenaje.hh"
#include "AreaDeEspera.hh"
#include <vector>

using namespace std;

typedef vector <Contenedor> Piso;
typedef vector <Piso> Hilera;

/** 
 * @class Terminal
 * @brief Representa una Terminal de N hileras, M plazas y H pisos
 */
class Terminal {
    
private:
    
    vector <Hilera> AreaDeAlmacenaje;
    
public:
    
    //Constructoras
    
    /**
     * @brief Creadora sin argumentos
     *  \pre <em>Cierto</em>
     *  \post El resultado es una Terminal de cero hileras, cero plazas y cero pisos
     */
    Terminal();
    
    /**
     * @brief Creadora con atributos
     *  \pre <em>Cierto</em>
     *  \post El resultado es una Terminal de <em>N</em> hileras, <em>M</em> plazas y <em>H</em> pisos, dos listas <em>AreaDeEspera</em> y <em>ContenedoresAlmacenaje</em> vacías y una lista de <em>Huecos</em> inicializada
     */
    Terminal (int N, int M, int H);
    
    /**
     * @brief Creadora de copia
     *  \pre <em>Cierto</em>
     *  \post El resultado es una Terminal con las mismas hileras, plazas y pisos que <em>t</em>
     */
    Terminal (const Terminal& t);
    
    //Destructora
    
    /**
     * @brief Destructora
     *  \pre <em>Cierto</em>
     *  \post Destruye un objeto Terminal
     */
    ~Terminal();
    
    //Modificadoras
    
    /**
     * @brief Añade un Contenedor del area de espera al area de almacenaje
     *  \pre La lista <em>AreaDeEspera</em> no está vacía
     *  \post Se han inserido todos los Contenedores (empezando por el último que entró al area de espera) al <em>AreaDeAlmacenaje</em> si tienen un hueco disponible y se actualiza la lista de Huecos si se ha conseguido insertar algún Contenedor
     */
    void insertar_AreaDeEspera (const list <Contenedor>& vespera);
    
    /**
     * @brief Añade un Contenedor a la Terminal
     *  \pre No existe el Contenedor <em>c</em> en la Terminal
     *  \post Se inserta el Contenedor en el <em>AreaDeEspera</em> si no tiene hueco, en caso contrario se coloca en el <em>AreaDeAlmacenaje</em> en la Ubicacion más adecuada según la estrategia BEST_FIT, se actualizan las listas AreaDeEspera, ContenedoresAlmacenaje y Huecos y se recorre el AreaDeEspera por si se puede colocar algún Contenedor más. En ambos casos se imprime por pantalla la Ubicacion donde se ha colocado
     */
    void insertar_contenedor (const Contenedor& c);
    
    /**
     * @brief Retira un Contenedor de la Terminal
     *  \pre Existe el Contenedor con matrícula <em>m</em> en la Terminal
     *  \post Se ha retirado el Contenedor con matrícula <em>m</em> de la Terminal, se actualizan las listas AreaDeEspera, ContenedoresAlmacenaje y Huecos y se recorre el AreaDeEspera por si se puede colocar algún Contenedor más. 
     */
    void retirar_contenedor (const string& m);
    
     /**
     * @brief Detecta los Contenedores que hay encima de un Segmento
     *  \pre El Segmento <em>s</em> indica la Ubicacion inicial y la longitud de un Contenedor
     *  \post Se han movido los Contenedores de los pisos superiores al Segmento <em>s</em> al area de espera
     */
    void Piso_superior (const Segmento& s);
    
    //Consultoras
    
    /**
     * @brief Consultora de las hileras de una Terminal
     *  \pre <em>Cierto</em>
     *  \post El resultado es el número de hileras de la Terminal p.i
     */
    int hileras() const;
    
    /**
     * @brief Consultora de las plazas por hilera de una Terminal
     *  \pre <em>Cierto</em>
     *  \post El resultado es el número de plazas por hilera de la Terminal p.i
     */
    int plazas() const;
    
    /**
     * @brief Consultora de los pisos por plaza de una hilera de una Terminal
     *  \pre <em>Cierto</em>
     *  \post El resultado es el número de pisos por plaza de una hilera de la Terminal p.i
     */
    int pisos() const;
    
    /**
     * @brief Consultora de la Ubicacion de una matrícula
     *  \pre <em>Cierto</em>
     *  \post El resultado es la Ubicacion <<em>-1</em>,<em>0</em>,<em>0</em>> si está en el area de espera, es <<em>-1</em>,<em>-1</em>,<em>-1</em>> si no está en el area de espera ni en el area de almacenaje, o es la Ubicacion con menor número de plaza que ocupa el Contenedor con matrícula <em>m</em>
     */
    Ubicacion donde (const string& m) const;
    
    /**
     * @brief Primera consultora de longitud
     *  \pre Existe un Contenedor con matrícula <em>m</em>
     *  \post El resultado es la longitud del Contenedor con matrícula <em>m</em>
     */
    int longitud (const string& m) const;
    
    /**
     * @brief Segunda consultora de longitud
     *  \pre La Ubicacion <em>u</em> es la Ubicacion con menor número de plaza que ocupa el Contenedor con matrícula <em>m</em>
     *  \post El resultado es la longitud del Contenedor con matrícula <em>m</em>
     */
    int longitud2 (const string& m, const Ubicacion& u) const;
    
    /**
     * @brief Consultora de una matrícula según su Ubicacion
     *  \pre La Ubicacion <em>u</em> pertenece al area de almacenaje
     *  \post Si hay un Contenedor ocupando la Ubicacion <em>u</em>, el resultado es la matricula del Contenedor, en caso contrario el resultado es -1
     */
    string matricula (const Ubicacion& u) const;
    
    /**
     * @brief Encuentra el hueco más adecuado según la estrategia BEST_FIT para insertar un Contenedor
     *  \pre La lista de huecos <em>h</em> no está vacía y 1<=l<=3
     *  \post El resultado es la Ubicacion <<em>-1</em>,<em>0</em>,<em>0</em>> si no hay un hueco disponible en el area de almacenaje y, por lo tanto, se colocará el Contenedor en el area de espera; en caso contrario el resultado es la Ubicacion dónde empieza el hueco con menor <em>longitud</em>, número menor de <em>hilera</em> y número menor de <em>plaza</em> posible en la que es posible insertar el contenedor 
     */
    Ubicacion hueco_mas_adecuado (const list <Segmento>& h, int l) const;
    
    /**
     * @brief Consultora de la existencia del Contenedor con matricula <em>m</em> en la terminal
     *  \pre <em>Cierto</em>
     *  \post El resultado indica <em>Cierto</em> si existe un Contenedor con matricula <em>m</em> en la Terminal, en caso contrario indica <em>Falso</em>
     */
    bool existe_contenedor (const string& m) const;
    
    //Escritura
    
    /**
     * @brief Operación de escritura del area de espera
     *  \pre <em>Cierto</em>
     *  \post Se escriben los Contenedores del area de espera en orden de salida uno encima de otro
     */
    void escribir_AreaDeEspera() const;
    
    /**
     * @brief Operación de escritura de los contenedores de la terminal
     *  \pre <em>Cierto</em>
     *  \post Se escribe la matrícula del Contenedor seguida de su Ubicacion y su longitud en orden ascendente de matrícula y una encima de otra
     */
    void escribir_ContenedoresAlmacenaje() const;
    
    /**
     * @brief Operación de represtentación bidimensional de una terminal por hileras
     *  \pre <em>Cierto</em>
     *  \post Se representa cada hilera en forma de matriz con la inicial de los contenedores tantas veces como su longitud
     */
    void representar_AreaDeAlmacenaje() const;
    
    /**
     * @brief Operación de escritura de los huecos del area de almacenaje
     *  \pre <em>Cierto</em>
     *  \post Se escriben los Segmentos de los huecos que hay en el area de almacenaje uno encima de otro
     */
    void escribir_Huecos() const;
};

#endif
