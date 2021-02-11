//
//  main.cpp
//  Insiemi_RBTree
//
//  Created by Denny Caruso on 10/02/21.
//

#include "RedBlackTree.hpp"

int main() {
/*
    Node<float> * temp_1 = new Node<float>(3, 10.33);
    Node<float> * temp_2 = new Node<float>(4, 10.33);
    Node<float> * temp_3 = new Node<float>(5, 10.33);
    
    temp_1->setLeft(temp_2);
    temp_2->setLeft(temp_3);
//    int height = temp_1->calculateHeight();
//    int minHeight = temp_1->calculateMinHeight();
//    std::cout << "HEIGHT: " << height << "\n";
//    std::cout << "MIN_HEIGHT: " << minHeight << "\n";
//
//
//    std::cout << "HEIGHT temp2: " << temp_2->getHeight() << "\n";
//    std::cout << "MIN_HEIGHT temp2: " << temp_2->getMinHeight() << "\n";
//    std::cout << "HEIGHT temp3: " << temp_3->getHeight() << "\n";
//    std::cout << "MIN_HEIGHT temp3: " << temp_3->getMinHeight() << "\n";
    
    BinarySearchTree<float> bst;
    bst.insertNode(10, 10.33);
    bst.insertNode(5, 10.33);
    bst.insertNode(15, 10.33);
    bst.insertNode(2, 10.33);
    bst.insertNode(6, 10.33);
    bst.insertNode(11, 10.33);
    bst.insertNode(17, 10.33);
    bst.insertNode(10, 10.33);
    bst.insertNode(20, 10.33);
    
    bst.inorderVisit(bst.getRoot());
    std::vector<Node<float>> * sortedArray = bst.buildSortedArray();
    std::cout << "\n";
*/
    
/*
    Duplicazione Albero (non si dovrebbero settare anche i figli e il padre
    dal momento che quest'operazione è quella che si farà sull'array di Nodi copia per andare a
    inserire ogni volta un nuovo nodo nell'albero risultante dall'operazione
    insiemistica che non ha nulla a che vedere con i ptr al vecchio albero
*/
    
/*
    Node<float> * rootLocal = new Node<float>(bst.getRoot()->getKey(), bst.getRoot()->getData());
//    rootLocal->setLeft(new Node<float> (*bst.getRoot()->getLeft()));
//    rootLocal->setRight(new Node<float> (*bst.getRoot()->getRight()));
//    rootLocal->setParent(new Node<float> (*bst.getNilTNode()));
    // Il nilT cambia indirizzo solo per il padre della radice
    
    
    
    std::cout << "SUCC: " << bst.getSuccessor(bst.getRoot())->getKey() << "\n";
    Node<float> *searchedNode = bst.searchNode(0, bst.getRoot());
 */
    
    RedBlackTree<float> redBlackTree = RedBlackTree<float>();
    
    redBlackTree.insertNodeRB(7, 20.0);
    redBlackTree.insertNodeRB(2, 20.0);
    redBlackTree.insertNodeRB(3, 20.0);
    redBlackTree.insertNodeRB(4, 20.0);
    redBlackTree.insertNodeRB(6, 20.0);
    redBlackTree.insertNodeRB(9, 20.0);
    redBlackTree.insertNodeRB(11, 20.0);
    redBlackTree.insertNodeRB(18, 20.0);
    redBlackTree.insertNodeRB(18, 20.0);
    
    std::cout << "PREORDER: \n\n";
    redBlackTree.preorderVisit(redBlackTree.getRoot());
    std::cout << "\n\n";
    Node<float> * nodeToDelete = redBlackTree.searchNode(6, redBlackTree.getRoot());
    if (nodeToDelete != nullptr) {
        redBlackTree.deleteNodeRB(nodeToDelete);
    }
    
    nodeToDelete = redBlackTree.searchNode(18, redBlackTree.getRoot());
    if (nodeToDelete != nullptr) {
        redBlackTree.deleteNodeRB(nodeToDelete);
    }
    
    nodeToDelete = redBlackTree.searchNode(9, redBlackTree.getRoot());
    if (nodeToDelete != nullptr) {
        redBlackTree.deleteNodeRB(nodeToDelete);
    }
//    redBlackTree.deleteNodeRB(6);
//    redBlackTree.deleteNodeRB(4);
//    redBlackTree.deleteNodeRB(30);
//    redBlackTree.deleteNodeRB(12);
    std::cout << "\n\nElimino 6...\nElimino 18...\nElimino 9...\n\n";
    
    Node<float> * min = redBlackTree.getMinimum(redBlackTree.getRoot());
    std::cout << "MIN: " << min->getKey() << "\n";
    
    Node<float> * max = redBlackTree.getMaximum(redBlackTree.getRoot());
    std::cout << "MAX: " << max->getKey() << "\n";
    
    std::cout << "PREORDER: \n\n";
    redBlackTree.preorderVisit(redBlackTree.getRoot());
    std::cout << "\n\n";
    return 0;
}
