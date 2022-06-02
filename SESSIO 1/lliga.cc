#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> Matriz;
typedef vector<vector<pair<int,int>>> Cuadro;

Matriz interpretacion_resultados (int N, const Cuadro& resultados) {
    Matriz clasificacion (N, vector<int>(4,0));
    for (int i=0; i<N; ++i) clasificacion[i][0] = i+1;                   // asignar numero a equipo
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (i!=j) {                                                                    // sumar puntos                                                                
                if(resultados [i][j].first > resultados[i][j].second) {
                    clasificacion [i][1]+=3;
                }
                else if (resultados [i][j].first==resultados [i][j].second) {
                    ++clasificacion [i][1];
                    ++clasificacion [j][1];
                }
                else {
                    clasificacion [j][1]+=3;
                }
                clasificacion [i][2]+=resultados [i][j].first;                  // sumar goles a foavor y en contra
                clasificacion [i][3]+=resultados [i][j].second;                 //
                clasificacion [j][2]+=resultados [i][j].second;                 //
                clasificacion [j][3]+=resultados [i][j].first;                  //
            }
        }
    }
    return clasificacion;
}

bool comp (const vector<int>& x, const vector<int>& y) {
    if (x[1]==y[1]) {
        if ((x[2]-x[3])==(y[2]-y[3])) return x[0]<y[0];
        else return (x[2]-x[3])>(y[2]-y[3]);
    }
    return x[1]>y[1];
}

void escribir_clasificacion (const Matriz& clasificacion) {
    int fil=clasificacion.size();
    int col=clasificacion[0].size();
    for (int i=0; i<fil; ++i) {
        for (int j=0; j<col; ++j) cout << clasificacion [i][j] << " " ;
        cout << endl;
    }
}

int main () {
    cout << "¿Cuantos equipos participan en la liga?" << endl;
    int N;                      // N >= 2 
    cin >> N;
    Cuadro resultados (N, vector<pair<int,int>>(N));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) cin >> resultados [i][j].first >> resultados [i][j].second;   // resultados puestos
    }
    Matriz clasificacion (N, vector<int>(4)); 
    clasificacion = interpretacion_resultados (N, resultados);    // clasificacion creada en orden creciente de equipos (falta ordenar)
    sort (clasificacion.begin(), clasificacion.end(), comp);
    escribir_clasificacion(clasificacion);
}
