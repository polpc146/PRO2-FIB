#include <iostream>
#include <queue>
#include "CuaIOParInt.hh"

using namespace std;

void distribucio (queue<pair<int,int>>& c, queue<pair<int,int>>& c1, queue<pair<int,int>>& c2) {
    int contcola1 = 0;
    int contcola2 = 0;
    while (not c.empty()) {
        if (contcola2 < contcola1) {
            c2.push(c.front());
            contcola2 += c.front().second;
        }
        else {
            c1.push(c.front());
            contcola1 += c.front().second;
        }
        c.pop();
    }
}

int main () {
    queue<pair<int,int>> c;
    llegirCuaParInt (c);
    queue<pair<int,int>> c1, c2;
    distribucio (c, c1, c2);
    escriureCuaParInt (c1);
    cout << endl;
    escriureCuaParInt (c2);
}
