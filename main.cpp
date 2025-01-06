#include "RequestGenerator.h"
#include "LoadBalancer.h"
#include "WebServer.h"
#include <iostream>
#include <sstream>

int main() {
    int initial_servers = 0;
    int num_cycles = 0;
    std::string input;
    srand(static_cast<unsigned int>(time(NULL)));

    std::cout << "Enter initial number of servers: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> initial_servers;

    std::cout << "Enter number of clock cycles: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> num_cycles;

    std::cout << "Simulation started with " << initial_servers << " servers and " << num_cycles << " clock cycles.\n";
    RequestGenerator rg;
    LoadBalancer lbS("S");
    LoadBalancer lbP("P");

    WebServer ws;
    for (int i = 0; i < initial_servers * 20; i++) {
        Request r = rg.generateRequestS();
        lbS.push(r);
        r = rg.generateRequestP();
        lbP.push(r);
    }
    for (int i = 0; i < num_cycles; i++) {
        std::cout << std::endl << "ENTERING CYCLE:  " << i << std::endl;
        
        lbS.LoadBalanceTick();
        lbP.LoadBalanceTick();
        std::cout << std::endl;
    }

    
    return 0;

}
