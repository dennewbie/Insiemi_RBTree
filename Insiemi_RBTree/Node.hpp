//
//  Node.hpp
//  Insiemi_RBTree
//
//  Created by Denny Caruso on 10/02/21.
//

#ifndef Node_hpp
#define Node_hpp

enum color { BLACK, RED };

template <class T> class Node {
private:
    int key;
    bool color;
    Node<T> * parent;
    Node<T> * left;
    Node<T> * right;
    T data;
    
public:
    // Costruttore Default con impostazione aggiunta del colore a BLACK
    Node() : parent { nullptr }, left { nullptr }, right { nullptr } {
        setKey(0);
        setColor(BLACK);
    }
    
    // Costruttore custom con impostazione del campo key, data e color
    Node(int key, T data) : parent { nullptr }, left { nullptr }, right { nullptr } {
        setKey(key);
        setColor(BLACK);
        setData(data);
    }
    
    
    // Distruttore
    virtual ~Node() { }
    
    
    // Metodi Pubblici Setters
    void setKey(int newKey);
    void setColor(bool newColor);
    void setParent(Node<T> * newParent);
    void setLeft(Node<T> * newLeft);
    void setRight(Node<T> * newRight);
    void setData(T newData);
    
    
    // Metodi Pubblici Getters
    int getKey();
    bool getColor();
    Node<T> * getParent();
    Node<T> * getLeft();
    Node<T> * getRight();
    T getData();
};


// Implementazion Metodi Setters
template <class T> void Node<T>::setKey(int newKey) {
    this->key = newKey;
}

template <class T> void Node<T>::setColor(bool newColor) {
    this->color = newColor;
}

template <class T> void Node<T>::setParent(Node<T> * newParent) {
    this->parent = newParent;
}

template <class T> void Node<T>::setLeft(Node<T> * newLeft) {
    this->left = newLeft;
}

template <class T> void Node<T>::setRight(Node<T> * newRight) {
    this->right = newRight;
}

template <class T> void Node<T>::setData(T newData) {
    this->data = newData;
}


// Implementazion Metodi Getters
template <class T> int Node<T>::getKey() {
    return this->key;
}

template <class T> bool Node<T>::getColor() {
    return this->color;
}

template <class T> Node<T> * Node<T>::getParent() {
    return this->parent;
}

template <class T> Node<T> * Node<T>::getLeft() {
    return this->left;
}

template <class T> Node<T> * Node<T>::getRight() {
    return this->right;
}

template <class T> T Node<T>::getData() {
    return this->data;
}

#endif /* Node_hpp */
