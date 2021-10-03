#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "claseEPS.h"
#include "claseLaboratorios.h"
#include "claseListaPersonas.h"
#include "clasePersona.h"
#include "claseSimulacion.h"

using namespace std;

void cambiarCaracteristcia(Simulacion &); // La prueba de que deberia funcionar

void modificarInformacion(Simulacion &);
void ejecutarConsulta(Simulacion &);
void simularVacunacion(Simulacion &);
void generarEstadisticas(Simulacion &);

int main() {
    Simulacion testSimulacion;
    char opcionUsuario;
    //testSimulacion.mainSimulado(); Simula lo que antes estaba en el main

    cout<<"¿Que desea hacer?"<<endl;
    cout<<"1-> Realizar cambios en la iformacion."<<endl;
    cout<<"2-> Realizar una consulta."<<endl;
    cout<<"3-> Iniciar Simulacion de vacunación"<<endl;
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

            break;
        case '5':
            break;
        default:
    }


    cout << "Hello, World!" << endl; // Texto para saber que algo hace xd
    return 0;
}

void cambiarCaracteristcia(Simulacion &testSimulacion){
    testSimulacion.setCaracteristica("Hay cambios");
    cout<<testSimulacion.getCaracteristica()<<endl;
}

void modificarInformacion(Simulacion &testSimulacion){

}

void ejecutarConsulta(Simulacion &testSimulacion){

}

void simularVacunacion(Simulacion &testSimulacion){

}