/**
 * @file RequestGenerator.h
 * @brief Declaration of the RequestGenerator class.
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef REQUESTGENERATOR_H
#define REQUESTGENERATOR_H


    #define S true
    #define P false
    /**
     * @struct Request
     * @brief Represents a  Request with inp./out. IPs, processing time, and type.
     */
    struct Request {            //define a queue 
            std::string ipIn;
            std::string ipOut;
            int time;
            bool type;
    };

    /**
     * @class RequestGenerator
     * @brief Generates Requests with random IPs, processing times, and types.
     */
    class RequestGenerator {
        public:
            RequestGenerator();
            Request generateRequest();
            Request generateRequestS();
            Request generateRequestP();
        private:
            string genIp();
    };


#endif // REQUESTGENERATOR_H