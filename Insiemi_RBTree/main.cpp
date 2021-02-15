//
//  main.cpp
//  Insiemi_RBTree
//
//  Created by Denny Caruso on 10/02/21.
//

#include "Sets.hpp"

int main() {
    const char * usrMenuMessage =   "\n\n\nBenvenuti a 'Insiemi implementati con alberi Red  Black' ...\n\nGli insiemi presenti nel file caricato sono i seguenti. "
                                    "Inserisci l'ID di un primo \ninsieme, poi l'ID di un secondo insieme e infine l'operazione che vuoi eseguire \nfra questi due insiemi.";
    
    const char * insertFirstSetID_message = "\nDigita qui l'ID del primo insieme: ";
    const char * insertSecondSetID_message = "\nDigita qui l'ID del secondo insieme: ";
    const char * insertSetOperationID_message = "\nScegli il codice dell'operazione insiemistica:\n1) Unione\n2) Intersezione\n3) Differenza\n\nDigita qui: ";
    const char * resultMessage = "\nIl risultato della tua operazione insiemistica, è il seguente: \n";
    const char * errorMenuMessage = "\n\n** Invalid input. Try again... **\n\n";
    const char * usrMenuContinueMessage = "Vuoi eseguire un'altra operazione insiemistica? (Y = YES / N = NO).\nScegli: ";
    unsigned int firstSetID, secondSetID, setOperationCodeID;
    char usrContinue;
    
    Sets<int> tempSets = Sets<int>("input.txt");
    
    do {
        std::cout << usrMenuMessage;
        tempSets.printSets();
        
        std::cout << insertFirstSetID_message;
        while (!(std::cin >> firstSetID)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << errorMenuMessage << insertFirstSetID_message;
        }
        
        std::cout << insertSecondSetID_message;
        while (!(std::cin >> secondSetID)){
            std::cout << insertSecondSetID_message;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << errorMenuMessage << insertSecondSetID_message;
        }
        
        std::cout << insertSetOperationID_message;
        while (!(std::cin >> setOperationCodeID)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << errorMenuMessage << insertSetOperationID_message;
        }

        Set<int> * tempSet = tempSets.requestSetOperation(setOperationCodeID, firstSetID, secondSetID);
        if (tempSet != nullptr) {
            std::cout << resultMessage;
            tempSet->printSet();
            std::cout << std::endl << std::endl;
        } else {
            std::cout << errorMenuMessage;
        }
        
        std::cout << usrMenuContinueMessage;
        while (!(std::cin >> usrContinue)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << errorMenuMessage << usrMenuContinueMessage;
        }
    } while (usrContinue == 'Y' || usrContinue == 'y');
    return 0;
}
