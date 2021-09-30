//
// Created by oscar on 24/09/2021.
//
#include <string>
#include <cstdlib>
using namespace std;

#ifndef PROYECTOCIENCIAS_CLASEIPS_H
#define PROYECTOCIENCIAS_CLASEIPS_H

struct nodoV{
    int indexLab;
    int numVacunas;
};

class IPS{
    string nombre;
    string direccion;
    nodoV listaVacunas[6];
public:
    const string &getNombre() const {
        return nombre;
    }

    void setNombre(const string &nombre) {
        IPS::nombre = nombre;
    }

    const string &getDireccion() const {
        return direccion;
    }

    void setDireccion(const string &direccion) {
        IPS::direccion = direccion;
    }

    const nodoV *getListaVacunas() const {
        return listaVacunas;
    }

    IPS(){
        for (int i = 0; i < 6; i++){
            listaVacunas[i].indexLab = i;
            listaVacunas[i].numVacunas = 0;
        }
    }

    int distribuirVacunas(int, int);

    //~IPS();

};

// Toma un número aleatorio de vacunas de un numero total de vacunas ingresadas, devolviendo el total de vacunas menos las vacunas tomadas
int IPS::distribuirVacunas(int indexLab, int numVacunas) {
    int numVacunasTomadas;
    if(numVacunas != 0){
        srand(time(NULL));
        numVacunasTomadas = rand() % numVacunas + 1;
    }else{
        numVacunasTomadas = 0;
    }
    listaVacunas[indexLab].numVacunas = numVacunasTomadas;

    return numVacunas - numVacunasTomadas;
}

#endif //PROYECTOCIENCIAS_CLASEIPS_H
