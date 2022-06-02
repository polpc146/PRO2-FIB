#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> Matriz;
typedef vector<vector<pair<int,int>>> Cuadro;

void llenar1 (Cuadro& resultados) {
    int tam = resultados.size();
    for  (int i=0; i<tam; ++i) {
        for (int j=0; j<tam; ++j) {
            resultados [i][j].first = -1;
            resultados [i][j].second = -1;
        }
    }
}

void leer_jornada (Cuadro& jornada) {
    int tam = jornada.size();
    for(int i=0; i<tam; ++i) {
        for (int j=0; j<2; ++j) {
            cin >> jornada [i][j].first >> jornada [i][j].second;
        }
    }
}

Matriz interpretacion_resultados (int N, const Cuadro& resultados) {
    Matriz clasificacion (N, vector<int>(4,0));
    for (int i=0; i<N; ++i) clasificacion[i][0] = i+1;                   // asignar numero a equipo
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (resultados[i][j].first!=-1) {                                                                    // sumar puntos                                                                
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
                clasificacion [i][2]+=resultados [i][j].first;                  // sumar goles a favor y en contra
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
    cout << "¿Cuantas jornadas se jugarán?" << endl;
    int J;
    cin >> J;
    
    Cuadro resultados (N, vector<pair<int,int>>(N));
    llenar1(resultados);
    
    int count=0;
    while (count<J) {
        Cuadro jornada (N/2, vector<pair<int,int>>(2));
        leer_jornada (jornada);
        int tam = jornada.size();
        for (int i=0; i<tam; ++i) {
            resultados [jornada[i][0].first -1][jornada[i][0].second -1].first = jornada[i][1].first;
            resultados [jornada[i][0].first -1][jornada[i][0].second -1].second = jornada[i][1].second;
        }
        ++count;
    }
    
    Matriz clasificacion;
    clasificacion = interpretacion_resultados (N, resultados);
    
    sort (clasificacion.begin(), clasificacion.end(), comp);
    escribir_clasificacion(clasificacion);
}
