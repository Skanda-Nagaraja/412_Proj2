#include <queue>  
#include <iostream>
#include <vector>
#include "RequestGenerator.h"
 
class LoadBalancer {
    private:
        //define a queue 
        std::queue<int> q;
        std::vector<int> servers;
        unsigned int iterCount;
        unsigned int maxIters;
        
    public:
        void push (Request Request);
        //constructo to initialize the queue 
        LoadBalancer();
        LoadBalancer(int maxIters);
        
        //destructor to delete the queue
        ~LoadBalancer();


};
