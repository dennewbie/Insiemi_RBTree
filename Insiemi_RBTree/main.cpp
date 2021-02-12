//
//  main.cpp
//  Insiemi_RBTree
//
//  Created by Denny Caruso on 10/02/21.
//

#include "Set.hpp"

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
/*
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
    

    
    Node<float> temp_1 = Node<float>(2, 10.33);
    Node<float> temp_2 = Node<float>(3, 10.33);
    Node<float> temp_3 = Node<float>(6, 10.33);
    Node<float> temp_4 = Node<float>(8, 10.33);
    Node<float> temp_5 = Node<float>(9, 10.33);
    
    Node<float> temp_6 = Node<float>(1, 10.33);
    Node<float> temp_7 = Node<float>(3, 10.33);
    Node<float> temp_8 = Node<float>(7, 10.33);
    Node<float> temp_9 = Node<float>(10, 10.33);
    
    Set<float> tempSet = Set<float>();
    std::vector<Node<float>> * tempVec_1 = new std::vector<Node<float>>;
    tempVec_1->push_back(temp_1);
    tempVec_1->push_back(temp_2);
    tempVec_1->push_back(temp_3);
    tempVec_1->push_back(temp_4);
    tempVec_1->push_back(temp_5);
    
    std::vector<Node<float>> * tempVec_2 = new std::vector<Node<float>>;
    tempVec_2->push_back(temp_6);
    tempVec_2->push_back(temp_7);
    tempVec_2->push_back(temp_8);
    tempVec_2->push_back(temp_9);
    
    std::vector<Node<float>> * tempVec_3 = tempSet.merge(tempVec_1, tempVec_2);
    for (auto it: *tempVec_3) {
        std::cout << it.getKey() << "\n";
    }
    */
    
    
    Set<float> * tempSet_1 = new Set<float>();
    Set<float> * tempSet_2 = new Set<float>();
    
    tempSet_1->insertNodeRB(7, 20.0);
    tempSet_1->insertNodeRB(10, 20.0);
    tempSet_1->insertNodeRB(13, 20.0);
    tempSet_1->insertNodeRB(14, 20.0);
    tempSet_1->insertNodeRB(16, 20.0);
    tempSet_1->insertNodeRB(18, 20.0);
    
    tempSet_2->insertNodeRB(11, 20.0);
    tempSet_2->insertNodeRB(14, 20.0);
    tempSet_2->insertNodeRB(18, 20.0);
    tempSet_2->insertNodeRB(20, 20.0);
    
    Set<float> * tempSet_3 = new Set<float>();
    tempSet_3 = tempSet_1->unionOperation(tempSet_2);
    
    tempSet_3->inorderVisit(tempSet_3->getRoot());
    

    Set<float> * tempSet_4 = new Set<float>();
    
    std::cout << "\nhere";
    return 0;
}
