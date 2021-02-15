//
//  RedBlackTree.hpp
//  Insiemi_RedBlackTree
//
//  Created by Denny Caruso on 11/02/21.
//

#ifndef RedBlackTree_hpp
#define RedBlackTree_hpp

#include "BinarySearchTree.hpp"

template <class T> class RedBlackTree: public BinarySearchTree<T> {
private:
    // Metodi Ulteriori Privati
    void leftRotate(Node<T> * current);
    void rightRotate(Node<T> * current);
    
    void transplantRB(Node<T> * to, Node<T> * from);
    void deleteFixUpRB(Node<T> * current);
    
public:
    // Costruttore
    RedBlackTree() {
        BinarySearchTree<T>();
    }
    
    
    // Distruttore
    virtual ~RedBlackTree() { }
    
    
    // Metodi Ulteriori Pubblici
    void insertNodeRB(int key, T data);
    void deleteNodeRB(Node<T> * current);
};


// Implementazione Metodi Ulteriori
template <class T> void RedBlackTree<T>::leftRotate(Node<T> * x) {
    Node <T> * y = x->getRight();
    x->setRight(y->getLeft());
    if (y->getLeft() != this->getNilTNode()) y->getLeft()->setParent(x);
    
    y->setParent(x->getParent());
    if (x->getParent() == this->getNilTNode()) {
        this->setRoot(y);
    } else if (x == (x->getParent()->getLeft())){
        x->getParent()->setLeft(y);
    } else {
        x->getParent()->setRight(y);
    }
    y->setLeft(x);
    x->setParent(y);
}

template <class T> void RedBlackTree<T>::rightRotate(Node<T> * x) {
    Node <T> *y = x->getLeft();
    x->setLeft(y->getRight());
    if (y->getRight() != this->getNilTNode()) y->getRight()->setParent(x);
    
    y->setParent(x->getParent());
    if (x->getParent() == this->getNilTNode()){
        this->setRoot(y);
    } else if (x == x->getParent()->getLeft()){
        x->getParent()->setLeft(y);
    } else {
        x->getParent()->setRight(y);
    }
    y->setRight(x);
    x->setParent(y);
}

template <class T> void RedBlackTree<T>::transplantRB(Node<T> * to, Node<T> * from) {
    if (to->getParent() == this->getNilTNode() || to->getParent() == nullptr) {
        this->setRoot(from);
    } else if (to == (to->getParent())->getLeft()) {
        (to->getParent())->setLeft(from);
    } else {
        (to->getParent())->setRight(from);
    }
    
    from->setParent(to->getParent());
}

template <class T> void RedBlackTree<T>::deleteFixUpRB(Node<T> * x) {
    Node <T> * w;
    while (x != this->getRoot() && x->getColor() == BLACK) {
        if (x == (x->getParent())->getLeft()) {
            w = (x->getParent())->getRight();
            
            if (w->getColor() == RED) {
                w->setColor(BLACK);
                (x->getParent())->setColor(RED);
                this->leftRotate(x->getParent());
                w = (x->getParent())->getRight();
            }
            
            if ((w->getLeft())->getColor() == BLACK && (w->getRight())->getColor() == BLACK) {
                w->setColor(RED);
                x = x->getParent();
            } else {
                if ((w->getRight())->getColor() == BLACK) {
                    (w->getLeft())->setColor(BLACK);
                    w->setColor(RED);
                    this->rightRotate(w);
                    w = (x->getParent())->getRight();
                }
                
                w->setColor((x->getParent()->getColor()));
                (x->getParent())->setColor(BLACK);
                (w->getRight())->setColor(BLACK);
                this->leftRotate(x->getParent());
                x = this->getRoot();
            }
        } else {
            w = (x->getParent())->getLeft();
            
            if (w->getColor() == RED) {
                w->setColor(BLACK);
                (x->getParent())->setColor(RED);
                this->rightRotate(x->getParent());
                w = (x->getParent())->getLeft();
            }
            
            if ((w->getRight())->getColor() == BLACK && (w->getLeft())->getColor() == BLACK) {
                w->setColor(RED);
                x = x->getParent();
            } else {
                if ((w->getLeft())->getColor() == BLACK) {
                    (w->getRight())->setColor(BLACK);
                    w->setColor(RED);
                    this->leftRotate(w);
                    w = (x->getParent())->getLeft();
                }
                
                w->setColor((x->getParent()->getColor()));
                (x->getParent())->setColor(BLACK);
                (w->getLeft())->setColor(BLACK);
                this->rightRotate(x->getParent());
                x = this->getRoot();
            }
        }
    }
    x->setColor(BLACK);
}

template <class T> void RedBlackTree<T>::insertNodeRB(int key, T data) {
    Node<T> * x = this->advancedInsertNode(key, data);
    x->setColor(RED);
    
    while (x != this->getRoot() && (x->getParent()->getColor() == RED)) {
        if (x->getParent() == ((x->getParent())->getParent())->getLeft()) {
            Node<T> * y = ((x->getParent())->getParent())->getRight();
            
            if (y != this->getNilTNode() && y->getColor() == RED) {
                (x->getParent())->setColor(BLACK);
                y->setColor(BLACK);
                ((x->getParent())->getParent())->setColor(RED);
                x = ((x->getParent())->getParent());
            } else {
                if (x == (x->getParent())->getRight()) {
                    x = x->getParent();
                    leftRotate(x);
                }
                
                (x->getParent())->setColor(BLACK);
                ((x->getParent())->getParent())->setColor(RED);
                rightRotate(((x->getParent())->getParent()));
            }
        } else {
            Node<T> * y = ((x->getParent())->getParent())->getLeft();
            
            if (y != this->getNilTNode() && y->getColor() == RED) {
                (x->getParent())->setColor(BLACK);
                y->setColor(BLACK);
                ((x->getParent())->getParent())->setColor(RED);
                x = ((x->getParent())->getParent());
            } else {
                if (x == (x->getParent())->getLeft()) {
                    x = x->getParent();
                    rightRotate(x);
                }
                
                (x->getParent())->setColor(BLACK);
                ((x->getParent())->getParent())->setColor(RED);
                leftRotate(((x->getParent())->getParent()));
            }
        }
    }
    
    (this->getRoot())->setColor(BLACK);
}

template <class T> void RedBlackTree<T>::deleteNodeRB(Node<T> * z) {
    Node<T> * x;
    Node<T> * y;
    
    if (z == this->getNilTNode() || z == nullptr) return;
    bool yOriginalColor;

    y = z;
    yOriginalColor = y->getColor();
    
    if (z->getLeft() == this->getNilTNode()) {
        x = z->getRight();
        transplantRB(z, z->getRight());
    } else if (z->getRight() == this->getNilTNode()) {
        x = z->getLeft();
        transplantRB(z, z->getLeft());
    } else {
        y = this->getMinimum(z->getRight());
        yOriginalColor = y->getColor();
        x = y->getRight();
        
        if (y->getParent() == z) {
            x->setParent(y);
        } else {
            transplantRB(y, y->getRight());
            y->setRight(z->getRight());
            (y->getRight())->setParent(y);
        }
        
        transplantRB(z, y);
        
        y->setLeft(z->getLeft());
        (y->getLeft())->setParent(y);
        y->setColor(z->getColor());
    }
    
    if (yOriginalColor == BLACK) deleteFixUpRB(x);
    this->getNilTNode()->setParent(nullptr);
}

#endif /* RedBlackTree_hpp */
