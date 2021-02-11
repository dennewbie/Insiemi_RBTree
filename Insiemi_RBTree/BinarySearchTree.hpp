//
//  BinarySearchTree.hpp
//  Insiemi_RBTree
//
//  Created by Denny Caruso on 11/02/21.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Node.hpp"
#include <iostream>

template <class T> class BinarySearchTree {
private:
    Node<T> * root;
    Node<T> * nilTNode = new Node<T>();
    
    
    // Metodi Ulteriori Privati
    void transplant(Node<T> * to, Node<T> * from);

protected:
    // Metodi Set Protetti
    void setRoot(Node<T> * newRoot);
    
public:
    // Costruttore che imposta la radice col nodo NIL_T
    BinarySearchTree() {
        setRoot(getNilTNode());
    }
    
    // Distruttore
    virtual ~BinarySearchTree() { }
    
    
    // Metodi Get Pubblici
    Node<T> * getRoot();
    Node<T> * getNilTNode();
    
    
    // Metodi Ulteriori Pubblici
    void insertNode(int key, T data);
};


// Implementazione Metodi Privati
template <class T> void BinarySearchTree<T>::transplant(Node<T> * to, Node<T> * from) {
    if (to->getParent() == getNilTNode()) {
        setRoot(from);
    } else if (to == (to->getParent())->getLeft()) {
        (to->getParent())->setLeft(from);
    } else {
        (to->getParent())->setRight(from);
    }

    if (from != getNilTNode()) from->setParent(to->getParent());
}


// Implementazione Distruttore
//template <class T> BinarySearchTree<T>::~BinarySearchTree() {
//    while (this->getRoot() != getNilTNode()) deleteNode(getRoot()->getKey());
//}


// Implementazione Metodi Set Protetti
template <class T> void BinarySearchTree<T>::setRoot(Node<T> * newRoot) {
    this->root = newRoot;
}


// Implementazione Metodi Get Pubblici
template <class T> Node<T> * BinarySearchTree<T>::getRoot() {
    return this->root;
}

template <class T> Node<T> * BinarySearchTree<T>::getNilTNode() {
    return this->nilTNode;
}


// Implementazione Metodi Ulteriori Pubblici
template <class T> void BinarySearchTree<T>::insertNode(int key, T data) {
    Node<T> * nodeToInsert = new Node<T>(key, data);
    nodeToInsert->setParent(getNilTNode());
    nodeToInsert->setLeft(getNilTNode());
    nodeToInsert->setRight(getNilTNode());
    
    Node<T> * parentNode = getNilTNode();
    Node<T> * currentNode = getRoot();
    
    while (currentNode != getNilTNode()){
        parentNode = currentNode;
        if (nodeToInsert->getKey() <= currentNode->getKey()) {
            currentNode = currentNode->getLeft();
        } else {
            currentNode = currentNode->getRight();
        }
    }
    
    nodeToInsert->setParent(parentNode);
    
    if(parentNode == getNilTNode()) {
        setRoot(nodeToInsert);
    } else if (nodeToInsert->getKey() <= parentNode->getKey()) {
        parentNode->setLeft(nodeToInsert);
    } else {
        parentNode->setRight(nodeToInsert);
    }
}

#endif /* BinarySearchTree_hpp */
