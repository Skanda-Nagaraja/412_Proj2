#include "RequestGenerator.h"

class WebServer {
    private:
        int timeRemaining;
    public:
        void processRequest(Request request);
        bool isFree();
        void tick();
};
