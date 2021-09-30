//
// Created by oscar on 28/09/2021.
//

#ifndef PROYECTOCIENCIAS_CLASESIMULACION_H
#define PROYECTOCIENCIAS_CLASESIMULACION_H

#include "clasePersona.h"
#include <ctime>

class Simulacion{
    fecha FechaActual;
public:
    const fecha &getFechaActual() const;

    void calcularFechaActual();
    bool compararFechas(fecha, fecha);
    fecha agregarTiempoFecha(fecha, int);

};

void Simulacion::calcularFechaActual(){
    time_t tiempo = time(NULL);
    struct tm *tlocal = localtime(&tiempo);
    FechaActual.dia = tlocal->tm_mday;
    FechaActual.mes = tlocal->tm_mon + 1;
    FechaActual.anio = tlocal->tm_year + 1900;
}

bool Simulacion::compararFechas(fecha fechaAfiliado1, fecha fechaAfiliado2) {

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

const fecha &Simulacion::getFechaActual() const {
    return FechaActual;
}

fecha Simulacion::agregarTiempoFecha(fecha fechaCambiar, int numDias) {
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

#endif //PROYECTOCIENCIAS_CLASESIMULACION_H
