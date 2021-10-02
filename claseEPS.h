//
// Created by mile on 24/09/21.
//
#include "claseIPS.h"
#include "clasePersona.h"
#include "arbolRN.h"
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
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
    string claveAfiliado;
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
    nodoIps cabeceraIPS[20];
    nodoCiudad cabeceraCiudad[20];
    nodoVacEps listaVacunas[6];
    int poscabIPS;
    int poscabCiudad;
    int numAfiliados;
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
        poscabCiudad = 0;
        numAfiliados = 0;
        for (int i = 0; i < 6; i++){
            listaVacunas[i].indexLab = i;
            listaVacunas[i].numVacunas = 0;
            listaVacunas[i].claveAfiliado = "";
        }
    }
    //~claseEPS();
    void agregarIPS(IPS ips, string ciudad);
    void eliminarIPS();
    void agregarCiudad(int clave, string n);
    void eliminarCiudad();
    void agregarRegistro(Persona *p, int clave_ciu , IPS *ips, fecha fechaActual);
    void vacunar();
    void agregarCargamentoVacunas(int, int);
    void repartirVacunas();
    int calcularAfiliados();

    fecha generarFechaAleatoria(fecha, fecha);
    fecha agregarTiempoFecha(fecha, int);
    bool compararFechas(fecha, fecha);
    inline bool verificarFechasIguales(fecha fecha1, fecha fecha2){
        return (fecha1.dia == fecha2.dia && fecha1.mes == fecha2.mes && fecha1.anio == fecha2.anio);
    }
    void imprimirCabeceraIPS();
    void imprirCabeceraCiudad();

};

// metodo temporal para testear la cabecera IPS
void claseEPS::imprimirCabeceraIPS(){
    for(int i=0; i<poscabIPS; i++){
        nodoIps *aux = &cabeceraIPS[i];
        registroAfiliado *regAux = arbolAfiliados.obtenerInfo( aux->claveAfiliado);
        while(regAux != NULL){
            cout<<aux->ips.getNombre()<<setw(10)<<regAux->persona->getNombre()<<setw(10)<<regAux->persona->getNumId()
            <<setw(5)<<regAux->fechaDosis.dia<<"/"<<regAux->fechaDosis.mes<<"/"<<regAux->fechaDosis.anio<<endl;
            regAux = arbolAfiliados.obtenerInfo(regAux->sigIPS);
        }
    }
}

//Genera aleatoriamente una fecha de vacunacion teniendo en cuenta un rango inferior y un rango superior de fechas
fecha claseEPS::generarFechaAleatoria(fecha rangoInferior, fecha rangoSuperior) {
    fecha resultado;
    srand(time(NULL)+rand());
    int random, rangInfDias = 0, rangSupDias = 0, month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    rangInfDias += rangoInferior.dia;
    for(int i=0; i<rangoInferior.mes-1; i++){
        rangInfDias += month[i];
    }
    rangInfDias += rangoInferior.anio*365;

    rangSupDias += rangoSuperior.dia;
    for(int i=0; i<rangoSuperior.mes-1; i++){
        rangSupDias += month[i];
    }
    rangSupDias += rangoSuperior.anio*365;

    random = abs(rangSupDias - rangInfDias);

    random = rand() % random + 1;

    resultado = agregarTiempoFecha(rangoInferior, random);
    return resultado;
}

// Metodo que agrega x numero de dias dados a una fecha y dada
fecha claseEPS::agregarTiempoFecha(fecha fechaCambiar, int numDias) {
    int rangoDeManejo, month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while(true){
        if(fechaCambiar.mes > 12){
            fechaCambiar.mes = 1;
            fechaCambiar.anio++;
        }
        rangoDeManejo = month[fechaCambiar.mes - 1] - fechaCambiar.dia;
        if(numDias > rangoDeManejo){
            fechaCambiar.mes++;
            fechaCambiar.dia = 0;
            numDias-=rangoDeManejo;
        }else{
            fechaCambiar.dia += numDias;
            break;
        }
    }

    return fechaCambiar;
}

//Metodo que compara dos fechas, retornando true en caso de que lafechaAfiliado1 sea menor.
bool claseEPS::compararFechas(fecha fechaAfiliado1, fecha fechaAfiliado2) {
    if(fechaAfiliado1.anio > fechaAfiliado2.anio){
        return false;
    }else if(fechaAfiliado1.anio < fechaAfiliado2.anio){
        return true;
    }else{
        if(fechaAfiliado1.mes > fechaAfiliado2.mes){
            return false;
        }else if(fechaAfiliado1.mes < fechaAfiliado2.mes){
            return true;
        }else{
            if(fechaAfiliado1.dia > fechaAfiliado2.dia){
                return false;
            }
            return true;
        }
    }
}

void  claseEPS::agregarRegistro(Persona *p, int clave_ciu , IPS *ips, fecha fechaActual){
    if(arbolAfiliados.obtenerInfo(p->getNumId()) == NULL ){
        registroAfiliado *registroAux = new registroAfiliado, *registroAuxSig = new registroAfiliado, *registro = new registroAfiliado;
        registro->persona = p;
        registro->ips = ips;
        registro->claveCiu = clave_ciu;
        registro->estado = "SA";
        registro->sigCiudad= "";
        registro->sigDosis = "";
        registro->sigIPS = "";
        registro->sigLab = "";
        registro->posLab = -1;
        //registro->fechaDosis = fechaActual;
        registro->fechaDosis = generarFechaAleatoria(fechaActual, agregarTiempoFecha(fechaActual, 11));

        nodoIps* nodoAux;
        nodoCiudad* nodoCiudadAux;

        // Arregla cabecera por IPS
        for(int i=0; i<poscabIPS; i++){
            nodoAux = &cabeceraIPS[i];
            if(nodoAux->ips.getNombre() == ips->getNombre()){
                nodoAux->ips.setNumAfiliados(nodoAux->ips.getNumAfiliados() + 1);
                break;
            }
        }

        if(nodoAux->claveAfiliado == ""){
            nodoAux->claveAfiliado = p->getNumId();
        }else{
            // Agrega el registro a la cabecera por IPS y la ordena de menor a mayor por la fecha
            registroAux = arbolAfiliados.obtenerInfo(nodoAux->claveAfiliado);
            if(!compararFechas(registroAux->fechaDosis, registro->fechaDosis)){
                registro->sigIPS = registroAux->persona->getNumId();
                nodoAux->claveAfiliado = p->getNumId();
            }else{
                if(numAfiliados > 1){
                    registroAuxSig = arbolAfiliados.obtenerInfo(registroAux->sigIPS);
                    while (registroAuxSig->sigIPS != "") {
                        if (!compararFechas(registroAuxSig->fechaDosis, registro->fechaDosis)) {
                            registro->sigIPS = registroAuxSig->sigIPS;
                            registroAux->sigIPS = registro->persona->getNumId();
                        }else if(verificarFechasIguales(registroAuxSig->fechaDosis, registro->fechaDosis)){
                            int cont = 0;
                            while(cont < 20 && verificarFechasIguales(registro->fechaDosis, registroAuxSig->fechaDosis)){
                                if(registroAuxSig->sigIPS == "") break;
                                registroAux = registroAuxSig;
                                registroAuxSig = arbolAfiliados.obtenerInfo(registroAuxSig->sigIPS);
                                cont++;
                            }
                            if(cont == 20){
                                registro->fechaDosis = registroAuxSig->fechaDosis;
                            }
                        }else{
                            registroAux = registroAuxSig;
                            registroAuxSig = arbolAfiliados.obtenerInfo(registroAuxSig->sigIPS);
                        }
                    }
                    registroAuxSig->sigIPS = p->getNumId();
                }else{
                    registroAux->sigIPS = p->getNumId();
                }
            }
        }

        // Arregla cabecera por ciudad
        for(int i=0; i<poscabCiudad; i++){
            nodoCiudadAux = &cabeceraCiudad[i];
            if(nodoCiudadAux->clave == clave_ciu){
                break;
            }
        }

        // Agrega el registro a la cabecera por ciudad
        if(nodoCiudadAux->claveAfiliado == ""){
            nodoCiudadAux->claveAfiliado = p->getNumId();
        }else{
            registroAux = arbolAfiliados.obtenerInfo(nodoCiudadAux->claveAfiliado);
            while(registroAux->sigCiudad != ""){
                registroAux = arbolAfiliados.obtenerInfo(registroAux->sigCiudad);
            }
            registroAux->sigCiudad = p->getNumId();
        }
        arbolAfiliados.insertarNodo(p->getNumId(),*registro);
        numAfiliados++;
    }else{
        cout<<"La cedula ingresada ya ha sido registrada con anterioridad, por favor ingrese otra"<<endl;
    }
}

void claseEPS::agregarCargamentoVacunas(int indexLab, int numVacunas){
    listaVacunas[indexLab].numVacunas = numVacunas;
}

void claseEPS::repartirVacunas(){
    for(int i=0; i<6; i++){
        for(int j=0; j<poscabIPS; j++){
            listaVacunas[i].numVacunas = cabeceraIPS[j].ips.distribuirVacunas(i, listaVacunas[i].numVacunas);
        }
    }
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
            break;
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
