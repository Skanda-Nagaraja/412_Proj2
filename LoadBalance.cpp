#include "LoadBalancer.h"

LoadBalancer::LoadBalancer(string _name) {
    iterCount = 0;
    name = _name;

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
    int totalServ = servers.size();
    while (servers.size() < q.size()/20) {
       //scale up
        WebServer* ws = new WebServer();
        servers.push_back(ws);
    } 
    while (servers.size() > q.size()/20) {
        //scale down
        bool found = false;
        for (int i = 0; i < servers.size(); i++) {
            if (servers[i]->isFree()) {
                delete servers[i];
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


void LoadBalancer::LoadBalanceTick() {
    scale();
    for (int i = 0; i < servers.size(); i++) {
        if (!q.empty() && servers[i]->isFree()) {
            servers[i]->processRequest(q.front());
            pop();
        } else if(!servers[i]->isFree()) {
            // std::cout << "Server " << i << " is busy" << std::endl;
            int timeRemaining = servers[i]->tick();
            cout << "Server " << i << " has " << timeRemaining << " cycles remaining" << endl;
        }
    }
    iterCount++;
}