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
        LoadBalancer(int maxIters);
        void push (Request Request);
        void pop();
        void scale();
        //destructor to delete the queue
        ~LoadBalancer();


};
