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

int main() {
    /* Codigo para hacer test a las clases que representan las estructuras */
    Simulacion test;
    Persona testPersona1, testPersona2;
    claseEPS testEps;
    IPS testIPS1, testIPS2;

    testIPS1.setNombre("ipsTest1");
    testIPS1.setDireccion("Calle 11");
    testIPS2.setNombre("ipsTest2");
    testIPS2.setDireccion("Calle 21");


    testEps.setNombre("testEps");
    testEps.setNumAfiliados(0);
    testEps.agregarCiudad(0, "ciudadTest1");
    testEps.agregarCiudad(1, "ciudadTest2");
    testEps.agregarIPS(testIPS1, "ciudadTest1");
    testEps.agregarIPS(testIPS2, "ciudadTest2");

    testPersona1.setNombre("Fulano");
    testPersona1.setApellido("Dulcano");
    testPersona1.setTipoId("CC");
    testPersona1.setNumId("101010101");
    testPersona1.setSexo('M');
    testPersona1.setTelCelular("4000000");
    testPersona1.setTelFijo("30000");
    testPersona1.setEmail("fulano@test.com");
    testPersona1.setFechaNac(01, 1, 2001);
    testPersona1.setCiudadNac("ciudadNac");
    testPersona1.setPaisNac("paisNac");
    testPersona1.setCiudadRes("ciudadTest1");
    testPersona1.setDirec("Calle_01");
    testPersona1.setBarrio("barrioTest1");
    testPersona1.setActivLab("Filosofia");
    testPersona1.setNombreEps(testEps.getNombre());

    testPersona2.setNombre("Sultana");
    testPersona2.setApellido("Delana");
    testPersona2.setTipoId("CC");
    testPersona2.setNumId("101010100");
    testPersona2.setSexo('F');
    testPersona2.setTelCelular("4000001");
    testPersona2.setTelFijo("30001");
    testPersona2.setEmail("sultana@test.com");
    testPersona2.setFechaNac(20, 2, 1999);
    testPersona2.setCiudadNac("ciudadNac");
    testPersona2.setPaisNac("paisNac");
    testPersona2.setCiudadRes("ciudadTest2");
    testPersona2.setDirec("Calle_221");
    testPersona2.setBarrio("barrioTest2");
    testPersona2.setActivLab("Artes");
    testPersona2.setNombreEps(testEps.getNombre());

    test.calcularFechaActual();
    //testEps.agregarRegistro(&testPersona1, 0, &testIPS1, test.getFechaActual());
    //testEps.agregarRegistro(&testPersona2, 1, &testIPS2, test.getFechaActual());

    testEps.agregarCargamentoVacunas(0, 1000);
    testEps.agregarCargamentoVacunas(1, 1200);

    testEps.repartirVacunas();

    testIPS1 = testEps.getCabeceraIps()[0].ips;
    testIPS2 = testEps.getCabeceraIps()[1].ips;


    testEps.imprimirCabeceraIPS();


    ofstream archsalida1("personaTest.csv", ios::out|ios::trunc);
    ofstream archsalida2("IPSTest.csv", ios::out|ios::trunc);
    ofstream archsalida3("EPSTest.csv", ios::out|ios::trunc);
    ofstream archsalida4("cabeceraIPS_Test.csv", ios::out|ios::trunc);
    if (!archsalida1.good() || !archsalida2.good() || !archsalida3.good() || !archsalida4.good()){
        cerr << "No se pudiron abrir los archivos" << endl;
        exit(1);
    }

    // Escribe en el archivo personaTest.csv la informacion de un objeto Persona llamado testPersona1
    archsalida1<<setw(20)<<testPersona1.getNombre()<<setw(20)<<testPersona1.getApellido()<<setw(20)<<testPersona1.getTipoId()
               <<setw(20)<<testPersona1.getNumId()<<setw(20)<<testPersona1.getSexo()<<setw(20)<<testPersona1.getTelCelular()
               <<setw(20)<<testPersona1.getTelFijo()<<setw(20)<<testPersona1.getEmail()<<setw(20)<<testPersona1.getFechaNac().dia
               <<setw(20)<<testPersona1.getFechaNac().mes<<setw(20)<<testPersona1.getFechaNac().anio<<setw(20)<<testPersona1.getCiudadNac()
               <<setw(20)<<testPersona1.getPaisNac()<<setw(20)<<testPersona1.getCiudadRes()<<setw(20)<<testPersona1.getDirec()<<setw(20)
               <<testPersona1.getBarrio()<<setw(20)<<testPersona1.getActivLab()<<setw(20)<<testPersona1.getNombreEps()<<endl;

    archsalida1<<setw(20)<<testPersona2.getNombre()<<setw(20)<<testPersona2.getApellido()<<setw(20)<<testPersona2.getTipoId()
               <<setw(20)<<testPersona2.getNumId()<<setw(20)<<testPersona2.getSexo()<<setw(20)<<testPersona2.getTelCelular()
               <<setw(20)<<testPersona2.getTelFijo()<<setw(20)<<testPersona2.getEmail()<<setw(20)<<testPersona2.getFechaNac().dia
               <<setw(20)<<testPersona2.getFechaNac().mes<<setw(20)<<testPersona2.getFechaNac().anio<<setw(20)<<testPersona2.getCiudadNac()
               <<setw(20)<<testPersona2.getPaisNac()<<setw(20)<<testPersona2.getCiudadRes()<<setw(20)<<testPersona2.getDirec()<<setw(20)
               <<testPersona2.getBarrio()<<setw(20)<<testPersona2.getActivLab()<<setw(20)<<testPersona2.getNombreEps();
    cout<<"Se escribio en personaTest.csv"<<endl;

    // Escribe en el archivo IPSTest.csv la informacion de un objeto IPS llamado testIPS1
    archsalida2<<setw(10)<<testIPS1.getNombre()<<setw(10)<<testIPS1.getDireccion()<<setw(10)
    <<testIPS1.getListaVacunas()[0].numVacunas<<setw(10)<<testIPS1.getListaVacunas()[1].numVacunas<<endl;
    archsalida2<<setw(10)<<testIPS2.getNombre()<<setw(10)<<testIPS2.getDireccion()<<setw(10)
    <<testIPS2.getListaVacunas()[0].numVacunas<<setw(10)<<testIPS2.getListaVacunas()[1].numVacunas<<endl;
    cout<<"Se escribio en IPSTest.csv"<<endl;


    // Escribe en el archivo EPSTest.csv la informacion de un objeto claseEPS llamado testEPS
    archsalida3<<setw(10)<<testEps.getNombre()<<setw(10)<<testEps.getNumAfiliados()<<endl;



    cout<<"Se escribio en EPSTest.csv"<<endl;

    archsalida1.close();
    archsalida2.close();
    archsalida3.close();

    // Declaracion del objeto que lee la informacion

    ifstream archEntrada("personaTest.txt", ios::in);
    if (!archEntrada.good()){
        cerr << "No se pudo abrir el archivo persona" << endl;
        exit(1);
    }

    ListaPersona listaTest;
    int edad, dia, mes, anio;
    string nombre, apellido, tipoId, numId, telCelular, telFijo, email, ciudadNac, paisNac, ciudadRes, direc, barrio, activLab, nombreEps;
    char sexo;
    fecha fechaActual;
    fechaActual.dia = 1;
    fechaActual.mes = 10;
    fechaActual.anio = 2021;

    int count=0;
    Persona testPersona3;
    while(!archEntrada.eof()){
        archEntrada>>nombre;
        testPersona3.setNombre(nombre);
        archEntrada>>apellido;
        testPersona3.setApellido(apellido);
        archEntrada>>tipoId;
        testPersona3.setTipoId(tipoId);
        archEntrada>>numId;
        testPersona3.setNumId(numId);
        archEntrada>>sexo;
        testPersona3.setSexo(sexo);
        archEntrada>>telCelular;
        testPersona3.setTelCelular(telCelular);
        archEntrada>>telFijo;
        testPersona3.setTelFijo(telFijo);
        archEntrada>>email;
        testPersona3.setEmail(email);
        archEntrada>>dia;
        archEntrada>>mes;
        archEntrada>>anio;
        testPersona3.setFechaNac(dia, mes, anio);
        archEntrada>>ciudadNac;
        testPersona3.setCiudadNac(ciudadNac);
        archEntrada>>paisNac;
        testPersona3.setPaisNac(paisNac);
        archEntrada>>ciudadRes;
        testPersona3.setCiudadRes(ciudadRes);
        archEntrada>>direc;
        testPersona3.setDirec(direc);
        archEntrada>>barrio;
        testPersona3.setBarrio(barrio);
        archEntrada>>activLab;
        testPersona3.setActivLab(activLab);
        archEntrada>>nombreEps;
        testPersona3.setNombreEps(nombreEps);
        listaTest.agregarPersona(testPersona3);
        testEps.agregarRegistro(listaTest.obtenerPersona(0), 0, &testIPS1, fechaActual);
    }

    archEntrada.close();

    cout << "Hello, World!" << endl; // Texto para saber que algo hace xd

    return 0;
}
