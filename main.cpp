#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "claseEPS.h"
#include "claseLaboratorios.h"
#include "claseListaPersonas.h"
#include "clasePersona.h"
#include "claseSimulacion.h"

// Creando rama

using namespace std;

void cambiarCaracteristcia(Simulacion &); // La prueba de que deberia funcionar

void modificarInformacion(Simulacion &);
void ejecutarConsulta(Simulacion &);
void simularVacunacion(Simulacion &);
void generarEstadisticas(Simulacion &);

int main() {
    Simulacion testSimulacion;
    char opcionUsuario = 0;
    //Simula lo que antes estaba en el main
    testSimulacion.mainSimulado();
    while (opcionUsuario != '5'){
        cout<<"¿Que desea hacer?"<<endl;
        cout<<"1-> Realizar cambios en la iformacion."<<endl;
        cout<<"2-> Realizar una consulta."<<endl;
        cout<<"3-> Iniciar Simulacion de vacunación"<<endl; // Se debe preguntar cuantas vacunas agregara a una EPS
        cout<<"4-> Generar reporte de estadisticas"<<endl;
        cout<<"5-> Salir de la app"<<endl;

        cin>>opcionUsuario;

        switch (opcionUsuario) {
            case '1':
                modificarInformacion(testSimulacion);
                break;
            case '2':
                ejecutarConsulta(testSimulacion);
                break;
            case '3':
                simularVacunacion(testSimulacion);
                break;
            case '4':
                generarEstadisticas(testSimulacion);
                break;
            case '5':
                cout<<"Saliend de la app..."<<endl;
                testSimulacion.mainSimulado();
                testSimulacion.guardarArchivos();
                break;
            default:
                cout<<"La opcion ingresada es invalida por favor ingrese otra"<<endl;
        }
    }

    return 0;
}


void modificarInformacion(Simulacion &testSimulacion){
    char opcionUsuario = 0;
    while(opcionUsuario != '3'){
        cout<<"Elija la opcion corrrespondiente con la modificacion de informacion que quiere realizar:"<<endl;
        cout<<"1-> Añadir informacion personal"<<endl;
        cout<<"2-> Modificar informacion de afiliacion"<<endl;
        cout<<"3-> Volver"<<endl;
        cin>>opcionUsuario;
        switch (opcionUsuario) {
            case '1':
                while(opcionUsuario != '4'){ // Cambiar esto al menu general de esta parte
                    cout<<"Elija el tipo de modificacion que quiera realizar:"<<endl;
                    cout<<"1-> Añadir a una persona"<<endl;
                    cout<<"2-> Modificar a una persona"<<endl;
                    cout<<"3-> Eliminar a una persona"<<endl;
                    cout<<"4-> Volver"<<endl;
                    cin>>opcionUsuario;
                }
                break;
            case '2':
                while(opcionUsuario != '4'){
                    cout<<"Elija el tipo de modificacion que quiera realizar:"<<endl;
                    cout<<"1-> Añadir un registro"<<endl;
                    cout<<"2-> Modificar un registro"<<endl;
                    cout<<"3-> Eliminar un registro"<<endl;
                    cout<<"4-> Volver"<<endl;
                    cin>>opcionUsuario;
                }
                break;
            case '3':
                cout<<"Regresando al menu anterior..."<<endl;
                break;
            default:
                cout<<"La opcion ingresada es invalida por favor ingrese otra"<<endl;
        }
    }
}

void ejecutarConsulta(Simulacion &testSimulacion){
    char opcionUsuario = -1;
    while(opcionUsuario != '0'){
        cout<<"Ingrese el numero de la consulta que quiere realizar:"<<endl;
        cin>>opcionUsuario;
        switch (opcionUsuario) {
            case '1':{
                cout<<"Estas son las EPS: "<<endl;
                for (int i = 0; i < testSimulacion.getListaPersonas().getPoscabEps(); i++) {
                    cout<<i<<"."<<testSimulacion.getListaPersonas().getCabeceraEps()[i]->eps->getNombre()<<endl;
                }
                int pos;
                cout<<"Escoja la EPS por medio de su posición en lista: ";
                cin>>pos;
                claseEPS *epsSel= testSimulacion.getListaPersonas().getCabeceraEps()[pos]->eps;
                testSimulacion.getListaPersonas().calculoConsulta1(epsSel->getNombre());
                break;
            }

            case '2':{
                cout<<"Estos son los paises de nacimiento: "<<endl;
                for (int i = 0; i < testSimulacion.getListaPersonas().getCabeceraPais().lista_size(); i++) {
                    cout<<i<<"."<<testSimulacion.getListaPersonas().getCabeceraPais().obtenerDato(i)<<endl;
                }
                int pos;
                cout<<"Escoja el pais por medio de su posición en lista: ";
                cin>>pos;
                nodoP *paisSel = testSimulacion.getListaPersonas().getCabeceraPais().obtenerDato(pos);
                testSimulacion.getListaPersonas().calculoConsulta2(paisSel->clave);
                break;
            }

            case '3':{
                cout<<"Estas son las ciudades: "<<endl;
                for (int i = 0; i < testSimulacion.getListaPersonas().getCabeceraCiudadRes().lista_size(); i++) {
                    cout<<i<<"."<<testSimulacion.getListaPersonas().getCabeceraCiudadRes().obtenerDato(i)<<endl;
                }
                int pos;
                cout<<"Escoja la ciudad por medio de su posición en lista: ";
                cin>>pos;
                nodoCiudadListaP *ciuSel = testSimulacion.getListaPersonas().getCabeceraCiudadRes().obtenerDato(pos);
                testSimulacion.getListaPersonas().calculoConsulta3(ciuSel->clave);
                break;
            }

            case '4':{
                int cantidad = 0;
                cout<<"Ingrese la cantidad de personas: ";
                cin>>cantidad;
                testSimulacion.getListaPersonas().calculoConsulta4(cantidad);
                break;
            }
            case '5':{
                testSimulacion.getListaPersonas().calculoConsulta5();
                break;
            }
            case '6':{
                cout<<"Estos son los rangos de edades: "<<endl;
                for (int i = 0; i < 8; i++) {
                    cout<<i<<"."<<testSimulacion.getListaPersonas().getCabeceraEdad()[i]->getEdad()<<endl;
                }
                cout<<"Estas son las actividades laborales: "<<endl;
                for (int i = 0; i < 6; i++) {
                    cout<<i<<"."<<testSimulacion.getListaPersonas().getCabeceraActividad()[i]->getActivLab()<<endl;
                }
                int pos1, pos2;
                cout<<"Escoja el rango de edad por medio de su posición en lista: ";
                cin>>pos1;
                cout<<"Escoja la actividad laboral por medio de su posición en lista: ";
                cin>>pos2;
                Persona *rangoEdadSel = testSimulacion.getListaPersonas().getCabeceraEdad()[pos1];
                Persona *actLabSel = testSimulacion.getListaPersonas().getCabeceraActividad()[pos2];
                testSimulacion.getListaPersonas().calculoConsulta6(rangoEdadSel->getEdad(), actLabSel->getActivLab());
                break;
            }
            case '7':{
                cout<<"Estas son las EPS: "<<endl;
                for (int i = 0; i < testSimulacion.getListaPersonas().getPoscabEps(); i++) {
                    cout<<i<<"."<<testSimulacion.getListaPersonas().getCabeceraEps()[i]->eps->getNombre()<<endl;
                }
                cout<<"Estas son los rangos de edades: "<<endl;
                for (int i = 0; i < 8; i++) {
                    cout<<i<<"."<<testSimulacion.getListaPersonas().getCabeceraEdad()[i]->getEdad()<<endl;
                }
                int pos1, pos2;
                cout<<"Escoja la EPS por medio de su posición en lista: ";
                cin>>pos1;
                cout<<"Escoja el rango de edad por medio de su posición en lista: ";
                cin>>pos2;
                claseEPS *epsSel = testSimulacion.getListaPersonas().getCabeceraEps()[pos1]->eps;
                Persona *rangoEdadSel = testSimulacion.getListaPersonas().getCabeceraEdad()[pos1];
                testSimulacion.getListaPersonas().calculoConsulta7(rangoEdadSel->getEdad(), epsSel->getNombre());
                break;
            }
            case '8':{
                cout<<"Estas son las laboratorios: "<<endl;
                for (int i = 0; i < 6; i++) {
                    cout<<i<<"."<<testSimulacion.getListaPersonas().getCabeceraEps()[i]->eps->getListaVacunas()->indexLab<<endl;
                }
                cout<<"Estas son las EPS: "<<endl;
                for (int i = 0; i < testSimulacion.getListaPersonas().getPoscabEps(); i++) {
                    cout<<i<<"."<<testSimulacion.getListaPersonas().getCabeceraEps()[i]->eps->getNombre()<<endl;
                }
                int pos1, pos2;
                cout<<"Escoja el laboratorio por medio de su posición en lista: ";
                cin>>pos1;
                cout<<"Escoja la EPS por medio de su posición en lista: ";
                cin>>pos2;
                nodoVacEps *labSel = const_cast<nodoVacEps *>(testSimulacion.getListaPersonas().getCabeceraEps()[pos1]->eps->getListaVacunas());
                claseEPS *epsSel = testSimulacion.getListaPersonas().getCabeceraEps()[pos1]->eps;
                testSimulacion.getListaPersonas().calculoConsulta8(labSel->indexLab, epsSel->getNombre());
                break;
            }
            case '9':
                fecha f;
                cout<<"Ingrese un Dia: ";
                cin>>f.dia;
                cout<<"Ingrese un Mes: ";
                cin>>f.mes;
                cout<<"Ingrese un Anio: ";
                cin>>f.anio;
                testSimulacion.getListaPersonas().calculoConsulta9(f);
                break;
            case '0':
                cout<<"Regresando al menu anterior..."<<endl;
                break;
            default:
                cout<<"La opcion ingresada es invalida por favor ingrese otra"<<endl;
        }
    }
}

void simularVacunacion(Simulacion &testSimulacion){

}

void generarEstadisticas(Simulacion &testSimulacion){

}