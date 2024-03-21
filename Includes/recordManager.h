/**
 * 
 * @author Thiago Barbosa Ribeiro
 * @copyright All rights reserved to the author
*/

#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

#include "bookhistory.h"
#include <fstream>

class cRecordManager{
    public:
        cRecordManager();
        ~cRecordManager();
        void InsertRecord(stBook & stBook);

    private:
        std::ofstream oDestiny;

};

#endif