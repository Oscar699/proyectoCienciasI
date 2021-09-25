//
// Created by oscar on 24/09/2021.
//
#include <string>
using namespace std;

#ifndef PROYECTOCIENCIAS_CLASEIPS_H
#define PROYECTOCIENCIAS_CLASEIPS_H

struct nodoV{
    int indexLab;
    int numVacunas;
};

class IPS{
    string nombre;
    string direccion
    nodoV listaVacunas[6];
public:
    IPS(){
        for (int i = 0; i < 6; i++){
            listaVacunas[i].indexLab = i;
            listaVacunas[i].numVacunas = 0;
        }
    }
    ~IPS();

};

#endif PROYECTOCIENCIAS_CLASEIPS_H
