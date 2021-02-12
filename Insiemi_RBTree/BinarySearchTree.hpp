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
#include <vector>

template <class T> class BinarySearchTree {
private:
    Node<T> * root;
        // Puntatore a Node parametrizzato da T indicante la radice del BST
    Node<T> * nilTNode = new Node<T>();
        /*
            Puntatore a Node parametrizzato da T indicante il nodo generico NIL_T.
            Utilizzato al posto di nullptr come padre della root e come figlio dei
            nodi foglia del BST
         */
    
    
    // Metodi Ulteriori Privati
    void transplant(Node<T> * to, Node<T> * from);
    void inorderVisitBuildArray(Node <T> * current, std::vector<Node<T>> * sortedArray);
        /*
            Usato da buildSortedArray(), consiste in una variante della visita inorder
            per memorizzare i vertici in maniera ordinata in un vector.
         */

protected:
    // Metodi Set Protetti
    void setRoot(Node<T> * newRoot);
    
    
    // Metodi Ulteriori Protetti
    Node<T> * advancedInsertNode(int key, T data);
    void insertNode(int key, T data);
    void deleteNode(Node<T> *  nodeToDelete);
    
public:
    // Costruttore che imposta la radice col nodo NIL_T
    BinarySearchTree() {
        setRoot(getNilTNode());
    }
    
    
    // Distruttore
    virtual ~BinarySearchTree();
    
    
    // Metodi Get Pubblici
    Node<T> * getRoot();
    Node<T> * getNilTNode();
    
    
    // Metodi Ulteriori Pubblici
    Node<T> * getMinimum(Node<T> * current);
    Node<T> * getMaximum(Node<T> * current);
    Node<T> * getPredecessor(Node<T> * current);
    Node<T> * getSuccessor(Node<T> * current);
    Node<T> * searchNode(int key, Node<T> *current);
    
    void preorderVisit(Node <T> * current);
    void inorderVisit(Node <T> * current);
    void postorderVisit(Node <T> * current);
    
    std::vector<Node<T>> * buildSortedArray();
        /*
            Restituisce un puntatore a vector di Nodi parametrizzati da T.
            Tale vector, grazie alla proprietà del BST e della inorderVisit
            (usata al suo interno in una sua variante), risulta ordinato
        */
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

template <class T> void BinarySearchTree<T>::inorderVisitBuildArray(Node <T> * current, std::vector<Node<T>> * sortedArray) {
    if (current != getNilTNode() && current != nullptr) {
        if (current->getLeft() != getNilTNode()) inorderVisitBuildArray(current->getLeft(), sortedArray);
        sortedArray->push_back(*current);
        if (current->getRight() != getNilTNode()) inorderVisitBuildArray(current->getRight(), sortedArray);
    }
}


// Implementazione Distruttore
template <class T> BinarySearchTree<T>::~BinarySearchTree() {
    while (this->getRoot() != getNilTNode()) deleteNode(getRoot());
}


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


// Implementazione Metodi Ulteriori Protetti
template <class T> Node<T> * BinarySearchTree<T>::advancedInsertNode(int key, T data) {
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
    
    return nodeToInsert;
}
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

template <class T> void BinarySearchTree<T>::deleteNode(Node<T> *  nodeToDelete) {
    if (nodeToDelete == getNilTNode()) return;
    
    if (nodeToDelete->getLeft() == getNilTNode()) {
        transplant(nodeToDelete, nodeToDelete->getRight());
    } else if (nodeToDelete->getRight() == getNilTNode()) {
        transplant(nodeToDelete, nodeToDelete->getLeft());
    } else {
        Node<T> * successor = getMinimum(nodeToDelete->getRight());
        
        if ((successor->getParent())->getKey() != nodeToDelete->getKey()) {
            transplant(successor, successor->getRight());
            successor->setRight(nodeToDelete->getRight());
            (successor->getRight())->setParent(successor);
        }
        
        transplant(nodeToDelete, successor);
        successor->setLeft(nodeToDelete->getLeft());
        (successor->getLeft())->setParent(successor);
        
        delete nodeToDelete;
    }
    
    getNilTNode()->setParent(nullptr);
}


// Implementazione Metodi Ulteriori Pubblici
template <class T> Node<T> * BinarySearchTree<T>::getMinimum(Node<T> * current) {
    while (current->getLeft() != getNilTNode()) current = current->getLeft();
    return current;
}

template <class T> Node<T> * BinarySearchTree<T>::getMaximum(Node<T> * current) {
    while (current->getRight() != getNilTNode()) current = current->getRight();
    return current;
}

template <class T> Node<T> * BinarySearchTree<T>::getPredecessor(Node<T> * current) {
    if (current->getLeft() != getNilTNode()) return getMaximum(current->getLeft());
    
    Node<T> * parentNode = current->getParent();
    while (parentNode != getNilTNode() && current == (parentNode->getLeft())) {
        current = parentNode;
        parentNode = parentNode->getParent();
    }
    
    return parentNode;
}

template <class T> Node<T> * BinarySearchTree<T>::getSuccessor(Node<T> * current) {
    if (current->getRight() != getNilTNode()) return getMinimum(current->getRight());
    
    Node<T> * parentNode = current->getParent();
    while (parentNode != getNilTNode() && current == (parentNode->getRight())) {
        current = parentNode;
        parentNode = parentNode->getParent();
    }
    
    return parentNode;
}

template <class T> Node<T> * BinarySearchTree<T>::searchNode(int key, Node <T> * current) {
    if (current == getNilTNode()) return nullptr;
    if (key == current->getKey()) return current;
    if (key <= current->getKey()) {
        return searchNode(key, current->getLeft());
    } else {
        return searchNode(key, current->getRight());
    }
}

template <class T> void BinarySearchTree<T>::preorderVisit(Node <T> * current) {
    if (current != getNilTNode()) {
        std::cout << current->getKey() << " ";
        if (current->getLeft() != getNilTNode()) preorderVisit(current->getLeft());
        if (current->getRight() != getNilTNode()) preorderVisit(current->getRight());
    }
}

template <class T> void BinarySearchTree<T>::inorderVisit(Node <T> * current) {
    if (current != getNilTNode()) {
        if (current->getLeft() != getNilTNode()) inorderVisit(current->getLeft());
        std::cout << current->getKey() << " ";
        if (current->getRight() != getNilTNode()) inorderVisit(current->getRight());
    }
}

template <class T> void BinarySearchTree<T>::postorderVisit(Node <T> * current) {
    if (current != getNilTNode()) {
        if (current->getLeft() != getNilTNode()) postorderVisit(current->getLeft());
        if (current->getRight() != getNilTNode()) postorderVisit(current->getRight());
        std::cout << current->getKey() << " ";
    }
}

template <class T> std::vector<Node<T>> * BinarySearchTree<T>::buildSortedArray() {
    std::vector<Node<T>> * sortedArray = new std::vector<Node<T>>;
    inorderVisitBuildArray(getRoot(), sortedArray);
    
    return sortedArray;
}

#endif /* BinarySearchTree_hpp */
