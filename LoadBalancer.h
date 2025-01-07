/**
 * @file LoadBalancer.h
 * @brief Declaration of the LoadBalancer class.
 */
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
         /**
         * @brief Constructs a LoadBalancer with the given name.
         * @param _name Name of the LoadBalancer.
         */
        LoadBalancer(string _name);
         
         /**
         * @brief Adds a Request to the LoadBalancer's queue.
         * @param request The Request to be added.
         */
        void push (const Request& Request);
        
        /**
         * @brief Removes the front Request from the queue.
         */
        void pop();

        /**
         * @brief Adjusts the number of WebServers based on the current load.
         * Scales up by adding servers if needed and scales down by removing idle servers.
         */
        void scale();

          /**
         * @brief Processes one tick (cycle) of load balancing.
         * Invokes scaling and assigns Requests to available WebServers.
         */
        void LoadBalanceTick();
        //destructor to delete the queue
        ~LoadBalancer();


};
#endif //WEB_SERVER_H
