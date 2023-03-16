#ifndef _AGRUPABLE
#define _AGRUPABLE
#include <iostream>
using namespace std;

class Agrupable {
  friend ostream& operator<<(ostream &salida, Agrupable& elemento) {
    return elemento.imprimir(salida);
  }

  friend istream& operator>>(istream& is, Agrupable& agrupable) {
    return agrupable.leer(is);
  }

public:
  virtual ~Agrupable() {} // Es virtual pero vacio , no es virtual puro
  virtual double distancia(Agrupable *) = 0;
  virtual int operator==(Agrupable *) = 0;
  virtual void operator=(Agrupable *) = 0;
  virtual Agrupable* clonar() = 0;
  virtual ostream& imprimir(ostream &) = 0;
  virtual istream& leer(istream &) = 0;

};
#endif
