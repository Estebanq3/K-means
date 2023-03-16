#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Agrupable.h"
#include "Semantico.h"
#include "Grupo.h"

#include <utility>
#include "KMeans.h"


int KMeans:: getNearestClusterId(Point point){
		double sum = 0.0, min_dist;
        int NearestClusterId;

        for(int i = 0; i < dimensions; i++){
            sum += pow(clusters[0].getCentroidByPos(i) - point.getVal(i), 2.0);
        }

        min_dist = sqrt(sum);
        NearestClusterId = clusters[0].getId();

        for(int i = 1; i < K; i++){
            double dist;
            sum = 0.0;

            for(int j = 0; j < dimensions; j++){
                sum += pow(clusters[i].getCentroidByPos(j) - point.getVal(j), 2.0);
            }

            dist = sqrt(sum);

            if(dist < min_dist){
                min_dist = dist;
                NearestClusterId = clusters[i].getId();
            }
        }

        return NearestClusterId;
}





KMeans::KMeans(int K, int iterations){
	this->K = K;
    this->iters = iterations;
}






void KMeans:: run(vector<Point>& all_points){
    cout<< "EJECUTANDO RUN DE KMEANS"<<endl;
	total_points = all_points.size();
    dimensions = all_points[0].getDimensions();


    //Initializing Clusters
    vector<int> used_pointIds;

    for(int i=1; i<=K; i++){
        while(true){
            int index = rand() % total_points;

            if(find(used_pointIds.begin(), used_pointIds.end(), index) == used_pointIds.end()){
                used_pointIds.push_back(index);
                all_points[index].setCluster(i);
                Cluster cluster(i, all_points[index]);
                clusters.push_back(cluster);
                break;
            }
        }
    }
    cout<<"Clusters inicializados = "<<clusters.size()<<endl<<endl;
    cout<<"Ejecutando K-Means Clustering.."<<endl;
    int iter = 1;
    while(true){
        cout<<"Iter - "<<iter<<"/"<<iters<<endl;
        bool done = true;
        // Add all points to their nearest cluster
        for(int i = 0; i < total_points; i++){
            int currentClusterId = all_points[i].getCluster();
            int nearestClusterId = getNearestClusterId(all_points[i]);
            
            if(currentClusterId != nearestClusterId){
                if(currentClusterId != 0){
                    for(int j=0; j<K; j++){
                        if(clusters[j].getId() == currentClusterId){
                            clusters[j].removePoint(all_points[i].getID());
                        }
                    }
                }

                for(int j=0; j<K; j++){
                    if(clusters[j].getId() == nearestClusterId){
                        clusters[j].addPoint(all_points[i]);
                    }
                }
                all_points[i].setCluster(nearestClusterId);
                done = false;
            }
        }

            // Recalculating the center of each cluster
            for(int i = 0; i < K; i++){
                int ClusterSize = clusters[i].getSize();
                for(int j = 0; j < dimensions; j++){
                    double sum = 0.0;
                    if(ClusterSize > 0){
                        for(int p = 0; p < ClusterSize; p++)
                            sum += clusters[i].getPoint(p).getVal(j);
                            clusters[i].setCentroidByPos(j, sum / ClusterSize);
                    }
                }
            }
            if(done || iter >= iters){
                cout << "Clustering completado en iteracion : " <<iter<<endl<<endl;
                break;
            }
            iter++;
    }




        //Print pointIds in each cluster //AQUI SACO LOS DATOS DE CADA GRUPO
    for(int i=0; i<K; i++){
        cout<<"Palabras en el grupo: "<<clusters[i].getId()<<" : ";
        for(int j=0; j<clusters[i].getSize(); j++){
            numerosPalabras.push_back(clusters[i].getPoint(j).getID());
            cout<<clusters[i].getPoint(j).getID()<<" ";
        }
        cout<<endl<<endl;
    }

    

    cout<<"========================"<<endl<<endl;
    //Write cluster centers to file
    ofstream outfile;
    outfile.open("clusters.txt");
    if(outfile.is_open()){
        for(int i=0; i<K; i++){
        cout<<"Cluster "<<clusters[i].getId()<<" centroide : ";
        for(int j=0; j<dimensions; j++){
            cout<<clusters[i].getCentroidByPos(j)<<" ";     //Output to console
            outfile<<clusters[i].getCentroidByPos(j)<<" ";  //Output to file
        }
        cout<<endl;
        outfile<<endl;
            }
            outfile.close();
    }
    else{
        cout<<"Error: Unable to write to clusters.txt";
    }


}


int KMeans:: getK(){
    return K;
}
int KMeans::getSizeClusters(int pos){
    return clusters[pos].getSize();
}

int KMeans:: getNumeroPalabras(int pos){
    return numerosPalabras[pos];
}
int KMeans:: getIterador(int i, int j){
    return clusters[i].getPoint(j).getID();
}






Grupo* KMeans::agrupar(const Grupo& grupo) {
  /*  
    vector<Agrupable*> elementos = grupo.getElementos(); 
    Grupo* semantico1 = new Grupo();
    Grupo* semantico2 = new Grupo();
    Grupo* semantico3 = new Grupo();
    for(int i=0;i<elementos.size();++i){
    //ya que los metodos de calculo de las distancias estan demostrados en el main, asi como el mismo agrupador, aqui solo demuestro como
        //seria la estructura si la hubiera formado de la manera correcta.
      //aqui agregaria cada elemento de mi brubuja ya formada a los grupos de la clase grupo      
    }
    Grupo* familia = new Grupo();
    familia->agregarElemento(semantico1);
    familia->agregarElemento(semantico2);
    familia->agregarElemento(semantico3);

*/
    Grupo* familia = new Grupo();
    return familia;
}








