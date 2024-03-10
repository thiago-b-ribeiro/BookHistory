/**
 * Software para armazenamento e consulta de livros em leitura e lidos.
 * @author Thiago Barbosa Ribeiro.
 * @copyright All rights reserved to the author.
*/

#include "../Includes/bookhistory.h"
#include <iostream>
#include <algorithm>

cBookHistory::cBookHistory()
  :oMessageTraffic(new cMessageTraffic()){

}

cBookHistory::~cBookHistory(){

}

std::vector<stBook> cBookHistory::SearchBook(std::string & oTitle){
    
    std::replace(oTitle.begin(), oTitle.end(), ' ', '+');
    std::string oUrl = ENDPOINT + oTitle + "&" + APIKEY;

    oMessageTraffic->MethodGET(oUrl);
    oResponse = oMessageTraffic->GetResponse();
    oJsonResponse.Parse(oResponse.c_str());

    const rapidjson::Value& oItems =  oJsonResponse["items"];
    for(rapidjson::Value::ConstValueIterator itr = oItems.Begin(); itr != oItems.End(); ++itr){

      STBook.id = (*itr)["id"].GetString();
      STBook.title = (*itr)["volumeInfo"]["title"].GetString();

      for(rapidjson::SizeType i; i < (*itr)["volumeInfo"]["authors"].Size(); ++i){
        STBook.authors.push_back(((*itr)["volumeInfo"]["authors"][i].GetString()));
      }

      const rapidjson::Value& oVolumeInfo = (*itr)["volumeInfo"];      
      rapidjson::Value::ConstMemberIterator itrPageCount = oVolumeInfo.FindMember("pageCount");
      if(itrPageCount != oVolumeInfo.MemberEnd()){
        STBook.pageCount = (*itr)["volumeInfo"]["pageCount"].GetInt();
      }

      oVectorBooks.push_back(STBook);
    }

    return(oVectorBooks);
}

int cBookHistory::CreateMenu(std::vector<std::string> & oOptions){
  
  int iOptionNumber = 0;
  int iChoice = 0;

  for(std::vector<std::string>::iterator itr = oOptions.begin(); itr != oOptions.end(); ++itr){
    std::cout << "   " << iOptionNumber + 1 << " - " << *itr << std::endl;
    ++iOptionNumber;
  }

  while(true){
    std::cout << "\nDigite a opcao desejada: ";
    std::cin >> iChoice;

    if(iChoice >= 1 && iChoice <= iOptionNumber){
      break;
    } else{
      std::cout << "Escolha um numero entre 1 e " << iOptionNumber << "." << std::endl;
    }
  }

  return(iChoice);
}