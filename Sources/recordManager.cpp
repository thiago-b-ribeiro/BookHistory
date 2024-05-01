/**
 * 
 * @author Thiago Barbosa Ribeiro
 * @copyright All rights reserved to the author
*/

#include "recordManager.h"
#include <iostream>

cRecordManager::cRecordManager(){}

cRecordManager::~cRecordManager(){}

void cRecordManager::InsertRecord(stBook & stBook){
    oDestiny.open("BooksRead.txt", std::ios_base::app);
    oDestiny << stBook.id         << ";" 
             << stBook.title      << ";" 
             << stBook.pageCount;
    oDestiny.close();
}

std::vector<stBook> cRecordManager::ListRecords(){
    std::vector<stBook> oList;
    stBook oBook;

    oOrigin.open("BooksRead.txt", std::ios_base::in);

    if(!oOrigin.is_open()){

        std::cout << "Nao foi possivel abrir o arquivo." << std::endl;

    } else{

        while(!oOrigin.eof()){

            std::getline(oOrigin, oBook.id, ';');
            std::getline(oOrigin, oBook.title, ';');
            oOrigin >> oBook.pageCount;

            oList.push_back(oBook);

        }
    }

    oOrigin.close();

    return(oList);
}

void cRecordManager::DeleteRecord(std::string lineToDelete){
    oOrigin.open("BookRead.txt");
    oTemporaryFile.open("BookRead.txt");
    std::string oTemporaryLine;

    if(!oOrigin.is_open()){

        std::cout << "Nao foi possivel abrir o arquivo." << std::endl;

    } else{
        while(std::getline(oOrigin, oTemporaryLine)){
            std::string id(oTemporaryLine.begin(), oTemporaryLine.begin() + oTemporaryLine.find(" "));
            if (id != lineToDelete)
            oTemporaryFile << oTemporaryLine << std::endl;
        }
    }

    oOrigin.close();
    oTemporaryFile.close();
}