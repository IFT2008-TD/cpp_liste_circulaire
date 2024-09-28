//
// Created by Pascal Charpentier on 2024-09-18.
//
#include "gtest/gtest.h"
#include "liste_circulaire.h"

TEST(ListeCirculaire, constructeur_liste_vide){
    ListeCirculaire<int> l ;
    EXPECT_EQ(0, l.taille()) ;
}

TEST(ListeCirculaire, liste_vide_to_string_crochets_vides) {
    ListeCirculaire<int> l ;
    EXPECT_EQ("[]", l.toString()) ;
}

TEST(ListeCirculaire, liste_vide_inserer_dernier_cardinal_un) {
    ListeCirculaire<int> l ;
    l.insererDernier(42) ;
    EXPECT_EQ(1, l.taille()) ;
}

TEST(ListeCirculaire, liste_vide_inserer_dernier_string_ok) {
    ListeCirculaire<int> l ;
    l.insererDernier(42) ;
    EXPECT_EQ("[42]", l.toString()) ;
}

TEST(ListeCirculaire, liste_vide_inserer_deux_elements_cardinal_deux) {
    ListeCirculaire<int> l ;
    l.insererDernier(42) ;
    l.insererDernier(53) ;
    EXPECT_EQ(2, l.taille()) ;
}

TEST(ListeCirculaire, liste_vide_inserer_deux_elements_bon_ordre) {
    ListeCirculaire<int> l ;
    l.insererDernier(42) ;
    l.insererDernier(53) ;
    EXPECT_EQ("[42, 53]", l.toString()) ;
}

class ListeTest : public testing::Test {
protected:
    ListeCirculaire<int> l0 ;
    ListeCirculaire<int> l1 ;
    ListeCirculaire<int> l5 ;

    void SetUp() override {
        l1.insererDernier(1) ;

        l5.insererDernier(1) ;
        l5.insererDernier(2) ;
        l5.insererDernier(3) ;
        l5.insererDernier(4) ;
        l5.insererDernier(5) ;
    }
};

TEST(ListeCirculaire, constructeur_vide) {
    ListeCirculaire<int> l ;
    EXPECT_TRUE(l.estVide()) ;
}

TEST(ListeCirculaire, vide_toString) {
    ListeCirculaire<int> l ;
    EXPECT_EQ("[]", l.toString()) ;
}

TEST(ListeCirculaire, vide_insererDernier_un_element) {
    ListeCirculaire<int> l ;
    l.insererDernier(42) ;
    EXPECT_EQ(1, l.taille()) ;
    EXPECT_EQ("[42]", l.toString()) ;
}

TEST_F(ListeTest, l5_copie_l5) {
    ListeCirculaire<int> lcopie(l5) ;
    EXPECT_EQ(lcopie.toString(), l5.toString()) ;
}

TEST_F(ListeTest, l5_supprimerPremier_4_elements) {
    l5.supprimerPremier() ;
    EXPECT_EQ("[2, 3, 4, 5]", l5.toString()) ;
}

TEST_F(ListeTest, l5_assigner_a_vide) {
    l0 = l5 ;
    EXPECT_EQ("[1, 2, 3, 4, 5]", l0.toString()) ;
    EXPECT_EQ("[1, 2, 3, 4, 5]", l5.toString()) ;
}







