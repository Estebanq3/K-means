#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;
//clase miembro de kMeans la cual almacena los puntos necesarios para llevar a cabo el algoritmo
//Guarda un vector de los valores, distancias las cuales se utilizarán para formar grupos específicos de elementos

class Point{
private:
	int pointId, clusterId;
	int dimensions;
	vector<double>values;
public:
	//Constructor y GETS AND SETS
	Point(int, string);
	int getDimensions();
	int getCluster();
	int getID();
	void setCluster(int);
	double getVal(int);





};