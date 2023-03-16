#include "Agrupable.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Semantico.h"
using namespace std;

//Metodo agrupable Semantico, se encarga de calcular las distancias entre dos palabras


		Semantico::Semantico(){ //constructor por defecto
			palabra = "";
		}

		Semantico::Semantico(string palabra){ //inicializa con string
			this->palabra = palabra;
		}

		Semantico::~Semantico(){ //destructor por defecto
			//destructor
		}


		//Calculo la distancia entre las palabras
		//Recibe como parametro un puntero tipo agrupable
		//Retorna la distancia entre las palabras
		double Semantico:: distancia (Agrupable * otro){
			Semantico * ptrSemantico = dynamic_cast< Semantico *>(otro);
			double distancia = 1.0;
			if(ptrSemantico){
				
				int N1 = this->palabra.size();
				//cout << "Palabra 1: " << this->palabra << endl << " Size: " << N1 << endl;
				int N2 = ptrSemantico->palabra.size();
				//cout << "Palabra 2: " << ptrSemantico->palabra << endl << " Size: " << N2 << endl;

				int i,j;
				vector <int> T(N2+1);

				for( i=0; i<= N2; i++)
					T[i] = i;
				for( i=0; i<N1; i++){
					T[0] = i+1;
					int corner = i;
					
					for( j=0; j<N2; j++){
						int upper = T[j+1];
            			if( this->palabra[i] == ptrSemantico->palabra[j] )
               				T[j+1] = corner;
            			else
               				T[j+1] = min(T[j], min(upper, corner)) + 1;
            			corner = upper;
					}

				}

				double dividir = T[N2];
				distancia = dividir/100;

				//cout<< "Distancia entre las palabras: " << T[N2]<< endl;
     			//cout << "Distancia entre 1 y 0: " << distancia << endl;
      


			}

			return distancia;
		}



		//operador que retorna si existe igualdad
		int Semantico:: operator==(Agrupable *otro){
			Semantico * ptrSemantico = dynamic_cast<Semantico *>(otro);
   			return (ptrSemantico && ptrSemantico->palabra == palabra);
		}

		//operador de asignacion
		void Semantico:: operator=(Agrupable *otro){
			Semantico * ptrSemantico = dynamic_cast<Semantico *>(otro);
  			palabra = "";
   			if(ptrSemantico){
     			palabra = ptrSemantico->palabra;
   			}
		}
		


		//clona elemento agrupable, retorna la copia
		Agrupable * Semantico:: clonar(){
			Semantico * nuevo = new Semantico(palabra);
			return nuevo;
		}

		//Metodo imprimir que retorna la palabra
		ostream& Semantico:: imprimir(ostream& salida){
			salida << " " << palabra;
			return salida;
		}

		//metodo de lectura
		istream& Semantico::leer(istream& entrada) {
   			entrada >> this->palabra;
   			return entrada;
		}