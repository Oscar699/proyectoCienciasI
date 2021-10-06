//
// Created by mile on 4/10/21.
//

#ifndef PROYECTOCIENCIAS_PILA_H
#define PROYECTOCIENCIAS_PILA_H

template<class T>
struct nodoPila{
    T dato;
    nodoPila<T> *sig;
};

template<class T>
class pila{nodoPila<T> *cab;
public:
    pila(){
        cab= new nodoPila<T>;
        cab->sig=NULL;}
    void Push(T dato);
    T Pop();
    bool PilaVacia();
    ~pila();
};

template<class T>
void pila<T>::Push(T dato){
    nodoPila<T> *t = new nodoPila<T>;
    t->dato=dato;
    t->sig=cab->sig;
    cab->sig= t;
}

template<class T>
T pila<T>::Pop(){
    T dato;
    nodoPila<T> *t= cab->sig;
    cab->sig= t->sig;
    dato=t->dato;
    delete t;
    return dato;
}

template<class T>
bool pila<T>::PilaVacia(){
    return cab->sig== NULL;
}

template<class T>
pila<T>::~pila(){
    nodoPila<T> *t=cab;
    while (t!=NULL){
        cab=t;
        t=t->sig;
        delete cab;
    }
}

#endif //PROYECTOCIENCIAS_PILA_H
