#ifndef _GRUPO
#define _GRUPO
#include <vector>
#include <iostream>
#include "Agrupable.h"
#include "Fabrica.h"

class Grupo : public Agrupable {
private:
    vector<Agrupable*> elementos;
    // no es el dueño de la fábrica, solo es usuario, por lo que no le toca destruirla
    Fabrica* fabrica;
    // helper functions
    void borrarElementos();
    void copiarElementos(const Grupo&);
public:
    Grupo();
    // rule of three, estamos trabajando con punteros
    Grupo(const Grupo&);
    ~Grupo();
    Grupo& operator=(const Grupo& rhs);

    double distancia(Agrupable*) override; 
    int operator==(Agrupable*) override;
    void operator=(Agrupable*) override;
    Agrupable* clonar() override;
    ostream& imprimir(ostream& os = cout) override;
    istream& leer(istream& is = cin) override;

    void agregarElemento(Agrupable* elemento);
    void setFabrica(Fabrica* fabrica);
};

#endif
