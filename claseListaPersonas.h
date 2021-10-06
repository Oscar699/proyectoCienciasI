//
// Created by mile on 24/09/21.
//
#include "clasePersona.h"
#include <string>
#include "listaSimple.h"
#include "claseEPS.h"
#include "pila.h"

using namespace std;

#ifndef PROYECTOCIENCIAS_CLASELISTAPERSONAS_H
#define PROYECTOCIENCIAS_CLASELISTAPERSONAS_H

//Creación de estructuras base

struct nodoP {
    string clave;
    Persona *persona;
};

struct nodoCiudadListaP {
    string nombreCiudad;
    int clave;
    Persona *persona;
};

struct nodoEps {
    claseEPS *eps;
    Persona *persona;
};

//Definición de la clase

class ListaPersona {
    ArbolRN<Persona> personas;
    Persona *cabeceraSexo[2]; // 0 ->M  1-> F
    Persona *cabeceraEdad[8];
    Persona *cabeceraActividad[5];
    nodoEps *cabeceraEPS[20];
    Lista<nodoP> cabeceraPais;
    Lista<nodoCiudadListaP> cabeceraCiudadRes;
    int poscabEPS;


public:
    ListaPersona() {
        poscabEPS = 0;
        for (int i = 0; i < 2; i++) {
            cabeceraSexo[i] = NULL;
        }
        for (int i = 0; i < 8; i++) {
            cabeceraEdad[i] = NULL;
        }
        for (int i = 0; i < 5; ++i) {
            cabeceraActividad[i] = NULL;
        }
        for (int i = 0; i < 20; i++) {
            cabeceraEPS[i] = NULL;
        }
    }

    void agregarEPS(claseEPS *eps);

    void agregarPais(string nombrePais);

    void agregarCiudadRes(int clave, string nombreCiudad);

    void quitarIPS();

    void agregarPersona(Persona p);

    void eliminarPersona(Persona p);

    void imprimirCabeceras();

    void calculoConsulta1(string nombreEPS);

    void calculoConsulta2(string pais);

    void calculoConsulta3(int clave);

    void calculoConsulta4(int numAfiliados);

    void calculoConsulta5();

    void calculoConsulta6(int rangoEdad, string actividadLaboral);

    void calculoConsulta7(int rangoEdad, string eps);

    void calculoConsulta8(int lab, string eps);

    void calculoConsulta9(fecha f);

    Persona *obtenerPersona(string clave) {
        return personas.obtenerInfo(clave);
    }

    claseEPS *obtenerEPS(string nombreEPS) {
        for (int i = 0; i < poscabEPS; i++) {
            if (nombreEPS == cabeceraEPS[i]->eps->getNombre()) {
                return cabeceraEPS[i]->eps;
            }
        }
    }

};

void ListaPersona::calculoConsulta1(string nombreEPS) {
    int contPersonas = 0;
    for (int i = 0; i < 8; i++) {
        Persona *aux = cabeceraEdad[i];
        while (aux != NULL) {
            if (aux->getNombreEps() == nombreEPS) {
                contPersonas++;
            }
            aux = aux->getSigEdad();
        }
        if (i == 0) {
            cout << "Menos de 20 años: " << contPersonas << endl;
            contPersonas = 0;
        } else if (i == 1) {
            cout << "Entre 20 y 30 años: " << contPersonas << endl;
            contPersonas = 0;
        } else if (i == 2) {
            cout << "Entre 30 y 40 años: " << contPersonas << endl;
            contPersonas = 0;
        } else if (i == 3) {
            cout << "Entre 40 y 50 años: " << contPersonas << endl;
            contPersonas = 0;
        } else if (i == 4) {
            cout << "Entre 50 y 60 años: " << contPersonas << endl;
            contPersonas = 0;
        } else if (i == 5) {
            cout << "Entre 60 y 70 años: " << contPersonas << endl;
            contPersonas = 0;
        } else if (i == 6) {
            cout << "Entre 70 y 80 años: " << contPersonas << endl;
            contPersonas = 0;
        } else if (i == 7) {
            cout << "Mas de 80 años: " << contPersonas << endl;
            contPersonas = 0;
        }
    }
}

void ListaPersona::calculoConsulta2(string pais) {
    cout << "Nombre\tApellido\tCiudad\tEps" << endl;
    for (int i = 0; i < cabeceraPais.lista_size(); ++i) {
        Persona *aux = cabeceraPais.obtenerDato(i)->persona;
        while (aux != NULL) {
            if (cabeceraPais.obtenerDato(i)->clave == pais) {
                cout << aux->getNombre() << "\t" << aux->getApellido() << "\t\t" << aux->getCiudadRes() <<
                     "\t" << aux->getNombreEps() << endl;
            }
            aux = aux->getSigPaisNac();
        }


    }
}

void ListaPersona::calculoConsulta3(int clave) {
    cout << "Nombre\tApellido\tEPS\tActividad Laboral" << endl;
    for (int i = 0; i < cabeceraCiudadRes.lista_size(); i++) {
        Persona *aux = cabeceraCiudadRes.obtenerDato(i)->persona;
        while (aux != NULL) {
            if (cabeceraCiudadRes.obtenerDato(i)->clave == clave) {
                cout << aux->getNombre() << "\t" << aux->getApellido() << "\t\t" << aux->getNombreEps() << "\t"
                     << aux->getActivLab() << endl;
            }
            aux = aux->getSigCiudadRes();
        }
    }
}

void ListaPersona::calculoConsulta4(int numAfiliados) {
    pila<int> cont;
    pila<int> num_ips;
    pila<int> num_ciu;
    pila<string> nombres_ips;
    pila<string> nombres_ciudad;
    pila<claseEPS *> nombres_eps;
    int cont_eps = 0;
    nodoEps *nodo_eps;
    for (int i = 0; i < poscabEPS; ++i) {
        int cont_num_ciu = 0;
        nodo_eps = cabeceraEPS[i];
        claseEPS *eps = nodo_eps->eps;
        nodoIps nodo_ips;
        if (eps->getNumAfiliados() >= numAfiliados) {
            cont_eps++;
            ArbolRN<registroAfiliado> *arbol = eps->getArbolAfiliados();
            for (int j = 0; j < eps->getPoscabCiudad(); ++j) {
                cont_num_ciu++;
                int cont_ciudad = 0;
                if (eps->getCabeceraCiudad()[j].posIPS == -1) {
                    cont.Push(cont_ciudad);
                    nombres_ciudad.Push(eps->getCabeceraCiudad()[j].nombreCiudad);
                    num_ips.Push(0);
                    continue;
                }
                nodo_ips = eps->getCabeceraIps()[eps->getCabeceraCiudad()[j].posIPS];
                int cont_ips = 0;
                while (nodo_ips.ips != NULL) {
                    cont_ips++;
                    cont_ciudad = cont_ciudad + nodo_ips.ips->getNumAfiliados();
                    cont.Push(nodo_ips.ips->getNumAfiliados());
                    nombres_ips.Push(nodo_ips.ips->getNombre());
                    if (nodo_ips.sigCiudad == -1) break;
                    nodo_ips = eps->getCabeceraIps()[nodo_ips.sigCiudad];
                }
                cont.Push(cont_ciudad);
                num_ips.Push(cont_ips);
                nombres_ciudad.Push(eps->getCabeceraCiudad()[j].nombreCiudad);
            }
            num_ciu.Push(cont_num_ciu);
            nombres_eps.Push(eps);
        }

    }
    cout << "# EPS's: " << cont_eps << endl;
    while (!nombres_eps.PilaVacia()) {
        claseEPS *aux_eps = nombres_eps.Pop();
        cout << aux_eps->getNombre() << ":" << aux_eps->getNumAfiliados() << endl;
        int lim_ciu = num_ciu.Pop();
        for (int j = 0; j < lim_ciu; ++j) {
            cout << "\t" << nombres_ciudad.Pop() << ":" << cont.Pop() << endl;
            int lim = num_ips.Pop();
            for (int i = 0; i < lim; ++i) {
                cout << "\t\t" << nombres_ips.Pop() << ":" << cont.Pop() << endl;
            }
        }
    }
}

void ListaPersona::calculoConsulta5() {
    for (int i = 0; i < poscabEPS; ++i) {
        nodoEps *nodo_eps = cabeceraEPS[i];
        claseEPS *eps = nodo_eps->eps;
        ArbolRN<registroAfiliado> *arbol = eps->getArbolAfiliados();
        pila<Persona *> mujeres;
        pila<Persona *> hombres;
        pila<int> eps_conteo_hombres;
        pila<int> eps_conteo_mujeres;
        pila<int> ciu_ips;
        pila<string> ips_nombres;
        pila<string> ciu_nombres;
        pila<string> eps_nombres;
        nodoIps nodo_ips;
        int num_hombres = 0;
        int num_mujeres = 0;
        for (int j = 0; j < eps->getPoscabCiudad(); ++j) {
            int contadorCiudadM = 0;
            int contadorCiudadH = 0;
            int cont_num_ips = 0;
            if (eps->getCabeceraCiudad()[j].posIPS == -1) {
                eps_conteo_hombres.Push(contadorCiudadH);
                eps_conteo_mujeres.Push(contadorCiudadM);
                ciu_nombres.Push(eps->getCabeceraCiudad()[j].nombreCiudad);
                ciu_ips.Push(0);
                break;
            }
            nodo_ips = eps->getCabeceraIps()[eps->getCabeceraCiudad()[j].posIPS];
            while (nodo_ips.ips != NULL) {
                int contadorIpsM = 0;
                int contadorIpsH = 0;
                registroAfiliado *aux = arbol->obtenerInfo(nodo_ips.claveAfiliado);
                while (aux != NULL) {
                    if (aux->persona->getSexo() == 'M' && aux->estado == "V") {
                        hombres.Push(aux->persona);
                    } else if (aux->persona->getSexo() == 'F' && aux->estado == "V") {
                        mujeres.Push(aux->persona);
                    }
                    aux = arbol->obtenerInfo(aux->sigIPS);
                }
                while (!hombres.PilaVacia()) {
                    num_hombres++;
                    contadorIpsH++;
                    contadorCiudadH++;
                    hombres.Pop();
                }
                while (!mujeres.PilaVacia()) {
                    num_mujeres++;
                    contadorIpsM++;
                    contadorCiudadM++;
                    mujeres.Pop();
                }
                cont_num_ips++;
                eps_conteo_hombres.Push(contadorIpsH);
                eps_conteo_mujeres.Push(contadorIpsM);
                ciu_ips.Push(cont_num_ips);
                ips_nombres.Push(nodo_ips.ips->getNombre());
                if (nodo_ips.sigCiudad == -1) break;
                nodo_ips = eps->getCabeceraIps()[nodo_ips.sigCiudad];

            }
            eps_conteo_hombres.Push(contadorCiudadH);
            eps_conteo_mujeres.Push(contadorCiudadM);
            ciu_nombres.Push(eps->getCabeceraCiudad()[j].nombreCiudad);
        }
        eps_nombres.Push(eps->getNombre());
        cout << "Hombres: " << num_hombres << endl;
        cout << "Mujeres: " << num_mujeres << endl;
        while (!eps_nombres.PilaVacia()) {
            cout << "\tEps: " << eps_nombres.Pop() << endl;
            while (!ciu_nombres.PilaVacia()) {
                cout << "\t\t" << ciu_nombres.Pop() << ":" << endl;
                cout << "\t\t\t" << "Hombres: " << eps_conteo_hombres.Pop() << endl;
                cout << "\t\t\t" << "Mujeres: " << eps_conteo_mujeres.Pop() << endl;

                int lim = ciu_ips.Pop();
                for (int j = 0; j < lim; ++j) {
                    if (ips_nombres.PilaVacia()) break;
                    cout << "\t\t\t" << ips_nombres.Pop() << ":" << endl;
                    cout << "\t\t\t\t" << "Hombres: " << eps_conteo_hombres.Pop() << endl;
                    cout << "\t\t\t\t" << "Mujeres: " << eps_conteo_mujeres.Pop() << endl;
                }


            }
        }
        num_hombres = 0;
        num_mujeres = 0;
    }
}

void ListaPersona::calculoConsulta6(int rangoEdad, string actividadLaboral) {
    cout << "Nombre\tApellido\tEPS\tCiudad" << endl;

    Persona *aux = cabeceraEdad[rangoEdad];

    while (aux->getSigEdad() != NULL) {
        if (aux->getActivLab() == actividadLaboral) {
            cout << aux->getNombre() << "\t" << aux->getApellido() << "\t\t" << aux->getNombreEps() << "\t"
                 << aux->getCiudadRes() << endl;
        }
        aux = aux->getSigEdad();
    }


}

void ListaPersona::calculoConsulta7(int rangoEdad, string eps) {

    Persona *aux = cabeceraEdad[rangoEdad];
    cout << "Nombre\tApellido\tIPS\tCiudad" << endl;
    while (aux != NULL) {
        if (aux->getNombreEps() == eps) {
            for (int j = 0; j < poscabEPS; ++j) {
                nodoEps *nodo_eps = cabeceraEPS[j];
                if (nodo_eps->eps->getNombre() == eps) {
                    ArbolRN<registroAfiliado> *arbol = nodo_eps->eps->getArbolAfiliados();
                    registroAfiliado *registro = arbol->obtenerInfo(aux->getNumId());
                    if (registro->estado == "PD") {
                        cout << aux->getNombre() << "\t" << aux->getApellido() << "\t\t" << registro->ips->getNombre()
                             << "\t" << aux->getCiudadRes() << endl;
                    }
                }

            }
        }
        aux = aux->getSigEdad();
    }
}

void ListaPersona::calculoConsulta8(int lab, string eps) {
    nodoEps *nodo_eps;
    for (int i = 0; i < poscabEPS; ++i) {
        nodo_eps = cabeceraEPS[i];
        if (nodo_eps->eps->getNombre() == eps) break;
    }
    claseEPS *eps_aux = nodo_eps->eps;

    cout << "Nombre\tApellido\tEdad\tIPS\tCiudad" << endl;
    ArbolRN<registroAfiliado> *arbol = eps_aux->getArbolAfiliados();
    nodoVacEps nodo_lab = eps_aux->getListaVacunas()[lab];
    registroAfiliado *registro = arbol->obtenerInfo(nodo_lab.claveAfiliado);
    while (registro != NULL) {
        if (registro->estado == "CS" || registro->estado == "V") {
            cout << registro->persona->getNombre() << "\t" << registro->persona->getApellido() << "\t\t"
                 << registro->persona->getEdad()
                 << "\t\t" << registro->ips->getNombre() << "\t" << registro->persona->getCiudadRes() << endl;
        }
        registro = arbol->obtenerInfo(registro->sigLab);
    }
}

/*void ListaPersona::calculoConsulta9(fecha f) {
    pila<int *> conteo_lab, conteo_aux;
    pila<string> nombre_ips, nombre_ips_aux, nombre_ciudad, nombre_ciudad_aux, nombre_eps;
    pila<int> num_ips, num_ips_aux, num_ciudades, num_ciudades_aux, cont_pacientes_ciu,
    cont_pacientes_ips, cont;
    int contador_ips;
    for (int i = 0; i < poscabEPS; ++i) {
        nodoEps *nodo_eps = cabeceraEPS[i];
        claseEPS *eps_aux = nodo_eps->eps;
        for (int j = 0; j < eps_aux->getPoscabCiudad(); ++j) {
            ArbolRN<registroAfiliado> *arbol = eps_aux->getArbolAfiliados();
            nodoCiudad ciudad = eps_aux->getCabeceraCiudad()[j];
            if (ciudad.posIPS == -1) {
                nombre_ciudad.Push(ciudad.nombreCiudad);
                num_ips.Push(0);
                continue;
            } else {
                nodoIps nodo_ips = eps_aux->getCabeceraIps()[ciudad.posIPS];
                contador_ips = 0;
                while (nodo_ips.ips != NULL) {
                    registroAfiliado *registro = arbol->obtenerInfo(nodo_ips.claveAfiliado);
                    contador_ips++;
                    int conteo[6] = {0, 0, 0, 0, 0, 0};
                    while (registro != NULL) {
                        if (eps_aux->verificarFechasIguales(registro->fechaDosis, f)) {
                            conteo[registro->posLab]++;
                        }
                        registro = arbol->obtenerInfo(registro->sigIPS);
                    }
                    conteo_lab.Push(conteo);
                    nombre_ips.Push(nodo_ips.ips->getNombre());
                    if (nodo_ips.sigCiudad == -1) break;
                    nodo_ips = eps_aux->getCabeceraIps()[nodo_ips.sigCiudad];
                }
                num_ips.Push(contador_ips);
                nombre_ciudad.Push(ciudad.nombreCiudad);
            }
            num_ciudades.Push(eps_aux->getPoscabCiudad());
            nombre_ciudad.Push(eps_aux->getNombre());
        }
    }
    for (int i = 0; i < 6; ++i) {
        while ()
    }
}
*/
void ListaPersona::agregarPais(string nombrePais) {
    nodoP *aux = new nodoP;
    aux->clave = nombrePais;
    aux->persona = NULL;
    cabeceraPais.insertar_inicio(*aux);
}

void ListaPersona::agregarCiudadRes(int clave, string nombreCiudad) {
    nodoCiudadListaP *aux = new nodoCiudadListaP;
    aux->clave = clave;
    aux->nombreCiudad = nombreCiudad;
    aux->persona = NULL;
    cabeceraCiudadRes.insertar_inicio(*aux);
}

void ListaPersona::agregarEPS(claseEPS *eps) {
    nodoEps *nuevo = new nodoEps;
    nuevo->eps = eps;
    nuevo->persona = NULL;
    cabeceraEPS[poscabEPS] = nuevo;
    if (poscabEPS < 20)
        poscabEPS++;
}

void ListaPersona::quitarIPS() {
    if (poscabEPS > 0)
        poscabEPS--;
}

void ListaPersona::agregarPersona(Persona per) {
    Persona *aux;
    nodoEps *nodoEps;
    nodoP *nodo;

    per.setSigActivLab(NULL);
    per.setSigCiudadRes(NULL);
    per.setSigEdad(NULL);
    per.setSigEps(NULL);
    per.setSigPaisNac(NULL);
    per.setSigSexo(NULL);
    personas.insertarNodo(per.getNumId(), per);

    Persona *p = personas.obtenerInfo(per.getNumId());

    if (p->getSexo() == 'M') {
        if (cabeceraSexo[0] == NULL) {
            cabeceraSexo[0] = p;
        } else {
            aux = cabeceraSexo[0];
            while (aux->getSigSexo() != NULL) {
                aux = aux->getSigSexo();
            }
            aux->setSigSexo(p);
        }

    } else {
        if (cabeceraSexo[1] == NULL) {
            cabeceraSexo[1] = p;
        } else {
            aux = cabeceraSexo[1];
            while (aux->getSigSexo() != NULL) {
                aux = aux->getSigSexo();
            }
            aux->setSigSexo(p);
        }
    }

    if (p->getEdad() < 20) {
        if (cabeceraEdad[0] == NULL) {
            cabeceraEdad[0] = p;
        } else {
            aux = cabeceraEdad[0];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }
    } else if (p->getEdad() >= 20 && p->getEdad() < 30) {
        if (cabeceraEdad[1] == NULL) {
            cabeceraEdad[1] = p;
        } else {
            aux = cabeceraEdad[1];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }
    } else if (p->getEdad() >= 30 && p->getEdad() < 40) {
        if (cabeceraEdad[2] == NULL) {
            cabeceraEdad[2] = p;
        } else {
            aux = cabeceraEdad[2];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }
    } else if (p->getEdad() >= 40 && p->getEdad() < 50) {
        if (cabeceraEdad[3] == NULL) {
            cabeceraEdad[3] = p;
        } else {
            aux = cabeceraEdad[3];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }

    } else if (p->getEdad() >= 50 && p->getEdad() < 60) {
        if (cabeceraEdad[4] == NULL) {
            cabeceraEdad[4] = p;
        } else {
            aux = cabeceraEdad[4];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }

    } else if (p->getEdad() >= 60 && p->getEdad() < 70) {
        if (cabeceraEdad[5] == NULL) {
            cabeceraEdad[5] = p;
        } else {
            aux = cabeceraEdad[5];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }
    } else if (p->getEdad() >= 70 && p->getEdad() < 80) {
        if (cabeceraEdad[6] == NULL) {
            cabeceraEdad[6] = p;
        } else {
            aux = cabeceraEdad[6];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }
    } else {
        if (cabeceraEdad[7] == NULL) {
            cabeceraEdad[7] = p;
        } else {
            aux = cabeceraEdad[7];
            while (aux->getSigEdad() != NULL) {
                aux = aux->getSigEdad();
            }
            aux->setSigEdad(p);
        }

    }

    if (p->getActivLab() == "ARTES") {
        if (cabeceraActividad[0] == NULL) {
            cabeceraActividad[0] = p;
        } else {
            aux = cabeceraActividad[0];
            while (aux->getSigActivLab() != NULL) {
                aux = aux->getSigActivLab();
            }
            aux->setSigActivLab(p);
        }
    } else if (p->getActivLab() == "TECNICO") {
        if (cabeceraActividad[1] == NULL) {
            cabeceraActividad[1] = p;
        } else {
            aux = cabeceraActividad[1];
            while (aux->getSigActivLab() != NULL) {
                aux = aux->getSigActivLab();
            }
            aux->setSigActivLab(p);
        }
    } else if (p->getActivLab() == "INGENIERO") {
        if (cabeceraActividad[2] == NULL) {
            cabeceraActividad[2] = p;
        } else {
            aux = cabeceraActividad[2];
            while (aux->getSigActivLab() != NULL) {
                aux = aux->getSigActivLab();
            }
            aux->setSigActivLab(p);
        }
    } else if (p->getActivLab() == "SOCIALES") {
        if (cabeceraActividad[3] == NULL) {
            cabeceraActividad[3] = p;
        } else {
            aux = cabeceraActividad[3];
            while (aux->getSigActivLab() != NULL) {
                aux = aux->getSigActivLab();
            }
            aux->setSigActivLab(p);
        }
    } else if (p->getActivLab() == "FILOSOFIA") {
        if (cabeceraActividad[4] == NULL) {
            cabeceraActividad[4] = p;
        } else {
            aux = cabeceraActividad[4];
            while (aux->getSigActivLab() != NULL) {
                aux = aux->getSigActivLab();
            }
            aux->setSigActivLab(p);
        }
    }

    for (int i = 0; i < cabeceraPais.lista_size(); ++i) {
        nodo = cabeceraPais.obtenerDato(i);
        if (p->getPaisNac() == nodo->clave) {
            if (nodo->persona == NULL) {
                nodo->persona = p;
                cabeceraPais.modificar(*nodo, i);
            } else {
                aux = nodo->persona;
                while (aux->getSigPaisNac() != NULL) {
                    aux = aux->getSigPaisNac();
                }
                aux->setSigPaisNac(p);
            }
        }

    }

    for (int i = 0; i < cabeceraCiudadRes.lista_size(); ++i) {
        nodoCiudadListaP *nodo = cabeceraCiudadRes.obtenerDato(i);
        if (p->getCiudadRes() == nodo->nombreCiudad) {
            if (nodo->persona == NULL) {
                nodo->persona = p;
                cabeceraCiudadRes.modificar(*nodo, i);
            } else {
                aux = nodo->persona;
                while (aux->getSigCiudadRes() != NULL) {
                    aux = aux->getSigCiudadRes();
                }
                aux->setSigCiudadRes(p);
            }
        }
    }

    for (int i = 0; i < poscabEPS; ++i) {
        nodoEps = cabeceraEPS[i];
        if (p->getNombreEps() == nodoEps->eps->getNombre()) {
            if (nodoEps->persona == NULL) {
                nodoEps->persona = p;
            } else {
                aux = nodoEps->persona;
                while (aux->getSigEps() != NULL) {
                    aux = aux->getSigEps();
                }
                aux->setSigEps(p);
            }
        }

    }
    /*delete aux;
    delete nodo;
    delete nodoEps;*/
}

void ListaPersona::eliminarPersona(Persona persona) {
    Persona *aux1;
    Persona *aux2;
    Persona *p = &persona;
    if (p->getSexo() == 'M') { //Borrado en Cabecera Sexo
        if (cabeceraSexo[0] == p) {
            cabeceraSexo[0] = p->getSigSexo();
            delete p;
        } else {
            aux1 = cabeceraSexo[0];
            aux2 = aux1->getSigEdad();

            while (aux2->getSigSexo() != NULL) {
                if (aux2 == p)
                    break;
                aux1 = aux2;
                aux2 = aux2->getSigSexo();
            }

            if (aux2->getSigSexo() == NULL) {
                aux1->setSigSexo(NULL);
                delete p;
            } else {
                aux1->setSigSexo(aux2->getSigSexo());
                delete p;
            }
        }

    } else { //Borrado en Cabecera Sexo
        if (cabeceraSexo[1] == p) {
            cabeceraSexo[1] = p->getSigSexo();
            delete p;
        } else {
            aux1 = cabeceraSexo[1];
            aux2 = aux1->getSigEdad();

            while (aux2->getSigSexo() != NULL) {
                if (aux2 == p)
                    break;
                aux1 = aux1->getSigSexo();
                aux2 = aux2->getSigSexo();
            }

            if (aux2->getSigSexo() == NULL) {
                aux1->setSigSexo(NULL);
                delete p;
            } else {
                aux1->setSigSexo(aux2->getSigSexo());
                delete p;
            }

        }

    }
    if (p->getEdad() < 20) { //Borrado en Cabecera Edad
        if (cabeceraEdad[0] == p) {
            cabeceraEdad[0] = p->getSigEdad();
            delete p;
        } else {
            aux1 = cabeceraEdad[0];
            aux2 = aux1->getSigEdad();

            while (aux2->getSigEdad() != NULL) {
                if (aux2 == p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if (aux2->getSigEdad() == NULL) {
                aux1->setSigEdad(NULL);
                delete p;
            } else {
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    } else if (p->getEdad() >= 20 && p->getEdad() < 30) { //Borrado en Cabecera Edad
        if (cabeceraEdad[1] == p) {
            cabeceraEdad[1] = p->getSigEdad();
            delete p;
        } else {
            aux1 = cabeceraEdad[1];
            aux2 = aux1->getSigEdad();

            while (aux2->getSigEdad() != NULL) {
                if (aux2 == p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if (aux2->getSigEdad() == NULL) {
                aux1->setSigEdad(NULL);
                delete p;
            } else {
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    } else if (p->getEdad() >= 30 && p->getEdad() < 40) { //Borrado en Cabecera Edad
        if (cabeceraEdad[2] == p) {
            cabeceraEdad[2] = p->getSigEdad();
            delete p;
        } else {
            aux1 = cabeceraEdad[2];
            aux2 = aux1->getSigEdad();

            while (aux2->getSigEdad() != NULL) {
                if (aux2 == p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if (aux2->getSigEdad() == NULL) {
                aux1->setSigEdad(NULL);
                delete p;
            } else {
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    } else if (p->getEdad() >= 40 && p->getEdad() < 50) { //Borrado en Cabecera Edad
        if (cabeceraEdad[3] == p) {
            cabeceraEdad[3] = p->getSigEdad();
            delete p;
        } else {
            aux1 = cabeceraEdad[3];
            aux2 = aux1->getSigEdad();

            while (aux2->getSigEdad() != NULL) {
                if (aux2 == p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if (aux2->getSigEdad() == NULL) {
                aux1->setSigEdad(NULL);
                delete p;
            } else {
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    } else if (p->getEdad() >= 50 && p->getEdad() < 60) { //Borrado en Cabecera Edad
        if (cabeceraEdad[4] == p) {
            cabeceraEdad[4] = p->getSigEdad();
            delete p;
        } else {
            aux1 = cabeceraEdad[4];
            aux2 = aux1->getSigEdad();

            while (aux2->getSigEdad() != NULL) {
                if (aux2 == p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if (aux2->getSigEdad() == NULL) {
                aux1->setSigEdad(NULL);
                delete p;
            } else {
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    } else if (p->getEdad() >= 60 && p->getEdad() < 70) { //Borrado en Cabecera Edad
        if (cabeceraEdad[5] == p) {
            cabeceraEdad[5] = p->getSigEdad();
            delete p;
        } else {
            aux1 = cabeceraEdad[5];
            aux2 = aux1->getSigEdad();

            while (aux2->getSigEdad() != NULL) {
                if (aux2 == p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if (aux2->getSigEdad() == NULL) {
                aux1->setSigEdad(NULL);
                delete p;
            } else {
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    } else if (p->getEdad() >= 70 && p->getEdad() < 80) { //Borrado en Cabecera Edad
        if (cabeceraEdad[6] == p) {
            cabeceraEdad[6] = p->getSigEdad();
            delete p;
        } else {
            aux1 = cabeceraEdad[6];
            aux2 = aux1->getSigEdad();

            while (aux2->getSigEdad() != NULL) {
                if (aux2 == p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if (aux2->getSigEdad() == NULL) {
                aux1->setSigEdad(NULL);
                delete p;
            } else {
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    } else { //Borrado en Cabecera Edad
        if (cabeceraEdad[7] == p) {
            cabeceraEdad[7] = p->getSigEdad();
            delete p;
        } else {
            aux1 = cabeceraEdad[7];
            aux2 = aux1->getSigEdad();

            while (aux2->getSigEdad() != NULL) {
                if (aux2 == p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigEdad();
                }
            }
            if (aux2->getSigEdad() == NULL) {
                aux1->setSigEdad(NULL);
                delete p;
            } else {
                aux1->setSigEdad(p->getSigEdad());
                delete p;
            }
        }
    }
    if (p->getActivLab() == "ARTES") { //Borrado en Cabecera ActLaboral
        if (cabeceraActividad[0] == p) {
            cabeceraActividad[0] = p->getSigActivLab();
            delete p;
        } else {
            aux1 = cabeceraActividad[0];
            aux2 = aux1->getSigActivLab();

            while (aux2->getSigActivLab() != NULL) {
                if (aux2 = p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigActivLab();
                }
            }
            if (aux2->getSigActivLab() == NULL) {
                aux1->setSigActivLab(NULL);
                delete p;
            } else {
                aux1->setSigActivLab(p->getSigActivLab());
                delete p;
            }
        }
    } else if (p->getActivLab() == "TECNICO") { //Borrado en Cabecera ActLaboral
        if (cabeceraActividad[1] == p) {
            cabeceraActividad[1] = p->getSigActivLab();
            delete p;
        } else {
            aux1 = cabeceraActividad[1];
            aux2 = aux1->getSigActivLab();

            while (aux2->getSigActivLab() != NULL) {
                if (aux2 = p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigActivLab();
                }
            }
            if (aux2->getSigActivLab() == NULL) {
                aux1->setSigActivLab(NULL);
                delete p;
            } else {
                aux1->setSigActivLab(p->getSigActivLab());
                delete p;
            }
        }
    } else if (p->getActivLab() == "INGENIERO") { //Borrado en Cabecera ActLaboral
        if (cabeceraActividad[2] == p) {
            cabeceraActividad[2] = p->getSigActivLab();
            delete p;
        } else {
            aux1 = cabeceraActividad[2];
            aux2 = aux1->getSigActivLab();

            while (aux2->getSigActivLab() != NULL) {
                if (aux2 = p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigActivLab();
                }
            }
            if (aux2->getSigActivLab() == NULL) {
                aux1->setSigActivLab(NULL);
                delete p;
            } else {
                aux1->setSigActivLab(p->getSigActivLab());
                delete p;
            }
        }
    } else if (p->getActivLab() == "SOCIALES") { //Borrado en Cabecera ActLaboral
        if (cabeceraActividad[3] == p) {
            cabeceraActividad[3] = p->getSigActivLab();
            delete p;
        } else {
            aux1 = cabeceraActividad[3];
            aux2 = aux1->getSigActivLab();

            while (aux2->getSigActivLab() != NULL) {
                if (aux2 = p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigActivLab();
                }
            }
            if (aux2->getSigActivLab() == NULL) {
                aux1->setSigActivLab(NULL);
                delete p;
            } else {
                aux1->setSigActivLab(p->getSigActivLab());
                delete p;
            }
        }
    } else if (p->getActivLab() == "FILOSOFIA") { //Borrado en Cabecera ActLaboral
        if (cabeceraActividad[4] == p) {
            cabeceraActividad[4] = p->getSigActivLab();
            delete p;
        } else {
            aux1 = cabeceraActividad[4];
            aux2 = aux1->getSigActivLab();

            while (aux2->getSigActivLab() != NULL) {
                if (aux2 = p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigActivLab();
                }
            }
            if (aux2->getSigActivLab() == NULL) {
                aux1->setSigActivLab(NULL);
                delete p;
            } else {
                aux1->setSigActivLab(p->getSigActivLab());
                delete p;
            }
        }
    }
    for (int i = 0; i < cabeceraPais.lista_size(); i++) {  //Borrado en Cabecera Pais
        nodoP *aux = cabeceraPais.obtenerDato(i);;
        if (aux->clave == p->getPaisNac()) {
            aux->persona = p->getSigPaisNac();
            cabeceraPais.modificar(*aux, i);
            delete p;
        } else {
            aux1 = aux->persona;
            aux2 = aux1->getSigPaisNac();

            while (aux2->getSigPaisNac() == NULL) {
                if (aux2 == p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigPaisNac();
                }
            }
            if (aux2->getSigPaisNac() == NULL) {
                aux1->setSigPaisNac(NULL);
                delete p;
            } else {
                aux1->setSigPaisNac(p->getSigPaisNac());
                delete p;
            }
        }
    }

    for (int i = 0; i < cabeceraCiudadRes.lista_size(); ++i) {
        nodoCiudadListaP *aux = cabeceraCiudadRes.obtenerDato(i);
        if (aux->nombreCiudad == p->getCiudadRes()) {
            aux->persona = p->getSigCiudadRes();
            cabeceraCiudadRes.modificar(*aux, i);
            delete p;
        } else {
            aux1 = aux->persona;
            aux2 = aux1->getSigCiudadRes();

            while (aux2->getSigCiudadRes() == NULL) {
                if (aux2 == p) {
                    break;
                } else {
                    aux1 = aux2;
                    aux2 = aux2->getSigCiudadRes();
                }
            }
            if (aux2->getSigCiudadRes() == NULL) {
                aux1->setSigCiudadRes(NULL);
                delete p;
            } else {
                aux1->setSigCiudadRes(p->getSigPaisNac());
                delete p;
            }
        }
    }

    for (int i = 0; i < poscabEPS; ++i) {
        nodoEps *eps = cabeceraEPS[i];
        if (eps->persona == p) {
            eps->persona = p->getSigEps();
            cabeceraEPS[i] = eps;
        } else {
            aux1 = eps->persona;
            aux2 = aux1->getSigEps();
            while (aux2->getSigEps() != NULL) {
                if (aux2 == p) {
                    break;
                }
                aux1 = aux2;
                aux2 = aux2->getSigEps();
            }
            if (aux2->getSigEps() == NULL) {
                aux1->setSigEps(NULL);
                delete p;
            } else {
                aux1->setSigEps(p->getSigEps());
                delete p;
            }
        }
    }
}

void ListaPersona::imprimirCabeceras() {
    cout << "Cabecera por sexo" << endl;
    Persona *aux;
    int cont = 1;
    for (int i = 0; i < 2; i++) {
        aux = cabeceraSexo[i];
        while (aux != NULL) {
            cout << cont++ << setw(10) << aux->getNombre() << setw(10) << aux->getSexo() << setw(10) << aux->getNumId()
                 << endl;
            aux = aux->getSigSexo();
        }
    }
    cout << "\nCabecera por Edad" << endl;
    cont = 1;
    for (int i = 0; i < 8; i++) {
        aux = cabeceraEdad[i];
        while (aux != NULL) {
            cout << cont++ << setw(10) << aux->getNombre() << setw(10) << aux->getEdad() << setw(10) << aux->getNumId()
                 << endl;
            aux = aux->getSigEdad();
        }
    }
    cout << "\nCabeza por Actividad Laboral" << endl;
    cont = 1;
    for (int i = 0; i < 5; i++) {
        aux = cabeceraActividad[i];
        while (aux != NULL) {
            cout << cont++ << setw(10) << aux->getNombre() << setw(10) << aux->getActivLab() << setw(10)
                 << aux->getNumId() << endl;
            aux = aux->getSigActivLab();
        }
    }

    cout << "\nCabecera por EPS" << endl;
    nodoEps *auxEps;
    int subCont;
    cont = 1;
    for (int i = 0; i < poscabEPS; i++) {
        auxEps = cabeceraEPS[i];
        cout << cont++ << setw(10) << auxEps->eps->getNombre() << setw(10) << auxEps->eps->getNumAfiliados() << endl;
        aux = auxEps->persona;
        subCont = 1;
        while (aux != NULL) {
            cout << subCont++ << setw(10) << aux->getNombre() << setw(10) << aux->getNumId() << endl;
            aux = aux->getSigEps();
        }

    }

}

#endif //PROYECTOCIENCIAS_CLASELISTAPERSONAS_H
