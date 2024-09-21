//
// Created by Pascal Charpentier on 2024-09-20.
//

#ifndef TESTLISTECIRCULAIRE_H
#define TESTLISTECIRCULAIRE_H

#include "ListeCirculaire.h"
#include "gtest/gtest.h"



class TestListeCirculaire : public testing::Test {
protected:
    TestListeCirculaire() : vide(), un {0}, six {1, 2, 3, 4, 5, 6} {}

    ListeCirculaire<int> vide ;
    ListeCirculaire<int> un  ;
    ListeCirculaire<int> six ;
};



#endif //TESTLISTECIRCULAIRE_H
