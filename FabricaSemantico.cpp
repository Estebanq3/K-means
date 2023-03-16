#include "FabricaSemantico.h"
#include "Semantico.h"

Agrupable* FabricaSemantico::construir() const {
    return new Semantico();
}
