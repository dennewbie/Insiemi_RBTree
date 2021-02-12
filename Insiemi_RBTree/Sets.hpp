//
//  Sets.hpp
//  Insiemi_RBTree
//
//  Created by Denny Caruso on 12/02/21.
//

#ifndef Sets_hpp
#define Sets_hpp

#include "Set.hpp"
#include <fstream>
#include <iterator>

#define streamNotOpenSuccessfully 100   //  Codice di errore relativo alla mancata apertura dello stream di input
#define invalidUserSetChoice 200        /*
                                            Codice di errore relativo alla scelta non valida di un insieme
                                            da parte dell'utente
                                        */

#define union       1
#define intersect   2
#define difference  3

template <class T> class Sets {
private:
    std::vector<Set<T> *> * sets;
    std::string inputFilePath;
    std::ifstream * inputFileStream;
    
    // Metodi Set Privati
    void setSets(std::vector<Set<T> *> * newSets);
    void setInputFilePath(std::string newInputFilePath);
    void setInputFileStream(std::ifstream * newInputFileStream);
    
    
    // Metodi Get Privati
    std::vector<Set<T> *> * getSets();
    std::string getInputFilePath();
    std::ifstream * getInputFileStream();
    
    
    // Metodi Ulteriori Privati
    void printError(unsigned short int errorCode);  // Stampa gli errori che possono verificarsi
    bool openInputFileStream();                     // Apre lo stream di input
    void closeInputFileStream();                    // Chiude lo stream di input
    
    
    
public:
    // Costruttore
    Sets(std::string inputFilePath) {
        setSets(new std::vector<Set<T> *>);
        setInputFilePath(inputFilePath);
        setInputFileStream(new std::ifstream);
        if (!(openInputFileStream())) {
            printError(streamNotOpenSuccessfully);
            return;
        }
    }
    
    
    // Distruttore
    ~Sets() {
        closeInputFileStream();
        delete getInputFileStream();
        
        for (auto i = 0; i < getSets()->size(); i++) delete getSets()->at(i);
        getSets()->clear();
        delete getSets();
    }
    
    
    // Metodi Ulteriori Pubblici
    void printSets();
    void printSetWithID(unsigned int setID);
    Set<T> * requestSetOperation(unsigned int setOperationID, unsigned int firstSet, unsigned int secondSet);
};


// Implementazione Metodi Set
template <class T> void Sets<T>::setSets(std::vector<Set<T> *> * newSets) {
    this->sets = newSets;
}

template <class T> void Sets<T>::setInputFilePath(std::string newInputFilePath) {
    this->inputFilePath = newInputFilePath;
}

template <class T> void Sets<T>::setInputFileStream(std::ifstream * newInputFileStream) {
    this->inputFileStream = newInputFileStream;
}


// Implementazione Metodi Get
template <class T> std::vector<Set<T> *> * Sets<T>::getSets() {
    return this->sets;
}

template <class T> std::string Sets<T>::getInputFilePath() {
    return this->inputFilePath;
}

template <class T> std::ifstream * Sets<T>::getInputFileStream() {
    return this->inputFileStream;
}


// Implementazione Metodi Ulteriori
template <class T> void Sets<T>::printError(unsigned short int errorCode) {
    switch (errorCode) {
        case streamNotOpenSuccessfully:
            std::cout << std::endl << "Input Stream Not Open Successfully..." << std::endl;
            break;
        case invalidUserSetChoice:
            std::cout << std::endl << "Set ID not valid. Please try again..." << std::endl;
            break;
        default:
            std::cout << std::endl << "Generic Error..." << std::endl;
            break;
    }
}

template <class T> bool Sets<T>::openInputFileStream() {
    getInputFileStream()->open(getInputFilePath().c_str(), std::ifstream::in);
    if (getInputFileStream()->fail()) return false;
    
    return true;
}

template <class T> void Sets<T>::closeInputFileStream() {
    getInputFileStream()->close();
}

template <class T> void Sets<T>::printSets() {
    for (auto & singleSet: *(getSets())) {
        std::cout << "\nSet # " << singleSet->getID() << ":\n";
        singleSet->inorderVisit(singleSet->getRoot());
    }
}

template <class T> void Sets<T>::printSetWithID(unsigned int setID) {
    if (setID < 0 || setID >= getSets()->size()) {
        printError(invalidUserSetChoice);
        return;
    }
    
    auto setToPrint = getSets()->at(setID);
    std::cout << "\nSet # " << setToPrint->getID() << ":\n";
    setToPrint->inorderVisit(setToPrint->getRoot());
}

//template <class T> Set<T> * Sets<T>::requestSetOperation(unsigned int setOperationID, unsigned int firstSet, unsigned int secondSet) {
//
//}

#endif /* Sets_hpp */
