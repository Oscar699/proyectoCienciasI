//
// Created by oscar on 24/09/2021.
//

#ifndef PROYECTOCIENCIAS_CLASEPERSONA_H
#define PROYECTOCIENCIAS_CLASEPERSONA_H

#include <string>
using namespace std;

//Estructura para definir atributo fecha
struct fecha{
    int dia;
    int mes;
    int anio;
};

class Persona{
    // Atributos
    string nombre;
    string apellido;
    string tipoId;
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
public:

    //Setters


    void calcEdad(fecha);
    void setFechaNac(int, int, int);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getApellido() const;

    void setApellido(const string &apellido);

    const string &getTipoId() const;

    void setTipoId(const string &tipoId);

    const string &getNumId() const;

    void setNumId(const string &numId);

    char getSexo() const;

    void setSexo(char sexo);

    const string &getTelCelular() const;

    void setTelCelular(const string &telCelular);

    const string &getTelFijo() const;

    void setTelFijo(const string &telFijo);

    const string &getEmail() const;

    void setEmail(const string &email);

    const fecha &getFechaNac() const;

    void setFechaNac1(const fecha &fechaNac);

    int getEdad() const;

    void setEdad(int edad);

    const string &getCiudadNac() const;

    void setCiudadNac(const string &ciudadNac);

    const string &getPaisNac() const;

    void setPaisNac(const string &paisNac);

    const string &getCiudadRes() const;

    void setCiudadRes(const string &ciudadRes);

    const string &getDirec() const;

    void setDirec(const string &direc);

    const string &getBarrio() const;

    void setBarrio(const string &barrio);

    const string &getActivLab() const;

    void setActivLab(const string &activLab);

    const string &getNombreEps() const;

    void setNombreEps(const string &nombreEps);

    Persona *getSigSexo() const;

    void setSigSexo(Persona *sigSexo);

    Persona *getSigEdad() const;

    void setSigEdad(Persona *sigEdad);

    Persona *getSigPaisNac() const;

    void setSigPaisNac(Persona *sigPaisNac);

    Persona *getSigCiudadRes() const;

    void setSigCiudadRes(Persona *sigCiudadRes);

    Persona *getSigActivLab() const;

    void setSigActivLab(Persona *sigActivLab);

    Persona *getSigEps() const;

    void setSigEps(Persona *sigEps);

private:
    //Apuntadores cabeceras
    Persona *sigSexo;
    Persona *sigEdad;
    Persona *sigPaisNac;
    Persona *sigCiudadRes;
    Persona *sigActivLab;
    Persona *sigEps;
};
//Método para hallar la edad de una persona
void Persona::calcEdad(fecha fechaActual) {
    //Se setean los meses del año
    int month[] = { 31, 28, 31, 30, 31, 30, 31,
                    31, 30, 31, 30, 31 };

    //Consigue los dias de nacido
    if (this->fechaNac.dia > fechaActual.dia) {
        fechaActual.dia += month[this->fechaNac.mes - 1];
        fechaActual.mes -= 1;
    }
    //Consigue los meses de nacido
    if (this->fechaNac.mes > fechaActual.mes) {
        fechaActual.anio -= 1;
        fechaActual.mes += 12;
    }


    //Consigue los años de nacido
    this->edad = fechaActual.anio - this->fechaNac.anio;
}

void Persona::setFechaNac(int diaNac, int mesNac, int anioNac) {
    this->fechaNac.dia = diaNac;
    this->fechaNac.mes = mesNac;
    this->fechaNac.anio = anioNac;
}
//Getters
const string &Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(const string &nombre) {
    Persona::nombre = nombre;
}

const string &Persona::getApellido() const {
    return apellido;
}

void Persona::setApellido(const string &apellido) {
    Persona::apellido = apellido;
}

const string &Persona::getTipoId() const {
    return tipoId;
}

void Persona::setTipoId(const string &tipoId) {
    Persona::tipoId = tipoId;
}

const string &Persona::getNumId() const {
    return numId;
}

void Persona::setNumId(const string &numId) {
    Persona::numId = numId;
}

char Persona::getSexo() const {
    return sexo;
}

void Persona::setSexo(char sexo) {
    Persona::sexo = sexo;
}

const string &Persona::getTelCelular() const {
    return telCelular;
}

void Persona::setTelCelular(const string &telCelular) {
    Persona::telCelular = telCelular;
}

const string &Persona::getTelFijo() const {
    return telFijo;
}

void Persona::setTelFijo(const string &telFijo) {
    Persona::telFijo = telFijo;
}

const string &Persona::getEmail() const {
    return email;
}

void Persona::setEmail(const string &email) {
    Persona::email = email;
}

const fecha &Persona::getFechaNac() const {
    return fechaNac;
}

void Persona::setFechaNac1(const fecha &fechaNac) {
    Persona::fechaNac = fechaNac;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setEdad(int edad) {
    Persona::edad = edad;
}

const string &Persona::getCiudadNac() const {
    return ciudadNac;
}

void Persona::setCiudadNac(const string &ciudadNac) {
    Persona::ciudadNac = ciudadNac;
}

const string &Persona::getPaisNac() const {
    return paisNac;
}

void Persona::setPaisNac(const string &paisNac) {
    Persona::paisNac = paisNac;
}

const string &Persona::getCiudadRes() const {
    return ciudadRes;
}

void Persona::setCiudadRes(const string &ciudadRes) {
    Persona::ciudadRes = ciudadRes;
}

const string &Persona::getDirec() const {
    return direc;
}

void Persona::setDirec(const string &direc) {
    Persona::direc = direc;
}

const string &Persona::getBarrio() const {
    return barrio;
}

void Persona::setBarrio(const string &barrio) {
    Persona::barrio = barrio;
}

const string &Persona::getActivLab() const {
    return activLab;
}

void Persona::setActivLab(const string &activLab) {
    Persona::activLab = activLab;
}

const string &Persona::getNombreEps() const {
    return nombreEps;
}

void Persona::setNombreEps(const string &nombreEps) {
    Persona::nombreEps = nombreEps;
}

Persona *Persona::getSigSexo() const {
    return sigSexo;
}

void Persona::setSigSexo(Persona *sigSexo) {
    Persona::sigSexo = sigSexo;
}

Persona *Persona::getSigEdad() const {
    return sigEdad;
}

void Persona::setSigEdad(Persona *sigEdad) {
    Persona::sigEdad = sigEdad;
}

Persona *Persona::getSigPaisNac() const {
    return sigPaisNac;
}

void Persona::setSigPaisNac(Persona *sigPaisNac) {
    Persona::sigPaisNac = sigPaisNac;
}

Persona *Persona::getSigCiudadRes() const {
    return sigCiudadRes;
}

void Persona::setSigCiudadRes(Persona *sigCiudadRes) {
    Persona::sigCiudadRes = sigCiudadRes;
}

Persona *Persona::getSigActivLab() const {
    return sigActivLab;
}

void Persona::setSigActivLab(Persona *sigActivLab) {
    Persona::sigActivLab = sigActivLab;
}

Persona *Persona::getSigEps() const {
    return sigEps;
}

void Persona::setSigEps(Persona *sigEps) {
    Persona::sigEps = sigEps;
}

#endif //PROYECTOCIENCIAS_CLASEPERSONA_H
