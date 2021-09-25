//
// Created by mile on 24/09/21.
//
#include "clasePersona.h"
#include <string>
#include "listaSimple.h"
#include "claseEPS.h"
using namespace std;

#ifndef PROYECTOCIENCIAS_CLASELISTAPERSONAS_H
#define PROYECTOCIENCIAS_CLASELISTAPERSONAS_H

struct nodoP{
    string clave;
    Persona *persona;
};

struct nodoCiudad{
    int id;
    string nombre;
    Persona *persona;
};

struct nodoEps{
    claseEPS *eps;
    Persona *persona;
};

class ListaPersona{
    Lista<Persona> personas;
    Persona *cabeceraSexo[2]; // 0 ->M  1-> F
    Persona *cabeceraEdad[8];
    Persona *cabeceraActividad[5];
    nodoEps cabeceraEPS[20];
    Lista<nodoP> cabeceraPais;
    Lista<nodoP> cabeceraCiudad;
    int  poscabEPS;

public:
    ListaPersona(){
        poscabEPS = 0;
        for (int i=0; i<2; i++){
            cabeceraSexo[i] = NULL
        }
        for (int i= 0; i< 8; i++){
            cabeceraEdad[i] = NULL;
        }
        for (int i = 0; i < 5; ++i) {
            cabeceraActividad[i] = NULL;
        }
    }
    void agregarEPS(claseEPS eps);
    void quitarIPS();
    void agregarPersona(Persona p);
};

void ListaPersona::agregarEPS(claseEPS eps) {
    nodoEps *nuevo = new nodoEps;
    nodoEps->eps = eps;
    nodoEps->persona = NULL;
    cabeceraEPS[poscabEPS] = nodoEps;
    if( poscabEPS < 20)
        poscabEPS++;

}

void ListaPersona::quitarIPS() {
    if (poscabEPS > 0)
        poscabEPS--;
}

void ListaPersona::agregarPersona(Persona p) {
    p.setSigActivLab(NULL);
    p.setSigCiudadRes(NULL);
    p.setSigEdad(NULL);
    p.setSigEps(NULL);
    p.setSigPaisNac(NULL);
    p.setSigSexo(NULL);
    personas.insertar_inicio(p);

    if (p.getSexo() == 'M'){
        if (cabeceraSexo[0] == NULL){
            cabeceraSexo[0] = p;
        } else{
            Persona *aux = cabeceraSexo[0];
            while (aux->getSigSexo() != NULL){
                aux = aux->getSigSexo();
            }
            aux->setSigSexo(p);
        }

    } else{
        if (cabeceraSexo[1] == NULL){
            cabeceraSexo[1] = p;
        } else{
            Persona *aux = cabeceraSexo[1];
            while (aux->getSigSexo() != NULL){
                aux = aux->getSigSexo();
            }
            aux->setSigSexo(p);
        }
    }

    if(p.getEdad() < 20){
        if (cabeceraEdad[0] == NULL){
            cabeceraEdad[0] = p;
        } else {
            Persona *aux = cabeceraEdad[0];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }
    }else if (p.getEdad() >= 20 && p.getEdad() < 30){
        if (cabeceraEdad[1] == NULL){
            cabeceraEdad[1] = p;
        } else {
            Persona *aux = cabeceraEdad[1];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }
    } else if (p.getEdad() >= 30 && p.getEdad() < 40){
        if (cabeceraEdad[2] == NULL){
            cabeceraEdad[2] = p;
        } else {
            Persona *aux = cabeceraEdad[2];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }
    }else if (p.getEdad() >= 40 && p.getEdad() < 50){
        if (cabeceraEdad[3] == NULL){
            cabeceraEdad[3] = p;
        } else {
            Persona *aux = cabeceraEdad[3];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }

    }else if (p.getEdad() >= 50 && p.getEdad() < 60){
        if (cabeceraEdad[4] == NULL){
            cabeceraEdad[4] = p;
        } else {
            Persona *aux = cabeceraEdad[4];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }

    }else if (p.getEdad() >= 60 && p.getEdad() < 70){
        if (cabeceraEdad[5] == NULL){
            cabeceraEdad[5] = p;
        } else {
            Persona *aux = cabeceraEdad[5];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }
    }else if (p.getEdad() >= 70 && p.getEdad() < 80){
        if (cabeceraEdad[6] == NULL){
            cabeceraEdad[6] = p;
        } else {
            Persona *aux = cabeceraEdad[6];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }
    } else{
        if (cabeceraEdad[7] == NULL){
            cabeceraEdad[7] = p;
        } else {
            Persona *aux = cabeceraEdad[7];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }

    }

}

#endif PROYECTOCIENCIAS_CLASELISTAPERSONAS_H
