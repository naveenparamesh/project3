#include <string>

using namespace std;
class Species{
  public:
    string name; // name of the species
    // next species in adjacency linked list, where the head node is always the species
    // and everything else is subspecies
    Species* next;  
    Species* parent; // the previous species, one level up in the heiarchy
    bool visited; // a flag used sometimes to determine if the species was visited
    int distance; // to node 
    string state;// discovered/ undiscovered, was just kept in for possible later use
    Species(string name, Species* next); // constructor
  private:
    
};