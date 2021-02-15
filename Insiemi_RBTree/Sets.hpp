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
#include <string>
#include <sstream>

#define streamNotOpenSuccessfully 100   //  Codice di errore relativo alla mancata apertura dello stream di input
#define invalidUserSetChoice 200        /*
                                            Codice di errore relativo alla scelta non valida di un insieme
                                            da parte dell'utente
                                        */
#define invalidUserSetOperationCode 300 /*
                                            Codice di errore relativo alla scelta non valida di un'operazione
                                            da parte dell'utente
                                        */

#define unionOperationCode       1
#define intersectOperationCode   2
#define differenceOperationCode  3

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
    bool checkInputSetID(unsigned int setID);
        /*
            Verifica che l'insieme (mediante identificativo) scelto dall'utente,
            sia valido o meno.
         */
    void buildSets();
        /*
            Costruisce a partire dal file di input prescelto, gli insiemi e li
            inserisce all'interno del vector di puntatori a insiemi parametrizzati
            dal parametro T
         */
    
public:
    // Costruttore
    Sets(std::string inputFilePath) {
        setInputFilePath(inputFilePath);
        setInputFileStream(new std::ifstream);
        if (!(openInputFileStream())) {
            printError(streamNotOpenSuccessfully);
            exit(EXIT_FAILURE);
        }
        
        setSets(new std::vector<Set<T> *>);
        buildSets();
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
    Set<T> * requestSetOperation(unsigned int setOperationID, unsigned int firstSetID, unsigned int secondSetID);
    /*
        Permette di eseguire le operazioni insiemistiche. In particolar modo
        se i parametri sono validi, esegue l'operazione identificata da setOperationID,
        tra l'insieme identificato da firstSetID e l'insieme identificato da
        secondSetID
     */
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
        case invalidUserSetOperationCode:
            std::cout << std::endl << "Set Operation Code not valid. Please try again..." << std::endl;
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

template <class T> bool Sets<T>::checkInputSetID(unsigned int setID) {
    if (setID < 1 || setID > getSets()->size()) {
        printError(invalidUserSetChoice);
        return false;
    }
    return true;
}

template <class T> void Sets<T>::buildSets() {
    if (!(getInputFileStream()->is_open())) {
        openInputFileStream();
        if (!(getInputFileStream()->is_open())) {
            printError(streamNotOpenSuccessfully);
            std::cout << "\n...Abort\n";
            exit(EXIT_FAILURE);
        }
    }
    
    /*
        istringstream:
            Input stream class to operate on strings. Objects of this class use a string buffer that
            contains a sequence of characters. This sequence of characters can be accessed directly
            as a string object, using member str.
            https://www.cplusplus.com/reference/sstream/istringstream/
     */
    
    std::string line;
    while (getline(*(getInputFileStream()), line)) {
        Set<T> * newSet = new Set<T>();
        
        std::istringstream is(line);
        T singleNumber;
        while (is >> singleNumber) {
            newSet->insertElement(singleNumber, singleNumber);
        }
        
        getSets()->push_back(newSet);
    }
    
}

template <class T> void Sets<T>::printSets() {
    std::cout << "\n\nSets...\n";
    for (auto & singleSet: *(getSets())) singleSet->printSet();
    std::cout << "\n";
}

template <class T> void Sets<T>::printSetWithID(unsigned int setID) {
    if (!(checkInputSetID(setID))) return;
    
    auto setToPrint = getSets()->at(setID - 1);
    setToPrint->printSet();
}

template <class T> Set<T> * Sets<T>::requestSetOperation(unsigned int setOperationID, unsigned int firstSetID, unsigned int secondSetID) {
    if (!(checkInputSetID(firstSetID))) return nullptr;
    if (!(checkInputSetID(secondSetID))) return nullptr;
    
    Set<T> * resultSet = new Set<T>();
    Set<T> * firstSet = getSets()->at(firstSetID - 1);
    Set<T> * secondSet = getSets()->at(secondSetID - 1);
    
    switch (setOperationID) {
        case unionOperationCode:
            resultSet = firstSet->unionOperation(secondSet);
            break;
        case intersectOperationCode:
            resultSet = firstSet->intersectOperation(secondSet);
            break;
        case differenceOperationCode:
            resultSet = firstSet->differenceOperation(secondSet);
            break;
        default:
            delete resultSet;
            printError(invalidUserSetOperationCode);
            return nullptr;
            break;
    }
    
    getSets()->push_back(resultSet);
    return resultSet;
}

#endif /* Sets_hpp */
