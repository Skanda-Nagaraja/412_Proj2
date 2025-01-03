#include "RequestGenerator.h"
#include "LoadBalancer.h"
#include "WebServer.h"



int main {
    int initialCapacityS = 0;
    int initialCapacityP = 0;
    int clockCycle = 0;
    RequestGenerator rg;
    LoadBalancer lbS;
    LoadBalancer lbP;
    
    WebServer ws;
    for (int i = 0; i < 100; i++) {
        Request r = rg.generateRequest();
        lb.push(r);
    }
    while (!lb.empty()) {
        ws.tick();
    }
    return 0;

}
