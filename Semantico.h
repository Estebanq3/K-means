#ifndef _CAMPO_SEMANTICO
#define _CAMPO_SEMANTICO
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Agrupable.h"

/*Agrupable semantico el cual calcula la distancia entre palabras de distintas familias de palabras
Si dos palabras son de una misma familia de palabras la mayor parte de las veces va a existir una distancia
minima entre ambas*/

class Semantico : public Agrupable{
	private:
		string palabra; //variable que almacena la palabra a comparar
	public:
		Semantico(); //constructor por defecto de semantico
		Semantico(string); //constructor que recibe como parametro un string
		~Semantico(); // destructor por defecto de semantico


		double distancia (Agrupable *); //cálculo de las distancias entre dos palabras, retorna la distancia, y recibe como parametro un puntero de tipo Agrupable
		int operator==(Agrupable *); //operador de igualdad, retorna el resultado de la comparación
		void operator=(Agrupable *); //operador de asignacion
		Agrupable * clonar(); //realiza copia de un elemento, retorna el elemento clonado
		ostream & imprimir(ostream&); //imprime los elementos del agrupable
		istream& leer(istream&); //lectura de elementos

};
#endif
