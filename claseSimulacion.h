//
// Created by oscar on 28/09/2021.
//

#ifndef PROYECTOCIENCIAS_CLASESIMULACION_H
#define PROYECTOCIENCIAS_CLASESIMULACION_H

#include "claseListaPersonas.h"
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>

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

    void cargarArchivos();
    void cargarPersonas();
    void cargarListaPersonas();
    void cargarLasEPS();
    void cargarInfoEPS();
    void conectarPersonasAEPS(claseEPS &);
    void guardarArchivos();
    void traducirCabsPersonas(string (&)[6], Persona &);
    ListaPersona* getListaPersonas();
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
    /*Simulacion test;
    Persona testPersona1, testPersona2;
    claseEPS *testEps = new claseEPS, *testEps2 = new claseEPS;
    IPS testIPS1, testIPS2, testIPS3, testIPS4;


    testIPS1.setNombre("ipsTest1");
    testIPS1.setDireccion("Calle 11");
    testIPS2.setNombre("ipsTest2");
    testIPS2.setDireccion("Calle 21");
    testIPS3.setNombre("ipsTest3");
    testIPS3.setDireccion("Calle 31");
    testIPS4.setNombre("ipsTest4");
    testIPS4.setDireccion("Calle 41");

    testEps->setNombre("Sanitas");
    testEps->setNumAfiliados(0);
    testEps->agregarCiudad(0, "ciudadTest1");
    testEps->agregarCiudad(1, "ciudadTest2");
    testEps->agregarIPS(testIPS1, "ciudadTest1");
    testEps->agregarIPS(testIPS2, "ciudadTest2");

    testEps2->setNombre("Compensar");
    testEps2->setNumAfiliados(0);
    testEps2->agregarCiudad(0, "ciudadTest3");
    testEps2->agregarCiudad(1, "ciudadTest4");
    testEps2->agregarIPS(testIPS3, "ciudadTest3");
    testEps2->agregarIPS(testIPS4, "ciudadTest4");


    listaPersonas.agregarEPS(testEps);
    listaPersonas.agregarEPS(testEps2);
    listaPersonas.agregarPais("COLOMBIA");
    listaPersonas.agregarPais("VENEZUELA");
    listaPersonas.agregarCiudadRes(0,"BOGOTA");
    listaPersonas.agregarCiudadRes(1,"MEDELLIN");

    testPersona1.setNombre("Santiago");
    testPersona1.setApellido("Dulcano");
    testPersona1.setTipoId("CC");
    testPersona1.setNumId("80745693");
    testPersona1.setSexo('M');
    testPersona1.setTelCelular("4000000");
    testPersona1.setTelFijo("30000");
    testPersona1.setEmail("fulano@test.com");
    testPersona1.setFechaNac(15, 4, 1980);
    testPersona1.setCiudadNac("ciudadNac");
    testPersona1.setPaisNac("COLOMBIA");
    testPersona1.setCiudadRes("BOGOTA");
    testPersona1.setDirec("Calle_01");
    testPersona1.setBarrio("barrioTest1");
    testPersona1.setActivLab("FILOSOFIA");
    testPersona1.setNombreEps(testEps2->getNombre());
    testPersona1.calcEdad(FechaActual);

    testPersona2.setNombre("Elena");
    testPersona2.setApellido("Delana");
    testPersona2.setTipoId("CC");
    testPersona2.setNumId("1910748324");
    testPersona2.setSexo('F');
    testPersona2.setTelCelular("4000001");
    testPersona2.setTelFijo("30001");
    testPersona2.setEmail("sultana@test.com");
    testPersona2.setFechaNac(20, 2, 1999);
    testPersona2.setCiudadNac("ciudadNac");
    testPersona2.setPaisNac("VENEZUELA");
    testPersona2.setCiudadRes("MEDELLIN");
    testPersona2.setDirec("Calle_221");
    testPersona2.setBarrio("barrioTest2");
    testPersona2.setActivLab("ARTES");
    testPersona2.setNombreEps(testEps2->getNombre());
    testPersona2.calcEdad(FechaActual);

    testIPS1 = testEps->getCabeceraIps()[0].ips;
    testIPS2 = testEps->getCabeceraIps()[1].ips;

    testIPS3 = testEps2->getCabeceraIps()[0].ips;
    testIPS4 = testEps2->getCabeceraIps()[1].ips;

    test.calcularFechaActual();
    listaPersonas.agregarPersona(testPersona1);
    testEps2->agregarRegistro(listaPersonas.obtenerPersona(testPersona1.getNumId()), 0, &testIPS3, FechaActual, "CP", true);
    listaPersonas.agregarPersona(testPersona2);
    testEps2->agregarRegistro(listaPersonas.obtenerPersona(testPersona2.getNumId()), 1, &testIPS4, FechaActual, "CP", true);


    for(int i=0; i<6; i++){
        testEps->agregarCargamentoVacunas(i, 500);
        testEps2->agregarCargamentoVacunas(i, 500);
    }

    testEps->repartirVacunas();
    testEps2->repartirVacunas();

    testIPS1 = testEps->getCabeceraIps()[0].ips;
    testIPS2 = testEps->getCabeceraIps()[1].ips;


    // Declaracion del objeto que lee la informacion
    ifstream archEntrada("personaTestSalida.txt", ios::in);
    if (!archEntrada.good()){
        cerr << "No se pudo abrir el archivo persona" << endl;
        exit(1);
    }


    // Variables que almacenaran los datos de las personas
    int edad, dia, mes, anio;
    string nombre, apellido, tipoId, numId, telCelular, telFijo, email;
    string ciudadNac, paisNac, ciudadRes, direc, barrio, activLab, nombreEps;
    string sexo, fechaNacimiento ,fechaDia, fechaMes, fechaAnio;
    // Cada linea del archivo
    string entrada;
    // Delimitador que permite leer dato por dato
    char delimitador=',';
    // Se lee la primera entrada para descartar a las cabeceras
    getline(archEntrada, entrada);
    Persona testPersona3;
    while(!archEntrada.eof()){
        getline(archEntrada, entrada);
        stringstream registro(entrada);
        getline(registro, nombre, delimitador);
        testPersona3.setNombre(nombre);
        getline(registro, apellido, delimitador);
        testPersona3.setApellido(apellido);
        getline(registro, tipoId, delimitador);
        testPersona3.setTipoId(tipoId);
        getline(registro, numId, delimitador);
        testPersona3.setNumId(numId);
        getline(registro, sexo, delimitador);
        testPersona3.setSexo(sexo[0]);
        getline(registro, telCelular, delimitador);
        testPersona3.setTelCelular(telCelular);
        getline(registro, telFijo, delimitador);
        testPersona3.setTelFijo(telFijo);
        getline(registro, email, delimitador);
        testPersona3.setEmail(email);
        getline(registro, fechaNacimiento, delimitador);
        stringstream fechaNac(fechaNacimiento);
        getline(fechaNac, fechaDia, '-');
        getline(fechaNac, fechaMes, '-');
        getline(fechaNac, fechaAnio, '-');
        dia = stoi(fechaDia, nullptr);
        mes = stoi(fechaMes, nullptr);
        anio = stoi(fechaAnio, nullptr);
        testPersona3.setFechaNac(dia, mes, anio);
        getline(registro, ciudadNac, delimitador);
        testPersona3.setCiudadNac(ciudadNac);
        getline(registro, paisNac, delimitador);
        testPersona3.setPaisNac(paisNac);
        getline(registro, ciudadRes, delimitador);
        testPersona3.setCiudadRes(ciudadRes);
        getline(registro, direc, delimitador);
        testPersona3.setDirec(direc);
        getline(registro, barrio, delimitador);
        testPersona3.setBarrio(barrio);
        getline(registro, activLab, delimitador);
        testPersona3.setActivLab(activLab);
        getline(registro, nombreEps, delimitador);
        testPersona3.setNombreEps(nombreEps);
        testPersona3.calcEdad(this->FechaActual);
        listaPersonas.agregarPersona(testPersona3);
        testEps->agregarRegistro(listaPersonas.obtenerPersona(testPersona3.getNumId()), 0, &testIPS2, this->FechaActual, "CP", true);
    }
     */

    fecha testFecha1, testFecha2;
    testFecha1 = FechaActual;
    testFecha2 = listaPersonas.obtenerEPS(0)->agregarTiempoFecha(testFecha1, 80);
    /*while(listaPersonas.obtenerEPS(0)->compararFechas(testFecha1, testFecha2)){
        listaPersonas.obtenerEPS(0)->vacunar(testFecha1);
        listaPersonas.obtenerEPS(1)->vacunar(testFecha1);
        testFecha1 = listaPersonas.obtenerEPS(0)->agregarTiempoFecha(testFecha1, 1);
    }*/
    cout<<listaPersonas.obtenerEPS(0)->getNombre()<<endl;
    cout<<"============================="<<endl;
    listaPersonas.obtenerEPS(0)->imprimirCabeceraIPS();
    cout<<"============================="<<endl;
    cout<<listaPersonas.obtenerEPS(1)->getNombre()<<endl;
    cout<<"============================="<<endl;
    listaPersonas.obtenerEPS(1)->imprimirCabeceraIPS();
    cout<<"============================="<<endl;
    listaPersonas.imprimirCabeceras();


    //archEntrada.close();



    cout<<"Aca fue"<<endl;
}


void Simulacion::atender(fecha fechaA ) {

}

void Simulacion::cargarArchivos() {
    cargarLasEPS();
    cargarListaPersonas();
    cargarPersonas();
    cargarInfoEPS();
}

void Simulacion::cargarPersonas() {
    ifstream archEntradaPersonas("personaTestSalida.txt", ios::in);
    if (!archEntradaPersonas.good()){
        cerr << "No se pudo abrir el archivo persona" << endl;
        exit(1);
    }
    // Variables que almacenaran los datos de las personas
    int edad, dia, mes, anio;
    string nombre, apellido, tipoId, numId, telCelular, telFijo, email;
    string ciudadNac, paisNac, ciudadRes, direc, barrio, activLab, nombreEps;
    string sexo, fechaNacimiento ,fechaDia, fechaMes, fechaAnio;
    // Cada linea del archivo
    string entrada;
    // Delimitador que permite leer dato por dato
    char delimitador=',';
    // Se lee la primera entrada para descartar a las cabeceras
    getline(archEntradaPersonas, entrada);
    Persona testPersona3;
    while(!archEntradaPersonas.eof()){
        getline(archEntradaPersonas, entrada);
        stringstream registro(entrada);
        getline(registro, nombre, delimitador);
        testPersona3.setNombre(nombre);
        getline(registro, apellido, delimitador);
        testPersona3.setApellido(apellido);
        getline(registro, tipoId, delimitador);
        testPersona3.setTipoId(tipoId);
        getline(registro, numId, delimitador);
        testPersona3.setNumId(numId);
        getline(registro, sexo, delimitador);
        testPersona3.setSexo(sexo[0]);
        getline(registro, telCelular, delimitador);
        testPersona3.setTelCelular(telCelular);
        getline(registro, telFijo, delimitador);
        testPersona3.setTelFijo(telFijo);
        getline(registro, email, delimitador);
        testPersona3.setEmail(email);
        getline(registro, fechaNacimiento, delimitador);
        stringstream fechaNac(fechaNacimiento);
        getline(fechaNac, fechaDia, '-');
        getline(fechaNac, fechaMes, '-');
        getline(fechaNac, fechaAnio, '-');
        dia = stoi(fechaDia, nullptr);
        mes = stoi(fechaMes, nullptr);
        anio = stoi(fechaAnio, nullptr);
        testPersona3.setFechaNac(dia, mes, anio);
        getline(registro, ciudadNac, delimitador);
        testPersona3.setCiudadNac(ciudadNac);
        getline(registro, paisNac, delimitador);
        testPersona3.setPaisNac(paisNac);
        getline(registro, ciudadRes, delimitador);
        testPersona3.setCiudadRes(ciudadRes);
        getline(registro, direc, delimitador);
        testPersona3.setDirec(direc);
        getline(registro, barrio, delimitador);
        testPersona3.setBarrio(barrio);
        getline(registro, activLab, delimitador);
        testPersona3.setActivLab(activLab);
        getline(registro, nombreEps, delimitador);
        testPersona3.setNombreEps(nombreEps);
        testPersona3.calcEdad(this->FechaActual);
        listaPersonas.agregarPersona(testPersona3);
    }
}

void Simulacion::cargarListaPersonas() {
    ifstream archEntradaCiudades("ciudadesGuardadsPersonas.txt", ios::in);
    ifstream archEntradaPaises("paisesGuardadsPersonas.txt", ios::in);
    if (!archEntradaCiudades.good() || !archEntradaPaises.good()){
        cerr << "No se pudieron abrir los archivos de ciudad y paises de las personas" << endl;
        exit(1);
    }
    // Variables que guardan los datos de las ciudades y paises entrantes
    string nombre, clave;
    // Cada linea del archivo
    string entrada;
    // Delimitador que permite leer dato por dato
    char delimitador=',';
    // Se lee la primera entrada para descartar a las cabeceras
    getline(archEntradaCiudades, entrada);
    // Guarda las ciudades encontradas en el archivo
    while(!archEntradaCiudades.eof()){
        getline(archEntradaCiudades, entrada);
        stringstream registro(entrada);
        getline(registro, nombre, delimitador);
        getline(registro, clave, delimitador);
        listaPersonas.agregarCiudadRes(stoi(clave), nombre);
    }
    // Se lee la primera entrada para descartar a las cabeceras
    getline(archEntradaPaises, entrada);
    // Guarda los paises encontrados en el archivo
    while(!archEntradaPaises.eof()){
        getline(archEntradaPaises, entrada);
        stringstream registro(entrada);
        getline(registro, clave, delimitador);
        listaPersonas.agregarPais(clave);
    }
}

void Simulacion::cargarLasEPS() {
    ifstream archEntradaEPS("epsGuardads.txt", ios::in);
    if (!archEntradaEPS.good()){
        cerr << "No se pudo abrir el archivo de EPS" << endl;
        exit(1);
    }

    string nombre, numAfiliados, poscabCiudad, poscabIPS;

    string entrada;

    char delimitador = ',';

    getline(archEntradaEPS, entrada);

    claseEPS *epsPlantilla;
    while(!archEntradaEPS.eof()){
        epsPlantilla = new claseEPS;
        getline(archEntradaEPS, entrada);
        stringstream registro(entrada);
        getline(registro, nombre, delimitador);
        epsPlantilla->setNombre(nombre);
        getline(registro, numAfiliados, delimitador);
        epsPlantilla->setNumAfiliados(stoi(numAfiliados, nullptr));
        getline(registro, poscabCiudad, delimitador);
        epsPlantilla->setPoscabCiudad(stoi(poscabCiudad, nullptr));
        getline(registro, poscabIPS, delimitador);
        epsPlantilla->setPoscabIps(stoi(poscabIPS, nullptr));
        listaPersonas.agregarEPS(epsPlantilla);
    }
}

void Simulacion::conectarPersonasAEPS(claseEPS &auxEPS) {
    Lista<string> listaClavesAfiliados;
    registroAfiliado *auxRegistro;
    auxEPS.obtenerClaves(listaClavesAfiliados);
    string clave;
    int pos;
    for(int i=0; i<listaClavesAfiliados.lista_size(); i++){
        clave = *listaClavesAfiliados.obtenerDato(i);
        pos = clave.find("S");
        if(pos == string::npos){
            auxRegistro = auxEPS.obtenerRegistro(clave);
            auxRegistro->persona = listaPersonas.obtenerPersona(clave);
        }else{
            auxRegistro = auxEPS.obtenerRegistro(clave);
            clave = clave.substr(0, pos);
            auxRegistro->persona = listaPersonas.obtenerPersona(clave);
        }
    }
}

void Simulacion::cargarInfoEPS() {
    ifstream archEntradaVacunasEPS("vacunasEPSGuardads.txt", ios::in);
    ifstream archEntradaCiudadEPS("ciudadesGuardadsEPS.txt", ios::in);
    ifstream archEntradaIPS("ipsGuardads.txt", ios::in);
    ifstream archEntradaVacunasIPS("vacunasIPSGuardads.txt", ios::in);
    ifstream archEntradaAfiliados("afiliadosEPS.txt", ios::in);

    if (!archEntradaVacunasEPS.good() || !archEntradaCiudadEPS.good() || !archEntradaIPS.good() || !archEntradaVacunasIPS.good() || !archEntradaAfiliados.good()){
        cerr << "No se pudo abrir alguno de los archivos" << endl;
        exit(1);
    }
    // Cada linea del archivo
    string entrada;
    // Delimitador que permite leer dato por dato
    char delimitador=',';
    // Saltamos la cabecera de los archivos
    getline(archEntradaVacunasEPS, entrada);
    getline(archEntradaCiudadEPS, entrada);
    getline(archEntradaIPS, entrada);
    getline(archEntradaVacunasIPS, entrada);
    getline(archEntradaAfiliados, entrada);
    for(int i=0; i<listaPersonas.getPoscabEps(); i++){
        claseEPS *auxEPS = listaPersonas.obtenerEPS(i);
        string nombreEPS = auxEPS->getNombre(); // temporal para saber si funciona lo que hago xd

        // Carga la informacion de las vacunas de una EPS
        getline(archEntradaVacunasEPS, entrada); // Nombre de la eps
        if(entrada != nombreEPS){
            cerr << "El nombre de la eps no es igual sad" << endl;
            exit(1);
        }

        string indexLab, numVacunas, claveAfiliado;
        nodoVacEps *auxVacEPS;
        for(int j=0; j<6; j++){
            auxVacEPS = auxEPS->obtenervacunas(j);
            getline(archEntradaVacunasEPS, entrada);
            stringstream registro(entrada);
            getline(registro, indexLab, delimitador);
            auxVacEPS->indexLab = stoi(indexLab, nullptr);
            getline(registro, numVacunas, delimitador);
            auxVacEPS->numVacunas = stoi(numVacunas, nullptr);
            getline(registro, claveAfiliado, delimitador);
            auxVacEPS->claveAfiliado = claveAfiliado;
        }

        // Carga la informacion de las ciudades de una EPS
        getline(archEntradaCiudadEPS, entrada); // Nombre de la eps
        string nombre, clave, posIPS;
        nodoCiudad *auxCiudadEPS = new nodoCiudad;
        for(int j=0; j<auxEPS->getPoscabCiudad(); j++){
            auxCiudadEPS = auxEPS->obtenerCiudad(j);
            getline(archEntradaCiudadEPS, entrada);
            stringstream registro(entrada);
            getline(registro, nombre, delimitador);
            auxCiudadEPS->nombreCiudad = nombre;
            getline(registro, clave, delimitador);
            auxCiudadEPS->clave = stoi(clave, nullptr);
            getline(registro, claveAfiliado, delimitador);
            auxCiudadEPS->claveAfiliado = claveAfiliado;
            getline(registro, posIPS, delimitador);
            auxCiudadEPS->posIPS = stoi(posIPS, nullptr);
        }

        // Carga la informacion de las IPS de una EPS
        string direccion, numAfiliados, sigCiudad;
        getline(archEntradaIPS, entrada); // Nombre de la eps
        getline(archEntradaVacunasIPS, entrada); // Nombre de la ips
        nodoIps *nodoAuxIPS = new nodoIps;
        IPS *auxIPS;
        for(int j=0; j<auxEPS->getPoscabIps(); j++){
            nodoAuxIPS = auxEPS->obtenerIps(j);
            auxIPS = new IPS;
            getline(archEntradaIPS, entrada);
            stringstream registro(entrada);
            getline(registro, nombre, delimitador);
            auxIPS->setNombre(nombre);
            getline(registro, direccion, delimitador);
            auxIPS->setDireccion(direccion);
            getline(registro, numAfiliados, delimitador);
            auxIPS->setNumAfiliados(stoi(numAfiliados, nullptr));

            getline(archEntradaVacunasIPS, entrada); // Nombre de la ips
            // Guarda la inforamcion de las vacunas de las IPS
            string subEntrada;
            nodoV *auxVacIPS = new nodoV;
            for(int k=0; k<6; k++){
                auxVacIPS = auxIPS->obtenerVacunas(k);
                getline(archEntradaVacunasIPS, subEntrada);
                stringstream subRegistro(subEntrada);
                getline(subRegistro, indexLab, delimitador);
                auxVacIPS->indexLab = stoi(indexLab, nullptr);
                getline(subRegistro, numVacunas, delimitador);
                auxVacIPS->numVacunas = stoi(numVacunas, nullptr);
            }

            nodoAuxIPS->ips = auxIPS;
            getline(registro, claveAfiliado, delimitador);
            nodoAuxIPS->claveAfiliado = claveAfiliado;
            getline(registro, sigCiudad, delimitador);
            nodoAuxIPS->sigCiudad = stoi(sigCiudad);
        }

        // Carga la informacion de los afiliados de una EPS
        string NodosArbol, claveCiu, fDosisDia, fDosisMes, fDosisAnio, sigIPS, estado, sigLAB, fechaDosisStr;
        getline(archEntradaAfiliados, entrada);
        stringstream valorControl(entrada);
        getline(valorControl, NodosArbol, delimitador); // Salta el nombre de la eps
        getline(valorControl, NodosArbol, delimitador);
        registroAfiliado *auxRegistroArbol;
        int numNodosArbol = stoi(NodosArbol, nullptr);
        for(int j=0; j<numNodosArbol; j++){
            auxRegistroArbol = new registroAfiliado;
            getline(archEntradaAfiliados, entrada);
            stringstream registro(entrada);
            getline(registro, clave, delimitador);
            auxRegistroArbol->clave = clave;
            getline(registro, claveCiu, delimitador);
            auxRegistroArbol->claveCiu = stoi(claveCiu, nullptr);
            getline(registro, sigCiudad, delimitador);
            auxRegistroArbol->sigCiudad = sigCiudad;
            getline(registro, fechaDosisStr, delimitador);
            stringstream fechaDosis(fechaDosisStr);
            getline(fechaDosis, fDosisDia, '-');
            getline(fechaDosis, fDosisMes, '-');
            getline(fechaDosis, fDosisAnio, '-');
            auxRegistroArbol->fechaDosis.dia = stoi(fDosisDia);
            auxRegistroArbol->fechaDosis.mes = stoi(fDosisMes);
            auxRegistroArbol->fechaDosis.anio = stoi(fDosisAnio);
            getline(registro, indexLab, delimitador);
            auxRegistroArbol->posLab = stoi(indexLab, nullptr);
            getline(registro, nombre, delimitador);
            for(int k=0; k<auxEPS->getPoscabIps(); k++){
                if(nombre == nodoAuxIPS->ips->getNombre()){
                    auxIPS = nodoAuxIPS->ips;
                }
            }
            auxRegistroArbol->ips = auxIPS;
            getline(registro, sigIPS, delimitador);
            auxRegistroArbol->sigIPS = sigIPS;
            getline(registro, estado, delimitador);
            auxRegistroArbol->estado = estado;
            getline(registro, sigLAB, delimitador);
            auxRegistroArbol->sigLab = sigLAB;
            auxEPS->cargarRegistro(*auxRegistroArbol);
        }
        // Conecta los afiliados de la eps con la lista de personas
        conectarPersonasAEPS(*auxEPS);
    }

}

void Simulacion::guardarArchivos() {
    Lista<string> listaClaves;
    listaPersonas.obtenerClaves(listaClaves);

    ofstream archsalidaPersonas("personaTestSalida.txt", ios::out|ios::trunc);
    ofstream archsalidaCiudadPersonas("ciudadesGuardadsPersonas.txt", ios::out|ios::trunc);
    ofstream archsalidaPaisPersonas("paisesGuardadsPersonas.txt", ios::out|ios::trunc);
    //ofstream archsalidaCabPersonas("cabPersonas.txt", ios::out|ios::trunc);
    ofstream archsalidaEPS("epsGuardads.txt", ios::out|ios::trunc);
    ofstream archsalidaCiudadEPS("ciudadesGuardadsEPS.txt", ios::out|ios::trunc);
    ofstream archsalidaIPS("ipsGuardads.txt", ios::out|ios::trunc);
    ofstream archsalidaVacunasEPS("vacunasEPSGuardads.txt", ios::out|ios::trunc);
    ofstream archsalidaVacunasIPS("vacunasIPSGuardads.txt", ios::out|ios::trunc);
    ofstream archsalidaAfiliados("afiliadosEPS.txt", ios::out|ios::trunc);

    //Cabeceras

    archsalidaPersonas<<"Nombres"<<','<<"Apellidos"<<','<<"Tipo Doc"<<','<<"Num Doc"<<','<<"Sexo"<<','<<"Tel Celular"<<
    ','<<"Tel Fijo"<<','<<"Email"<<','<<"Fecha Nacimiento"<<','<<"Ciudad Nacimiento"<<
    ','<<"Pais Nacimiento"<<','<<"Ciudad Residencia"<<','<<"Direccion"<<','<<"Barrio"<<','<<"Actividad Lab"<<","<<"Nombre EPS"<<endl;

    archsalidaCiudadPersonas<<"Nombre"<<','<<"Clave ciudad"<<','<<"Clave Persona"<<endl;

    archsalidaPaisPersonas<<"Clave Pais"<<','<<"Clave afiliado"<<endl;

    //archsalidaCabPersonas<<"Sig Sexo"<<','<<"Sig Edad"<<','<<"sig PaisNac"<<','<<"Sig CiudadRes"<<','<<"Sig ActLab"<<','<<"Sig EPS"<<endl;

    archsalidaEPS<<"Nombre"<<','<<"N° Afiliados"<<','<<"Pos CabCiudad"<<','<<"Pos CabIPS"<<endl;

    archsalidaVacunasEPS<<"Index LAB"<<','<<"N° vacuna"<<','<<"Clave Afiliado"<<endl;

    archsalidaCiudadEPS<<"Nombre"<<','<<"Clave Ciudad"<<','<<"Clave Afiliado"<<','<<"Pos IPS"<<endl;

    archsalidaIPS<<"Nombre"<<','<<"Direccion"<<','<<"N° Afiliados"<<','<<"Clave Afiliado"<<','<<"Sig Ciudad"<<endl;

    archsalidaVacunasIPS<<"Index LAB"<<','<<"N° Vacunas"<<endl;

    archsalidaAfiliados<<"Doc Afiliado"<<','<<"Clave Ciudad"<<','<<"Sig Ciudad"<<','<<"Fecha Dosis"<<','<<"Pos LAB"<<','<<"Nombre IPS"<<','
    <<"Sig IPS"<<','<<"Estado"<<','<<"Sig LAB"<<endl;

    // Guarda la informacion de las personas
    Persona *aux;
    for(int i=0; i<listaClaves.lista_size(); i++){
        if(i != 0){
            archsalidaPersonas<<"\n";
            //archsalidaCabPersonas<<"\n";
        }

        aux = listaPersonas.obtenerPersona(*listaClaves.obtenerDato(i));
        archsalidaPersonas<<aux->getNombre()<<','<<aux->getApellido()<<','<<aux->getTipoId()<<','<<aux->getNumId()<<
        ','<<aux->getSexo()<<','<<aux->getTelCelular()<<','<<aux->getTelFijo()<<','<<
        aux->getEmail()<<','<<aux->getFechaNac().dia<<'-'<<aux->getFechaNac().mes<<'-'<<
        aux->getFechaNac().anio<<','<<aux->getCiudadNac()<<','<<aux->getPaisNac()<<','<<aux->getCiudadRes()<<
        ','<<aux->getDirec()<<','<<aux->getBarrio()<<','<<aux->getActivLab()<<','<<aux->getNombreEps();

        /*string arrayClaves[6];
        traducirCabsPersonas(arrayClaves, *aux);
        archsalidaCabPersonas<<arrayClaves[0]<<','<<arrayClaves[1]<<','<<arrayClaves[2]<<','<<arrayClaves[3]<<','<<
        arrayClaves[4]<<','<<arrayClaves[5];*/
    }

    // Guarda la informacion de las ciudades en la lista de personas
    nodoCiudadListaP *auxCiudadPer;
    for(int i=0; i<listaPersonas.getNumCiudades(); i++){
        if(i != 0){
            archsalidaCiudadPersonas<<"\n";
        }
        string clavePersona;
        auxCiudadPer = listaPersonas.obtenerCiudadP(i);
        if(auxCiudadPer->persona == NULL){
            clavePersona = "";
        }
        else{
            clavePersona = auxCiudadPer->persona->getNumId();
        }
        archsalidaCiudadPersonas<<auxCiudadPer->nombreCiudad<<','<<auxCiudadPer->clave<<','<<clavePersona;
    }

    // Guarda la informacion de los paises en la lista de personas
    nodoP *auxPais;
    for(int i=0; i<listaPersonas.getNumPaises(); i++){
        if(i != 0){
            archsalidaPaisPersonas<<"\n";
        }

        string clavePersona;
        auxPais = listaPersonas.obtenerPais(i);
        if(auxPais->persona == NULL){
            clavePersona = "";
        }
        else{
            clavePersona = auxPais->persona->getNumId();
        }

        archsalidaPaisPersonas<<auxPais->clave<<','<<clavePersona;
    }

    // Guarda la informacion de las EPS
    for(int i=0; i<listaPersonas.getPoscabEps(); i++){
        claseEPS *auxEPS = listaPersonas.obtenerEPS(i);
        Lista<string> listaClavesAfiliados;
        auxEPS->obtenerClaves(listaClavesAfiliados);
        nodoVacEps *auxVacEps;
        if(i != 0){
            archsalidaEPS<<"\n";
            archsalidaVacunasEPS<<"\n";
            archsalidaVacunasIPS<<"\n";
            archsalidaCiudadEPS<<"\n";
            archsalidaIPS<<"\n";
            archsalidaAfiliados<<"\n";
        }
        archsalidaVacunasEPS<<auxEPS->getNombre()<<"\n";
        archsalidaVacunasIPS<<auxEPS->getNombre()<<"\n";
        archsalidaCiudadEPS<<auxEPS->getNombre()<<"\n";
        archsalidaIPS<<auxEPS->getNombre()<<"\n";
        archsalidaAfiliados<<auxEPS->getNombre()<<','<<listaClavesAfiliados.lista_size()<<"\n";
        archsalidaEPS<<auxEPS->getNombre()<<','<<auxEPS->getNumAfiliados()<<','<<auxEPS->getPoscabCiudad()<<','<<auxEPS->getPoscabIps();

        // Guarda la inforamcion de las vacunas de la EPS
        for(int j=0; j<6; j++){
            if(j != 0) archsalidaVacunasEPS<<"\n";
            auxVacEps = auxEPS->obtenervacunas(j);
            archsalidaVacunasEPS<<auxVacEps->indexLab<<','<<auxVacEps->numVacunas
            <<','<<auxVacEps->claveAfiliado;
        }
        // Guarda la informacion de las ciudades de la EPS
        for(int k=0; k<auxEPS->getPoscabCiudad(); k++){
            if(k != 0) archsalidaCiudadEPS<<"\n";
            nodoCiudad *auxCiudad = auxEPS->obtenerCiudad(k);
            archsalidaCiudadEPS<<auxCiudad->nombreCiudad<<','<<auxCiudad->clave<<","
            <<auxCiudad->claveAfiliado<<','<<auxCiudad->posIPS;
        }

        // Guarda la informacion de las IPS de la EPS
        for(int j=0; j<auxEPS->getPoscabIps(); j++){
            nodoIps *auxIPS = auxEPS->obtenerIps(j);
            if(j != 0){
                archsalidaIPS<<"\n";
                archsalidaVacunasIPS<<"\n";
            }
            archsalidaIPS<<auxIPS->ips->getNombre()<<','<<auxIPS->ips->getDireccion()<<','<<
            auxIPS->ips->getNumAfiliados()<<','<<auxIPS->claveAfiliado<<','<<auxIPS->sigCiudad;

            // Guarda la informacion de las vacunas de una IPS
            archsalidaVacunasIPS<<auxIPS->ips->getNombre()<<"\n";
            nodoV *auxVacIPS = const_cast<nodoV *>(auxIPS->ips->getListaVacunas());
            for(int k=0; k<6; k++){
                if(k != 0) archsalidaVacunasIPS<<"\n";
                archsalidaVacunasIPS<<auxVacIPS[k].indexLab<<','<<auxVacIPS[k].numVacunas;
            }
        }

        // Guarda la iformacion de los afiliados a la EPS
        registroAfiliado *auxRegistro;
        for(int i=0; i<listaClavesAfiliados.lista_size(); i++){
            if(i != 0) archsalidaAfiliados<<"\n";
            auxRegistro = auxEPS->obtenerRegistro(*listaClavesAfiliados.obtenerDato(i));
            if(auxRegistro == NULL) break;
            archsalidaAfiliados<<auxRegistro->clave<<','<<auxRegistro->claveCiu<<','<<
            auxRegistro->sigCiudad<<','<<auxRegistro->fechaDosis.dia<<'-'<<auxRegistro->fechaDosis.mes<<
            '-'<<auxRegistro->fechaDosis.anio<<','<<auxRegistro->posLab<<','<<auxRegistro->ips->getNombre()<<
            ','<<auxRegistro->sigIPS<<','<<auxRegistro->estado<<','<<auxRegistro->sigLab;

        }
    }

    archsalidaPersonas.close();
    //archsalidaCabPersonas.close();
    archsalidaEPS.close();
    archsalidaVacunasIPS.close();
    archsalidaVacunasEPS.close();
    archsalidaCiudadEPS.close();
    archsalidaIPS.close();
    archsalidaAfiliados.close();
    archsalidaCiudadPersonas.close();
}

void Simulacion::traducirCabsPersonas(string (& arrayClaves)[6], Persona &aux) {
    if(aux.getSigSexo() == NULL){
        arrayClaves[0] = "";
    } else{
        arrayClaves[0] = aux.getSigSexo()->getNumId();
    }
    if(aux.getSigEdad() == NULL){
        arrayClaves[1] = "";
    } else{
        arrayClaves[1] = aux.getSigEdad()->getNumId();
    }
    if(aux.getSigPaisNac() == NULL){
        arrayClaves[2] = "";
    } else{
        arrayClaves[2] = aux.getSigPaisNac()->getNumId();
    }
    if(aux.getSigCiudadRes() == NULL){
        arrayClaves[3] = "";
    } else{
        arrayClaves[3] = aux.getSigCiudadRes()->getNumId();
    }
    if(aux.getSigActivLab() == NULL){
        arrayClaves[4] = "";
    } else{
        arrayClaves[4] = aux.getSigActivLab()->getNumId();
    }
    if(aux.getSigEps() == NULL){
        arrayClaves[5] = "";
    } else{
        arrayClaves[5] = aux.getSigEps()->getNumId();
    }

}

 ListaPersona *Simulacion::getListaPersonas()  {
    return &listaPersonas;
}

#endif //PROYECTOCIENCIAS_CLASESIMULACION_H
