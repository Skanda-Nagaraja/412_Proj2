/**
 * @file main.cpp
 * @brief high level program abstraction
 */
#include "RequestGenerator.h"
#include "LoadBalancer.h"
#include "WebServer.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

int main() {
    int initial_servers = 0;
    int num_cycles = 0;
    int request_density = 0;
    std::string input;
    srand(static_cast<unsigned int>(time(NULL)));

    /**
     * @brief User prompting. 
     */

    std::cout << "Enter initial number of servers: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> initial_servers;

    std::cout << "Enter number of clock cycles: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> num_cycles;

    std::cout << "Enter average request density: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> request_density;

    std::cout << "Simulation started with " << initial_servers << " servers and " << num_cycles << " clock cycles.\n";
    RequestGenerator rg;
    LoadBalancer lbS("S");
    LoadBalancer lbP("P");

     /**
     * @brief Seeds LoadBalancers  initial batch of requests.
     */
    WebServer ws;
    for (int i = 0; i < initial_servers * 20; i++) {
        Request r = rg.generateRequestS();
        lbS.push(r);
        r = rg.generateRequestP();
        lbP.push(r);
    }
       
   

     /**
     * @brief Simulates the specified number of clock cycles.
     * Each cycle processes load balancing ticks for both LoadBalancers.
     */
    for (int i = 0; i < num_cycles; i++) {
        std::cout << std::endl << "ENTERING CYCLE:  " << i << std::endl;
        for (int j = 0; j < request_density; j++) {
            if(rand() % 2 == 0){
                Request r = rg.generateRequestS();
                lbS.push(r);
            }
            if(rand() % 2 == 0){
                Request r = rg.generateRequestP();
                lbP.push(r);
            }
        }
        
        lbS.LoadBalanceTick();
        lbP.LoadBalanceTick();
        std::cout << std::endl;
    }

    
    return 0;

}
