//
// Created by mile on 24/09/21.
//
#include "claseIPS.h"
#include "clasePersona.h"
#include <string>
#include "arbolRN.h"
#include <cstdlib>
using namespace std;

#ifndef PROYECTOCIENCIAS_EPS_H
#define PROYECTOCIENCIAS_EPS_H

struct nodoIps{
    IPS ips;
    string claveAfiliado;
    int sigCiudad;
};

struct nodoVacEps{
    int indexLab;
    int numVacunas;
};

struct nodoCiudad{
    string nombreCiudad;
    int clave;
    string claveAfiliado;
    int posIPS;
};

struct registroAfiliado{
    Persona *persona;
    int  claveCiu;
    fecha fechaDosis;
    int posLab;
    IPS *ips;
    string estado;
    string sigCiudad;
    string sigIPS;
    string sigDosis;
    string sigLab;
};

class claseEPS{
    string nombre;
    int numAfiliados;
    nodoIps cabeceraIPS[20];
    nodoCiudad cabeceraCiudad[20];
    nodoVacEps listaVacunas[6];
    int poscabIPS;
    int poscabCiudad;
    ArbolRN<registroAfiliado> arbolAfiliados;
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
    //~claseEPS();
    void agregarIPS(IPS ips, string ciudad);
    void eliminarIPS();
    void agregarCiudad(int clave, string ciudad);
    void eliminarCiudad();
    void agregarRegistro(Persona p, int clave_ciu , IPS ips, fecha fechaActual);

    fecha generarFechaAleatoria(fecha, fecha);
    fecha agregarTiempoFecha(fecha);
    bool compararFechas(fecha, fecha);

};

fecha claseEPS::generarFechaAleatoria(fecha rangoInferior, fecha rangoSuperior) {   //Genera aleatoriamente una fecha de vacunacion
    fecha resultado;
    srand(time(NULL));

    int month[] = { 31, 28, 31, 30, 31, 30, 31,
                    31, 30, 31, 30, 31};

    resultado.mes = abs(rangoSuperior.mes - rangoInferior.mes);
    if(resultado.mes != 0){
        resultado.mes = rand() % resultado.mes + 1;
        resultado.mes = resultado.mes + rangoInferior.mes;
    }else{
        resultado.mes = rangoSuperior.mes;
    }

    resultado.dia = abs(rangoSuperior.dia - rangoInferior.dia);
    if(resultado.dia != 0){
        resultado.dia = rand() % resultado.dia + 1;
        resultado.dia = (resultado.dia + rangoInferior.dia) % month[resultado.mes - 1];
        if(resultado.dia == 0) resultado.dia + 1;
    }else{
        resultado.dia = rangoSuperior.dia;
    }

    if(resultado.dia > month[resultado.mes - 1]){
        resultado.dia = resultado.dia % month[resultado.mes - 1];
        resultado.mes++;
    }
    resultado.anio = abs(rangoSuperior.anio - rangoInferior.anio);
    if(resultado.anio != 0){
        resultado.anio = rand() % resultado.anio + rangoSuperior.anio;
    }else{
        resultado.anio = rangoSuperior.anio;
    }

    if(resultado.mes > 12){
        resultado.mes = 1;
        resultado.anio++;
    }

    cout<<resultado.dia<<'/'<<resultado.mes<<'/'<<resultado.anio<<endl;
}

bool claseEPS::compararFechas(fecha fechaAfiliado1, fecha fechaAfiliado2) {

    if(fechaAfiliado1.anio > fechaAfiliado2.anio){ // 11/11/2021 - 10/12/2021
        return false;
    }else{
        if(fechaAfiliado1.mes > fechaAfiliado2.mes){
            return false;
        }else{
            if(fechaAfiliado1.dia > fechaAfiliado2.dia){
                return false;
            }
        }
    }

    return true;
}

void  claseEPS::agregarRegistro(Persona p, int clave_ciu , IPS ips, fecha fechaUltimoVacunado)  {
    registroAfiliado *registroAux,*registro = new registroAfiliado;
    registro->persona = &p;
    registro->ips = &ips;
    registro->claveCiu = clave_ciu;
    registro->estado = "SA";
    registro->sigCiudad= "";
    registro->sigDosis = "";
    registro->sigIPS = "";
    registro->sigLab = "";
    registro->posLab = -1;
    registro->fechaDosis = generarFechaAleatoria(fechaUltimoVacunado, agregarTiempoFecha(fechaUltimoVacunado));
    arbolAfiliados.insertarNodo(p.getNumId(),*registro);

    nodoIps* nodoAux;
    nodoCiudad* nodoCiudadAux;
    for(int i=0; i<poscabIPS; i++){
        nodoAux = &cabeceraIPS[i];
        if(nodoAux->ips.getNombre() == ips.getNombre()){
            break;
        }
    }

    if(nodoAux->claveAfiliado == ""){
        nodoAux->claveAfiliado = p.getNumId();
    }else{
        registroAux = arbolAfiliados.obtenerInfo(nodoAux->claveAfiliado);
        while(registroAux->sigIPS != ""){
            registroAux = arbolAfiliados.obtenerInfo(registroAux->sigIPS);
        }
        registroAux->sigIPS = p.getNumId();
    }

    for(int i=0; i<poscabCiudad; i++){
        nodoCiudadAux = &cabeceraCiudad[i];
        if(nodoCiudadAux->clave == clave_ciu){
            break;
        }
    }

    if(nodoCiudadAux->claveAfiliado == ""){
        nodoCiudadAux->claveAfiliado = p.getNumId();
    }else{
        registroAux = arbolAfiliados.obtenerInfo(nodoCiudadAux->claveAfiliado);
        while(registroAux->sigCiudad != ""){
            registroAux = arbolAfiliados.obtenerInfo(registroAux->sigCiudad);
        }
        registroAux->sigCiudad = p.getNumId();
    }



}

fecha claseEPS::agregarTiempoFecha(fecha rangoMinimo) {
    fecha rangoMaximo;
    rangoMaximo.dia = rangoMinimo.dia;
    rangoMaximo.mes = rangoMinimo.mes + 1;
    rangoMaximo.anio = rangoMinimo.anio;
    if(rangoMaximo.mes > 12){
        rangoMaximo.mes = 1;
        rangoMaximo.anio++;
    }
    return rangoMaximo;
}

void claseEPS::agregarIPS(IPS ips, string ciudad){
    nodoCiudad *aux;
    for (int i = 0; i < poscabCiudad; ++i) {
        aux = &cabeceraCiudad[i];
        if (aux->nombreCiudad == ciudad){
            if(aux->posIPS == -1){
                aux->posIPS = poscabIPS;
            }
            nodoIps *nodoAux = &cabeceraIPS[aux->posIPS];
            nodoIps *nuevo = new nodoIps();
            nuevo->ips = ips;
            nuevo->claveAfiliado = "";
            nuevo->sigCiudad = -1;
            cabeceraIPS[poscabIPS] = *nuevo;
            if(poscabIPS > 0){
                while (nodoAux->sigCiudad != -1){
                    nodoAux = &cabeceraIPS[nodoAux->sigCiudad];
                }
                nodoAux->sigCiudad = poscabIPS;
            }
        }
    }

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
    nuevo->nombreCiudad = "";
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

#endif //PROYECTOCIENCIAS_EPS_H
