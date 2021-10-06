//
// Created by mile on 24/09/21.
//Rama Milena
//
#include "claseIPS.h"
#include "clasePersona.h"
#include "arbolRN.h"
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "claseLaboratorios.h"

using namespace std;

#ifndef PROYECTOCIENCIAS_EPS_H
#define PROYECTOCIENCIAS_EPS_H

struct nodoIps {
    IPS *ips;
    string claveAfiliado;
    int sigCiudad;
};

struct nodoVacEps {
    int indexLab;
    int numVacunas;
    string claveAfiliado;
};

struct nodoCiudad {
    string nombreCiudad;
    int clave;
    string claveAfiliado;
    int posIPS;
};

struct registroAfiliado {
    Persona *persona;
    string clave;
    int claveCiu;
    fecha fechaDosis;
    int posLab;
    IPS *ips;
    string estado;
    string sigCiudad;
    string sigIPS;
    string sigLab;
};

class claseEPS {
private:
    string nombre;
    nodoIps cabeceraIPS[20];
    nodoCiudad cabeceraCiudad[20];
    nodoVacEps listaVacunas[6];
    int poscabIPS;
    int poscabCiudad;
    int numAfiliados;
    ArbolRN<registroAfiliado> arbolAfiliados;
    claseLaboratorios labs;
public:
    ArbolRN<registroAfiliado> *getArbolAfiliados();

    const string &getNombre() const;

    void setNombre(const string nombre);

    int getNumAfiliados() const;

    void setNumAfiliados(int numAfiliados);

    const nodoIps *getCabeceraIps() const;

    const nodoCiudad *getCabeceraCiudad() const;

    const nodoVacEps *getListaVacunas() const;

    claseEPS() {
        //arbolAfiliados = new ArbolRN<registroAfiliado>;
        poscabIPS = 0;
        poscabCiudad = 0;
        numAfiliados = 0;
        for (int i = 0; i < 6; i++) {
            listaVacunas[i].indexLab = i;
            listaVacunas[i].numVacunas = 0;
            listaVacunas[i].claveAfiliado = "";
        }
        for (int i = 0; i < 20; ++i) {
            cabeceraIPS[i].sigCiudad = -1;
            cabeceraIPS[i].claveAfiliado = "";
            cabeceraIPS[i].ips = NULL;
            cabeceraCiudad[i].posIPS = -1;
            cabeceraCiudad[i].claveAfiliado = "";
        }
    }

    //~claseEPS();
    void agregarIPS(IPS ips, string ciudad);

    void eliminarIPS();

    void agregarCiudad(int clave, string n);

    void eliminarCiudad();

    void agregarRegistro(Persona *p, int clave_ciu, IPS *ips, fecha fechaActual, string estado, bool tipo_insercion);

    void vacunar(fecha);

    void agregarCargamentoVacunas(int, int);

    void repartirVacunas();

    int calcularAfiliados();

    bool existenciaVacunas();

    fecha generarFechaAleatoria(fecha, fecha);

    fecha agregarTiempoFecha(fecha, int);

    bool compararFechas(fecha, fecha);

    inline bool verificarFechasIguales(fecha fecha1, fecha fecha2) {
        return (fecha1.dia == fecha2.dia && fecha1.mes == fecha2.mes && fecha1.anio == fecha2.anio);
    }

    void imprimirCabeceraIPS();

    void imprirCabeceraCiudad();

    int getPoscabIps() const;

    void setPoscabIps(int poscabIps);

    int getPoscabCiudad() const;

    void setPoscabCiudad(int poscabCiudad);

};

//este metodo verifica si a la ips todavia le quedan vacunas
bool claseEPS::existenciaVacunas() {
    int contador = 0;
    nodoVacEps *vac_aux;
    for (int i = 0; i < 6; ++i) {
        vac_aux = &listaVacunas[i];
        contador = contador + vac_aux->numVacunas;
    }
    return (contador > 0);
}

//metodo vacunar
void claseEPS::vacunar(fecha f) {
    // Iteraa sobre la cabecera de ciudades
    for (int i = 0; i < poscabCiudad; ++i) {
        nodoCiudad *ciudad_aux = &cabeceraCiudad[i];
        nodoIps *ips_aux = &cabeceraIPS[ciudad_aux->posIPS];
        //Itera sobre las IPS de la ciudad correspondiente a la iteracion
        do {
            nodoVacEps *vac_aux;
            int pos;
            if (ips_aux->claveAfiliado != "") {
                registroAfiliado *registro = arbolAfiliados.obtenerInfo(ips_aux->claveAfiliado);
                registroAfiliado *registro_aux;
                while (registro != NULL){ // Mientras la IPS tenga mas afiliados
                    if (verificarFechasIguales(f, registro->fechaDosis)){
                        if (registro->estado == "CP") {
                            do {
                                srand(time(NULL) + rand());
                                pos = rand() % 5;
                                vac_aux = &listaVacunas[pos];
                            } while (vac_aux->numVacunas == 0 && existenciaVacunas());
                            if(!existenciaVacunas()) break;
                            if (pos == 2) {
                                vac_aux->numVacunas = vac_aux->numVacunas-1;
                                registro->estado = "V";
                                registro->posLab = vac_aux->indexLab;

                                if (vac_aux->claveAfiliado == "") {
                                    vac_aux->claveAfiliado = registro->clave;
                                } else {
                                    registro_aux = arbolAfiliados.obtenerInfo(vac_aux->claveAfiliado);
                                    while (registro_aux->sigLab != "") {
                                        registro_aux = arbolAfiliados.obtenerInfo(registro_aux->sigLab);
                                    }
                                    registro_aux->sigLab = registro->clave;
                                }
                            } else {
                                vac_aux->numVacunas = vac_aux->numVacunas-1;
                                registro->estado = "PD";
                                registro->posLab = vac_aux->indexLab;

                                if (vac_aux->claveAfiliado == "") {
                                    vac_aux->claveAfiliado = registro->clave;
                                } else {
                                    registro_aux = arbolAfiliados.obtenerInfo(vac_aux->claveAfiliado);
                                    while (registro_aux->sigLab != "") {
                                        registro_aux = arbolAfiliados.obtenerInfo(registro_aux->sigLab);
                                    }
                                    registro_aux->sigLab = registro->clave;
                                }
                                agregarRegistro(registro->persona, registro->claveCiu, registro->ips,
                                                agregarTiempoFecha(f, 28), "CS", false);
                            }
                        } else if (registro->estado == "CS") {
                            vac_aux = &listaVacunas[registro->posLab];
                            if (vac_aux->numVacunas > 0) {
                                vac_aux->numVacunas = vac_aux->numVacunas-1;
                                registro->estado = "V";
                                registro->posLab = vac_aux->indexLab;

                                registro_aux = arbolAfiliados.obtenerInfo(vac_aux->claveAfiliado);
                                while (registro_aux->sigLab != "") {
                                    registro_aux = arbolAfiliados.obtenerInfo(registro_aux->sigLab);
                                }
                                registro_aux->sigLab = registro->clave;
                            } else {
                                registro->fechaDosis = agregarTiempoFecha(registro->fechaDosis, 14);
                            }
                        }
                        registro = arbolAfiliados.obtenerInfo(registro->sigIPS);
                    }else{
                        registro = arbolAfiliados.obtenerInfo(registro->sigIPS);
                    }
                }
            }
            if(ips_aux->sigCiudad != -1)
                ips_aux = &cabeceraIPS[ips_aux->sigCiudad];
        } while (ips_aux->sigCiudad != -1);
    }

}


// metodo temporal para testear la cabecera IPS
void claseEPS::imprimirCabeceraIPS() {
    for (int i = 0; i < poscabIPS; i++) {
        nodoIps *aux = &cabeceraIPS[i];
        registroAfiliado *regAux = arbolAfiliados.obtenerInfo(aux->claveAfiliado);
        while (regAux != NULL) {
            cout << aux->ips->getNombre() << setw(10) << regAux->persona->getNombre() << setw(10)
                 << regAux->persona->getNumId() <<setw(8)<< regAux->persona->getEdad()
                 << setw(5) << regAux->estado << setw(5)
                 << regAux->fechaDosis.dia << "/" << regAux->fechaDosis.mes << "/" << regAux->fechaDosis.anio
                 << endl;
            regAux = arbolAfiliados.obtenerInfo(regAux->sigIPS);
        }
    }
}

//Genera aleatoriamente una fecha de vacunacion teniendo en cuenta un rango inferior y un rango superior de fechas
fecha claseEPS::generarFechaAleatoria(fecha rangoInferior, fecha rangoSuperior) {
    fecha resultado;
    srand(time(NULL) + rand());
    int random, rangInfDias = 0, rangSupDias = 0, month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    rangInfDias += rangoInferior.dia;
    for (int i = 0; i < rangoInferior.mes - 1; i++) {
        rangInfDias += month[i];
    }
    rangInfDias += rangoInferior.anio * 365;

    rangSupDias += rangoSuperior.dia;
    for (int i = 0; i < rangoSuperior.mes - 1; i++) {
        rangSupDias += month[i];
    }
    rangSupDias += rangoSuperior.anio * 365;

    random = abs(rangSupDias - rangInfDias);

    random = rand() % random + 1;

    resultado = agregarTiempoFecha(rangoInferior, random);
    return resultado;
}

// Metodo que agrega x numero de dias dados a una fecha y dada
fecha claseEPS::agregarTiempoFecha(fecha fechaCambiar, int numDias) {
    int rangoDeManejo, month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (true) {
        if (fechaCambiar.mes > 12) {
            fechaCambiar.mes = 1;
            fechaCambiar.anio++;
        }
        rangoDeManejo = month[fechaCambiar.mes - 1] - fechaCambiar.dia;
        if (numDias > rangoDeManejo) {
            fechaCambiar.mes++;
            fechaCambiar.dia = 0;
            numDias -= rangoDeManejo;
        } else {
            fechaCambiar.dia += numDias;
            break;
        }
    }

    return fechaCambiar;
}

//Metodo que compara dos fechas, retornando true en caso de que lafechaAfiliado1 sea menor.
bool claseEPS::compararFechas(fecha fechaAfiliado1, fecha fechaAfiliado2) {
    if (fechaAfiliado1.anio > fechaAfiliado2.anio) {
        return false;
    } else if (fechaAfiliado1.anio < fechaAfiliado2.anio) {
        return true;
    } else {
        if (fechaAfiliado1.mes > fechaAfiliado2.mes) {
            return false;
        } else if (fechaAfiliado1.mes < fechaAfiliado2.mes) {
            return true;
        } else {
            if (fechaAfiliado1.dia > fechaAfiliado2.dia) {
                return false;
            }
            return true;
        }
    }
}

void claseEPS::agregarRegistro(Persona *p, int clave_ciu, IPS *ips, fecha fechaActual, string estado, bool tipo_insercion) {
    if (arbolAfiliados.obtenerInfo(p->getNumId()) == NULL || !tipo_insercion) {
        string clave;
        registroAfiliado *registroAux = new registroAfiliado, *registroAuxSig = new registroAfiliado, *registro = new registroAfiliado;
        if(tipo_insercion){
            clave = p->getNumId();
        }else{
            clave = p->getNumId() + "S";
        }
        registro->clave = clave;
        registro->persona = p;
        registro->ips = ips;
        registro->claveCiu = clave_ciu;
        registro->estado = estado;
        registro->sigCiudad = "";
        registro->sigIPS = "";
        registro->sigLab = "";
        if(tipo_insercion){
            registro->posLab = -1;
        }else{
            registro->posLab = arbolAfiliados.obtenerInfo(registro->persona->getNumId())->posLab;
        }

        //registro->fechaDosis = fechaActual;
        registro->fechaDosis = generarFechaAleatoria(fechaActual, agregarTiempoFecha(fechaActual, 6));

        nodoIps *nodoAux;
        nodoCiudad *nodoCiudadAux;

        // Arregla cabecera por IPS
        for (int i = 0; i < poscabIPS; i++) {
            nodoAux = &cabeceraIPS[i];
            if (nodoAux->ips->getNombre() == ips->getNombre()) {
                if(tipo_insercion){
                    nodoAux->ips->setNumAfiliados(nodoAux->ips->getNumAfiliados() + 1);
                }

                break;
            }
        }

        if (nodoAux->claveAfiliado == "") {
            nodoAux->claveAfiliado = clave;
        } else {
            // Agrega el registro a la cabecera por IPS y la ordena de menor a mayor por la fecha
            registroAux = arbolAfiliados.obtenerInfo(nodoAux->claveAfiliado);
            if (!compararFechas(registroAux->fechaDosis, registro->fechaDosis)) {
                registro->sigIPS = registroAux->clave;
                nodoAux->claveAfiliado = clave;
            } else {
                if (numAfiliados > 1) {
                    registroAuxSig = arbolAfiliados.obtenerInfo(registroAux->sigIPS);
                    int cont = 1;
                    while (registroAuxSig != NULL) {
                        if (!compararFechas(registroAuxSig->fechaDosis, registro->fechaDosis)) {
                            registro->sigIPS = registroAuxSig->clave;
                            break;
                        } else if (verificarFechasIguales(registroAuxSig->fechaDosis, registro->fechaDosis)) {
                            while (cont < 20 && verificarFechasIguales(registro->fechaDosis, registroAuxSig->fechaDosis) ) {
                                cont++;
                                registroAux = registroAuxSig;
                                registroAuxSig = arbolAfiliados.obtenerInfo(registroAuxSig->sigIPS);
                                if(registroAuxSig == NULL) break;
                            }
                            if (cont == 20) {
                                registro->fechaDosis = agregarTiempoFecha(registro->fechaDosis, 7);
                                cont = 0;
                            }
                        } else {
                            registroAux = registroAuxSig;
                            registroAuxSig = arbolAfiliados.obtenerInfo(registroAuxSig->sigIPS);
                        }
                    }
                    registroAux->sigIPS = registro->clave;
                } else {
                    registroAux->sigIPS = registro->clave;
                }
            }
        }

        // Arregla cabecera por ciudad
        for (int i = 0; i < poscabCiudad; i++) {
            nodoCiudadAux = &cabeceraCiudad[i];
            if (nodoCiudadAux->clave == clave_ciu) {
                break;
            }
        }

        // Agrega el registro a la cabecera por ciudad
        if (nodoCiudadAux->claveAfiliado == "") {
            nodoCiudadAux->claveAfiliado = clave;
        } else {
            registroAux = arbolAfiliados.obtenerInfo(nodoCiudadAux->claveAfiliado);
            while (registroAux->sigCiudad != "") {
                registroAux = arbolAfiliados.obtenerInfo(registroAux->sigCiudad);
            }
            registroAux->sigCiudad = clave;
        }

        arbolAfiliados.insertarNodo(clave, *registro);

        if(tipo_insercion){
            numAfiliados++;
        }
    } else {
        cout << "La cedula ingresada ya ha sido registrada con anterioridad, por favor ingrese otra" << endl;
    }
}

void claseEPS::agregarCargamentoVacunas(int indexLab, int numVacunas) {
    listaVacunas[indexLab].numVacunas = numVacunas;
}

void claseEPS::repartirVacunas() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < poscabIPS; j++) {
            listaVacunas[i].numVacunas = cabeceraIPS[j].ips->distribuirVacunas(i, listaVacunas[i].numVacunas);
        }
    }
}

void claseEPS::agregarIPS(IPS ips, string ciudad) {
    nodoCiudad *aux;
    for (int i = 0; i < poscabCiudad; ++i) {
        aux = &cabeceraCiudad[i];
        if (aux->nombreCiudad == ciudad) {
            if (aux->posIPS == -1) {
                aux->posIPS = poscabIPS;
            }
            nodoIps *nodoAux = &cabeceraIPS[aux->posIPS];
            nodoIps *nuevo = new nodoIps();
            nuevo->ips = &ips;
            nuevo->claveAfiliado = "";
            nuevo->sigCiudad = -1;
            cabeceraIPS[poscabIPS] = *nuevo;
            if (poscabIPS > 0 && nodoAux->sigCiudad != -1) {
                while (nodoAux->sigCiudad != -1) {
                    nodoAux = &cabeceraIPS[nodoAux->sigCiudad];
                }
                nodoAux->sigCiudad = poscabIPS;
            }
            break;
        }
    }

    if (poscabIPS < 20) {
        poscabIPS++;
    }
}

int claseEPS::getPoscabIps() const {
    return poscabIPS;
}

void claseEPS::setPoscabIps(int poscabIps) {
    poscabIPS = poscabIps;
}

int claseEPS::getPoscabCiudad() const {
    return poscabCiudad;
}

void claseEPS::setPoscabCiudad(int poscabCiudad) {
    claseEPS::poscabCiudad = poscabCiudad;
}

void claseEPS::eliminarIPS() {
    if (poscabIPS > 0)
        poscabIPS--;
}

void claseEPS::agregarCiudad(int clave, string n) {
    nodoCiudad *nuevo = new nodoCiudad();
    nuevo->nombreCiudad = n;
    nuevo->clave = clave;
    nuevo->posIPS = -1;
    cabeceraCiudad[poscabCiudad] = *nuevo;

    if (poscabCiudad < 20) {
        poscabCiudad++;
    }
}

void claseEPS::eliminarCiudad() {
    if (poscabCiudad > 0)
        poscabCiudad--;
}

const string &claseEPS::getNombre() const {
    return nombre;
}

void claseEPS::setNombre( const string nombre) {
    claseEPS::nombre = nombre;
}

int claseEPS::getNumAfiliados() const {
    return numAfiliados;
}

void claseEPS::setNumAfiliados(int numAfiliados) {
    numAfiliados = numAfiliados;
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

ArbolRN<struct registroAfiliado> * claseEPS::getArbolAfiliados() {
    return &arbolAfiliados;
}


#endif //PROYECTOCIENCIAS_EPS_H
