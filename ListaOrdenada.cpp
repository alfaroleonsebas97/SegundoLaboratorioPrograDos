/* 
 * File:   Digrafo.cpp
 * Author: Alan
 * 
 * Created on 1 de setiembre de 2017, 12:25 PM
 */

#include "ListaOrdenada.h"

ListaOrdenada::ListaOrdenada() : inicio(nullptr) {
    cntAdy = 0;                                                             //inicialización de variables.
}

ListaOrdenada::ListaOrdenada(const ListaOrdenada& orig) {                   //crea una copia de la original
    shared_ptr<Nodo> p = orig.inicio;                                       //puntero p se iguala al inicio original.
    if (p == nullptr) {                                                     //si p el nulo, inicio de la copia apunta a nulo.
        inicio = nullptr;
    } else {                                                                //sino,
        inicio = shared_ptr<Nodo>(new Nodo(orig.inicio->pos));              //agrega nuevo un nodo.
        p = p->sgt;                                                         //mueve p al siguiente
        shared_ptr<Nodo> ultimo = inicio;                                   //puntero último es igual a inicio
        while (p != nullptr) {                                              //mientras p no apunte a nulo, agregue el siguiente nodo.
            ultimo->sgt = shared_ptr<Nodo>(new Nodo(p->pos));
            p = p->sgt;
            ultimo = ultimo->sgt;
        }
    }
}

ListaOrdenada::~ListaOrdenada() {
}

void ListaOrdenada::agregar(int nPos) {
    bool rsl = false;
    shared_ptr<Nodo> p = inicio;
    shared_ptr<Nodo> ant = nullptr;
    if (inicio == nullptr) {                                                //si no ha agregado, agrega al principio y aumenta CntAdy.
        inicio = shared_ptr<Nodo>(new Nodo(nPos));
        cntAdy++;
    } else {                                                                //sino,
        if (inicio->pos > nPos) {                                           //si el elemento a agregar es menor que el primero, lo agrega al principio
            p = shared_ptr<Nodo>(new Nodo(nPos));
            cntAdy++;
            p->sgt = inicio;
            inicio = p;
            rsl = true;
        } else {                                                            //sino, lo agrega en medio o al final.
            p = inicio;
            while (p != nullptr) {                                          //busca dónde agregar, mientras no haya llegado al final.
                if (p->pos == nPos) {
                    p = nullptr;
                } else {
                    if (p->pos < nPos) {
                        ant = p;
                        p = p->sgt;
                        if (p == nullptr) {
                            rsl = true;
                        }
                    } else {
                        p = nullptr;
                        rsl = true;
                    }
                }
            }
            if (rsl) {                                                      //agrega si rsl = true.
                p = ant->sgt;
                ant->sgt = shared_ptr<Nodo>(new Nodo(nPos));
                cntAdy++;
                ant->sgt->sgt = p;
            }
        }
    }
}

bool ListaOrdenada::buscar(int nPos) {
    bool rsl = false;
    shared_ptr<Nodo> p = inicio;
    while (p != nullptr) {                                                  //mientras no haya llegado al final, busca nPos
        if (p->pos == nPos) {                                               //pregunta que si lo encontró.
            rsl = true;                                                     //devuelve true
            p = nullptr;
        } else {                                                            //sino, sigue avanzando.
            if (p->pos < nPos) {
                p = p->sgt;
            } else {
                p = nullptr;
            }
        }
    }
    return rsl;
}

string ListaOrdenada::toString() {
    stringstream fs;                                                        //para imprimir la hilera.
    fs << '{';
    shared_ptr<Nodo> p = inicio;
    while (p != nullptr) {                                                  //hasta llegar al último, imprime el vértice, imprime una coma, y avanza al siguiente.
        fs << p->pos;
        if (p->sgt != nullptr) {
            fs << ',';
            p = p->sgt;
        } else {
            p = nullptr;
        }
    }
    fs << '}';
    return fs.str();
}

int* ListaOrdenada::adyacencias() {
    int* arreglo = new int[cntAdy];                                         //arreglo de Adyacencias
    shared_ptr<Nodo> p = inicio;                                            //puntero p.
    if (p == nullptr) {                                                     //si p es nulo, entonces el arreglo se devuelve vacío.
        arreglo = nullptr;
    } else {                                                                //sin, agrega en el arreglo todos los vértices de la lista.
        int k = 0;
        while (p != nullptr) {
            arreglo[k] = p->pos;
            p = p->sgt;
            k++;
        }
    }
    return arreglo;
}

int ListaOrdenada::cantidadAdy() {
    return cntAdy;                                                          //retorna cantidad de adyacencias.
}
