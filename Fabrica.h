#ifndef _FABRICA
#define _FABRICA
#include <map>
#include <string>
#include "Agrupable.h"
#include "FabricaAbstracta.h"

class Fabrica {
private:
    map<string, FabricaAbstracta*> fabricas;
public:
    ~Fabrica();
    Agrupable* construir(string nombreAgrupable) const;
    void agregarFabrica(string nombreAgrupable, FabricaAbstracta* fabrica);
};

#endif
