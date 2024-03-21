#include "bookhistory.h"
#include "messageTraffic.h"
#include "menu.h"
#include "recordManager.h"
#include "ASCIIArt.h"
#include <iostream>
#include <curl/curl.h>

int main(int argc, char *argv[]){

  cBookHistory * oBookHistory = new cBookHistory();  
  cMenu * oMenu = new cMenu();
  std::vector<stBook> oVectorBooks;
  std::vector<std::string> oOptionsMenu;

  cASCIIArt::ShowAsciiArt();
  
  int iChoice = oMenu->CreateMenu(oBookHistory->GetMainMenu());

  switch(iChoice){
    case 1:
      std::cout << "Digite o titulo que deseja pesquisar: ";
      std::getline(std::cin, oBookHistory->oTitleBook);

      oVectorBooks = oBookHistory->SearchBook(oBookHistory->oTitleBook);

      for(std::vector<stBook>::iterator itr = oVectorBooks.begin(); itr != oVectorBooks.end(); ++itr){
        oOptionsMenu.push_back((*itr).title);
      }

      std::cout << "\nO resultado da pesquisa eh: \n" << std::endl;
      iChoice = oMenu->CreateMenu(oOptionsMenu);
      std::cout << "A opcao escolhida foi: " << oVectorBooks[iChoice - 1].title << std::endl;

      cRecordManager * oRecordManager = new cRecordManager();
      oRecordManager->InsertRecord(oVectorBooks[iChoice - 1]);
  }


  return (0);
}