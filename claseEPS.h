//
// Created by mile on 24/09/21.
//
#include "claseIPS.h"
#include "clasePersona.h"
#include <string>
using namespace std;

#ifndef PROYECTOCIENCIAS_EPS_H
#define PROYECTOCIENCIAS_EPS_H

struct nodoIps{
    IPS ips;
    int claveAfiliado;
    int sigCiudad;
};

struct nodoV{
    int indexLab;
    int numVacunas;
};

struct nodoCiudad{
    string nombreCiudad;
    int claveAfiliado;
    int posIPS;

};

struct registroAfiliado{
    Persona *persona;
    string nombreCiudad;
    int sigCiudad;
    fecha fecha;
    int posLab;
    int posIPS;
    char estado[2];
    int sigIPS;
    int sigDosis;
    int sigLab;
};

class claseEPS{
    string nombre;
    int numAfiliados;
    nodoIps cabeceraIPS[20];
    nodoIps cabeceraCiudad[20];
    nodoV listaVacunas[6];
    int poscabIPS;
    int poscabCiudad;
public:
    const string &getNombre() const;

    void setNombre(const string &nombre);

    int getNumAfiliados() const;

    void setNumAfiliados(int numAfiliados);

    const nodoIps *getCabeceraIps() const;

    const nodoIps *getCabeceraCiudad() const;

    const nodoV *getListaVacunas() const;

    EPS(){
        poscabIPS = 0;
        for (int i = 0; i < 6; i++){
            listaVacunas[i].indexLab = i;
            listaVacunas[i].numVacunas = 0;
            listaVacunas[i].sigCiudad = 0;
        }
    }
    ~EPS();
    void agregarIPS(IPS ips, int clave);
    void eliminarIPS();
    void agregarCiudad(IPS ips, int clave);
    void eliminarCiudad();
}

void claseEPS::agregarIPS(IPS ips, int clave, string ciudad){
    nodoCiudad *aux;
    for (int i = 0; i < poscabCiudad; ++i) {
        aux = poscabCiudad[i];
        if (aux->nombreCiudad == ciudad){
            if(aux->posIPS == -1){
                aux->posIPS = poscabIPS;
            }
            nodoIps *nodoAux = cabeceraIPS[aux->posIPS];
            while (nodoAux->sigCiudad != -1){
                nodoAux = cabeceraIPS[nodoAux->sigCiudad];
            }
            nodoAux->sigCiudad = poscabIPS;
        }
    }
    nodoIps *nuevo = new nodoIps();
    nuevo->ips = ips;
    nuevo->clave = clave;
    nuevo->sigCiudad = -1;
    cabeceraIps[poscabIPS] = nuevo;

    if (poscabIPS < 20){
        poscabIPS++;
    }
}

void claseEPS::eliminarIPS(){
    if(poscabIPS > 0)
        poscabIPS--;
}

void claseEPS::agregarCiudad(string n, int clave){
    nodoIps *nuevo = new nodoCiudad();
    nuevo->nombreCiudad = n;
    nuevo->clave = clave;
    nuevo->posIPS = -1;
    cabeceraCiudad[poscabCiudad] = nuevo;

    if (poscab < 20){
        poscabCiudad++
    }
}

void claseEPS::eliminarCiudad(){
    if(poscabCiudad > 0)
        poscabCiudad--;
}

const string &claseEPS::getNombre() const {
    return nombre;
}

void claseEPS::setNombre(const string &nombre) {
    claseEPS::nombre = nombre;
}

int claseEPS::getNumAfiliados() const {
    return numAfiliados;
}

void claseEPS::setNumAfiliados(int numAfiliados) {
    claseEPS::numAfiliados = numAfiliados;
}

const nodoIps *claseEPS::getCabeceraIps() const {
    return cabeceraIPS;
}

const nodoIps *claseEPS::getCabeceraCiudad() const {
    return cabeceraCiudad;
}

const nodoV *claseEPS::getListaVacunas() const {
    return listaVacunas;
}

#endif PROYECTOCIENCIAS_EPS_H
