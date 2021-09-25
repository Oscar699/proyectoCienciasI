//
// Created by oscar on 24/09/2021.
//

#ifndef PROYECTOCIENCIAS_CLASEPERSONA_H
#define PROYECTOCIENCIAS_CLASEPERSONA_H

#include <string>
using namespace std;

struct fecha{
    int dia;
    int mes;
    int anio;
};

class Persona{
    string nombre;
    string apellido;
    string tipoId
    string numId;
    char sexo;
    string telCelular;
    string telFijo;
    string email;
    fecha fechaNac;
    int edad;
    string ciudadNac;
    string paisNac;
    string ciudadRes;
    string direc;
    string barrio;
    string activLab;
    string nombreEps;

    Persona *sigSexo;
    Persona *sigEdad;
    Persona *sigPaisNac;
    Persona *sigCiudadRes;
    Persona *sigActivLab;
    Persona *sigEps;

    public:
        Persona();
        ~Persona();
        void calcEdad(int, int, int);
        void setFechaNac(int, int, int);


};

int Persona::calcEdad(int diaActual, int mesAtual, int anioActual) {
    int month[] = { 31, 28, 31, 30, 31, 30, 31,
                    31, 30, 31, 30, 31 };

    if (this->fechaNac.dia > diaActual) {
        diaActual = diaActual + month[this->fechaNac.mes - 1];
        mesAtual = mesAtual - 1;
    }

    if (this->fechaNac.mes > mesAtual) {
        anioActual = anioActual - 1;
        mesAtual = mesAtual + 12;
    }

    this->edad = anioActual - this->fechaNac.anio;
}

void Persona::setFechaNac(int diaNac, int mesNac, int anioNac) {
    this->fechaNac.dia = diaNac;
    this->fechaNac.mes = mesNac;
    this->fechaNac.anio = anioNac;
}

#endif //PROYECTOCIENCIAS_CLASEPERSONA_H
