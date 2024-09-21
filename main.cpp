#include <iostream>
#include "ListeCirculaire.h"

int main() {
    ListeCirculaire<int> l1 ;
    ListeCirculaire<int> l2 ;
    l1.insererPremier(1000) ;
    l2.insererPremier(4000) ;
    l1 = std::move(l2) ;

    return 0;
}
