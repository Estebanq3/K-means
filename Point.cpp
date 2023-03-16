#include "Point.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>

//Constructor de pointer el cual guarda los valores(distancias)
Point::Point(int id, string line){
	dimensions = 0;
    pointId = id;
    stringstream is(line);
    double val;
    while(is >> val){
      values.push_back(val);
      dimensions++;
    }
    clusterId = 0; //Initially not assigned to any cluster

}

int Point:: getDimensions(){
	return dimensions;
}

int Point:: getCluster(){
	return clusterId;
}

int Point:: getID(){
	return pointId;
}

void Point:: setCluster(int val){
	clusterId = val;
}

double Point:: getVal(int pos){
	return values[pos];
}






	
	
	
	

