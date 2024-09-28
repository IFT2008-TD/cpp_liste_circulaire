//
// Created by Pascal Charpentier on 2024-09-18.
//

#ifndef LISTE_CIRCULAIRE_LISTE_CIRCULAIRE_H
#define LISTE_CIRCULAIRE_LISTE_CIRCULAIRE_H

#include <sstream>
#include <cassert>

template <typename T>
class ListeCirculaire {
private:
    struct Cellule {
        T valeur ;
        Cellule* next ;
        explicit Cellule(const T& val) : valeur(val), next(nullptr) {}
    };

public:
    ListeCirculaire() ;
    ListeCirculaire(const ListeCirculaire& source) ;
    ListeCirculaire(ListeCirculaire&& source) noexcept ;
    ~ListeCirculaire() ;

    ListeCirculaire& operator = (ListeCirculaire rhs) ;

    void insererDernier(const T& val) ;

    void supprimerPremier() ;

    size_t taille() const ;
    bool estVide() const ;
    std::string toString() const ;

private:
    bool invariant() const ;

private:
    Cellule* dernier ;
    size_t  cardinal ;
};

template<typename T>
ListeCirculaire<T>::ListeCirculaire() : dernier(nullptr), cardinal(0) {
    assert(invariant()) ;
}

template<typename T>
bool ListeCirculaire<T>::invariant() const {
    if (cardinal == 0) return (dernier == nullptr) ;
    auto p = dernier ;
    for (size_t i = 0; i < cardinal; ++i) p = p->next ;
    return (p == dernier) ;

}

template<typename T>
size_t ListeCirculaire<T>::taille() const {
    return cardinal ;
}

template<typename T>
bool ListeCirculaire<T>::estVide() const {
    return taille() == 0 ;
}

template<typename T>
std::string ListeCirculaire<T>::toString() const {
    std::ostringstream os ;

    os << "[" ;
    if (dernier != nullptr) {
        auto p = dernier ;
        do {
            p = p->next ;
            os << p->valeur ;
            if (p != dernier) os << ", " ;
        } while (p != dernier) ;
    }
    os  << "]" ;
    return os.str() ;
}

template<typename T>
void ListeCirculaire<T>::insererDernier(const T &val) {

    auto nouveau = new Cellule(val) ;
    if (dernier == nullptr) nouveau->next = nouveau ;
    else {
        nouveau->next = dernier->next ;
        dernier->next = nouveau ;
    }
    dernier = nouveau ;
    ++ cardinal ;

    assert(invariant()) ;
}

template<typename T>
ListeCirculaire<T>::ListeCirculaire(const ListeCirculaire &source) : dernier(nullptr), cardinal(0) {
    if (source.dernier != nullptr) {
        auto p = source.dernier ;
        do {
            p = p->next ;
            insererDernier(p->valeur) ;
        } while (p != source.dernier) ;
    }
    assert(invariant()) ;
}

template<typename T>
void ListeCirculaire<T>::supprimerPremier() {
    assert(!estVide()) ;

    if (cardinal == 1) {
        delete dernier ;
        dernier = nullptr ;
    }
    else {
        auto p = dernier->next ;
        dernier->next = p->next ;
        delete p ;
    }
    -- cardinal ;

    assert(invariant()) ;
}

template<typename T>
ListeCirculaire<T>::~ListeCirculaire() {
    while (!estVide()) supprimerPremier() ;
}

template<typename T>
ListeCirculaire<T>::ListeCirculaire(ListeCirculaire &&source) noexcept : dernier(source.dernier), cardinal(source.cardinal)  {
    source.dernier = nullptr ;
    source.cardinal = 0 ;
}


template<typename T>
ListeCirculaire<T> &ListeCirculaire<T>::operator=(ListeCirculaire rhs) {
    using std::swap ;
    swap(dernier, rhs.dernier) ;
    swap(cardinal, rhs.cardinal) ;
    return *this ;
}


#endif

