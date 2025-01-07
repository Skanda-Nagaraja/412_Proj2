/**
 * @file WebServer.cpp
 * @brief Declaration of the RequestGenerator class.
 */

#include "WebServer.h"

WebServer::WebServer() : timeRemaining(0) {}


/**
 * @brief Processes a Request by setting the request and time remaining.
 * @param _request The Request to be processed. 
 */
void WebServer::processRequest(const Request& _request) {
    request = _request;
    timeRemaining = _request.time;
    timeRemaining  = true;
}

/**
 * @brief Checks if the WebServer is free.
 * @return True if the WebServer is free, false otherwise.
 */
bool WebServer::isFree() const{
    return timeRemaining == 0;
}

/**
 * @brief Processes a tick of the WebServer.
 * @return The remaining time of the request.
 */

int WebServer::tick() {
    if (timeRemaining > 0) {
        timeRemaining--;
    }
    
    if(timeRemaining == 0){
        std::cout << "Request " << request.ipOut << " complete" << std::endl;
    }
    
    return timeRemaining;
}

