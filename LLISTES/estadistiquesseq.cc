#include <iostream>
#include <list>

using namespace std;

void eliminar (list<int>& l, int x, int& suma) {
    if (not l.empty()) {
        list<int>::iterator it = l.begin();
        while (it != l.end()) {
            if (*it == x) {
                it = l.erase(it);
                suma -= x;
                return;
            }
            else ++it;
        }
    }
}

int recalcularmin (const list<int>& l) {
    list<int>::const_iterator it = l.begin();
    int min = *it;
    ++it;
    while (it != l.end()) {
        if (*it < min) min = *it;
        ++it;
    }
    return min;
}

int recalcularmax (const list<int>& l) {
    list<int>::const_iterator it = l.begin();
    int max = *it;
    ++it;
    while (it != l.end()) {
        if (*it > max) max = *it;
        ++it;
    }
    return max;
}

void llegiricalcular (list<int>& l) {
    list<int>::iterator it = l.end();
    pair <int,int> p;
    cin >> p.first >> p.second;
    int min = p.second, max = p.second, suma = 0;
    double media;
    while (p.first != 0 or p.second != 0) {
        if (p.first == -1) {
            if (l.empty()) {
                min = p.second;
                max = p.second;
                suma = p.second;
            }
            else {
                if (p.second < min) min = p.second;
                if (p.second > max) max = p.second;
                suma += p.second;
            }
            l.insert (it, p.second);
        }
        else if (p.first == -2) {
            eliminar (l, p.second, suma);
            if (not l.empty()) {
                if (p.second == min) min = recalcularmin (l);
                if (p.second == max) max = recalcularmax (l);
            }
        }
        if (l.empty()) cout << 0 << endl;
        else {
            media = double (suma) / l.size(); 
            cout << min << " " << max << " " << media << endl;
        }
        cin >> p.first >> p.second;
    }
}

int main () {
    list<int> l;
    llegiricalcular(l);
}
