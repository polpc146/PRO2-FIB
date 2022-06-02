#include<iostream>
using namespace std;

void intercambiar (int& m, int& n) {
    int x=n;
    n=m;
    m=x;
}

int main () {
    int m, n;
    cin >> m >> n;
    intercambiar (m, n);
    cout << m <<" " <<  n << endl;
}
