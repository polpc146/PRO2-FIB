#include <iostream>
#include <vector>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

using namespace std;

double redondear(double r) {  
    return int(10.*(r + 0.05)) / 10.0;
} 

int main () {
    Cjt_estudiants c;
    c.llegir();
    int n;
    while (cin >> n and n != -6) {
        if (n == -1) {
            Estudiant est;
            est.llegir();
            bool existeix = c.existeix_estudiant (est.consultar_DNI());
            if (existeix) cout << "el estudiante " << est.consultar_DNI() << " ya estaba" << endl;
            else c.afegir_estudiant (est);
        }
        else if (n == -2) {
            int dni;
            cin >> dni;
            bool existeix = c.existeix_estudiant (dni);
            if (not existeix) cout << "el estudiante " << dni << " no esta" << endl;
            else {
                if (not c.consultar_estudiant(dni).te_nota()) cout << "el estudiante " << dni << " no tiene nota" << endl;
                else {
                    double nota = c.consultar_estudiant(dni).consultar_nota();
                    cout << "el estudiante " << dni << " tiene nota " << nota << endl;
                }
            }
        }
        else if (n == -3) {
            Estudiant est;
            est.llegir();
            bool existeix = c.existeix_estudiant (est.consultar_DNI());
            if (not existeix) cout << "el estudiante " << est.consultar_DNI() << " no esta" << endl;
            else c.modificar_estudiant (est);
        }
        else if (n == -4) {
            int tam = c.mida();
            for (int i = 0; i<tam; ++i) {
                if (c.consultar_iessim (i+1).te_nota()) {
                    double notared = redondear (c.consultar_iessim (i+1).consultar_nota());
                    c.consultar_iessim (i+1).modificar_nota (notared);
                }    
            }
        }
        else c.escriure();
    }
}
