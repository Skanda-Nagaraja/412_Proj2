#include <iostream>
#include <string>
#include <vector>

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
    };


#endif // REQUESTGENERATOR_H