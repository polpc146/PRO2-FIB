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

using namespace std;

/** 
 * @class Terminal
 * @brief Representa una Terminal de contenedores de carga
 */
class Terminal {
    
private:
    
    typedef vector <string> Piso;
    typedef vector <Piso> Hilera;
    
    /**
     * @brief Vector de matrices para guardar en forma bidimensional la posición de los contenedores en su respectiva hilera
     */
    vector <Hilera> AreaDeAlmacenaje;
    
    /**
     * @brief Número de hileras por defecto en una terminal vacía
     */
    int num_hileras = -1;    
    
    /**
     * @brief Número de plazas por defecto en una terminal vacía
     */
    int num_plazas = -1;
    
    /**
     * @brief Número de pisos por defecto en una terminal vacía
     */
    int num_pisos = -1;
    
    /**
     * @brief Objeto almacenaje
     */
    Almacenaje almacenaje;
    
    /**
     * @brief Objeto espera
     */
    Espera espera;
    
    /**
     * @brief Actualiza los huecos despúes de una inserción
     *  \pre <em>u</em> es la ubicación donde se ha insertado el úlitmo contenedor y <em>l</em> es su longitud
     *  \post El conjunto de huecos del objeto almacenaje ha quedado actualizado con los huecos válidos después de la inserción
     */
    void buscar_huecos_i (const Ubicacion& u, int l);
    
    /**
     * @brief Actualiza los huecos después de una retirada
     *  \pre <em>u</em> es la ubicación donde se ha retirado el úlitmo contenedor y <em>l</em> es su longitud
     *  \post El conjunto de huecos del objeto almacenaje ha quedado actualizado con los huecos válidos después de la retirada
     */
    void buscar_huecos_r (const Ubicacion& u, int l);
    
public:
    
    //Constructoras
    
    /**
     * @brief Creadora con atributos
     *  \pre <em>Cierto</em>
     *  \post El resultado es una Terminal de <em>N</em> hileras, <em>M</em> plazas y <em>H</em> pisos, un área de almacenaje inicializado y un área de espera vacío
     */
    Terminal (int N, int M, int H);
    
    //Destructora
    
    /**
     * @brief Destructora
     *  \pre <em>Cierto</em>
     *  \post Destruye un objeto Terminal
     */
    ~Terminal();
    
    //Modificadoras
    
    /**
     * @brief Añade los Contenedores del área de espera al área de almacenaje
     *  \pre La lista <em>AreaDeEspera</em> no está vacía
     *  \post Se han inserido todos los Contenedores (empezando por el último que entró al área de espera) al <em>AreaDeAlmacenaje</em> si tienen un hueco disponible y se actualiza la lista de Huecos si se ha conseguido insertar algún Contenedor
     */
    void insertar_AreaDeEspera();
    
    /**
     * @brief Añade un Contenedor a la Terminal
     *  \pre No existe el Contenedor <em>c</em> en la Terminal
     *  \post Se inserta el Contenedor en el <em>AreaDeEspera</em> si no tiene hueco, en caso contrario se coloca en el <em>AreaDeAlmacenaje</em> en la Ubicacion más adecuada según la estrategia BEST_FIT, se actualizan AreaDeEspera, ContenedoresAlmacenaje y Huecos y se recorre el AreaDeEspera por si se puede colocar algún Contenedor más. En ambos casos se imprime por pantalla la Ubicacion donde se ha colocado
     */
    void insertar_contenedor (const Contenedor& c);
    
    /**
     * @brief Retira un Contenedor de la Terminal
     *  \pre Existe el Contenedor con matrícula <em>m</em> en la Terminal
     *  \post Se ha retirado el Contenedor con matrícula <em>m</em> de la Terminal, se actualizan AreaDeEspera, ContenedoresAlmacenaje y Huecos y se recorre el AreaDeEspera por si se puede colocar algún Contenedor más. 
     */
    void retirar_contenedor (const string& m);
    
     /**
     * @brief Detecta los Contenedores que hay encima de un Segmento
     *  \pre La Ubicacion <em>u</em> pertenece al area de almacenaje y <em>l</em> y <em>m</em> son los parámetros del Contenedor a retirar
     *  \post Se han movido los Contenedores de los pisos superiores al Segmento <em>s</em> al area de espera
     */
    void piso_superior (const Ubicacion& u, int l, const string& m);
    
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
     *  \post El resultado es la Ubicacion <<em>-1</em>,<em>0</em>,<em>0</em>> si está en el área de espera, es <<em>-1</em>,<em>-1</em>,<em>-1</em>> si no está en el área de espera ni en el área de almacenaje, o es la ubicación con menor número de plaza que ocupa el Contenedor con matrícula <em>m</em>
     */
    Ubicacion donde (const string& m) const;
    
    /**
     * @brief Primera consultora de longitud
     *  \pre Existe un Contenedor con matrícula <em>m</em> en la terminal
     *  \post El resultado es la longitud del Contenedor con matrícula <em>m</em>
     */
    int longitud (const string& m) const;
    
    /**
     * @brief Consultora de una matrícula según su Ubicacion
     *  \pre La ubicación <em>u</em> pertenece al area de almacenaje
     *  \post Si hay un Contenedor ocupando la Ubicacion <em>u</em>, el resultado es la matrícula del Contenedor, en caso contrario el resultado es -1
     */
    string matricula (const Ubicacion& u) const;
    
    /**
     * @brief Consultora de la existencia del Contenedor con matricula <em>m</em> en la terminal
     *  \pre <em>Cierto</em>
     *  \post El resultado indica <em>Cierto</em> si existe un Contenedor con matricula <em>m</em> en la Terminal, en caso contrario indica <em>Falso</em>
     */
    bool existe_contenedor (const string& m) const;
    
    //Salidas
    
    /**
     * @brief Operación de escritura del área de espera
     *  \pre <em>Cierto</em>
     *  \post Se escriben los Contenedores del área de espera en orden de salida uno encima de otro
     */
    void escribir_AreaDeEspera() const;
    
    /**
     * @brief Operación de escritura de los contenedores del área de almacenaje
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
     * @brief Operación de escritura de los huecos del área de almacenaje
     *  \pre <em>Cierto</em>
     *  \post Se escriben los Segmentos de los huecos que hay en el área de almacenaje uno encima de otro
     */
    void escribir_Huecos() const;
};

#endif
