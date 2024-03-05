#include "rapidjson/document.h"
#include <iostream>
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(int argc, char *argv[]){
  CURL * curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.googleapis.com/books/v1/volumes/2DgT_J9HyogC?key=AIzaSyBPvMXUMZXVMKq8HdQjkx8Te7wTQJCLBFs");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    rapidjson::Document oJsonResult;
    oJsonResult.Parse(readBuffer.c_str());

    const rapidjson::Value& oId = oJsonResult["id"];
    std::cout << "O id do livro eh: " << oId.GetString() << std::endl;
    
    const rapidjson::Value& oBookName = oJsonResult["volumeInfo"]["title"];
    std::cout << "O nome do livro eh: " << oBookName.GetString() << std::endl;

    const rapidjson::Value& oAmount = oJsonResult["saleInfo"]["listPrice"]["amount"];
    std::cout << "O preco do livro eh: " << oAmount.GetDouble() << std::endl;

  }
  return (0);
}