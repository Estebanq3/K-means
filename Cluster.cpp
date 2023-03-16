#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Cluster.h"

//Clase encargada de calcular los centroides o clusters del algoritmo de KMenas, lo cuales
//serán los diferentes centros donde se agruparán los datos según su cercanía con centroide

Cluster::Cluster(int clusterId, Point centroid){
	this->clusterId = clusterId;
    for(int i=0; i<centroid.getDimensions(); i++){
        this->centroid.push_back(centroid.getVal(i));
    }
    this->addPoint(centroid);	
}


//Añade un punto específico para la ejecución del algoritmo
void Cluster::addPoint(Point p){
	p.setCluster(this->clusterId);
    points.push_back(p);
}


//metodo el cual remueve un punto, pero si no encuentra el punto a eliminar retorna false
bool Cluster::removePoint(int pointId){
	int size = points.size();

	for(int i = 0; i < size; i++){
	    if(points[i].getID() == pointId){
	        points.erase(points.begin() + i);
	        return true;
	    }
	}
	return false;
}

//METODOS DE GETS SETS

int Cluster:: getId(){
	return clusterId;
}


Point Cluster:: getPoint(int pos){
	return points[pos];
}

int Cluster:: getSize(){
	return points.size();
}

double Cluster:: getCentroidByPos(int pos){
	return centroid[pos];
}


void Cluster:: setCentroidByPos(int pos, double val){
	this->centroid[pos] = val;
}
