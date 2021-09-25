//
// Created by mile on 24/09/21.
//
#ifndef PROYECTOCIENCIAS_CLASELABORATORIOS_H
#define PROYECTOCIENCIAS_CLASELABORATORIOS_H

#include <string>
using namespace std;


struct nodoV{
    string nombreLab;
    int numDosis;
};

class claseLaboratorios {
    nodoV listaLab[6];

public:
    claseLaboratorios(){
        listaLab[0].nombreLab = "Pfizer";
        listaLab[1].nombreLab = "Moderna";
        listaLab[2].nombreLab = "Jhonson";
        listaLab[3].nombreLab = "Astrazeneca";
        listaLab[4].nombreLab = "Sputnik";
        listaLab[5].nombreLab = "Sinovac";

        listaLab[0].numDosis = 2;
        listaLab[1].numDosis = 2;
        listaLab[2].numDosis = 1;
        listaLab[3].numDosis = 2;
        listaLab[4].numDosis = 2;
        listaLab[5].numDosis = 2;

    }

};


#endif //PROYECTOCIENCIAS_CLASELABORATORIOS_H
