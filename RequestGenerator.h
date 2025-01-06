#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef REQUESTGENERATOR_H
#define REQUESTGENERATOR_H


    #define S true
    #define P false
    struct Request {            //define a queue 
            std::string ipIn;
            std::string ipOut;
            int time;
            bool type;
    };

    class RequestGenerator {
        public:
            RequestGenerator();
            Request* generateRequest();
        private:
            string genIp();
    };


#endif // REQUESTGENERATOR_H