#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Point.h"

//Clase encargada de calcular los centroides o clusters del algoritmo de KMenas, los cuales
//serán los diferentes centros donde se agruparán los datos según su cercanía con centroide

class Cluster{
private:
	int clusterId;
	vector<double> centroid;
	vector<Point> points;

public:
	Cluster(int, Point);
	void addPoint(Point); //añade un punto en especifico para la ejecución del algoritmo
	bool removePoint(int); //remueve un punto específico, retorna falso si no se encuentra al valor buscado
	//Gets and Sets
	int getId(); //obtiene el ID de un punto o un cluster
	Point getPoint(int);
	int getSize();
	double getCentroidByPos(int);
	void setCentroidByPos(int,double);

};