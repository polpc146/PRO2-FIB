#include <iostream>
using namespace std;

#include "vectorIOint.hh"

/* Buscar  */    
int busqueda_lin(const vector<int>& v, int x) {
  int tam = v.size();
  int i = 0;
  bool b = false;
  while (i<tam and not b) {
    if (v[i]==x) b=true; 
    else ++i;
  }
  if (b) return i;
  else return -1;
}

int main()
{
  vector<int> v;
  leer_vector_int(v); 
  cout << "Escribe el elemento a buscar: " << endl;
  int x;
  cin >> x; 
  int c = busqueda_lin(v,x);
  if (c==-1) cout << "El elemento no está en el vector" << endl;
  else cout << "El elemento está en el vector en la posición " << c << endl;
  cout << "Escribimos el vector para que se vea que no ha cambiado:" << endl;
  escribir_vector_int(v);
}
