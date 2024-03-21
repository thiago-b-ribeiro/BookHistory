/**
 * 
 * @author Thiago Barbosa Ribeiro
 * @copyright All rights reserved to the author
*/

#include "recordManager.h"
#include <string>
#include <iostream>

cRecordManager::cRecordManager(){}

cRecordManager::~cRecordManager(){}

void cRecordManager::InsertRecord(stBook & stBook){
    oDestiny.open("BooksRead.txt", std::ios_base::app);
    oDestiny << stBook.id         << "; " 
             << stBook.title      << "; " 
             << stBook.pageCount  << std::endl;
    oDestiny.close();
    }