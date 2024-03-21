/**
 * 
 * @author Thiago Barbosa Ribeiro.
 * @copyright All rights reserved to the author.
*/

#include "menu.h"
#include <iostream>

cMenu::cMenu(){}

cMenu::~cMenu(){}

int cMenu::CreateMenu(const std::vector<std::string> & oOptions){

  iOptionNumber = 1;
  
  for(std::vector<std::string>::const_iterator itr = oOptions.begin(); itr != oOptions.end(); ++itr){
    std::cout << "   " << iOptionNumber << " - " << *itr << std::endl;
    ++iOptionNumber;
  }

  while(true){
    std::cout << "\nDigite a opcao desejada: ";
    std::cin >> iChoice;
    std::cin.get();
    
    if(iChoice >= 1 && iChoice <= iOptionNumber){
      break;
    } else{
      std::cout << "Escolha um numero entre 1 e " << iOptionNumber << "." << std::endl;
    }
  }

  return(iChoice);
}