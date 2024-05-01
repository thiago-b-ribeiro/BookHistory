/**
 * 
 * @author Thiago Barbosa Ribeiro
 * @copyright All rights reserved to the author
*/

#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

#include "bookhistory.h"
#include <fstream>
#include <vector>

class cRecordManager{
    public:
        cRecordManager();
        ~cRecordManager();
        void InsertRecord(stBook & stBook);
        std::vector<stBook> ListRecords();
        void DeleteRecord(std::string lineToDelete);

    private:
        std::ofstream oDestiny;
        std::ifstream oOrigin;
        std::ofstream oTemporaryFile;

};

#endif