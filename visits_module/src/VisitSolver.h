#ifndef TESTSOLVER_H
#define TESTSOLVER_H

#include "ExternalSolver.h"
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <queue>
#include <unordered_map>

using namespace std;

class VisitSolver : public ExternalSolver
{
public:
    // Constructor
    VisitSolver();
    // Destructor
    ~VisitSolver();
    // Load the solver with parameters
    virtual void loadSolver(string* parameters, int n);
    // Call the external solver and return the resulting state
    virtual map<string,double> callExternalSolver(map<string,double> initialState, bool isHeuristic);
    // Get the parameters of the solver
    virtual  list<string> getParameters();
    // Get the dependencies of the solver
    virtual  list<string> getDependencies();
    // Waypoint data
    map<string, vector<double>> waypoint;
    // Distance and cost variables
    double distance;
    double cost;
    // Cost matrix and adjacency matrix
    double cost_m[30][30]; 
    double cost_array[30];
    int cost_m_adj[30][30] = {};
    // Parameter k
    int k;


    // Waypoints and regions arrays
    string wp[30] = {"wp0","wp1","wp2","wp3","wp4","wp5","wp6","wp7","wp8","wp9","wp10","wp11","wp12","wp13","wp14","wp15","wp16","wp17","wp18","wp19","wp20","wp21","wp22","wp23","wp24","wp25","wp26","wp27","wp28", "wp29"};
    string region[30] = {"r0","r1","r2","r3","r4","r5","r6","r7","r8","r9","r10","r11","r12","r13","r14","r15","r16","r17","r18","r19","r20","r21","r22","r23","r24","r25","r26","r27","r28", "r29"};
    // Parse waypoint data from file   
    void parseWaypoint(string waypoint_file);
    // Region mapping     
    map<string, vector<string>> region_mapping;
    vector <string> source, target; 
    string starting_position;
    // Find the minimum element in the cost_array     
    double min_elem();
    // Build the map
    void my_map();
    // Parse solver parameters
    void parseParameters(string parameters);
    // Calculate Euclidean distance between two waypoints
    double ecldn_dist(string from, string to);
    // Localize a position from one waypoint to another
    double localize(string from, string to);
    // Generate random waypoints
    void generate_rnd_wyp(string wyp);

private:
    // Affected and dependency lists
    list<string> affected;
    list<string> dependencies;
    
    // Calculate the external solver      
    double calculateExtern();
    // Find parameters in a line
    vector<string> findParameters(string line, int&n);

};

#endif // TESTSOLVER_H
