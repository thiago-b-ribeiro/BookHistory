/**
 * Coletanea de metodos utilizando a libCurl para facilitar o transito de mensagens.
 * @author Thiago Barbosa Ribeiro.
 * @copyright All rights reserved to the author.
*/

#include <curl/curl.h>
#include <string>

#ifndef MESSAGETRAFFIC_H
#define MESSAGETRAFFIC_H

class cMessageTraffic{
    public:
        cMessageTraffic();
        ~cMessageTraffic();
        void MethodGET(std::string & oUrl);
        std::string GetResponse();
    
    private:
        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

        std::string m_oRequest;
        std::string m_oResponse;

        CURL * curl;
        CURLcode m_ReturnCode;
};

#endif