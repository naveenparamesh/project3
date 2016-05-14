#include <iostream> 
#include <cstdlib>
#include <string>
#include "graph.h"

using namespace std;

int main(){
    
    // These line take the file name as input and passes it in as an argument
    // to the graph variable constructor, which sets up the graph
    string fileName = "";
    cout << "Enter file name: " << endl;
    cin >> fileName;
    Graph* graph = new Graph(fileName);
    
   
   // This is the interface that greets the user after inputing the file name
    cout << "Welcome to our graph analysis of the animal heirarchy class. Here are our operations: " << endl;
    cout << endl;
    cout << "1. Display NUMBER/All of the subtypes of a given species of a given order." << endl;
    cout << "2. Display the number of subspecies of a given species." << endl;
    cout << "3. Display  the lowest common ancestor between two given species starting from (SP01)." << endl; 

    // these variables are used for taking input for the tasks
    int choice = 0;
    string species_name = "";
    int order_num = 0;
    string sp2 = "";
    string sp3 = "";
    int numSubTypes = 0;
    
    cout << "Enter 1, 2, or 3 to continue: " << endl;
    cin >> choice;
    
    switch(choice){
        case 1: 
                while (getline(cin, species_name))//while loop is used to keep displaying question until input is taken
                {
                    if (species_name == ""){
                        cout << "Enter a species name (string): " << endl;    
                    }
                    else {
                        break;
                    }
                }
                // uses the editFormat function to convert all letters to lowercase,
                // and replaces any spaces to underscores
                species_name = graph->editFormat(species_name); 
                cout << "Enter the number of subtypes wanted (int): " << endl;
                cin >> numSubTypes;
                cout << "Enter an order (int): " << endl;
                cin >> order_num;
                graph->optionOne(numSubTypes, species_name, order_num); // after input, calls corresponding task function
                break;
                
        case 2: 
                while (getline(cin, species_name)) // used while loop for same reason as in case 1
                {
                    if (species_name == ""){
                        cout << "Enter a species name (string): " << endl;    
                    }
                    else {
                        break;
                    }
                    
                }
                species_name = graph->editFormat(species_name); // formats it properly
                graph->optionTwo(species_name); // calls corresponding task function
                break;
        case 3: // here for some reason, only one while loop is needed, and other 
                // string variables can be read using regular getline, else the output gets
                // displayed twice before input and it gets really weird so this implementation worked for me
                // wouldn't overlook it, just gets the needed input and formats them properly and calls 
                // corresponding task function
                while (getline(cin, species_name)) 
                {
                    if (species_name == ""){
                        cout << "Enter the first species (string): " << endl;
                    }
                    else {
                        break;
                    }
                }
                species_name = graph->editFormat(species_name);
                
                cout << "Enter the second species (string): " << endl;
                getline(cin, sp2);
                sp2 = graph->editFormat(sp2);
              
                cout << "Enter the third species (string): " << endl;
                getline(cin, sp3); 
                sp3 = graph->editFormat(sp3);
                
                graph->optionThree(species_name, sp2, sp3);
                break;
        default: cout << "Invalid input!" << endl;
                break;
        
    }

    delete graph; // frees memory allocated by the graph
    return 0;
}