#include "WebServer.h"

WebServer::WebServer() : timeRemaining(0) {}



void WebServer::processRequest(const Request& _request) {
    request = _request;
    timeRemaining = _request.time;
    timeRemaining  = true;
}
bool WebServer::isFree() const{
    return timeRemaining == 0;
}

int WebServer::tick() {
    if (timeRemaining > 0) {
        timeRemaining--;
    }
    
    if(timeRemaining == 0){
        std::cout << "Request " << request.ipOut << " complete" << std::endl;
    }
    
    return timeRemaining;
}

