/**
 * @file LoadBalancer.cpp
 * @brief Implementation of the LoadBalancer class.
 */

#include "LoadBalancer.h"

/**
 * @brief Constructs a LoadBalancer with the given name and initializes iterCount.
 * @param _name Name of the LoadBalancer.
 */
LoadBalancer::LoadBalancer(string _name) {
    iterCount = 0;
    name = _name;

}


LoadBalancer::~LoadBalancer() {
    while (!q.empty()) {
        q.pop();
    }
}

/**
 * @brief Adds a Request to the LoadBalancer's queue.
 * @param request The Request to be added.
 */

void LoadBalancer::push(const Request& request) {
    q.push(request);
}

/**
 * @brief Removes the front Request from the queue.
 */
void LoadBalancer::pop() {
    if(!q.empty()) {
        q.pop();
    }
}

/**
 * @brief Adjusts the number of WebServers based on the current load.
 * Scales up by adding servers if needed and scales down as well.
 */
void LoadBalancer::scale() {
    int totalServ = servers.size();
    int required = q.size()/20;
    if(required == 0){
        required = 1;
    }
    while (servers.size() < required) {
       //scale up
        WebServer ws =  WebServer();
        servers.push_back(ws);
    } 
    while (servers.size() > required && servers.size()>1) {
        //scale down
        bool found = false;
        for (int i = 0; i < servers.size(); i++) {
            if (servers[i].isFree()) {
                servers.erase(servers.begin() + i);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "All servers busy, cannot scale down" << endl;
            break;
        }

    }
    if(totalServ != servers.size()){
        cout << "Load Balancer Name: " << name << " scaling from " << totalServ << " to " << servers.size() << " servers" << endl;
    } else {
        cout << "Load Balancer Name: " << name << " still has: " << servers.size() << endl;
    }
}

/**
 * @brief Processes one cycle of load balancing.
 *  scaling and identifies  Requests for available WebServers.
 */
void LoadBalancer::LoadBalanceTick() {
    scale();
    for (int i = 0; i < servers.size(); i++) {
        if (!q.empty() && servers[i].isFree()) {
            servers[i].processRequest(q.front());
            pop();
        } else if(!servers[i].isFree()) {
            // std::cout << "Server " << i << " is busy" << std::endl;
            int timeRemaining = servers[i].tick();
            cout << "Server " << i << " has " << timeRemaining << " cycles remaining" << endl;
        }
    }
    iterCount++;
}