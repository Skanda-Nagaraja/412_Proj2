#include "RequestGenerator.h"
#include "LoadBalancer.h"
#include "WebServer.h"
#include <iostream>
#include <sstream>



int main() {
    int initial_servers = 0;
    int clock_cycles = 0;
    std::string input;

    std::cout << "Enter initial number of servers: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> initial_servers;

    std::cout << "Enter number of clock cycles: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> clock_cycles;

    std::cout << "Simulation started with " << initial_servers << " servers and " << clock_cycles << " clock cycles.\n";
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
