#include <iostream>
#include "BinTree.hh"
#include "Estudiant.hh"
#include "BinTreeIOEst.hh"
using namespace std;

int cercar(const BinTree<Estudiant>& a, int n, int& s) {
    if (not a.empty()) {
        Estudiant est = a.value();
        if (est.consultar_DNI() == n) {
            if (est.te_nota()) s = est.consultar_nota();
            else s = -1;
            return 0;
        }
        int left = cercar(a.left(), n, s);
        int n_aux;
        int right = cercar(a.right(), n, n_aux);
        if (left != -1 and right != -1) {
            if (left <= right) return 1 + left;
            else {
                s = n_aux;
                return 1 + right;
            }
        }
        if (left != -1) return 1 + left;
        else if (right != -1) {
            s = n_aux;
            return 1 + right;
        }
        else return -1;

    }
    return -1;
}


int main() {
    BinTree<Estudiant> arbre;
    read_bintree_est(arbre);

    int n, s;
    while (cin >> n) {
        int p = cercar(arbre, n, s);
        if (p != -1) {
            cout << n << ' ' << p << ' '  << s << endl;
        }
        else cout << n << ' ' << -1 << endl;
    }
}
