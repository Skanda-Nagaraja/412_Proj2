#ifndef LOADBALANCER_H
#define LOADBALANCER_H


#include <queue>  
#include <iostream>
#include <vector>
#include "RequestGenerator.h"
#include "WebServer.h"

class LoadBalancer {
    private:
        //define a queue 
        string name;
        std::queue<Request> q;
        std::vector<WebServer> servers;
        unsigned int iterCount;
        unsigned int maxIters;
        
    public:
        LoadBalancer(string _name);
        void push (const Request& Request);
        void pop();
        void scale();
        void LoadBalanceTick();
        //destructor to delete the queue
        ~LoadBalancer();


};
#endif //WEB_SERVER_H
