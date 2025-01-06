
#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include "RequestGenerator.h"

class WebServer {
    private:
        unsigned int timeRemaining;
        Request* request;
    public:
        WebServer();
        void processRequest(Request* request);
        bool isFree();
        int tick();
};
#endif //WEB_SERVER_H
