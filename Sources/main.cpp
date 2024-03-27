#include "bookhistory.h"
#include "messageTraffic.h"
#include "menu.h"
#include "recordManager.h"
#include "ASCIIArt.h"
#include <iostream>
#include <curl/curl.h>

int main(int argc, char *argv[]){

  cBookHistory   * oBookHistory   = new cBookHistory();  
  cRecordManager * oRecordManager = new cRecordManager();
  cMenu          * oMenu          = new cMenu();
  std::vector<stBook>      oVectorBooks;
  std::vector<std::string> oOptionsMenu;

  cASCIIArt::ShowAsciiArt();
  
  int iChoice = oMenu->CreateMenu(oBookHistory->GetMainMenu());

  switch(iChoice){
    case 1:
      std::cout << "Digite o titulo que deseja pesquisar: ";
      std::getline(std::cin, oBookHistory->oTitleBook);

      oVectorBooks = oBookHistory->SearchBook(oBookHistory->oTitleBook);

      for(std::vector<stBook>::iterator itr = oVectorBooks.begin(); itr != oVectorBooks.end(); ++itr){
        oOptionsMenu.push_back((*itr).id);
      }

      std::cout << "\nO resultado da pesquisa eh: \n" << std::endl;
      iChoice = oMenu->CreateMenu(oOptionsMenu);

      oRecordManager->InsertRecord(oVectorBooks[iChoice - 1]);

      break;

    case 2:
      std::vector<stBook> oListRecords = oRecordManager->ListRecords();
      
      if(oListRecords.size() > 0){
        std::cout << "A quantidade de livros lidos eh: " << oListRecords.size() << std::endl;
        std::cout << "Os livros lidos foram: " << std::endl;

        for(std::vector<stBook>::iterator itr = oListRecords.begin(); itr != oListRecords.end(); ++itr){
          std::cout << "     - " << itr->id << "     " << itr->title << "     " << itr->pageCount << std::endl;
        }

      }

      break;
  }


  return (0);
}