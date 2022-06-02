#include <iostream>
#include <queue>
#include "ParInt.hh"
#include "CuaIOParInt.hh"

using namespace std;

void distribucio (queue<ParInt>& c, queue<ParInt>& c1, queue<ParInt>& c2) {
    int contcola1 = 0;
    int contcola2 = 0;
    while (not c.empty()) {
        if (contcola2 < contcola1) {
            c2.push(c.front());
            contcola2 += c.front().segon();
        }
        else {
            c1.push(c.front());
            contcola1 += c.front().segon();
        }
        c.pop();
    }
}

int main () {
    queue<ParInt> c;
    llegirCuaParInt (c);
    queue<ParInt> c1, c2;
    distribucio (c, c1, c2);
    escriureCuaParInt (c1);
    cout << endl;
    escriureCuaParInt (c2);
}
