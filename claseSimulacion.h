//
// Created by oscar on 28/09/2021.
//

#ifndef PROYECTOCIENCIAS_CLASESIMULACION_H
#define PROYECTOCIENCIAS_CLASESIMULACION_H

#include "claseListaPersonas.h"
#include <ctime>

class Simulacion{
    fecha FechaActual;
    ListaPersona listaPersonas;
public:
    Simulacion(){ // Temporal
        calcularFechaActual();
    }
    const fecha &getFechaActual() const;

    const string &getCaracteristica() const;

    void setCaracteristica(const string &caracteristica);

    void calcularFechaActual();
    void atender(fecha);
    void mainSimulado();

    void guardarArchivos();
    void cargarArchivos();
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

void Simulacion::mainSimulado() {
    /* Codigo para hacer test a las clases que representan las estructuras */
    Simulacion test;
    Persona testPersona1, testPersona2;
    claseEPS *testEps = new claseEPS, *testEps2 = new claseEPS;
    IPS testIPS1, testIPS2;
    ListaPersona listaTest;

    testIPS1.setNombre("ipsTest1");
    testIPS1.setDireccion("Calle 11");
    testIPS2.setNombre("ipsTest2");
    testIPS2.setDireccion("Calle 21");

    testEps->setNombre("testEps");
    testEps->setNumAfiliados(0);
    testEps->agregarCiudad(0, "ciudadTest1");
    testEps->agregarCiudad(1, "ciudadTest2");
    testEps->agregarIPS(testIPS1, "ciudadTest1");
    testEps->agregarIPS(testIPS2, "ciudadTest2");

    testEps2->setNombre("testEps2");
    testEps2->setNumAfiliados(0);
    testEps2->agregarCiudad(0, "ciudadTest1");
    testEps2->agregarCiudad(1, "ciudadTest2");

    listaTest.agregarEPS(testEps);
    listaTest.agregarEPS(testEps2);


    testPersona1.setNombre("Santiago");
    testPersona1.setApellido("Dulcano");
    testPersona1.setTipoId("CC");
    testPersona1.setNumId("101010111");
    testPersona1.setSexo('M');
    testPersona1.setTelCelular("4000000");
    testPersona1.setTelFijo("30000");
    testPersona1.setEmail("fulano@test.com");
    testPersona1.setFechaNac(15, 4, 1980);
    testPersona1.setCiudadNac("ciudadNac");
    testPersona1.setPaisNac("paisNac");
    testPersona1.setCiudadRes("ciudadTest1");
    testPersona1.setDirec("Calle_01");
    testPersona1.setBarrio("barrioTest1");
    testPersona1.setActivLab("Filosofia");
    testPersona1.setNombreEps(testEps->getNombre());
    testPersona1.calcEdad(FechaActual);

    testPersona2.setNombre("Elena");
    testPersona2.setApellido("Delana");
    testPersona2.setTipoId("CC");
    testPersona2.setNumId("101010200");
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
    testPersona2.setNombreEps(testEps->getNombre());
    testPersona2.calcEdad(FechaActual);

    test.calcularFechaActual();
    fecha testFecha1, testFecha2;
    testFecha1.dia = 9;
    testFecha1.mes = 10;
    testFecha1.anio = 2021;
    listaTest.agregarPersona(testPersona1);
    testEps->agregarRegistro(listaTest.obtenerPersona(testPersona1.getNumId()), 0, &testIPS2, testFecha1, "CP", true);
    testFecha2.dia = 11;
    testFecha2.mes = 10;
    testFecha2.anio = 2021;
    listaTest.agregarPersona(testPersona2);
    testEps->agregarRegistro(listaTest.obtenerPersona(testPersona2.getNumId()), 1, &testIPS2, testFecha2, "CP", true);

    testEps->agregarCargamentoVacunas(0, 500);
    testEps->agregarCargamentoVacunas(1, 500);
    testEps->agregarCargamentoVacunas(2, 500);

    testEps->repartirVacunas();

    testIPS1 = testEps->getCabeceraIps()[0].ips;
    testIPS2 = testEps->getCabeceraIps()[1].ips;

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
    archsalida3<<setw(10)<<testEps->getNombre()<<setw(10)<<testEps->getNumAfiliados()<<endl;



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


    int edad, dia, mes, anio;
    string nombre, apellido, tipoId, numId, telCelular, telFijo, email, ciudadNac, paisNac, ciudadRes, direc, barrio, activLab, nombreEps;
    char sexo;

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
        testPersona3.calcEdad(this->FechaActual);
        listaTest.agregarPersona(testPersona3);
        testEps->agregarRegistro(listaTest.obtenerPersona(testPersona3.getNumId()), 0, &testIPS1, this->FechaActual, "CP", true);
    }

    testFecha1 = FechaActual;
    testFecha2 = testEps->agregarTiempoFecha(testFecha1, 80);
    while(testEps->compararFechas(testFecha1, testFecha2)){
        testEps->vacunar(testFecha1);
        testFecha1 = testEps->agregarTiempoFecha(testFecha1, 1);
    }
    //testEps->imprimirCabeceraIPS();
    listaTest.imprimirCabeceras();


    archEntrada.close();
}


void Simulacion::atender(fecha fechaA ) {

}

void Simulacion::guardarArchivos() {
    string *clavesArbol;
    clavesArbol = listaPersonas.obtenerClaves();
    //ofstream archsalida1("personaGuardada.txt", ios::out|ios::trunc);
}

#endif //PROYECTOCIENCIAS_CLASESIMULACION_H
