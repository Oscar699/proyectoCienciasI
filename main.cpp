#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <random>
#include "claseEPS.h"
#include "claseLaboratorios.h"
#include "claseListaPersonas.h"
#include "clasePersona.h"
#include "claseSimulacion.h"


using namespace std;

int main() {
    /* Codigo para hacer test a las clases que representan las estructuras */

    /*Persona testPersona;
    claseEPS testEps;
    IPS testIPS;

    testIPS.setNombre("ipsTest");
    testIPS.setDireccion("Calle 11");

    testEps.setNombre("testEps");
    testEps.setNumAfiliados(1);
    testEps.agregarCiudad(0, "ciudadTest");
    testEps.agregarIPS(testIPS, 0, "ciudadTest");

    testPersona.setNombre("Fulano");
    testPersona.setApellido("Dulcano");
    testPersona.setTipoId("CC");
    testPersona.setNumId("101010101");
    testPersona.setSexo('M');
    testPersona.setTelCelular("4000000");
    testPersona.setTelFijo("30000");
    testPersona.setEmail("fulano@test.com");
    testPersona.setFechaNac(01, 01, 2001);
    testPersona.setCiudadNac("ciudadNac");
    testPersona.setPaisNac("paisNac");
    testPersona.setCiudadRes("ciudadRes");
    testPersona.setDirec("Calle 01");
    testPersona.setBarrio("barrioTest");
    testPersona.setActivLab("filosofia");
    testPersona.setNombreEps(testEps.getNombre());


    ofstream archsalida1("personaTest.csv", ios::out|ios::trunc);
    ofstream archsalida2("IPSTest.csv", ios::out|ios::trunc);
    ofstream archsalida3("EPSTest.csv", ios::out|ios::trunc);
    if (!archsalida1.good() || !archsalida2.good() || !archsalida3.good()){
        cerr << "No se pudiron abrir los archivos" << endl;
        exit(1);
    }

    // Escribe en el archivo personaTest.csv la informacion de un objeto Persona llamado testPersona
    archsalida1<<setw(10)<<testPersona.getNombre()<<setw(10)<<testPersona.getApellido()<<setw(10)<<testPersona.getTipoId()
               <<setw(10)<<testPersona.getNumId()<<setw(10)<<testPersona.getSexo()<<setw(10)<<testPersona.getTelCelular()
               <<setw(10)<<testPersona.getTelFijo()<<setw(10)<<testPersona.getEmail()<<setw(10)<<testPersona.getFechaNac().dia
               <<setw(10)<<testPersona.getFechaNac().mes<<setw(10)<<testPersona.getFechaNac().anio<<setw(10)<<testPersona.getCiudadNac()
               <<setw(10)<<testPersona.getPaisNac()<<setw(10)<<testPersona.getCiudadRes()<<setw(10)<<testPersona.getDirec()<<setw(10)
               <<testPersona.getBarrio()<<setw(10)<<testPersona.getActivLab()<<setw(10)<<testPersona.getNombreEps()<<endl;

    cout<<"Se escribio en personaTest.csv"<<endl;

    // Escribe en el archivo IPSTest.csv la informacion de un objeto IPS llamado testIPS
    archsalida2<<setw(10)<<testIPS.getNombre()<<setw(10)<<testIPS.getDireccion()<<endl;
    cout<<"Se escribio en IPSTest.csv"<<endl;


    // Escribe en el archivo EPSTest.csv la informacion de un objeto claseEPS llamado testEPS
    archsalida3<<setw(10)<<testEps.getNombre()<<setw(10)<<testEps.getNumAfiliados()<<endl;
    cout<<"Se escribio en EPSTest.csv"<<endl;

    archsalida1.close();
    archsalida2.close();
    archsalida3.close();

    // Declaracion del objeto que lee la informacion

    ifstream archEntrada("informacion.csv", ios::in);
    if (!archEntrada.good()){
        cerr << "No se pudo abrir el archivo persona" << endl;
        exit(1);
    }*/

    /*claseEPS testEPS;

    Simulacion testSimulacion;
    testSimulacion.calcularFechaActual();
    fecha testFecha2,testFecha1 = testSimulacion.getFechaActual();
    testFecha2.dia = 31;
    testFecha2.mes = testFecha1.mes + 3;
    testFecha2.anio = testFecha1.anio;

    cout<<testFecha1.dia<<'/'<<testFecha1.mes<<'/'<<testFecha1.anio<<endl;
    cout<<testFecha2.dia<<'/'<<testFecha2.mes<<'/'<<testFecha2.anio<<endl;

    cout<<"---------------"<<endl;

    testEPS.generarFechaAleatoria(testFecha1, testFecha2);*/




    cout << "Hello, World!" << endl; // Texto para saber que algo hace xd

    return 0;
}
