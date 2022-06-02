#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    for (int i=1; i<=n; ++i) {
        int y;
        int suma = 0;
        string s;
        while (cin >> y and y != x) {
            suma += y;
        }
        cout << "La suma de la secuencia " << i << " es " << suma << endl;
        getline (cin, s);
    }
}

