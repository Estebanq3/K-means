#ifndef _FABRICA_ABSTRACTA
#define _FABRICA_ABSTRACTA
#include "Agrupable.h"

class FabricaAbstracta {
public:
    // destructor virtual y vacío
    virtual ~FabricaAbstracta() {}
    virtual Agrupable* construir() const = 0;
};

#endif
