/**
 * @file RequestGenerator.cpp
 * @brief Implementation of the RequestGenerator 
 */
#include "RequestGenerator.h" 
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Constructs a RequestGenerator object.
 */
RequestGenerator::RequestGenerator() {
    srand(static_cast<unsigned int>(time(NULL)));
}

/**
 * @brief Generates a random IP address.
 * @return A string representing the IP address.
 */

string RequestGenerator::genIp() {
    string ip = "";
    for (int i = 0; i < 4; i++) {
        ip += to_string(rand() % 256);
        if (i < 3) {
            ip += ".";
        }
    }
    return ip;
}


/**
 * @brief Generates a request of type S
 * @return A Request object with type S.
 * 
 */
Request RequestGenerator::generateRequestS() {
    Request r =  Request();
    r.ipIn = genIp();
    r.ipOut = genIp();
    r.time = (rand() % 1000) + 1;;
    r.type = S;
    return r;
}

/**
 * @brief Generates a request of type P
 * @return A Request object with type P.
 * 
 */

// Manually generate a request of type P
Request RequestGenerator::generateRequestP() {
    Request r =  Request();
    r.ipIn = genIp();
    r.ipOut = genIp();
    r.time = (rand() % 1000) + 1;
    r.type = P;
    cout << "P Request generated: " << r.ipIn << " " << r.ipOut << " " << r.time << " " << r.type << endl;
    return r;
}

/**
 * @brief Generates a request of random type.
 * @return A Request object with a random type.
 * 
 */


Request RequestGenerator::generateRequest() {
    Request r =  Request();
    r.ipIn = genIp();
    r.ipOut = genIp();

    r.time = (rand() % 1000) + 1;

    if(rand() % 2 == 0) {
        r.type = S;
    } else {
        r.type = P;
    }
    cout << "S Request generated: " << r.ipIn << " " << r.ipOut << " " << r.time << " " << r.type << endl;
    return r;
}
