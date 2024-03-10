#include "bookhistory.h"
#include "messageTraffic.h"
#include <iostream>
#include <curl/curl.h>

int main(int argc, char *argv[]){

  std::string oTitleBook = "O Mundo de Sofia";

  cBookHistory * oBookHistory = new cBookHistory();  
  std::vector<stBook> oVectorBooks = oBookHistory->SearchBook(oTitleBook);

  std::vector<std::string> oOptionsMenu;
  for(std::vector<stBook>::iterator itr = oVectorBooks.begin(); itr != oVectorBooks.end(); ++itr){
    oOptionsMenu.push_back((*itr).title);
  }

  std::cout << "\nO resultado da pesquisa eh: \n" << std::endl;

  int iChoice = oBookHistory->CreateMenu(oOptionsMenu);

  std::cout << "A opcao escolhida foi: " << iChoice << "\n" << std::endl;

  return (0);
}