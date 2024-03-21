/**
 * Coletanea de metodos utilizando a libCurl para facilitar o transito de mensagens.
 * @author Thiago Barbosa Ribeiro.
 * @copyright All rights reserved to the author.
*/

#include "messageTraffic.h"

cMessageTraffic::cMessageTraffic(){}

cMessageTraffic::~cMessageTraffic(){}

std::string cMessageTraffic::GetResponse(){
    return(m_oResponse);
}

size_t cMessageTraffic::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void cMessageTraffic::MethodGET(std::string & oUrl){
  curl = curl_easy_init();

  if(curl){
    curl_easy_setopt(curl, CURLOPT_URL, oUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &m_oResponse);
    
    m_ReturnCode = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
  }
}
