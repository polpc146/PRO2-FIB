#include <iostream>
#include "BinTree.hh"

using namespace std;

bool poda_subarbre(BinTree<int> &a, int x) {
    
    if (not a.empty()) {
        if (a.value() == x) {
            BinTree<int> b;
            a = b;
            return true;
        }
        else {
            bool trobat;
            trobat = poda_subarbre (a.left(), x);
            trobat = poda_subarbre (a.right(), x);
        }
    }
    return false;
}
