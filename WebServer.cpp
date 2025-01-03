#include "WebServer.h"

WebServer::WebServer() : timeRemaining(0) {}

void WebServer::processRequest(Request* request) {
    timeRemaining = request->time;
}

bool WebServer::isFree() {
    return timeRemaining == 0;
}

void WebServer::tick() {
    if (timeRemaining > 0) {
        timeRemaining--;
    }
}
