#include "RequestGenerator.h"
#include "LoadBalancer.h"

class WebServer {
    private:
        unsigned int timeRemaining;
    public:
        WebServer();
        void processRequest(Request request);
        bool isFree();
        void tick();
};
