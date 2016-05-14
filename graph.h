#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include "species.h"

using namespace std;

class Graph{
  
    public:
        // this vector holds a species in each bucket and each species 
        // has a pointer to a subtype, and each subtype has a pointer to another
        // subtype, thus its basically an adjacency linked list in each bucket 
        // of the vector
        vector<Species*> subclasses; 
        Graph(string file);
        int getIndex(string name);
        void print();
        string editFormat(string s);
        void storeInfoInGraph(string theString);
        void printResults(vector<Species*> results);
        void optionOne(int num_subtypes, string sp, int order);
        void optionTwo(string sp);
        void optionThree(string sp1, string sp2, string sp3);
    
    private:
    
};
