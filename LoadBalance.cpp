#include "LoadBalancer.h"

LoadBalancer::LoadBalancer(int maxIters) {
    iterCount = 0;
    this->maxIters = maxIters;
}

LoadBalancer::~LoadBalancer() {
    while (!q.empty()) {
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
    if (iterCount == maxIters) {
        scale();
        iterCount = 0;
    } 
    for (int i = 0; i < servers.size(); i++) {
        if (servers[i]->isFree() && !q.empty()) {
            servers[i]->processRequest(q.front());
            pop();
        }
    }
    iterCount++;
}