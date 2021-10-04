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
                break;
            default:
                cout<<"La opcion ingresada es invalida por favor ingrese otra"<<endl;
        }
    }

    return 0;
}

void cambiarCaracteristcia(Simulacion &testSimulacion){
    testSimulacion.setCaracteristica("Hay cambios");
    cout<<testSimulacion.getCaracteristica()<<endl;
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
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
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