#include "Cluster.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <utility>
#include "Agrupador.h"
#include "Grupo.h"

//K-means es un algoritmo de clasificación no supervisada (clusterización) que agrupa objetos en k grupos basándose en sus características. 
//El agrupamiento en esta clase se realiza minimizando la suma de distancias entre cada objeto y el centroide de su grupo o cluster.
//Esta clase no esta adaptada con grupo por lo tanto para mostrar que funciona el agrupador lo que realice fue un main del mismo
//que recibe entradas del usuario. Mas la agrupacion si la realiza de la forma correcta como queda demostrado en el main, las unicas modificaciones
//que se tendrian que hacer es darle como valores a KMeans grupos que se reciban como parametro para que pueda trabajar enlazado con el agrupador
//en lugar de las entradas del usuario, se necesita una matriz para ir guardando los valores.


class KMeans: public Agrupador{
private:

	int K, iters, dimensions, total_points; //numero de clusters, iteraciones a realizar para agrupar todos los elementos, dimensiones, y puntos totales a agrupar
    vector<Cluster> clusters; //vector de centroides
    int getNearestClusterId(Point);
    vector<int>numerosPalabras; //vector que almacena una representaicon de las palabras segun su orden de introduccion
public:
	Grupo* agrupar(const Grupo& grupo) override; //metodo encargado de agrupar segun el criterio y las distancias, retorna un grupo
	KMeans(int,int); //constructor que recibe dos parametros int
	void run(vector<Point>& all_points); //metodo para ejecutar el algoritmo de KMeans y todos sus metodos
	//Metodos get
	int getNumeroPalabras(int);
	int getK();
	int getSizeClusters(int);
	int getIterador(int,int);

};