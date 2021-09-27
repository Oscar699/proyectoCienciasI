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

struct nodoVacEps{
    int indexLab;
    int numVacunas;
};

struct nodoCiudad{
    string nombreCiudad;
    int clave;
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
    nodoCiudad cabeceraCiudad[20];
    nodoVacEps listaVacunas[6];
    int poscabIPS;
    int poscabCiudad;
public:
    const string &getNombre() const;

    void setNombre(const string &nombre);

    int getNumAfiliados() const;

    void setNumAfiliados(int numAfiliados);

    const nodoIps *getCabeceraIps() const;

    const nodoCiudad *getCabeceraCiudad() const;

    const nodoVacEps *getListaVacunas() const;

    claseEPS(){
        poscabIPS = 0;
        for (int i = 0; i < 6; i++){
            listaVacunas[i].indexLab = i;
            listaVacunas[i].numVacunas = 0;
        }
    }
    ~claseEPS();
    void agregarIPS(IPS ips, int clave, string ciudad);
    void eliminarIPS();
    void agregarCiudad(int clave, string ciudad);
    void eliminarCiudad();
};

void claseEPS::agregarIPS(IPS ips, int clave, string ciudad){
    nodoCiudad *aux;
    for (int i = 0; i < poscabCiudad; ++i) {
        aux = &cabeceraCiudad[i];
        if (aux->nombreCiudad == ciudad){
            if(aux->posIPS == -1){
                aux->posIPS = poscabIPS;
            }
            nodoIps *nodoAux = &cabeceraIPS[aux->posIPS];
            while (nodoAux->sigCiudad != -1){
                nodoAux = &cabeceraIPS[nodoAux->sigCiudad];
            }
            nodoAux->sigCiudad = poscabIPS;
        }
    }
    nodoIps *nuevo = new nodoIps();
    nuevo->ips = ips;
    nuevo->claveAfiliado = clave;
    nuevo->sigCiudad = -1;
    cabeceraIPS[poscabIPS] = *nuevo;

    if (poscabIPS < 20){
        poscabIPS++;
    }
}

void claseEPS::eliminarIPS(){
    if(poscabIPS > 0)
        poscabIPS--;
}

void claseEPS::agregarCiudad(int clave, string n){
    nodoCiudad *nuevo = new nodoCiudad();
    nuevo->nombreCiudad = n;
    nuevo->clave = clave;
    nuevo->posIPS = -1;
    cabeceraCiudad[poscabCiudad] = *nuevo;

    if (poscabCiudad < 20){
        poscabCiudad++;
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

const nodoCiudad *claseEPS::getCabeceraCiudad() const {
    return cabeceraCiudad;
}

const nodoVacEps *claseEPS::getListaVacunas() const {
    return listaVacunas;
}

#endif PROYECTOCIENCIAS_EPS_H
