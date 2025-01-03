#include "LoadBalancer.h"

LoadBalancer::LoadBalancer() {
    iterCount = 0;
}

LoadBalancer::~LoadBalancer() {
    while (!q.empty()) {
        delete q.front();
        q.pop();
    }
}

void LoadBalancer::push(Request* request) {
    q.push(request);
}

void LoadBalancer::pop() {
    q.pop();
}

void LoadBalancer::scale() {
    if (servers.size() < q.size()/20) {
       //scale up
        WebServer* ws = new WebServer();
        servers.push_back(ws);
    } else if (servers.size() > q.size()/20) {
        //scale down
        WebServer* ws = servers.back();
        servers.pop_back();
    }
}


void LoadBalancer::LoadBalanceTick() {
    scale();
    for (int i = 0; i < servers.size(); i++) {
        if (!q.empty() && servers[i]->isFree()) {
            servers[i]->processRequest(q.front());
            pop();
        } else if(!servers[i]->isFree()) {
            std::cout << "Server " << i << " is busy" << std::endl;
            servers[i]->tick();
        }
    }
    iterCount++;
}