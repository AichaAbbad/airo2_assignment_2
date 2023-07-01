/*
     <one line to give the program's name and a brief idea of what it does.>
     Copyright (C) 2015  <copyright holder> <email>
     
     This program is free software: you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation, either version 3 of the License, or
     (at your option) any later version.
     
     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.
     
     You should have received a copy of the GNU General Public License
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
     */

#include "VisitSolver.h"
#include "ExternalSolver.h"
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

// extra libraries
#include <random>
#include <cmath>

#include "armadillo"
#include <initializer_list>

using namespace std;
using namespace arma;



    //map <string, vector<double> > region_mapping;

extern "C" ExternalSolver* create_object(){
  return new VisitSolver();
}

extern "C" void destroy_object(ExternalSolver *externalSolver){
  delete externalSolver;
}

VisitSolver::VisitSolver(){

}

VisitSolver::~VisitSolver(){

}

void VisitSolver::loadSolver(string *parameters, int n){
  starting_position = "r0";
  string Paramers = parameters[0];

  char const *x[]={"dummy"};
  char const *y[]={"act-cost","triggered"};
  parseParameters(Paramers);
  affected = list<string>(x,x+1);
  dependencies = list<string>(y,y+2);

  string waypoint_file = "./waypoint.txt";
  // here we need to generate random waypoints
  generate_rnd_wyp(waypoint_file);
  parseWaypoint(waypoint_file);

  // string landmark_file = "./landmark.txt";
  //parseLandmark(landmark_file);
  
  int k = 5;  // each way-point is connected to a maximum of 5 other way-points
  
  my_map();
}

map<string,double> VisitSolver::callExternalSolver(map<string,double> initialState,bool isHeuristic){

  map<string, double> toReturn;
  map<string, double>::iterator iSIt = initialState.begin();
  map<string, double>::iterator isEnd = initialState.end();
  double dummy;
  double act_cost;

  map<string, double> trigger;

  for(;iSIt!=isEnd;++iSIt){

    string parameter = iSIt->first;
    string function = iSIt->first;
    double value = iSIt->second;

    function.erase(0,1);
    function.erase(function.length()-1,function.length());
    int n=function.find(" ");

    if(n!=-1){
      string arg=function;
      string tmp = function.substr(n+1,5);

      function.erase(n,function.length()-1);
      arg.erase(0,n+1);
      if(function=="triggered"){
        trigger[arg] = value>0?1:0;
        if (value>0){

      string from = tmp.substr(0,2);   // from and to are regions, need to extract wps (poses)
      string to = tmp.substr(3,2);
  }
    }
    else{
        if(function=="dummy"){
            dummy = value;
        }
        else if(function=="act-cost"){
            act_cost = value;
        } //else if(function=="dummy1"){
                    //duy = value;              
                    ////cout << parameter << " " << value << endl;
                 //}
        //}
        }
    }}
               double results = calculateExtern();
               if (ExternalSolver::verbose){
                   cout << "(dummy) " << results << endl;
               }

               toReturn["(dummy)"] = results;
               return toReturn;
            }

            list<string> VisitSolver::getParameters(){

              return affected;
            }

            list<string> VisitSolver::getDependencies(){

              return dependencies;
            }


            void VisitSolver::parseParameters(string parameters){

              int curr, next;
              string line;
              ifstream parametersFile(parameters.c_str());
              if (parametersFile.is_open()){
                while (getline(parametersFile,line)){
                 curr=line.find(" ");
                 string region_name = line.substr(0,curr).c_str();
                 curr=curr+1;
                 while(true ){
                  next=line.find(" ",curr);
                  region_mapping[region_name].push_back(line.substr(curr,next-curr).c_str());
                  if (next ==-1)
                   break;
                 curr=next+1;

               }                
             }

           }

         }

        double VisitSolver::calculateExtern(){
            //float random1 = static_cast <float> (rand())/static_cast <float>(RAND_MAX);
            double cost = cost;//random1;
            return cost;
     }

     void VisitSolver::parseWaypoint(string waypoint_file){

       int curr, next;
       string line;
       double pose1, pose2, pose3;
       ifstream parametersFile(waypoint_file);
       if (parametersFile.is_open()){
        while (getline(parametersFile,line)){
         curr=line.find("[");
         string waypoint_name = line.substr(0,curr).c_str();

         curr=curr+1;
         next=line.find(",",curr);

         pose1 = (double)atof(line.substr(curr,next-curr).c_str());
         curr=next+1; next=line.find(",",curr);

         pose2 = (double)atof(line.substr(curr,next-curr).c_str());
         curr=next+1; next=line.find("]",curr);

         pose3 = (double)atof(line.substr(curr,next-curr).c_str());

         waypoint[waypoint_name] = vector<double> {pose1, pose2, pose3};
       }
     }

   }
  /*
   void VisitSolver::parseLandmark(string landmark_file){

     int curr, next;
     string line;
     double pose1, posdlknv2, pose3;
     ifstream parametersFile(landmark_file);
     if (parametersFile.is_open()){
      while (getline(rrrrrrrrrrrrrrrine)){
       curr=line.find("[");
      estrinb landmark_name = line.substr(0,curr).c_str()b
      b
       curn=curr+ee
       next=line.find(",",furr);
fggy<n
       pose)atof(line.substr(curr,next-curr).c_str());
       curr=next+1; next=line.find("]",curr);

       pose3 = (double)atof(line.substr(curr,next-curr).c_str());

       landmark[landmark_name] = vector<double> {pose1, pose2, pose3};
     }
   }
   
 }
 */
 // ------ Additional Functions ------ //
 
 // LOCALIZE FUNCTION //
 double VisitSolver::localize(string from, string to){
    
    std::string number1 = from.substr(1);
    std::string number2 = to.substr(1);
    int n1 = 0;
    int n2 = 0;
    for(char num1 : number1){
        if (std::isdigit(num1)) {
            n1 = n1 * 10 + (num1 - '0');
        }
        else{
          cout << "error"<<endl;
        }
    }
    for(char num2 : number2){
        if (std::isdigit(num2)) {
            n2 = n2 * 10 + (num2 - '0');
        }
        else{
          cout<<"error"<<endl;
        }
    }
    
    int start = n1;
    int target = n2;
    
    bool visited_nodes_array[30] = {};
    double dists[30] = {0};
    
    for(int index = 0; index < 30; index++){
        if(index == start){
            dists[index] = 0;
            // set the distance of the initial node we start from to zero
        }
        else{
            dists[index] = 100000; // set it to infinity
        }
    }
    // Implementing Djikstra algoritm to compute the cost
    for(int visited_vertices = 1; visited_vertices < 30; visited_vertices++){
        // FIND THE NEAREST UNVISITED NODE //
        int min_d = INT_MAX;
        int min;
        for(int s = 0; s < 30; s++){
            if(!visited_nodes_array[s] && dists[s] < min_d){
                min_d = dists[s];
                min = s;
            }
        }
        visited_nodes_array[min] = true;
        
        for(int y = 0; y < 30; y++){
            if(cost_m_adj[min][y] != 0 && !visited_nodes_array[y] && dists[min] != INT_MAX && dists[min] + cost_m[min][y] < dists[y]) {
                dists[y] = dists[min] + cost_m[min][y];
            }
        }
        return dists[target];
    }
 }
 
 // GENERATE RANDOM WAYPOINTS //
 
 void VisitSolver::generate_rnd_wyp(string wyp){
    float waypoints[30][3] ;// (x,y,theta) for 24 sample waypoint
    ofstream waypoint_file; // openning the waypoints file
    waypoint_file.open(wyp, ios_base::trunc);
    
    // closing the file
    waypoint_file.close();
    
    waypoint_file.open(wyp, ios_base::app);
    
    if (!waypoint_file.is_open()) {
        cout << "Failed to create output file." << endl;
    }
    else{
      // initial waypoint
      waypoint_file << "wp0[0,0,0]" <<endl;
    
      // waypoints of the 4 regions
      waypoint_file << "wp1[-2.75,2.75,0]" <<endl;
      waypoint_file << "wp2[2.75,2.75,1.57]" <<endl;
      waypoint_file << "wp3[-2.75,-2.75,3.14]" <<endl;
      waypoint_file << "wp4[2.75,-2.75,-1.57]" <<endl;

      // Traget waypoint
      waypoint_file << "wp5[3,0,0]" <<endl;

      random_device random;
      default_random_engine generate(random());
      uniform_real_distribution<double> distribution(-3.0, 3.0);
      double random_value = distribution(generate);
      
      for (int i =6; i< 30; i++){
          for (int j = 0; j < 3; j++){
              waypoints[i][j] = trunc(((distribution(generate))*100)/100);
          }
          waypoint_file << "wp" << i << "[" << waypoints[i][0] << "," << waypoints[i][1] << "," << waypoints[i][2] << "]" << endl;
      }
    }
    // closing the file
    waypoint_file.close();
 }
 
 // FIND MIN IN "cost_array"
 double VisitSolver::min_elem(){
    int m = cost_array[0];
    int i = 0;
    for (int j = 0; j < 30; j++){
        if(cost_array[j] < m){
            i = j;
            m = cost_array[j];
        }
    }
    cost_array[i] = 100.0;
    return i;
 }
 
 double VisitSolver::ecldn_dist(string from, string to){
    map <string, string> regions;
    for(int l = 0; l < 30; l++) {
      regions[region[l]] = wp[l];
    }
    double x_1 = waypoint[regions[from]].at(0);
    double y_1 = waypoint[regions[from]].at(1);
    
    double x_2 = waypoint[regions[to]].at(0);
    double y_2 = waypoint[regions[to]].at(1);
    
    distance = sqrt(pow((x_2-x_1),2) + pow((y_2-y_1),2));
    return distance;
 }

void VisitSolver::my_map(){
    int min;
    int maxWaypoints = 30;
    int maxConnections = k;
    int links[30]={};
    int i = 0;
    if(i< maxWaypoints){
        int f = 0;
        for(int j = 0; j < maxWaypoints; j++){
            if (i != j){
              string current_node = "r" + to_string(i);
              string next_node = "r" + to_string(j);
              cost_m[i][j] = ecldn_dist(current_node,next_node);
              cost_array[j] = cost_m[i][j]; //used to find mmin dist
            }
            else{
              cost_m[i][j] = 10000.0;
              cost_array[j] = cost_m[i][j];
            }
        }
        while(links[i] < maxConnections){
          if(f < maxWaypoints){
            min = min_elem();
            while(links[min] < maxConnections){
              cost_m_adj[i][min] = 1;
              cost_m_adj[min][i] = 1;
              links[i]++;
              links[min]++;
            }
            f++;  
          }
          i++;
        }
      }
  }
