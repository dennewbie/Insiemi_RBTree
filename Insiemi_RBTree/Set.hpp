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
    unsigned int ID;                // Codice identificativo univoco dell'insieme
    
    
    // Metodi Set Privati
    void setID(unsigned int newID);
    
    
    // Metodi Ulteriori Privati
    std::vector<Node<T>> * merge(std::vector<Node<T>> * firstSet, std::vector<Node<T>> * secondSet);
        /*
            Metodo che permette di unire due vector di Node parametrizzati da T passati come parametri
            sotto forma di puntatori. Restituisce un puntatore a un vector di Node parametrizzati da T
         */
    void removeDuplicate(std::vector<Node<T>> * array);
        /*
            Metodo che permette di rimuove i duplicati dal vector di Node parametrizzati da T
            passatogli come parametro sotto forma di puntatore
         */
    
public:
    // Costruttore
    Set() : ID(this->currID++) { }
    
    
    // Distruttore
    virtual ~Set() {
        this->currID--;
    }
    
    
    // Metodi Get Pubblici
    unsigned int getCounterID();
    unsigned int getID();
    
    
    // Metodi Ulteriori Pubblici
    Set<T> * unionOperation(Set<T> * secondSet);
    Set<T> * intersectOperation(Set<T> * secondSet);
    Set<T> * differenceOperation(Set<T> * secondSet);
        /*
            Operazioni Insiemistiche di Unione, Intersezione e Differenza.
            Ognuna di esse prende come parametro il secondo insieme sotto forma di puntatore.
            Ognuna fa la relativa operazione con l'insieme sul quale il metodo è invocato.
            Ognuna restituisce un puntatore a Set parametrizzato da T
         */
    void printSet();
        /*
            Stampa l'insieme in maniera ordinata grazie a una visita inorder
         */
    void insertElement(int key, T data);
        /*
            Inserisce un elemento composto da chiave e data all'interno di un insieme
         */
};


// Inizializzazione contatore classe Set
template <class T> unsigned int Set<T>::currID = 1;


// Implementazione Metodi Set
template <class T> void Set<T>::setID(unsigned int newID) {
    this->currID = newID - 1;
    this->ID--;
}


// Implementazione Metodi Get
template <class T> unsigned int Set<T>::getCounterID() {
    return this->currID;
}

template <class T> unsigned int Set<T>::getID() {
    return this->ID;
}


// Implementazione Metodi Ulteriori
template <class T> std::vector<Node<T>> * Set<T>::merge(std::vector<Node<T>> * firstSet, std::vector<Node<T>> * secondSet) {
    std::vector<Node<T>> * thirdSet = new std::vector<Node<T>>;
    
    for (auto i = 0, j = 0, k = 0; k < (firstSet->size() + secondSet->size()); k++) {
        if (i == firstSet->size()) {
            thirdSet->push_back(secondSet->at(j++));
            continue;
        }
        
        if (j == secondSet->size()) {
            thirdSet->push_back(firstSet->at(i++));
            continue;
        }
        
        if (firstSet->at(i).getKey() < secondSet->at(j).getKey()) {
            thirdSet->push_back(firstSet->at(i++));
        } else {
            thirdSet->push_back(secondSet->at(j++));
        }
    }
    
    return thirdSet;
}

template <class T> void Set<T>::removeDuplicate(std::vector<Node<T>> * array) {
    for (auto i = 1; i < array->size(); i++) {
        if (array->at(i - 1).getKey() == array->at(i).getKey()) {
            array->erase(array->begin() + i);
            i--;
        }
    }
}

template <class T> Set<T> * Set<T>::unionOperation(Set<T> * secondSet) {
    Set<T> * resultSet = new Set<T>();
    resultSet->setID(getCounterID());
    
    std::vector<Node<T>> * firstSetArray = this->buildSortedArray();
    std::vector<Node<T>> * secondSetArray = secondSet->buildSortedArray();
    std::vector<Node<T>> * resultSetArray = merge(firstSetArray, secondSetArray);
    
    removeDuplicate(resultSetArray);
    
    for (auto i = 0; i < resultSetArray->size(); i++) {
        resultSet->insertNodeRB(resultSetArray->at(i).getKey(), resultSetArray->at(i).getData());
    }
    
    resultSet->resetNilT_Node();
    return resultSet;
}

template <class T> Set<T> * Set<T>::intersectOperation(Set<T> * secondSet) {
    Set<T> * resultSet = new Set<T>();
    resultSet->setID(getCounterID());
    
    std::vector<Node<T>> * firstSetArray = this->buildSortedArray();
    std::vector<Node<T>> * secondSetArray = secondSet->buildSortedArray();
    std::vector<Node<T>> * resultSetArray = new std::vector<Node<T>>;
    
    auto i = 0, j = 0;
    while (i < firstSetArray->size() && j < secondSetArray->size()) {
        if (firstSetArray->at(i).getKey() < secondSetArray->at(j).getKey()) {
            i++;
        } else if (firstSetArray->at(i).getKey() > secondSetArray->at(j).getKey()) {
            j++;
        } else {
            resultSetArray->push_back(firstSetArray->at(i));
            i++;
            j++;
        }
    }
    
    removeDuplicate(resultSetArray);
    
    for (auto i = 0; i < resultSetArray->size(); i++) {
        resultSet->insertNodeRB(resultSetArray->at(i).getKey(), resultSetArray->at(i).getData());
    }
    
    resultSet->resetNilT_Node();
    return resultSet;
}

template <class T> Set<T> * Set<T>::differenceOperation(Set<T> * secondSet) {
    Set<T> * resultSet = new Set<T>();
    resultSet->setID(getCounterID());
    
    std::vector<Node<T>> * firstSetArray = this->buildSortedArray();
    std::vector<Node<T>> * secondSetArray = secondSet->buildSortedArray();
    std::vector<Node<T>> * resultSetArray = new std::vector<Node<T>>;
    
    auto i = 0, j = 0;
    while (i < firstSetArray->size() && j < secondSetArray->size()) {
        if (firstSetArray->at(i).getKey() < secondSetArray->at(j).getKey()) {
            resultSetArray->push_back(firstSetArray->at(i));
            i++;
        } else if (firstSetArray->at(i).getKey() > secondSetArray->at(j).getKey()) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    
    while (i < firstSetArray->size()) {
        resultSetArray->push_back(firstSetArray->at(i));
        i++;
    }
    
    removeDuplicate(resultSetArray);
    
    for (auto i = 0; i < resultSetArray->size(); i++) {
        resultSet->insertNodeRB(resultSetArray->at(i).getKey(), resultSetArray->at(i).getData());
    }
    
    resultSet->resetNilT_Node();
    return resultSet;
}

template <class T> void Set<T>::printSet() {
    std::cout << "\nSet # " << getID() << ":\n";
    this->inorderVisit(this->getRoot());
    std::cout << "\n";
}

template <class T> void Set<T>::insertElement(int key, T data) {
    this->insertNodeRB(key, data);
}
    
#endif /* Set_hpp */
