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

class claseEPS(){
    string nombre;
    int numAfiliados;
    nodoIps cabeceraIPS[20];
    nodoIps cabeceraCiudad[20];
    nodoV listaVacunas[6];
    int poscabIPS;
    int poscabCiudad;

public:
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

void claseEPS::agregarIPS(IPS ips, int clave){
    nodoIps *nuevo = new nodoIps();
    nuevo->ips = ips;
    nuevo->clave = clave;
    nuevo->sigCiudad = 0;
    cabeceraIps[poscabIPS] = nuevo;

    if (cabeceraIPS.size>poscab){
        poscabIPS++
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
    nuevo->posIPS = 0;
    cabeceraCiudad[poscabCiudad] = nuevo;

    if (20>poscab){
        poscabCiudad++
    }
}

void claseEPS::eliminarCiudad(){
    if(poscabCiudad > 0)
        poscabCiudad--;
}

#endif PROYECTOCIENCIAS_EPS_H
