#include "RequestGenerator.h" 
#include <iostream>
#include <string>
using namespace std;

RequestGenerator::RequestGenerator() {
    srand(static_cast<unsigned int>(time(NULL)));
}

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

Request RequestGenerator::generateRequestS() {
    Request r =  Request();
    r.ipIn = genIp();
    r.ipOut = genIp();
    r.time = (rand() % 1000) + 1;
    r.type = S;
    return r;
}

// Manually generate a request of type P
Request RequestGenerator::generateRequestP() {
   Request r =  Request();
    r.ipIn = genIp();
    r.ipOut = genIp();
    r.time = r.time = (rand() % 1000) + 1;
    r.type = P;
    return r;
}


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
    return r;
}
