//
//  Node.hpp
//  Insiemi_RBTree
//
//  Created by Denny Caruso on 10/02/21.
//

#ifndef Node_hpp
#define Node_hpp

//#include <algorithm>

enum color { BLACK, RED };

template <class T> class Node {
private:
    int key;
    bool color;
    Node<T> * parent;
    Node<T> * left;
    Node<T> * right;
    T data;
    
    /*
     
    int height;
    int minHeight;
    int blackHeight;
    
    int calculateHeightUtility(Node<T> * curr);
    int calculateMinHeightUtility(Node<T> * curr);
//    std::pair<int, int> calculateHeightMinHeightUtility(Node<T> * curr);
     
     */
    
public:
    // Costruttore Default con impostazione aggiunta del colore a BLACK
    Node() : parent { nullptr }, left { nullptr }, right { nullptr } {
        setColor(BLACK);
        /*
         
        setHeight(0);
        setMinHeight(0);
        setBlackHeight(0);
        
        */
    }
    
    // Costruttore custom con impostazione del campo key, data e color
    Node(int key, T data) : parent { nullptr }, left { nullptr }, right { nullptr } {
        setKey(key);
        setColor(BLACK);  // doubt here <???> there wasn't on code of lesson exercise #14.1
        setData(data);
        /*
         
        setHeight(0);
        setMinHeight(0);
        setBlackHeight(0);
         
         */
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
    /*
     
    void setHeight(int newHeight);
    void setMinHeight(int newMinHeight);
    void setBlackHeight(int newBlackHeight);
     
     */
    
    
    // Metodi Pubblici Getters
    int getKey();
    bool getColor();
    Node<T> * getParent();
    Node<T> * getLeft();
    Node<T> * getRight();
    T getData();
    
    /*
     
    int getHeight();
    int getMinHeight();
    int getBlackHeight();
    
    
    // Metodi Pubblici Ulteriori
    int calculateHeight();
    int calculateMinHeight();
//    std::pair<int, int> calculateHeightMinHeight();
    void calculateBlackHeight();
     
     */
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
//
//template <class T> void Node<T>::setHeight(int newHeight) {
//    this->height = newHeight;
//}
//
//template <class T> void Node<T>::setMinHeight(int newMinHeight) {
//    this->minHeight = newMinHeight;
//}
//
//template <class T> void Node<T>::setBlackHeight(int newBlackHeight) {
//    this->blackHeight = newBlackHeight;
//}


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
//
//template <class T> int Node<T>::getHeight() {
//    return this->height;
//}
//
//template <class T> int Node<T>::getMinHeight() {
//    return this->minHeight;
//}
//
//template <class T> int Node<T>::getBlackHeight() {
//    return this->blackHeight;
//}


// Implementazione Metodi Pubblici Ulteriori
//template <class T> int Node<T>::calculateHeightUtility(Node<T> * curr) {
//    if (curr == nullptr) return -1;
//
//    int recursiveHeight = (1 + std::max(calculateHeightUtility(curr->getLeft()), calculateHeightUtility(curr->getRight())));
//    curr->setHeight(recursiveHeight);
//    return recursiveHeight;
//}
//
//template <class T> int Node<T>::calculateHeight() {
//    int recursiveHeight = calculateHeightUtility(this);
////    if (recursiveHeight != -1) setHeight(recursiveHeight);
//    return recursiveHeight;
//}
//
//template <class T> int Node<T>::calculateMinHeightUtility(Node<T> * curr) {
//    if (curr == nullptr) return -1;
//
//    int recursiveMinHeight = (1 + std::min(calculateMinHeightUtility(curr->getLeft()), calculateMinHeightUtility(curr->getRight())));
//    curr->setMinHeight(recursiveMinHeight);
//    return recursiveMinHeight;
//}
//
//template <class T> int Node<T>::calculateMinHeight() {
//    int recursiveMinHeight = calculateMinHeightUtility(this);
////    if (recursiveMinHeight != -1) setMinHeight(recursiveMinHeight);
//    return recursiveMinHeight;
//}

//
//template <class T> std::pair<int, int> Node<T>::calculateHeightMinHeightUtility(Node<T> * curr) {
//    if (curr == nullptr) return std::pair<int, int>(-1, -1);
//
//    std::pair<int, int> height_minHeight = std::minmax(calculateHeightMinHeightUtility(curr->getLeft()), calculateHeightMinHeightUtility(curr->getRight()));
//    return height_minHeight;
//}
//
//template <class T> std::pair<int, int> Node<T>::calculateHeightMinHeight() {
//    std::pair<int, int> height_minHeight = calculateHeightMinHeightUtility(this);
//
//    if (height_minHeight.first != -1)   setHeight(height_minHeight.first);
//    if (height_minHeight.second != -1)  setMinHeight(height_minHeight.second);
//
//    return height_minHeight;
//}

//
//template <class T> void Node<T>::calculateBlackHeight() {
//
//}


#endif /* Node_hpp */
