#include <iostream>
#include "VisitSolver.h"
#include <fstream>
#include <list>
#include <bits/stdc++.h> 

using namespace std;

int main(int argc, char **argv) {
    // Create an instance of VisitSolver
    VisitSolver visitExample;
    string problem;
    // Check the command line arguments    
    if (argc > 2){
        problem = argv[1];// Store the problem argument
    }else{
        cout << "Usage:\n"
        << argv[0] << " problem parameters plan" << endl;
        return 1;
    }
    string parameters[] = {0};
    // Load the solver with parameters
    visitExample.loadSolver(parameters,1);
    // Create a map for the initial state
    map<string,double> initialState;

    // Set initial state fluents
    initialState["(act-cost)"] = 0;
    initialState["(dummy)"] = 0;

    // Declaring Vector of String type 
    vector <string> region; 
  
    // Initialize vector with regions using push_back  
    
    // The way-point associated to the initial position of the robot
    region.push_back("r0"); 
    
    // The waypoints associated to the 4 regions in the map
    region.push_back("r1"); 
    region.push_back("r2"); 
    region.push_back("r3"); 
    region.push_back("r4");
    
    // The waypoint associated to the goal position of the robot
    region.push_back("r5"); 
    
    // There are the randomly sampled way-points
    // from "r6" to "r29"
    region.push_back("r6"); 
    region.push_back("r7"); 
    region.push_back("r8"); 
    region.push_back("r9");
    region.push_back("r10"); 
    region.push_back("r11"); 
    region.push_back("r12"); 
    region.push_back("r13"); 
    region.push_back("r14");
    region.push_back("r15"); 
    region.push_back("r16"); 
    region.push_back("r17"); 
    region.push_back("r18"); 
    region.push_back("r19");
    region.push_back("r20"); 
    region.push_back("r21"); 
    region.push_back("r22"); 
    region.push_back("r23"); 
    region.push_back("r24");
    region.push_back("r25"); 
    region.push_back("r26"); 
    region.push_back("r27"); 
    region.push_back("r28"); 
    region.push_back("r29"); 

    // store the initial state fluents
    for (int i=0; i<region.size(); i++)   { 
        for(int j=0; j<region.size(); j++){
           if (i != j){       
            initialState["(triggered " + region[i] + " " + region[j]+")"] = 0;
           }
        }
    }
    return 0;
}
