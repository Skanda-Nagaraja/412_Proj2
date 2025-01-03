#include "RequestGenerator.h"
#include "LoadBalancer.h"
#include "WebServer.h"



int main() {
    int initialCapacity = 10000;
    int numCycles = 10000;
    RequestGenerator rg;
    LoadBalancer lbS;
    LoadBalancer lbP;
    
    WebServer ws;
    for (int i = 0; i < initialCapacity; i++) {
        Request * r = rg.generateRequest();
        if (r->type == S) {
            lbS.push(r);
        } else {
            lbP.push(r);
        }
    }
    for (int i = 0; i < numCycles; i++) {
        std::cout << "ENTERING CYCLE " << i << std::endl;
        lbS.LoadBalanceTick();
        lbP.LoadBalanceTick();
        std::cout << std::endl;
    }
    return 0;

}
