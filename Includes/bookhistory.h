/**
 * Software para armazenamento e consulta de livros em leitura e lidos.
 * @author Thiago Barbosa Ribeiro.
 * @copyright All rights reserved to the author.
*/

#include <string>
#include <vector>

#ifndef BOOKHISTORY_H
#define BOOKHISTORY_H

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
    protected:
    private:
};

#endif