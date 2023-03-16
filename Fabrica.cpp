#include "Fabrica.h"

Fabrica::~Fabrica() {
    for (auto pair : fabricas) {
        delete pair.second;
    }
}

Agrupable* Fabrica::construir(string nombreAgrupable) const {
    auto itr = fabricas.find(nombreAgrupable);
    if (itr != fabricas.end()) {
    // se encontró la fábrica
        return itr->second->construir();
    }
    return nullptr;
}

void Fabrica::agregarFabrica(string nombreAgrupable, FabricaAbstracta* fabrica) {
    if (fabrica != nullptr)
        fabricas.insert({ nombreAgrupable, fabrica });
}
