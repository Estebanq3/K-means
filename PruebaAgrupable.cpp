#include "Agrupable.h"

// INCLUYA SU AGRUPABLE AQUÍ
#include "RealNormal.h"

// NO TOQUE EL RESTO DEL CODIGO EXCEPTO DONDE SE INDICA
int main(){
   // Asignele una instancia de su clase
   // Agrupable * a = new SuAgrupable(); 
   Agrupable * a = new RealNormal(0.5); 

   // Asigne otra instancia de cualqueir Agrupable
   // Agrupable * b = new SuAgrupable(); 
   Agrupable * b = new RealNormal(0.75);

   cout << a << endl;
   cout << b << endl;
   cout << "Estan a una distancia de: "<< a->distancia(b) << endl;   
   cout << ((*a == b)?"":"No ") << "son iguales a y b"<< endl;
   cout << ((*a == a)?"":"No ") << "son iguales a y a"<< endl;
   Agrupable * clon = a->clonar();
   cout << "El clon vale ";
   cout << clon << endl;
   *clon = b;
   cout << "El clon ahora vale ";
   cout << clon << endl;
   delete a;
   delete b;
   delete clon;
}
