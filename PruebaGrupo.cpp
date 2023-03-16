#include <iostream>
#include "Grupo.h"
#include "RealNormal.h"
#include "Fabrica.h"
// incluyan sus fábricas
#include "FabricaGrupo.h"
#include "FabricaRealNormal.h"

int main() {
    Fabrica* fabrica = new Fabrica();
    // registren sus fábricas
    fabrica->agregarFabrica("Grupo", new FabricaGrupo());
    fabrica->agregarFabrica("RealNormal", new FabricaRealNormal());

    Grupo* primerGrupo = new Grupo();
    for (int i = 0; i < 2; ++i) {
        Grupo* subGrupo = new Grupo();
        for (int j = 0; j < 1; ++j) {
            Grupo* subSubGrupo = new Grupo();
            for (int k = 0; k < 2; ++k) {
                subSubGrupo->agregarElemento(new RealNormal((rand()) / (double)RAND_MAX));
            }
            subGrupo->agregarElemento(subSubGrupo);
        }
        primerGrupo->agregarElemento(subGrupo);
    }

    Grupo* segundoGrupo = new Grupo();
    for (int i = 0; i < 2; ++i) {
        Grupo* subGrupo = new Grupo();
        for (int j = 0; j < 2; ++j) {
            subGrupo->agregarElemento(new RealNormal((rand()) / (double)RAND_MAX));
        }
        segundoGrupo->agregarElemento(subGrupo);
    }

    Grupo* tercerGrupo = new Grupo();
    tercerGrupo->setFabrica(fabrica);
    cin >> *tercerGrupo;

    /*
     * primer grupo conformado por subgrupos de subgrupos
     * segundo grupo conformado por subgrupos
     */

    double distancia = primerGrupo->distancia(segundoGrupo);
    cout << "Distancia: " << distancia << endl;
    cout << "Primer grupo: \n" << *primerGrupo << '\n';
    cout << "Segundo grupo: \n" << *segundoGrupo << '\n';
    cout << "Tercer grupo: \n" << *tercerGrupo << '\n';

    delete primerGrupo;
    delete segundoGrupo;
    delete tercerGrupo;

    delete fabrica;

}