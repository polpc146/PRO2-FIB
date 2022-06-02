#include <iostream>
#include <queue>

using namespace std;

void minmax (int& min, int& max, int n, queue <int> c) {
    if (n != -1001) {
        if (n < min) min = n;
        if (n > max) max = n;
    }
    else {
        queue <int> copia (c);
        min = c.front();
        max = c.front();
        copia.pop();
        while (not copia.empty()) {
            if (copia.front() < min) min = copia.front();
            if (copia.front() > max) max = copia.front();
            copia.pop();
        }
    }
}

double average (int suma, queue <int> c) {
    double media = double (suma) / c.size();
    return media;
}

int main () {
    queue <int> c;
    int n, min, max, suma = 0;
    double media;
    while (cin >> n and n!=1001) {
        if (n==-1001) {
            if (not c.empty()) {
                suma -= c.front();
                c.pop();
            }
            if (c.empty()) cout << 0 << endl;
            else  {
                minmax (min, max, n, c);
                media = average (suma, c);
                cout << "min " << min << "; max " << max << "; media " << media << endl;
            }
        }
        else if (n>-1001 and n<1001) {
            c.push(n);
            suma += n;
            if (c.size()==1) {
                min = n;
                max = n;
                media = n;
            }
            else {
                minmax (min, max, n, c);
                media = average (suma, c);
            }
            cout << "min " << min << "; max " << max << "; media " << media << endl;
        }
    }
}
