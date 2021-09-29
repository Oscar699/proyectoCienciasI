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
    void calcularFechaActual();
    const fecha &getFechaActual() const;
};

void Simulacion::calcularFechaActual(){
    time_t tiempo = time(NULL);
    struct tm *tlocal = localtime(&tiempo);
    FechaActual.dia = tlocal->tm_mday;
    FechaActual.mes = tlocal->tm_mon + 1;
    FechaActual.anio = tlocal->tm_year + 1900;
}

const fecha &Simulacion::getFechaActual() const {
    return FechaActual;
}

#endif //PROYECTOCIENCIAS_CLASESIMULACION_H
