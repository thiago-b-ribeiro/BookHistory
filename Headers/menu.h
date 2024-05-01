/**
 * 
 * @author Thiago Barbosa Ribeiro
 * @copyright All rights reserved to the author.
*/

#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

class cMenu{
    public:
        cMenu();
        ~cMenu();
        int CreateMenu(const std::vector<std::string> & oOptions);
    
    private:
        int iOptionNumber = 0;
        int iChoice = 0;
};

#endif