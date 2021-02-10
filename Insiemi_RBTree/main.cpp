//
//  main.cpp
//  Insiemi_RBTree
//
//  Created by Denny Caruso on 10/02/21.
//

#include "Node.hpp"
#include <iostream>

int main() {
    Node<float> * temp_1 = new Node<float>(3, 10.33);
    Node<float> * temp_2 = new Node<float>(4, 10.33);
    Node<float> * temp_3 = new Node<float>(5, 10.33);
    
    temp_1->setLeft(temp_2);
    temp_2->setLeft(temp_3);
    int height = temp_1->calculateHeight();
    int minHeight = temp_1->calculateMinHeight();
    std::cout << "HEIGHT: " << height << "\n";
    std::cout << "MIN_HEIGHT: " << minHeight << "\n";
    
    
    std::cout << "HEIGHT temp2: " << temp_2->getHeight() << "\n";
    std::cout << "MIN_HEIGHT temp2: " << temp_2->getMinHeight() << "\n";
    std::cout << "HEIGHT temp3: " << temp_3->getHeight() << "\n";
    std::cout << "MIN_HEIGHT temp3: " << temp_3->getMinHeight() << "\n";
    return 0;
}
