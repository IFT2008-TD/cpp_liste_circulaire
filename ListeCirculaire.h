//
// Created by Pascal Charpentier on 2024-09-18.
//

#ifndef LISTECIRCULAIRE_H
#define LISTECIRCULAIRE_H

#include <sstream>
#include <iostream>
#include <string>
#include <initializer_list>

template <typename T>
class ListeCirculaire {
private:
    struct Cellule {
        T val ;
        Cellule* next;
        explicit Cellule(T val) : val(val), next(nullptr) {}
    };
    using Cellule = struct Cellule ;

public:
    ListeCirculaire();
    ListeCirculaire(std::initializer_list<T> liste);
    ListeCirculaire(const ListeCirculaire& orig) ;
    ListeCirculaire(ListeCirculaire&& orig) noexcept ;
    ~ListeCirculaire() ;
    ListeCirculaire& operator=(ListeCirculaire orig) ;

    void insererEnPosition(size_t pos, T val) ;
    void insererDernier(const T &val) ;
    void insererPremier(const T& val) ;
    void retirerEnPosition(size_t pos) ;
    void retirerPremier() ;
    const T& lireDernier() const ;
    const T& lirePremier() const ;
    const T& lireEnPosition(size_t pos) const ;

    size_t taille() const ;
    bool estVide() const ;
    std::string toString() const ;

    friend std::ostream &operator<<(std::ostream &os, const ListeCirculaire &l) {
        os << l.toString();
        return os;
    }

private:
    Cellule* trouverPosition(size_t pos) const ;
    void insertionDans(const T& val, Cellule* cell) ;
    void retraitDans(Cellule* cell) ;
    bool invariant() const ;


private:
    Cellule* dernier ;
    size_t cardinal ;


};

template<typename T>
ListeCirculaire<T>::ListeCirculaire() : dernier(nullptr), cardinal(0) {

}

template<typename T>
ListeCirculaire<T>::ListeCirculaire(std::initializer_list<T> liste) : dernier(nullptr), cardinal(0) {


}

template<typename T>
ListeCirculaire<T>::ListeCirculaire(const ListeCirculaire &orig) : dernier(nullptr), cardinal(0) {



}

template<typename T>
ListeCirculaire<T>::ListeCirculaire(ListeCirculaire &&orig) noexcept: dernier(orig.dernier), cardinal(orig.cardinal)  {


}

template<typename T>
ListeCirculaire<T>::~ListeCirculaire() {

}

template<typename T>
ListeCirculaire<T> & ListeCirculaire<T>::operator=(ListeCirculaire orig) {


    return *this ;
}

template<typename T>
void ListeCirculaire<T>::insererEnPosition(size_t pos, T val) {

}

template<typename T>
void ListeCirculaire<T>::insererDernier(const T &val) {

}

template<typename T>
void ListeCirculaire<T>::insererPremier(const T &val) {

}

template<typename T>
void ListeCirculaire<T>::retirerEnPosition(size_t pos) {

}

template<typename T>
void ListeCirculaire<T>::retirerPremier() {

}


template<typename T>
const T & ListeCirculaire<T>::lireDernier() const {
   return T() ;
}

template<typename T>
const T & ListeCirculaire<T>::lirePremier() const {
    return T() ;
}

template<typename T>
const T & ListeCirculaire<T>::lireEnPosition(size_t pos) const {
    return T() ;
}

template<typename T>
size_t ListeCirculaire<T>::taille() const {
    return 0 ;
}

template<typename T>
bool ListeCirculaire<T>::estVide() const {
    return true ;
}

template<typename T>
std::string ListeCirculaire<T>::toString() const {
   return "" ;
}

template<typename T>
typename ListeCirculaire<T>::Cellule * ListeCirculaire<T>::trouverPosition(size_t pos) const {
    return nullptr ;
}

template<typename T>
void ListeCirculaire<T>::insertionDans(const T& val, Cellule *cell) {

}

template<typename T>
void ListeCirculaire<T>::retraitDans(Cellule *cell) {

}

template<typename T>
bool ListeCirculaire<T>::invariant() const {
    return true ;
}

#endif //LISTECIRCULAIRE_H
