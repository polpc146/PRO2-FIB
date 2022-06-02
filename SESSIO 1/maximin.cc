#include <vector>
using namespace std;

struct parint {
    int prim, seg;
} ;

parint max_min1 (const vector<int>& v) {
    parint parint1;
    int max = v[0];
    int min = v[0];
    int tam = v.size();
    for (int i=1; i<tam; ++i) {
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
    }
    parint1.prim = max;
    parint1.seg = min;
    return parint1;
}


pair<int,int> max_min2 (const vector<int>& v) {
    pair<int,int> pair2;
    int max = v[0];
    int min = v[0];
    int tam = v.size();
    for (int i=1; i<tam; ++i) {
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
    }
    pair2.first = max;
    pair2.second = min;
    return pair2;
}


void max_min3 (const vector<int>& v, int& x, int& y) {
    x = v[0];
    y = v[0];
    int tam = v.size();
    for (int i=1; i<tam; ++i) {
        if (v[i] > x) x = v[i];
        if (v[i] < y) y = v[i];
    }
}
