#include "bookhistory.h"
#include "messageTraffic.h"
#include "rapidjson/document.h"
#include <iostream>
#include <curl/curl.h>

int main(int argc, char *argv[]){

  std::string oUrl = "https://www.googleapis.com/books/v1/volumes/mR9zCQAAQBAJ?key=AIzaSyBPvMXUMZXVMKq8HdQjkx8Te7wTQJCLBFs";
  std::string oResponse;
  stBook STBook;

  cMessageTraffic * oMessageTraffic = new cMessageTraffic();
  oMessageTraffic->MethodGET(oUrl);
  oResponse = oMessageTraffic->GetResponse();

  rapidjson::Document oJsonResponse;
  oJsonResponse.Parse(oResponse.c_str());

  const rapidjson::Value& oId = oJsonResponse["id"];
  const rapidjson::Value& oTitle = oJsonResponse["volumeInfo"]["title"];
  const rapidjson::Value& oAuthors = oJsonResponse["volumeInfo"]["authors"];
  const rapidjson::Value& oPageCount = oJsonResponse["volumeInfo"]["pageCount"];

  STBook.id = oId.GetString();
  STBook.title = oTitle.GetString();

  for(rapidjson::SizeType i; i < oAuthors.Size(); i++){
    STBook.authors.push_back((oAuthors[i].GetString()));
  }

  STBook.pageCount = oPageCount.GetInt();

  std::cout << "\nO id do livro eh: " << STBook.id << std::endl;
  std::cout << "O nome do livro eh: " << STBook.title << std::endl;

  std::cout << "Os autores do livro sao:" << std::endl;
  for(std::vector<std::string>::iterator it = STBook.authors.begin(); it != STBook.authors.end(); it++){
     std::cout << "   - " << *it << std::endl;
  }

  std::cout << "O numero de paginas do livro eh: " << STBook.pageCount << std::endl << "\n";

  return (0);
}