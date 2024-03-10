/**
 * Software para armazenamento e consulta de livros em leitura e lidos.
 * @author Thiago Barbosa Ribeiro.
 * @copyright All rights reserved to the author.
*/

#include "rapidjson/document.h"
#include "../Includes/messageTraffic.h"
#include <string>
#include <vector>

#ifndef BOOKHISTORY_H
#define BOOKHISTORY_H

#define ENDPOINT "https://www.googleapis.com/books/v1/volumes?q="
#define APIKEY "key=AIzaSyBPvMXUMZXVMKq8HdQjkx8Te7wTQJCLBFs"

struct stBook{
    std::string id;
    std::string title;
    std::vector<std::string> authors;
    int pageCount;
};

class cBookHistory{
    public:
        cBookHistory();
        ~cBookHistory();
        std::vector<stBook> SearchBook(std::string & oTitle);
        int CreateMenu(std::vector<std::string> & oOptions);

        cMessageTraffic * oMessageTraffic;

    protected:
    private:
        rapidjson::Document oJsonResponse;
        std::vector<stBook> oVectorBooks;
        std::string oResponse;
        stBook STBook;
};

#endif