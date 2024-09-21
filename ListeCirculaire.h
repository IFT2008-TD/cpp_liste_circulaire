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
    assert(invariant()) ;
}

template<typename T>
ListeCirculaire<T>::ListeCirculaire(std::initializer_list<T> liste) : dernier(nullptr), cardinal(0) {
    for (const auto& elem : liste) insererDernier(elem) ;
    assert(invariant()) ;
}

template<typename T>
ListeCirculaire<T>::ListeCirculaire(const ListeCirculaire &orig) : dernier(nullptr), cardinal(0) {
    std::cerr << "COPY\n" ;
    if (orig.dernier == nullptr) return ;
    auto p = orig.dernier ;
    do {
        p = p->next ;
        insererDernier(p->val) ;
    } while (p != orig.dernier) ;

    assert(invariant()) ;
}

template<typename T>
ListeCirculaire<T>::ListeCirculaire(ListeCirculaire &&orig) noexcept: dernier(orig.dernier), cardinal(orig.cardinal)  {
    std::cerr << "MOVE\n" ;
    orig.dernier = nullptr ;
    orig.cardinal = 0 ;
    assert(invariant()) ;
}

template<typename T>
ListeCirculaire<T>::~ListeCirculaire() {
    while (!estVide()) retirerPremier() ;
}

template<typename T>
ListeCirculaire<T> & ListeCirculaire<T>::operator=(ListeCirculaire orig) {
    std::swap(dernier, orig.dernier) ;
    std::swap(cardinal, orig.cardinal) ;
    assert(invariant()) ;
    return *this ;
}

template<typename T>
void ListeCirculaire<T>::insererEnPosition(size_t pos, T val) {
    assert(pos <= cardinal) ;

    if (pos == cardinal) insererDernier(val) ;
    else insertionDans(val, trouverPosition(pos)) ;

    assert(invariant()) ;
}

template<typename T>
void ListeCirculaire<T>::insererDernier(const T &val) {
    auto nouveau = new Cellule(val) ;
    if (dernier == nullptr) {
        nouveau->next = nouveau ;
    }
    else {
        nouveau->next = dernier->next ;
        dernier->next = nouveau ;
    }
    dernier = nouveau ;
    ++ cardinal ;

    assert(invariant()) ;
}

template<typename T>
void ListeCirculaire<T>::insererPremier(const T &val) {
    auto nouveau = new Cellule(val) ;
    if (dernier == nullptr) {
        nouveau->next = nouveau ;
        dernier = nouveau ;
    }
    else {
        nouveau->next = dernier->next ;
        dernier->next = nouveau ;
    }
    ++ cardinal ;

    assert(invariant()) ;
}

template<typename T>
void ListeCirculaire<T>::retirerEnPosition(size_t pos) {
    assert(cardinal > 0) ;
    assert(pos < cardinal) ;

    if (cardinal == 1) retirerPremier() ;
    else if (pos == cardinal - 1) {
        auto p = trouverPosition(pos - 1) ;
        retraitDans(p->next) ;
        dernier = p ;
    }
    else {
        retraitDans(trouverPosition(pos)) ;
    }

    assert(invariant()) ;
}

template<typename T>
void ListeCirculaire<T>::retirerPremier() {
    assert(!estVide()) ;

    if (dernier->next == dernier) {
        delete dernier ;
        dernier = nullptr ;
    }
    else {
        auto p = dernier->next ;
        dernier->next = dernier->next->next ;
        delete p ;
    }
    --cardinal ;

    assert(invariant()) ;
}


template<typename T>
const T & ListeCirculaire<T>::lireDernier() const {
    assert(!estVide()) ;
    return dernier->val ;
}

template<typename T>
const T & ListeCirculaire<T>::lirePremier() const {
    assert(!estVide()) ;
    return dernier->next->val ;
}

template<typename T>
const T & ListeCirculaire<T>::lireEnPosition(size_t pos) const {
    assert(!estVide()) ;
    assert(pos < cardinal) ;
    return trouverPosition(pos)->val ;
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
    if (estVide()) return "[]" ;

    std::ostringstream os ;
    os << "[" ;
    auto p = dernier ;
    do {
        p = p->next ;
        os << p->val ;
        if (p != dernier) os << ", " ;
    } while (p != dernier) ;
    os << "]" ;
    return os.str() ;
}

template<typename T>
typename ListeCirculaire<T>::Cellule * ListeCirculaire<T>::trouverPosition(size_t pos) const {
    assert(pos < cardinal) ;
    auto p = dernier->next ;
    for (size_t i = 0 ; i < pos ; i++) p = p->next ;
    return p ;
}

template<typename T>
void ListeCirculaire<T>::insertionDans(const T& val, Cellule *cell) {
    auto nouveau = new Cellule(cell->val) ;
    nouveau->next = cell->next ;
    cell->next = nouveau ;
    cell->val = val ;
    ++ cardinal ;
}

template<typename T>
void ListeCirculaire<T>::retraitDans(Cellule *cell) {
    cell->val = cell->next->val ;
    auto p = cell->next ;
    cell->next = p->next ;
    delete p ;
    -- cardinal ;
}

template<typename T>
bool ListeCirculaire<T>::invariant() const {
    if (dernier == nullptr) return cardinal == 0;
    auto p = dernier ;
    for (size_t i = 0 ; i < cardinal ; ++i) {
        p = p->next ;
    }
    return p == dernier ;
}

#endif //LISTECIRCULAIRE_H
