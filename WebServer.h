/**
 * @file WebServer.h
 * @brief Declaration of the webserver class.
 */


#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include "RequestGenerator.h"

struct Request;

/**
 * @class WebServer
 * @brief Represents a WebServer that processes requests.
 */
class WebServer {
    private:
        unsigned int timeRemaining;
        Request request;
    public:

        WebServer();
        void processRequest(const Request& _request);
        bool isFree () const;
        int tick();
};
#endif //WEB_SERVER_H
