#include "species.h"

//implementation of constructor
Species::Species(string name, Species* next){
    this->name = name;
    this->next = next;
}
