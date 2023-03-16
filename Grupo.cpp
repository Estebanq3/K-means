#include "Grupo.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>

Grupo::Grupo() : fabrica(nullptr) {}

/* constructor por copia, destructor y operador de asignación: regla de 3 */
Grupo::Grupo(const Grupo& otro) {
    copiarElementos(otro);
}

Grupo::~Grupo() {
    borrarElementos();
}

Grupo& Grupo::operator=(const Grupo& rhs) {
    // revisar el caso de auto asignación
    if (this != &rhs) {
        borrarElementos();
        copiarElementos(rhs);
    }
    return *this;
}

/* métodos privados */

void Grupo::copiarElementos(const Grupo& otroGrupo) {
    for (Agrupable* elemento : otroGrupo.elementos) {
        // clono los elementos para evitar que ambos tengan punteros al mismo objeto
        Agrupable* clonElemento = elemento->clonar();
        this->agregarElemento(clonElemento);
    }
}

void Grupo::borrarElementos() {
    for (Agrupable* elemento : this->elementos) {
        // no reviso si son nulos porque solo inserto punteros que no son nulos
        delete elemento;
    } 
}

/* implementación de los métodos virtuales puros de agrupable */

double Grupo::distancia(Agrupable* otro) {
    double sumatoria_total = 0.0;
    // reviso si otro es un grupo o un elemento
    Grupo* otroGrupo = dynamic_cast<Grupo*>(otro);

    // calculo la suma de las distancias del otro agrupable con cada uno de los elementos de mi grupo

    // ranged for loop de c++11 :
    // equivalente a: for (vector<Agrupable*>::iterator itr = this->elementos.begin(); itr != this->elementos.end(); ++itr)
    for (Agrupable* elementoMiGrupo : this->elementos) {
        if (otroGrupo != nullptr) {
        // la conversión fue exitosa, el otro agrupable es un grupo
            double sumatoria_local = 0.0;
            // tengo que promediar la distancia del elemento actual de mi grupo con cada uno de los elementos del otro grupo
            for (Agrupable* elementoOtroGrupo : otroGrupo->elementos) {
                // note que este llamado puede ser recursivo en caso que el elemento de mi grupo sea también un grupo
                sumatoria_local += elementoMiGrupo->distancia(elementoOtroGrupo);
            }
            // saco el promedio con todos los elementos del otro grupo
            sumatoria_local /= otroGrupo->elementos.size();
            // sumo el promedio del elemento actual de mi grupo a la sumatoria total
            sumatoria_total += sumatoria_local;
        }
        else {
        // la conversión falló, el otro agrupable es un único elemento
            // sumo la distancia entre el elemento actual de mi grupo y el otro agrupable a la sumatoria total
            // note que este llamado puede ser recursivo en caso que el elemento de mi grupo sea también un grupo
            sumatoria_total += elementoMiGrupo->distancia(otro);
        }
    }
    // retorno el promedio
    return sumatoria_total / this->elementos.size();
} 

void Grupo::operator=(Agrupable* rhs) {
    Grupo* otroGrupo = dynamic_cast<Grupo*>(rhs);
    if (otroGrupo != nullptr) {
        this->elementos = otroGrupo->elementos;
    }
}

Agrupable* Grupo::clonar() {
    Grupo* clon = new Grupo();
    clon->copiarElementos(*this);
    return clon;
}

int Grupo::operator==(Agrupable* rhs) {
    Grupo* otroGrupo = dynamic_cast<Grupo*>(rhs);
    bool equals = true;

    if (otroGrupo == nullptr || otroGrupo->elementos.size() != this->elementos.size())
        equals = false;

    for (unsigned int i = 0; i < elementos.size() && equals; ++i) {
        equals = *(elementos[i]) == otroGrupo->elementos[i];
    }

    return equals;
};

ostream& Grupo::imprimir(ostream& os) {
    os << "{ ";
    for (unsigned int i = 0; i < elementos.size(); ++i) {
        elementos[i]->imprimir(os);
        if (i != elementos.size() - 1)
            os << ", ";
    }
    return os << " }";
}

istream& Grupo::leer(istream& is) {
    if (fabrica == nullptr) {
        throw std::logic_error("Debe fijar una instancia de fábrica con el método setFabrica antes de poder leer grupos.");
    }

    throw runtime_error("Not implemented.");

    return is;
}

/* métodos públicos adicionales */

void Grupo::agregarElemento(Agrupable* elemento) {
    // solo inserto punteros que no son nulos
    if (elemento != nullptr) {
        this->elementos.push_back(elemento);
    }
}

void Grupo::setFabrica(Fabrica* fabrica) {
    this->fabrica = fabrica;
}
