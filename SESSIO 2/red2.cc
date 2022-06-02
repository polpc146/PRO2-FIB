#include "Estudiant.hh"


// Redondear, version accion

void redondear_e_a(Estudiant& est)
/* Pre: est tiene nota */
/* Post: est pasa a tener su nota original redondeada */
{
  est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
}

int main() {
  Estudiant est;
  cout << "Escribe un estudiante <DNI nota>" << endl;
  est.llegir();
  while (est.consultar_DNI()!=0) {
      if (est.te_nota()) {
          redondear_e_a(est);
          cout << "El estudiante con la nota redondeada, o NP: " <<endl;
          est.escriure();
      }
      else cout << est.consultar_DNI() << " NP" << endl;
      cout << "Escribe un estudiante <DNI nota>" << endl;
      est.llegir();
  }
  
}
