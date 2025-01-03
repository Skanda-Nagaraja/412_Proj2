#include <queue>  
#include <iostream>
#include <vector>
#include "RequestGenerator.h"
#include "WebServer.h"

class LoadBalancer {
    private:
        //define a queue 
        std::queue<Request*> q;
        std::vector<WebServer*> servers;
        unsigned int iterCount;
        unsigned int maxIters;
        
    public:
        LoadBalancer();
        void push (Request* Request);
        void pop();
        void scale();
        void LoadBalanceTick();
        //destructor to delete the queue
        ~LoadBalancer();


};
