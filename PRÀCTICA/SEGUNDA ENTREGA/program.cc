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
        
        cout << "#" << comando << " " << HILERAS << " " << PLAZAS << " " << PISOS << endl;
        
        cin >> comando;
        
        while (comando != "fin" and comando != "crea_terminal") {
            
            if (comando == "inserta_contenedor" or comando == "i") {
                
                string matricula;
                int longitud;
                cin >> matricula >> longitud;
                cout << "#" << comando << " " << matricula << " " << longitud << endl;
                Contenedor contenedor (matricula, longitud);
                
                if (terminal.existe_contenedor (matricula)) cout << "error: el contenedor ya existe" << endl;
                
                else terminal.insertar_contenedor (contenedor);
            }
            
            else if (comando == "retira_contenedor" or comando == "r") {
                
                string matricula;
                cin >> matricula;
                cout << "#" << comando << " " << matricula << endl;
                
                if (not terminal.existe_contenedor (matricula)) cout << "error: el contenedor no existe" << endl;
                
                else terminal.retirar_contenedor (matricula);
            }
            
            else if (comando == "donde") {
               
                string matricula;
                cin >> matricula;
                cout << "#" << comando << " " << matricula << endl;
                
                Ubicacion u;
                u = terminal.donde (matricula);
                u.print();
                cout << endl;
            }
            
            else if (comando == "longitud") {
                
                string matricula;
                cin >> matricula;
                cout << "#" << comando << " " << matricula << endl;
                
                if (not terminal.existe_contenedor (matricula)) cout << "error: el contenedor no existe" << endl;
                
                else {
                    
                    int l;
                    l = terminal.longitud (matricula);
                    cout << l << endl;
                }
            }
            
            else if (comando == "contenedor_ocupa") {
                
                int i, j, k;
                cin >> i >> j >> k;
                cout << "#" << comando << " " << i << " " << j << " " << k << endl;
                
                if (i < 0 or i >= HILERAS or j < 0 or j >= PLAZAS or k < 0 or k >= PISOS) cout << "error: ubicacion fuera de rango" << endl;
                
                else {
                    
                    Ubicacion u (i, j, k);
                    string matricula;
                    matricula = terminal.matricula (u);
                    
                    if (matricula != "-1") cout << matricula;
                    cout << endl;
                }
            }
            
            else if (comando == "num_hileras") {
                
                cout << "#" << comando << endl;
                int hileras;
                hileras = terminal.hileras();
                cout << hileras << endl;
            }
            
            else if (comando == "num_plazas") {
                
                cout << "#" << comando << endl;
                int plazas;
                plazas = terminal.plazas();
                cout << plazas << endl;
            }
            
            else if (comando == "num_pisos") {
                
                cout << "#" << comando << endl;
                int pisos;
                pisos = terminal.pisos();
                cout << pisos << endl;
            }
            
            else if (comando == "area_espera") {
                
                cout << "#" << comando << endl;
                terminal.escribir_AreaDeEspera();
            }
            
            else if (comando == "contenedores") {
                
                cout << "#" << comando << endl;
                terminal.escribir_ContenedoresAlmacenaje();
            }
            
            else if (comando == "area_almacenaje") {
                
                cout << "#" << comando << endl;
                terminal.representar_AreaDeAlmacenaje();
            }
            
            else if (comando == "huecos") {
                
                cout << "#" << comando << endl;
                terminal.escribir_Huecos();
            }
            cin >> comando;
        }
    }
}
