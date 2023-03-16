#ifndef _FABRICA_SEMANTICO
#define _FABRICA_SEMANTICO
#include "Grupo.h"
#include "FabricaAbstracta.h"

class FabricaSemantico : public FabricaAbstracta {
public:
    Agrupable* construir() const override;
};

#endif
