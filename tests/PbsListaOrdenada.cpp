/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PbsListaOrdenada.cpp
 * Author: alan.calderon
 *
 * Created on 9 de abril de 2018, 10:49 AM
 */

#include <stdlib.h>
#include <iostream>
#include "ListaOrdenada.h"

/*
 * Simple C++ Test Suite
 */

void testListaOrdenada() {
    ListaOrdenada listaOrdenada; // debe construir una lista vacÃ­a
    string rsl = listaOrdenada.toString();
    if (rsl != "{}") {
        std::cout << "FallÃ³ el constructor estÃ¡ndar" << std::endl;
    }
}

void testListaOrdenada2() {
    ListaOrdenada orig;
    ListaOrdenada listaOrdenada(orig);
    string rsl = listaOrdenada.toString();
    if (rsl != "{}") {
        std::cout << "FallÃ³ el constructor de copias al copiar {}" << std::endl;
    }
    
    orig.agregar(1);
    ListaOrdenada listaOrdenada1(orig);
    rsl = listaOrdenada1.toString();
    if (rsl != "{1}") {
        std::cout << "FallÃ³ el constructor de copias al copiar {1}" << std::endl;
    }
    
    orig.agregar(2);
    ListaOrdenada listaOrdenada2(orig);
    rsl = listaOrdenada2.toString();
    if (rsl != "{1,2}") {
        std::cout << "FallÃ³ el constructor de copias al copiar {1,2}" << std::endl;
    } 

    orig.agregar(3);
    ListaOrdenada listaOrdenada3(orig);
    rsl = listaOrdenada3.toString();
    if (rsl != "{1,2,3}") {
        std::cout << "FallÃ³ el constructor de copias al copiar {1,2,3}" << std::endl;
    }     
}

void testAgregar() {
    ListaOrdenada listaOrdenada;
    listaOrdenada.agregar(3);
    string rsl = listaOrdenada.toString();
    if (rsl != "{3}") {
        std::cout << "FallÃ³ al agregar 3 sobre {}" << std::endl;
    }
    
    listaOrdenada.agregar(7);
    rsl = listaOrdenada.toString();
    if (rsl != "{3,7}") {
        std::cout << "FallÃ³ al agregar 7 sobre {3}" << std::endl;
    }
    
    listaOrdenada.agregar(1);
    rsl = listaOrdenada.toString();
    if (rsl != "{1,3,7}") {
        std::cout << "FallÃ³ al agregar 1 sobre {3,7}" << std::endl;
    }   
    
    listaOrdenada.agregar(5);
    rsl = listaOrdenada.toString();
    if (rsl != "{1,3,5,7}") {
        std::cout << "FallÃ³ al agregar 5 sobre {1,3,7}" << std::endl;
    }    
}

void testBuscar() {
    ListaOrdenada listaOrdenada;
    
    bool rsl = listaOrdenada.buscar(1);
    if (rsl) {
        std::cout << "buscar(1) fallÃ³ sobre {}" << std::endl;
    }
    listaOrdenada.agregar(5);
    rsl = listaOrdenada.buscar(5);
    if (!rsl) {
        std::cout << "buscar(5) fallÃ³ sobre {5}" << std::endl;
    }    
    
    listaOrdenada.agregar(11);
    rsl = listaOrdenada.buscar(11);
    if (!rsl) {
        std::cout << "buscar(11) fallÃ³ sobre {5,11}" << std::endl;
    }
    
    listaOrdenada.agregar(8);
    rsl = listaOrdenada.buscar(8);
    if (!rsl) {
        std::cout << "buscar(8) fallÃ³ sobre {5,8,11}" << std::endl;
    }
    
    rsl = listaOrdenada.buscar(9);
    if (rsl) {
        std::cout << "buscar(9) fallÃ³ sobre {5,8,11}" << std::endl;
    }    
}

void testAdyacencias() {
    ListaOrdenada listaOrdenada;
    int* rsl = listaOrdenada.adyacencias();
    if (rsl != nullptr) {
        std::cout << "FallÃ³ adyacencias() sobre {}" << std::endl;
    }
    
    listaOrdenada.agregar(1);
    rsl = listaOrdenada.adyacencias();
    if (rsl[0] != 1)  {
        std::cout << "FallÃ³ adyacencias() sobre {1}" << std::endl;
    }
    
    listaOrdenada.agregar(5);
    listaOrdenada.agregar(11);
    rsl = listaOrdenada.adyacencias();
    if ((rsl[0] != 1)||(rsl[1] != 5)||(rsl[2] != 11))  {
        std::cout << "FallÃ³ adyacencias() sobre {1,5,11}" << std::endl;
    }
}

void testCantidadAdy() {
    ListaOrdenada listaOrdenada;
    int rsl = listaOrdenada.cantidadAdy();
    if (rsl != 0) {
        std::cout << "FallÃ³ cantidadAdy() con {}" << std::endl;
    }
    
    listaOrdenada.agregar(1);
    rsl = listaOrdenada.cantidadAdy();
    if (rsl != 1) {
        std::cout << "FallÃ³ cantidadAdy() con {1}" << std::endl;
    }
    
    listaOrdenada.agregar(5);
    listaOrdenada.agregar(11);
    rsl = listaOrdenada.cantidadAdy();
    if (rsl != 3) {
        std::cout << "FallÃ³ cantidadAdy() con {1,5,11}" << std::endl;
    }    
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% PbsListaOrdenada" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testListaOrdenada (PbsListaOrdenada)" << std::endl;
    testListaOrdenada();
    std::cout << "%TEST_FINISHED% time=0 testListaOrdenada (PbsListaOrdenada)" << std::endl;

    std::cout << "%TEST_STARTED% testAgregar (PbsListaOrdenada)" << std::endl;
    testAgregar();
    std::cout << "%TEST_FINISHED% time=0 testAgregar (PbsListaOrdenada)" << std::endl;
    
    std::cout << "%TEST_STARTED% testListaOrdenada2 (PbsListaOrdenada)" << std::endl;
    testListaOrdenada2();
    std::cout << "%TEST_FINISHED% time=0 testListaOrdenada2 (PbsListaOrdenada)" << std::endl;

    std::cout << "%TEST_STARTED% testBuscar (PbsListaOrdenada)" << std::endl;
    testBuscar();
    std::cout << "%TEST_FINISHED% time=0 testBuscar (PbsListaOrdenada)" << std::endl;

    std::cout << "%TEST_STARTED% testAdyacencias (PbsListaOrdenada)" << std::endl;
    testAdyacencias();
    std::cout << "%TEST_FINISHED% time=0 testAdyacencias (PbsListaOrdenada)" << std::endl;

    std::cout << "%TEST_STARTED% testCantidadAdy (PbsListaOrdenada)" << std::endl;
    testCantidadAdy();
    std::cout << "%TEST_FINISHED% time=0 testCantidadAdy (PbsListaOrdenada)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

