//
// Created by Familia Garay on 25/09/2021.
//

#ifndef PROYECTOCIENCIAS_ARBOLRN_H
#define PROYECTOCIENCIAS_ARBOLRN_H
#include <iostream>
#include <string>
#include "listaSimple.h"

using namespace std;

// ROJO=true;
// NEGRO=false;

template <class T>
struct Nodo {
    string clave;
    bool color;
    T info;
    bool nulo;
    Nodo<T> *hijoIzq, *hijoDer, *padre;
};

template <class T>
class ArbolRN{
    Nodo<T> *raiz;
    int numNodos;
public:
    ArbolRN(){
        numNodos = 0;
        raiz = new Nodo<T>;
        raiz->padre = raiz;
        raiz->nulo = true;
        raiz->color = false;
        raiz->clave = "-1";
        crearNulos(raiz);
    }
    inline bool arbolVacio();
    Nodo<T> *ins_arbol (string);
    Nodo<T> *buscar_nodo(string, Nodo<T> *, Nodo<T> *);
    Nodo<T> *buscar_arbol (string, Nodo<T> *, Nodo<T> *);
    void crearNulos(Nodo<T> *);
    void insertarNodo(string, T);
    void revisarCasoInsercion(Nodo<T> *);
    Nodo<T> *insertarCaso1(Nodo<T> *, Nodo<T> *);
    Nodo<T> *insertarCaso2(Nodo<T> *, Nodo<T> *, bool);
    Nodo<T> *insertarCaso3(Nodo<T> *, Nodo<T> *, bool);
    void rotDer(Nodo<T> *, Nodo<T> *);
    void rotIzq(Nodo<T> *, Nodo<T> *);
    void eliminarNodo(string);
    Nodo<T> *buscarRemplazo(Nodo<T> *);
    void ajustarSupresionRN(Nodo<T> *);
    Nodo<T> *raiz_arbol( ) {return raiz;}
    void inorden(Nodo<T> *);
    void destruir (Nodo<T> *p);
    T * obtenerInfo(string);
    void obtenerClavesArbol(Nodo<T> *p, string *arrClaves, int &pos);
    ~ArbolRN( );
};

template <class T>
inline bool ArbolRN<T>::arbolVacio(){
    return (raiz->padre == raiz);
}

template <class T>
Nodo<T> *ArbolRN<T>::buscar_arbol(string clave, Nodo<T> *p, Nodo<T> *q){
    if (p->nulo) return q;
    if (clave < p->clave){
        q=p;
        q=buscar_arbol(clave,p->hijoIzq,q);
        return q;}
    else{
        q=p;
        q=buscar_arbol(clave,p->hijoDer,q);
        return q;
    }
}

template <class T>
void ArbolRN<T>::crearNulos(Nodo<T> *n) {
    n->hijoIzq = new Nodo<T>;
    n->hijoDer = new Nodo<T>;
    n->hijoIzq->nulo = true;
    n->hijoIzq->color = false;
    n->hijoDer->nulo = true;
    n->hijoDer->color = false;
    n->hijoIzq->padre = n;
    n->hijoDer->padre = n;
    n->hijoIzq->hijoIzq = n->hijoIzq->hijoDer = NULL;
    n->hijoDer->hijoIzq = n->hijoDer->hijoDer = NULL;
}

template <class T>
Nodo<T> *ArbolRN<T>:: ins_arbol(string clave){
    Nodo<T> *q;
    if (arbolVacio()){
        raiz->clave = clave;
        raiz->color = false;
        raiz->padre = NULL;
        raiz->nulo = false;
        crearNulos(raiz);
        return raiz;
    }
    q = buscar_arbol(clave, raiz,NULL);
    Nodo<T> *nuevo;
    nuevo = new Nodo<T>;
    nuevo->clave= clave;
    nuevo->color = true;
    nuevo->padre = q;
    nuevo->nulo = false;
    crearNulos(nuevo);
    if (clave < q->clave){
        delete q->hijoIzq;
        q->hijoIzq = nuevo;
    }
    else{
        delete q->hijoDer;
        q->hijoDer = nuevo;
    }
    return nuevo;
}

template <class T>
void ArbolRN<T>::insertarNodo(string clave, T info){
    Nodo<T> *x;
    x = ins_arbol(clave);
    x->info = info;
    numNodos++;
    revisarCasoInsercion(x);
}

template <class T>
void ArbolRN<T>::revisarCasoInsercion(Nodo<T> * x) {
    Nodo<T> *p, *t;
    p = x->padre;
    while(x->color && p->color) {
        if (p == p->padre->hijoIzq) {
            t = p->padre->hijoDer;
            if(t->color){                               // Caso 1
                x = insertarCaso1(p, t);
            }
            else if (x == p->hijoDer) {                 //Caso 2
                p = insertarCaso2(x, p, true);
                x = insertarCaso3(p, p->padre, true);
            } else {                                    //Caso 3
                x = insertarCaso3(p, p->padre, true);
            }
        } else {
            t = p->padre->hijoIzq;
            if(t->color){                               // Caso 1
                x = insertarCaso1(p, t);
            }
            else if (x == p->hijoIzq) {                 //Caso 2
                p = insertarCaso2(x, p, false);
                x = insertarCaso3(p, p->padre, false);
            } else {                                    //Caso 3
                x = insertarCaso3(p, p->padre, false);
            }
        }
        if(x != raiz){
            p = x->padre;
        }
    }
}

template <class T>
Nodo<T> *ArbolRN<T>::insertarCaso1(Nodo<T> *p, Nodo<T> *t){     //Algoritmo para caso 1 de insercion
    p->color = false;
    t->color = false;
    if(p->padre != raiz){
        p->padre->color = true;
    }
    return p->padre;
}

template <class T>
Nodo<T> *ArbolRN<T>::insertarCaso2(Nodo<T> *x, Nodo<T> *p, bool lado) {     //Algoritmo para caso 2 de insercion
    if(lado){                       // El tio esta a la derecha del abuelo
        rotIzq(p, x);
    }else{                          // El tio esta a la izquierda del abuelo
        rotDer(p, x);
    }
    return x;
}

template <class T>
Nodo<T> *ArbolRN<T>::insertarCaso3(Nodo<T> *p, Nodo<T> *a, bool lado){
    p->color = false;
    a->color = true;
    if(lado){                       // El padre esta a la izquierda del abuelo
        rotDer(a, p);
    }else{                          // El padre esta a la derecha del abuelo
        rotIzq(a, p);
    }
    return p;
}

template <class T>
void ArbolRN<T>::rotIzq(Nodo<T> *p, Nodo<T> *x) {
    p->hijoDer = x->hijoIzq;
    x->hijoIzq->padre = p;
    x->hijoIzq = p;
    if(p != raiz){                  // Se modifica la conexion del ancestro del abuelo si no es la raiz
        if(p->padre->hijoDer == p){
            p->padre->hijoDer = x;
        }else{
            p->padre->hijoIzq = x;
        }
    }else{
        raiz = x;
    }
    x->padre = p->padre;
    p->padre = x;
}

template <class T>
void ArbolRN<T>::rotDer(Nodo<T> *p, Nodo<T> *x) {
    p->hijoIzq = x->hijoDer;
    x->hijoDer->padre = p;
    x->hijoDer = p;
    if(p != raiz){                  // Se modifica la conexion del ancestro del abuelo si no es la raiz
        if(p->padre->hijoDer == p){
            p->padre->hijoDer = x;
        }else{
            p->padre->hijoIzq = x;
        }
    }else{
        raiz = x;
    }
    x->padre = p->padre;
    p->padre = x;
}

template <class T>
void ArbolRN<T>::eliminarNodo(string clave) {
    Nodo<T> *x;
    x = buscar_nodo(clave, raiz, NULL);
    x = buscarRemplazo(x);
    ajustarSupresionRN(x);
}

template <class T>
Nodo<T> *ArbolRN<T>::buscar_nodo(string clave, Nodo<T> *p, Nodo<T> *q){
    if(p == NULL){
        return q;
    }else if(p->nulo){
        return NULL;
    }
    if(clave < p->clave){
        q=p;
        q=buscar_nodo(clave,p->hijoIzq,q);
        return q;}
    else if(clave > p->clave){
        q=p;
        q=buscar_nodo(clave,p->hijoDer,q);
        return q;
    }else{
        return q = buscar_nodo(clave, NULL, p);
    }
}

template <class T>
Nodo<T> *ArbolRN<T>::buscarRemplazo(Nodo<T> *r) {
    Nodo<T> *cambio = r;
    if(!r->hijoIzq->nulo && !r->hijoDer->nulo){
        r = r->hijoDer;
        while(!r->hijoIzq->nulo){
            r = r->hijoIzq;
        }
        cambio->clave = r->clave;
        cambio->info = r->info;
        cambio = r;
        if(!r->hijoDer->nulo){
            r = r->hijoDer;
            cambio->clave = r->clave;
            cambio->info = r->info;
        }
    }
    else if(!r->hijoIzq->nulo){
        r = r->hijoIzq;
        cambio->clave = r->clave;
        cambio->info = r->info;
    }
    else if(!r->hijoDer->nulo){
        r = r->hijoDer;
        cambio->clave = r->clave;
        cambio->info = r->info;
    }
    return r;
}

template <class T>
void ArbolRN<T>::ajustarSupresionRN(Nodo<T> *x) {
    Nodo<T> *w, *p, *eliminado = x;
    while (x != raiz  && x->color == 0){
        p = x->padre;
        if(x == p->hijoIzq){
            w = p->hijoDer;
            if(w->color){
                w->color = false;               // Caso 1
                p->color = true;
                rotIzq(p, w);
                w = p->hijoDer;
            }
            if(!w->hijoIzq->color && !w->hijoDer->color){
                w->color = true;                // Caos 2
                x = p;
            }else{
                if(!w->hijoDer->color){
                    w->hijoIzq->color = false;  // Caso 3
                    w->color = true;
                    rotDer(w, w->hijoIzq);
                    w = p->hijoDer;
                }
                w->color = p->color;            // Caso 4
                p->color = false;
                w->hijoDer->color = false;
                rotIzq(p, w);
                x = raiz;
            }
        }else{
            w = x->padre->hijoIzq;
            if(w->color){
                w->color = false;               // Caso 1
                p->color = true;
                rotDer(p, w);
                w = p->hijoIzq;
            }
            if(!w->hijoDer->color && !w->hijoIzq->color){
                w->color = true;                // Caos 2
                x = p;
            }else{
                if(!w->hijoIzq->color){
                    w->hijoDer->color = false;  // Caso 3
                    w->color = true;
                    rotIzq(w, w->hijoDer);
                    w = p->hijoIzq;
                }
                w->color = p->color;            // Caso 4
                p->color = false;
                w->hijoIzq->color = false;
                rotDer(p, w);
                x = raiz;
            }
        }
    }
    x->color = false;
    if(eliminado == eliminado->padre->hijoIzq){
        eliminado->padre->hijoIzq = eliminado->hijoIzq;
    } else{
        eliminado->padre->hijoDer = eliminado->hijoIzq;
    }
    delete eliminado->hijoDer;
    delete eliminado;
}

template <class T>
void ArbolRN<T>::inorden(Nodo<T> *p) {
    if (!p->nulo){
        inorden(p->hijoIzq);
        cout<<p->clave<<" "<<p->color<<endl;
        inorden(p->hijoDer);
    }
}

template<class T>
void ArbolRN<T>::obtenerClavesArbol(Nodo<T> *p, string *arrClaves, int &pos) {
    if(!p->nulo){
        obtenerClavesArbol(p->hijoIzq, arrClaves, ++pos);
        arrClaves[pos] = p->clave;
        obtenerClavesArbol(p->hijoDer, arrClaves, ++pos);
    }
}



template <class T>
T *ArbolRN<T>::obtenerInfo(string clave){
    Nodo<T> *aux = buscar_nodo(clave, raiz, NULL);
    if(aux!= NULL){
        return &(aux->info);
    }else{
        return NULL;
    }
}

template <class T>
void ArbolRN<T>::destruir(Nodo<T> *p){
    if (p!=NULL){
        destruir(p->hijoIzq);
        destruir(p->hijoDer);
        delete p;
        //cout<<"Nodo destruido..."<< endl;
    }
}

template <class T>
ArbolRN<T>::~ArbolRN( ) {destruir(raiz);}

#endif //PROYECTOCIENCIAS_ARBOLRN_H
