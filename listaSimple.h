//
// Created by oscar on 24/09/2021.
//

#ifndef PROYECTOCIENCIAS_LISTASIMPLE_H
#define PROYECTOCIENCIAS_LISTASIMPLE_H

#include<iostream>
using namespace std;

template<class T>
struct nodo{
    T info;
    nodo<T> *sig;
};

template<class T>
class Lista{
private:
    nodo<T> *cabeza;
    int size;

public:
    Lista(){
        cabeza = NULL;
        size = 0;
    }
    bool lista_vacia();
    int lista_size();
    T obtenerDato(int pos);
    bool eliminar(int pos);
    void insertar_final(T nuevaInfo);
    void insertar_inicio(T nuevaInfo);
    void insertar_pos(T nuevaInfo, int pos);
    bool modificar(T nuevaInfo, int pos);
};

template<class T>
bool Lista<T>::lista_vacia(){
    bool respuesta;
    if(this->size == 0){
        respuesta = true;
    }
    else{
        respuesta = false;
    }
    return respuesta;
}

template<class T>
int Lista<T>::lista_size(){
    return size;
}


template<class T>
void Lista<T>::insertar_inicio(T nuevaInfo){
    nodo<T> *nuevo = new nodo<T>;
    nuevo->info = nuevaInfo;
    nuevo->sig = cabeza;
    cabeza = nuevo;
    size++;
}

template<class T>
void Lista<T>::insertar_final(T nuevaInfo){
    if(!lista_vacia()){
        nodo<T> *nuevo = new nodo<T>;
        nodo<T> *Aux = cabeza;
        while( Aux->sig != NULL){
            Aux = Aux->sig;
        }
        nuevo->info = nuevaInfo;
        nuevo->sig = NULL;
        Aux->sig = nuevo;
        size++;
    }
    else{
        insertar_inicio(nuevaInfo);
    }
}

template<class T>
void Lista<T>::insertar_pos(T nuevaInfo, int pos){

    if(!lista_vacia() && pos !=0){
        if(pos > size - 1){
            insertar_final(nuevaInfo);
        }
        else{
            int posicionActual = 0;
            nodo<T> *nuevo = new nodo<T>;
            nuevo->info = nuevaInfo;
            nodo<T> *Aux = cabeza;
            nodo<T> *AuxPlus = Aux->sig;

            while(posicionActual != pos-1){
                Aux = Aux->sig;
                AuxPlus = AuxPlus->sig;
                posicionActual++;
            }
            Aux->sig = nuevo;
            nuevo->sig = AuxPlus;
            size++;
        }
    }
    else{
        insertar_inicio(nuevaInfo);
    }
}

template<class T>
T Lista<T>::obtenerDato(int pos){
    if(!lista_vacia()){
        T dato;
        int posicionActual = 0;
        nodo<T> *nodoDato = cabeza;
        if(pos < size && pos>= 0){
            while(posicionActual != pos){
                nodoDato = nodoDato->sig;
                posicionActual++;
            }
            dato = nodoDato->info;

        }
        else{
            dato = obtenerDato(size-1);
        }
        return dato;
    }
    else{

    }
}

template<class T>
bool Lista<T>::eliminar(int pos){
    bool respuesta;
    if(!lista_vacia()){
        if(pos == 0){
            cabeza = cabeza->sig;
        }
        else if(pos >= size - 1){
            nodo<T> *Aux = cabeza;
            nodo<T> *AuxPlus = Aux->sig;
            if(AuxPlus != NULL){
                while( AuxPlus->sig != NULL){
                    Aux = Aux->sig;
                    AuxPlus = AuxPlus->sig;
                }
            }
            Aux->sig = NULL;
            delete AuxPlus;
        }
        else{
            int posicionActual = 0;
            nodo<T> *Aux = cabeza;
            nodo<T> *AuxUltraPlus = Aux->sig;

            while(posicionActual != pos-1){
                Aux = Aux->sig;
                posicionActual++;
            }
            posicionActual = 0;
            while(posicionActual != pos){
                AuxUltraPlus = AuxUltraPlus->sig;
                posicionActual++;
            }
            Aux->sig = AuxUltraPlus;
        }
        size--;
        respuesta = true;
    }
    else{
        respuesta = false;
    }
    return respuesta;
}

template<class T>
bool Lista<T>::modificar(T nuevaInfo, int pos){
    if(!lista_vacia()){
        int posicionActual = 0;
        nodo<T> *nodoDato = cabeza;
        if(pos < size && pos>= 0){
            while(posicionActual != pos){
                nodoDato = nodoDato->sig;
                posicionActual++;
            }
            nodoDato->info = nuevaInfo;

        }
        else{
            modificar(nuevaInfo ,size-1);
        }
        return true;
    }
    else{
        return false;
    }
}

#endif //PROYECTOCIENCIAS_LISTASIMPLE_H
