#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include "KMeans.h"
#include "Agrupable.h"
#include "Semantico.h"
#include "Grupo.h"

int main(){
    cout<< "EJECUTANDO MAIN"<<endl;
    cout<< "Cuantos grupos de palabras desea construir: "<<endl;
    int K; //NUMERO DE GRUPOS QUE HACE
    cin>>K;



    //CREAR MI TXT CON MI AGRUPABLE Y HACERLO IGUAL A FILENAME
    int cantidadElementos;
    cout<< "Digite elementos a comparar: "<< endl;
    cin>> cantidadElementos;
    vector<string>palabras;
    cout << "Escriba las palabras a comparar: "<< endl;
    for(int i=0; i<cantidadElementos; i++){
        string palabra;
        cin>> palabra;
        palabras.push_back (palabra);
    }
    ofstream file;
    file.open("C:/Users/Extreme-pc/Desktop/archivo.txt"); 
    for( int i=0; i<cantidadElementos; i++){
        for(int j=0; j<cantidadElementos; j++){
            Agrupable * a = new Semantico(palabras[i]); 
            Agrupable * b = new Semantico(palabras[j]);
            file << a->distancia(b) << " "; 
        }
        file<< "\n";
    }
    file.close();
    //Open file for fetching points
    string filename = "archivo.txt";
    ifstream infile(filename.c_str());
    if(!infile.is_open()){
        cout<<"Error: Failed to open file."<<endl;
        return 1;
    }


//COMIENZA A LEER DISTANCIAS DEL TXT
    //Fetching points from file
    int pointId = 1;
    vector<Point> all_points;
    string line;
    while(getline(infile, line)){
        cout<< line <<endl;  //IMPRIMO LINE, ES DECIR DISTANCIAS AQUI ESTAN LAS DISTANCIAS!!!!
        Point point(pointId, line);
        all_points.push_back(point);
        pointId++;
    }
    infile.close();
    cout<<"\nData fetched exitoso!"<<endl<<endl;
    


    //Return if number of clusters > number of points
    if(all_points.size() < K){
        cout<<"Error: Number of clusters greater than number of points."<<endl;
        return 1;
    }
    //Running K-Means Clustering
    int iters = 100;
    KMeans kmeans(K, iters);
    kmeans.run(all_points);

    //ESCRIBO EN IDIOMA PALABRAS LOS CLUSTERS
    cout<<endl;
    cout<< "Grupos pero representados con las palabras:"<<endl;
    int grupo = 1;
    for(int i=0; i<kmeans.getK(); i++){
        cout<<"Palabras en el grupo: "<< grupo <<" : ";
        for(int j=0; j<kmeans.getSizeClusters(i); j++){
            cout<< palabras[kmeans.getIterador(i,j)-1] <<" ";
        }
        ++grupo;
        cout<<endl;
    }


    


    
    return 0;
}