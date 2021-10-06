//
// Created by oscar on 24/09/2021.
//

#ifndef PROYECTOCIENCIAS_CLASEIPS_H
#define PROYECTOCIENCIAS_CLASEIPS_H

#include <string>
#include <cstdlib>
using namespace std;

struct nodoV{
    int indexLab;
    int numVacunas;
};

class IPS{
    string nombre;
    string direccion;
    nodoV listaVacunas[6];
    int numAfiliados;

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

    int getNumAfiliados() const;

    void setNumAfiliados(int numAfiliados);

    IPS(){
        numAfiliados = 0;
        for (int i = 0; i < 6; i++){
            listaVacunas[i].indexLab = i;
            listaVacunas[i].numVacunas = 0;
        }
    }

    int distribuirVacunas(int, int);

    nodoV* obtenerVacunas(int pos);


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

int IPS::getNumAfiliados() const {
    return numAfiliados;
}

void IPS::setNumAfiliados(int numAfiliados) {
    IPS::numAfiliados = numAfiliados;
}

nodoV *IPS::obtenerVacunas(int pos){
    return &listaVacunas[pos];
}

#endif //PROYECTOCIENCIAS_CLASEIPS_H
