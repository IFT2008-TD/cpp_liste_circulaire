//
// Created by Pascal Charpentier on 2024-09-18.
//
#include <ListeCirculaire.h>
#include "TestListeCirculaire.h"
#include "gtest/gtest.h"

TEST(liste_circulaire, constructor) {
  ListeCirculaire<int> l ;
  EXPECT_TRUE(l.estVide()) ;
}

TEST(liste_circulaire, vide_toString_vide) {
  ListeCirculaire<int> l ;
  EXPECT_EQ("[]", l.toString()) ;
}

TEST(liste_circulaire, vide_insererPremier_contient_un_element) {
  ListeCirculaire<int> l ;
  l.insererPremier(42) ;
  EXPECT_EQ(1, l.taille()) ;
  EXPECT_EQ(42, l.lireDernier()) ;
  EXPECT_EQ(42, l.lirePremier()) ;
  EXPECT_EQ("[42]", l.toString()) ;
}

TEST(liste_circulaire, vide_insererDernier_contient_un_element) {
  ListeCirculaire<int> l ;
  l.insererDernier(42) ;
  EXPECT_EQ(1, l.taille()) ;
  EXPECT_EQ(42, l.lireDernier()) ;
  EXPECT_EQ("[42]", l.toString()) ;
}

TEST(liste_circulaire, un_element_lirePremier) {
  ListeCirculaire<int> l ;
  l.insererDernier(42) ;
  EXPECT_EQ(42, l.lirePremier()) ;
}

TEST(liste_circulaire, liste_un_element_retirerPremier_liste_vide) {
  ListeCirculaire<int> l ;
  l.insererDernier(42) ;
  l.retirerPremier() ;
  EXPECT_EQ(0, l.taille()) ;
  EXPECT_EQ("[]", l.toString()) ;
}

TEST_F(TestListeCirculaire, six_elements_retirerPremier_cinq_elements) {
  six.retirerPremier() ;
  EXPECT_EQ(5, six.taille()) ;
  EXPECT_EQ("[2, 3, 4, 5, 6]", six.toString()) ;
  EXPECT_EQ(6, six.lireDernier()) ;
  EXPECT_EQ(2, six.lirePremier()) ;
}

TEST_F(TestListeCirculaire, six_elements_retirerPremier_deux_elements_reste_quatre) {
  six.retirerPremier() ;
  six.retirerPremier() ;
  EXPECT_EQ(4, six.taille()) ;
  EXPECT_EQ("[3, 4, 5, 6]", six.toString()) ;
  EXPECT_EQ(6, six.lireDernier()) ;
  EXPECT_EQ(3, six.lirePremier()) ;
}

TEST_F(TestListeCirculaire, vide_insererEnPosition_0_element_insere) {
  vide.insererEnPosition(0, 42) ;
  EXPECT_EQ(1, vide.taille()) ;
  EXPECT_EQ(42, vide.lireDernier()) ;
  EXPECT_EQ(42, vide.lirePremier()) ;
  EXPECT_EQ("[42]", vide.toString()) ;
}

TEST_F(TestListeCirculaire, six_elements_inserer_un_element_en_troisieme_position) {
  six.insererEnPosition(3, 42) ;
  EXPECT_EQ("[1, 2, 3, 42, 4, 5, 6]", six.toString()) ;
}

TEST_F(TestListeCirculaire, six_elements_retirerEnPosition_troisieme_element) {
  six.retirerEnPosition(2) ;
  EXPECT_EQ("[1, 2, 4, 5, 6]", six.toString()) ;
}

TEST_F(TestListeCirculaire, six_elements_retirerEnPosition_dernier_element) {
  six.retirerEnPosition(5) ;
  EXPECT_EQ("[1, 2, 3, 4, 5]", six.toString()) ;
}

TEST_F(TestListeCirculaire, six_elements_constructeur_copie_identique) {
  ListeCirculaire<int> copie(six) ;
  EXPECT_EQ("[1, 2, 3, 4, 5, 6]", copie.toString()) ;
}

TEST_F(TestListeCirculaire, vide_copie_vide) {
  ListeCirculaire<int> copie(vide) ;
  EXPECT_EQ("[]", copie.toString()) ;
}

TEST_F(TestListeCirculaire, six_elements_assignation_trois_elements) {
  six = un ;
  EXPECT_EQ("[0]", six.toString()) ;
}