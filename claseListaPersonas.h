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

//Creación de estructuras base

struct nodoP{
    string clave;
    Persona *persona;
};

struct nodoEps{
    claseEPS *eps;
    Persona *persona;
};

//Creación de

class ListaPersona{
    Lista<Persona> personas;
    Persona *cabeceraSexo[2]; // 0 ->M  1-> F
    Persona *cabeceraEdad[8];
    Persona *cabeceraActividad[5];
    nodoEps *cabeceraEPS[20];
    Lista<nodoP> cabeceraPais;
    Lista<nodoP> cabeceraCiudad;
    int  poscabEPS;

public:
    ListaPersona(){
        poscabEPS = 0;
        for (int i=0; i<2; i++){
            cabeceraSexo[i] = NULL;
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
    void eliminarPersona(Persona p);
};

void ListaPersona::agregarEPS(claseEPS eps) {
    nodoEps *nuevo = new nodoEps;
    nuevo->eps = &eps;
    nuevo->persona = NULL;
    cabeceraEPS[poscabEPS] = nuevo;
    if( poscabEPS < 20)
        poscabEPS++;

}

void ListaPersona::quitarIPS() {
    if (poscabEPS > 0)
        poscabEPS--;
}

void ListaPersona::agregarPersona(Persona p) {
    Persona *aux;
    nodoEps *nodoEps;
    nodoP *nodo;

    p.setSigActivLab(NULL);
    p.setSigCiudadRes(NULL);
    p.setSigEdad(NULL);
    p.setSigEps(NULL);
    p.setSigPaisNac(NULL);
    p.setSigSexo(NULL);
    personas.insertar_inicio(p);

    if (p.getSexo() == 'M'){
        if (cabeceraSexo[0] == NULL){
            cabeceraSexo[0] = &p;
        } else{
            aux = cabeceraSexo[0];
            while (aux->getSigSexo() != NULL){
                aux = aux->getSigSexo();
            }
            aux->setSigSexo(&p);
        }

    } else{
        if (cabeceraSexo[1] == NULL){
            cabeceraSexo[1] = &p;
        } else{
            aux = cabeceraSexo[1];
            while (aux->getSigSexo() != NULL){
                aux = aux->getSigSexo();
            }
            aux->setSigSexo(&p);
        }
    }

    if(p.getEdad() < 20){
        if (cabeceraEdad[0] == NULL){
            cabeceraEdad[0] = &p;
        } else {
            aux = cabeceraEdad[0];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(&p);
        }
    }else if (p.getEdad() >= 20 && p.getEdad() < 30){
        if (cabeceraEdad[1] == NULL){
            cabeceraEdad[1] = &p;
        } else {
            aux = cabeceraEdad[1];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(&p);
        }
    } else if (p.getEdad() >= 30 && p.getEdad() < 40){
        if (cabeceraEdad[2] == NULL){
            cabeceraEdad[2] = &p;
        } else {
            aux = cabeceraEdad[2];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(&p);
        }
    }else if (p.getEdad() >= 40 && p.getEdad() < 50){
        if (cabeceraEdad[3] == NULL){
            cabeceraEdad[3] = &p;
        } else {
            aux = cabeceraEdad[3];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(&p);
        }

    }else if (p.getEdad() >= 50 && p.getEdad() < 60){
        if (cabeceraEdad[4] == NULL){
            cabeceraEdad[4] = &p;
        } else {
            aux = cabeceraEdad[4];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(&p);
        }

    }else if (p.getEdad() >= 60 && p.getEdad() < 70){
        if (cabeceraEdad[5] == NULL){
            cabeceraEdad[5] = &p;
        } else {
            aux = cabeceraEdad[5];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(&p);
        }
    }else if (p.getEdad() >= 70 && p.getEdad() < 80){
        if (cabeceraEdad[6] == NULL){
            cabeceraEdad[6] = &p;
        } else {
            aux = cabeceraEdad[6];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(&p);
        }
    } else{
        if (cabeceraEdad[7] == NULL){
            cabeceraEdad[7] = &p;
        } else {
            aux = cabeceraEdad[7];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(&p);
        }

    }

    if(p.getActivLab() == "ARTES"){
        if (cabeceraActividad[0] == NULL){
            cabeceraActividad[0] = &p;
        } else {
            aux = cabeceraActividad[0];
            while (aux->getSigActivLab() != NULL) {
                aux = aux->getSigActivLab();
            }
            aux->setSigEdad(&p);
        }
    }else if(p.getActivLab() == "TECNICO"){
        if (cabeceraActividad[1] == NULL){
            cabeceraActividad[1] = &p;
        } else {
            aux = cabeceraActividad[0];
            while (aux->getSigActivLab() != NULL) {
                aux = aux->getSigActivLab();
            }
            aux->setSigEdad(&p);
        }
    }else if(p.getActivLab() == "INGENIERO"){
        if (cabeceraActividad[2] == NULL){
            cabeceraActividad[2] = &p;
        } else {
            aux = cabeceraActividad[0];
            while (aux->getSigActivLab() != NULL) {
                aux = aux->getSigActivLab();
            }
            aux->setSigEdad(&p);
        }
    }else if(p.getActivLab() == "SOCIALES"){
        if (cabeceraActividad[3] == NULL){
            cabeceraActividad[3] = &p;
        } else {
            aux = cabeceraActividad[0];
            while (aux->getSigActivLab() != NULL) {
                aux = aux->getSigActivLab();
            }
            aux->setSigEdad(&p);
        }
    }else if(p.getActivLab() == "FILOSOFIA"){
        if (cabeceraActividad[4] == NULL){
            cabeceraActividad[4] = &p;
        } else {
            aux = cabeceraActividad[0];
            while (aux->getSigActivLab() != NULL) {
                aux = aux->getSigActivLab();
            }
            aux->setSigEdad(&p);
        }
    }

    for (int i = 0; i < cabeceraPais.lista_size(); ++i) {
        nodoP nodoAux =cabeceraPais.obtenerDato(i);
        nodo = &nodoAux;
        if (p.getPaisNac() == nodo->clave){
            if (nodo->persona == NULL){
                nodo->persona = &p;
                cabeceraPais.modificar(*nodo,i);
            } else{
                aux = nodo->persona;
                while (aux->getSigPaisNac() != NULL){
                    aux = aux->getSigPaisNac();
                }
                aux->setSigPaisNac(&p);
            }
        }

    }

    for (int i = 0; i < cabeceraCiudad.lista_size(); ++i) {
        nodoP nodoAux =cabeceraCiudad.obtenerDato(i);
        nodoP *nodo = &nodoAux;
        if (p.getCiudadRes() == nodo->clave){
            if (nodo->persona == NULL){
                nodo->persona = &p;
                cabeceraCiudad.modificar(*nodo,i);
            } else{
                aux = nodo->persona;
                while (aux->getSigCiudadRes() != NULL){
                    aux = aux->getSigCiudadRes();
                }
                aux->setSigCiudadRes(&p);
            }
        }

    }

    for (int i = 0; i < poscabEPS; ++i) {
        nodoEps = cabeceraEPS[i];
        if (p.getNombreEps() == nodo->persona->getNombreEps()){
            if (nodoEps->persona == NULL){
                nodoEps->persona = &p;
            } else{
                aux = nodoEps->persona;
                while (aux->getSigEps() != NULL){
                    aux = aux->getSigEps();
                }
                aux->setSigEps(&p);
            }
        }

    }
    delete aux;
    delete nodo;
    delete nodoEps;

}

void ListaPersona::eliminarPersona(Persona persona) {
    Persona *aux1;
    Persona *aux2;
    Persona *p = &persona;
    if (p->getSexo() == 'M'){ //Borrado en Cabecera Sexo
        if(cabeceraSexo[0] == p){
            cabeceraSexo[0] = p->getSigSexo();
            delete p;
        }else{
            aux1 = cabeceraSexo[0];
            aux2 = aux1->getSigEdad();

            while (aux2->getSigSexo() != NULL){
                if ( aux2 == p )
                    break;
                aux1 = aux2;
                aux2 = aux2->getSigSexo();
            }

            if ( aux2->getSigSexo() == NULL ){
                aux1->setSigSexo(NULL);
                delete p;
            }else {
                aux1->setSigSexo(aux2->getSigSexo());
                delete p;
            }
        }

    }else{ //Borrado en Cabecera Sexo
        if(cabeceraSexo[1] == p){
            cabeceraSexo[1] =p->getSigSexo();
            delete p;
        }else{
            aux1 = cabeceraSexo[1];
            aux2 = aux1->getSigEdad();

            while (aux2->getSigSexo() != NULL){
                if ( aux2 == p )
                    break;
                aux1 = aux1->getSigSexo();
                aux2 = aux2->getSigSexo();
            }

            if (aux2->getSigSexo() == NULL ){
                aux1->setSigSexo(NULL);
                delete p;
            }else {
                aux1->setSigSexo(aux2->getSigSexo());
                delete p;
            }

        }

    }
    if(p->getEdad()<20){ //Borrado en Cabecera Edad
        if(cabeceraEdad[0] == p){
            cabeceraEdad[0] = p->getSigEdad();
            delete p;
        }else{
            aux1 = cabeceraEdad[0];
            aux2 = aux1->getSigEdad();

            while(aux2->getSigEdad() != NULL){
                if(aux2 == p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if(aux2->getSigEdad() == NULL){
                aux1->setSigEdad(NULL);
                delete p;
            }else{
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    }else if(p->getEdad()>=20 && p->getEdad()<30){ //Borrado en Cabecera Edad
        if(cabeceraEdad[1] == p){
            cabeceraEdad[1] = p->getSigEdad();
            delete p;
        }else{
            aux1 = cabeceraEdad[1];
            aux2 = aux1->getSigEdad();

            while(aux2->getSigEdad() != NULL){
                if(aux2 == p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if(aux2->getSigEdad() == NULL){
                aux1->setSigEdad(NULL);
                delete p;
            }else{
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    }else if(p->getEdad()>=30 && p->getEdad()<40){ //Borrado en Cabecera Edad
        if(cabeceraEdad[2] == p){
            cabeceraEdad[2] = p->getSigEdad();
            delete p;
        }else{
            aux1 = cabeceraEdad[2];
            aux2 = aux1->getSigEdad();

            while(aux2->getSigEdad() != NULL){
                if(aux2 == p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if(aux2->getSigEdad() == NULL){
                aux1->setSigEdad(NULL);
                delete p;
            }else{
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    }else if(p->getEdad()>=40 && p->getEdad()<50){ //Borrado en Cabecera Edad
        if(cabeceraEdad[3] == p){
            cabeceraEdad[3] = p->getSigEdad();
            delete p;
        }else{
            aux1 = cabeceraEdad[3];
            aux2 = aux1->getSigEdad();

            while(aux2->getSigEdad() != NULL){
                if(aux2 == p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if(aux2->getSigEdad() == NULL){
                aux1->setSigEdad(NULL);
                delete p;
            }else{
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    }else if(p->getEdad()>=50 && p->getEdad()<60){ //Borrado en Cabecera Edad
        if(cabeceraEdad[4] == p){
            cabeceraEdad[4] = p->getSigEdad();
            delete p;
        }else{
            aux1 = cabeceraEdad[4];
            aux2 = aux1->getSigEdad();

            while(aux2->getSigEdad() != NULL){
                if(aux2 == p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if(aux2->getSigEdad() == NULL){
                aux1->setSigEdad(NULL);
                delete p;
            }else{
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    }else if(p->getEdad()>=60 && p->getEdad()<70){ //Borrado en Cabecera Edad
        if(cabeceraEdad[5] == p){
            cabeceraEdad[5] = p->getSigEdad();
            delete p;
        }else{
            aux1 = cabeceraEdad[5];
            aux2 = aux1->getSigEdad();

            while(aux2->getSigEdad() != NULL){
                if(aux2 == p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if(aux2->getSigEdad() == NULL){
                aux1->setSigEdad(NULL);
                delete p;
            }else{
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    }else if(p->getEdad()>=70 && p->getEdad()<80){ //Borrado en Cabecera Edad
        if(cabeceraEdad[6] == p){
            cabeceraEdad[6] = p->getSigEdad();
            delete p;
        }else{
            aux1 = cabeceraEdad[6];
            aux2 = aux1->getSigEdad();

            while(aux2->getSigEdad() != NULL){
                if(aux2 == p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if(aux2->getSigEdad() == NULL){
                aux1->setSigEdad(NULL);
                delete p;
            }else{
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    }else{ //Borrado en Cabecera Edad
        if(cabeceraEdad[7] == p){
            cabeceraEdad[7] = p->getSigEdad();
            delete p;
        }else{
            aux1 = cabeceraEdad[7];
            aux2 = aux1->getSigEdad();

            while(aux2->getSigEdad() != NULL){
                if(aux2 == p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if(aux2->getSigEdad() == NULL){
                aux1->setSigEdad(NULL);
                delete p;
            }else{
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    }
    if(p->getActivLab() == "ARTES"){ //Borrado en Cabecera ActLaboral
        if(cabeceraActividad[0] == p){
            cabeceraActividad[0] = p->getSigActivLab();
            delete p;
        }else{
            aux1 = cabeceraActividad[0];
            aux2 = aux1->getSigActivLab();

            while(aux2->getSigActivLab()!=NULL){
                if(aux2 = p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigActivLab();
                }
            }
            if(aux2->getSigActivLab() == NULL){
                aux1->setSigActivLab(NULL);
                delete p;
            }else{
                aux1->setSigActivLab(p->getSigActivLab());
                delete p;
            }
        }
    }else if(p->getActivLab() == "TECNICO"){ //Borrado en Cabecera ActLaboral
        if(cabeceraActividad[1] == p){
            cabeceraActividad[1] = p->getSigActivLab();
            delete p;
        }else{
            aux1 = cabeceraActividad[1];
            aux2 = aux1->getSigActivLab();

            while(aux2->getSigActivLab()!=NULL){
                if(aux2 = p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigActivLab();
                }
            }
            if(aux2->getSigActivLab() == NULL){
                aux1->setSigActivLab(NULL);
                delete p;
            }else{
                aux1->setSigActivLab(p->getSigActivLab());
                delete p;
            }
        }
    }else if(p->getActivLab() == "INGENIERO"){ //Borrado en Cabecera ActLaboral
        if(cabeceraActividad[2] == p){
            cabeceraActividad[2] = p->getSigActivLab();
            delete p;
        }else{
            aux1 = cabeceraActividad[2];
            aux2 = aux1->getSigActivLab();

            while(aux2->getSigActivLab()!=NULL){
                if(aux2 = p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigActivLab();
                }
            }
            if(aux2->getSigActivLab() == NULL){
                aux1->setSigActivLab(NULL);
                delete p;
            }else{
                aux1->setSigActivLab(p->getSigActivLab());
                delete p;
            }
        }
    }else if(p->getActivLab() == "SOCIALES"){ //Borrado en Cabecera ActLaboral
        if(cabeceraActividad[3] == p){
            cabeceraActividad[3] = p->getSigActivLab();
            delete p;
        }else{
            aux1 = cabeceraActividad[3];
            aux2 = aux1->getSigActivLab();

            while(aux2->getSigActivLab()!=NULL){
                if(aux2 = p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigActivLab();
                }
            }
            if(aux2->getSigActivLab() == NULL){
                aux1->setSigActivLab(NULL);
                delete p;
            }else{
                aux1->setSigActivLab(p->getSigActivLab());
                delete p;
            }
        }
    }else if(p->getActivLab() == "FILOSOFIA"){ //Borrado en Cabecera ActLaboral
        if(cabeceraActividad[4] == p){
            cabeceraActividad[4] = p->getSigActivLab();
            delete p;
        }else{
            aux1 = cabeceraActividad[4];
            aux2 = aux1->getSigActivLab();

            while(aux2->getSigActivLab()!=NULL){
                if(aux2 = p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigActivLab();
                }
            }
            if(aux2->getSigActivLab() == NULL){
                aux1->setSigActivLab(NULL);
                delete p;
            }else{
                aux1->setSigActivLab(p->getSigActivLab());
                delete p;
            }
        }
    }
    for(int i = 0; i<cabeceraPais.lista_size(); i++){  //Borrado en Cabecera Pais
        Persona *aux1;
        Persona *aux2;
        nodoP *aux;
        nodoP nodoAUx = cabeceraPais.obtenerDato(i);
        aux = &nodoAUx;
        if(aux->clave == p->getPaisNac()){
            aux->persona = p->getSigPaisNac();
            cabeceraPais.modificar(*aux, i);
            delete p;
        }else{
            aux1 = aux->persona;
            aux2 = aux1->getSigPaisNac();

            while(aux2->getSigPaisNac() == NULL){
                if(aux2 == p){
                    break;
                }else{
                    aux1 = aux2;
                    aux2 = aux2->getSigPaisNac();
                }
            }
            if(aux2->getSigPaisNac() == NULL){
                aux1->setSigPaisNac(NULL);
                delete p;
            }else{
                aux1->setSigPaisNac(p->getSigPaisNac());
                delete p;
            }
        }
    }
}

#endif PROYECTOCIENCIAS_CLASELISTAPERSONAS_H
