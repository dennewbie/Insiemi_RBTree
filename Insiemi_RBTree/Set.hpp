//
//  Set.hpp
//  Insiemi_RBTree
//
//  Created by Denny Caruso on 11/02/21.
//

#ifndef Set_hpp
#define Set_hpp

#include "RedBlackTree.hpp"

template <class T> class Set: private RedBlackTree<T> {
private:
    static unsigned int currID;     // Contatore
    const unsigned int ID;          // Codice identificativo univoco dell'insieme
    
    
    // Metodi Ulteriori Privati
    Set merge(std::vector<Node<T> * > firstSet, std::vector<Node<T> * > secondSet);
    void removeDuplicate(std::vector<Node<T> * > array);
    
public:
    // Costruttore
    Set() : ID(this->currID++) { }
    
    
    // Distruttore
    virtual ~Set() { }
    
    
    // Metodi Get Pubblici
    unsigned int getID();
    
    
    // Metodi Ulteriori Pubblici
    Set * unionOperation(Set * secondSet);
    Set * intersectOperation(Set * secondSet);
    Set * differenceOperation(Set * secondSet);
};


// Inizializzazione contatore Set
template <class T> unsigned int Set<T>::currID = 0;


// Implementazione Metodi Ulteriori Privati


 
// Implementazione Metodi Get Pubblici
template <class T> unsigned int Set<T>::getID() {
    return this-ID;
}


// Implementazione Metodi Ulteriori Pubblici



#endif /* Set_hpp */
