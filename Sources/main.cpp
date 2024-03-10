#include "bookhistory.h"
#include "messageTraffic.h"
#include <iostream>
#include <curl/curl.h>

int main(int argc, char *argv[]){

  std::string oTitleBook = "O Mundo de Sofia";

  cBookHistory * oBookHistory = new cBookHistory();  
  std::vector<stBook> oVectorBook = oBookHistory->SearchBook(oTitleBook);

  std::cout << "A quantidade de livros encontrados eh: " << oVectorBook.size() << std::endl;
  std::cout << "Os titulos dos livros sao: \n" << std::endl;
  for(std::vector<stBook>::iterator itr = oVectorBook.begin(); itr != oVectorBook.end(); ++itr){
    std::cout << "   - " << (*itr).title << std::endl;
  }

  std::cout << std::endl;
  return (0);
}