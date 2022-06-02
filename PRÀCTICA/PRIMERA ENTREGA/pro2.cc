/**
 * @mainpage Gestión de una terminal de contenedores de carga.
 */

/**
 * @file ProgramaPrincipal.cc
 * @date 31/10/2020
 * @author Pérez Castillo, Pol
 * @brief Programa principal para el ejercicio <em>Gestión de una terminal de contenedores de carga</em>.
 */

#include "TerminalDeContenedoresDeCarga.hh"
#include <iostream>

using namespace std;

/** 
 * @brief Programa principal para el ejercicio <em>Gestión de una terminal de contenedores de carga</em>.
 */

int main () {
    
    string comando;
    cin >> comando;
    
    while (comando != "fin") {
        
        int HILERAS, PLAZAS, PISOS;
        cin >> HILERAS >> PLAZAS >> PISOS;
        Terminal terminal (HILERAS, PLAZAS, PISOS);
        
        cin >> comando;
        
        while (comando != "fin" and comando != "crea_terminal") {
            
            if (comando == "inserta_contenedor" or comando == "i") {
                
                string matricula;
                int longitud;
                cin >> matricula >> longitud;
                Contenedor contenedor (matricula, longitud);
                
                if (terminal.existe_contenedor (matricula)) cout << "Ya existe un contenedor con la misma matricula" << endl;
                
                else terminal.insertar_contenedor (contenedor);
            }
            
            else if (comando == "retira_contenedor" or comando == "r") {
                
                string matricula;
                cin >> matricula;
                
                if (not terminal.existe_contenedor (matricula)) cout << "No existe un contenedor con esa matricula" << endl;
                
                else terminal.retirar_contenedor (matricula);
            }
            
            else if (comando == "donde") {
               
                string matricula;
                cin >> matricula;
                
                Ubicacion u;
                u = terminal.donde (matricula);
                u.print();
            }
            
            else if (comando == "longitud") {
                
                string matricula;
                cin >> matricula;
                
                if (not terminal.existe_contenedor (matricula)) cout << "No existe un contenedor con esa matricula" << endl;
                
                else {
                    
                    int l;
                    l = terminal.longitud (matricula);
                    cout << l << endl;
                }
            }
            
            else if (comando == "contenedor_ocupa") {
                
                int i, j, k;
                cin >> i >> j >> k;
                
                if (i < 0 or i >= HILERAS or j < 0 or j >= PLAZAS or k < 0 or k >= PISOS) cout << "Ubicacion fuera del area de almacenaje" << endl;
                
                else {
                    
                    Ubicacion u (i, j, k);
                    string matricula;
                    matricula = terminal.matricula (u);
                    
                    if (matricula != "-1") cout << matricula << endl;
                }
            }
            
            else if (comando == "num_hileras") {
                
                int hileras;
                hileras = terminal.hileras();
                cout << hileras << endl;
            }
            
            else if (comando == "num_plazas") {
                
                int plazas;
                plazas = terminal.plazas();
                cout << plazas << endl;
            }
            
            else if (comando == "num_pisos") {
                
                int pisos;
                pisos = terminal.pisos();
                cout << pisos << endl;
            }
            
            else if (comando == "area_espera") terminal.escribir_AreaDeEspera();
            
            else if (comando == "contenedores") terminal.escribir_ContenedoresAlmacenaje();
            
            else if (comando == "area_almacenaje") terminal.representar_AreaDeAlmacenaje();
            
            else if (comando == "huecos") terminal.escribir_Huecos();
        }
    }
}
