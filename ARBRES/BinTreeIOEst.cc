#include "BinTree.hh"
#include "Estudiant.hh"
#include "BinTreeIOEst.hh"


void read_bintree_est(BinTree<Estudiant>& a) {
    Estudiant est;
    est.llegir();
    if (est.consultar_DNI() != 0 or est.consultar_nota() != 0) {
        BinTree<Estudiant> e1;
        BinTree<Estudiant> e2;

        read_bintree_est(e1);
        read_bintree_est(e2);
        a = BinTree<Estudiant> (est, e1, e2);
    }
}
