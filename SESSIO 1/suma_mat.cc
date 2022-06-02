#include <iostream>
using namespace std;


#include "matrizIOint.hh" // contiene la declaracion 
                          // typedef vector <vector<int> > Matriz;
      
void sumar_matriz_int(const Matriz& m1, const Matriz& m2, Matriz& suma)
{
  int fil = m1.size(); int col = m1[0].size(); 
  for (int i=0; i<fil;++i) {                
    for (int j=0; j<col;++j)
      suma[i][j]=m1[i][j]+m2[i][j];     
  }
}


int main()
{
  cout << "Primera matriz" << endl;
  Matriz m1;
  leer_matriz_int(m1);  
  cout << "Segunda matriz (ha de tener la misma dimension que la primera) " << endl;
  Matriz m2;
  leer_matriz_int(m2);  
  vector<vector<int> > suma(m1.size(), vector<int>(m1[0].size()));
    sumar_matriz_int(m1,m2,suma);

  cout << "La matriz suma es: " << endl;
  escribir_matriz_int(suma);
}
