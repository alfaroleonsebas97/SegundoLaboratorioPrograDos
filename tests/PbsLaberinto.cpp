/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Laberinto.cpp
 * Author: alfar
 *
 * Created on 20 de abril de 2018, 07:13 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Laberinto.h"
#include <cstdlib>
#include <fstream>
#include <string>


void testLaberinto() {
    int cantidadVrts = 50;
    double probabilidadAdy = 0.7;
    probabilidadAdy = 0.16 + probabilidadAdy * (0.68); // MIN + P*(MAX-MIN):: MIN = 0.16,  MAX = 0.84
    Laberinto laberinto(cantidadVrts, probabilidadAdy);
    int totVrt = laberinto.obtTotVrt();
    int totAdy = laberinto.obtTotAdy();
    for (int i = 0; i < 50000; ++i) {
        Laberinto laberinto(cantidadVrts, probabilidadAdy);
        totAdy += laberinto.obtTotAdy();
    }
    double promedio = totAdy / 50000.0;
    double media = probabilidadAdy * 50 * (49); //p*n*(n-1), n = 50
    if (totVrt != 50) {
        std::cout << "%TEST_FAILED% time=0 testname=testLaberinto (Laberinto) message=La cantidad total no es igual a 50" << std::endl;
    }
    if (promedio < media - (15)) {
        std::cout << "%TEST_FAILED% time=0 testname=testLaberinto (Laberinto) message=El promedio está más abajo de la media esperada" << std::endl;
    }
    if (promedio > media + (15)) {
        std::cout << "%TEST_FAILED% time=0 testname=testLaberinto (Laberinto) message=El promedio está más arriba de la media esperada" << std::endl;
    }
}

void testLaberinto2() {
    ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        int cantidadDeVerticesEnElArchivo;
        string hileraActual;
        getline(archivo, hileraActual);
        cantidadDeVerticesEnElArchivo = stoi(hileraActual);
        int cantidadDeAdyacenciasPorVertice[10];
        int NumeroDeLinea = 0;
        while (getline(archivo, hileraActual)) {
            int contadorEspaciosEnBlanco = 0;
            int indiceDeLaHilera = 0;
            while (hileraActual[indiceDeLaHilera] != '\r') {
                if (hileraActual[indiceDeLaHilera] == ' ') {
                    contadorEspaciosEnBlanco++;
                }
                indiceDeLaHilera++;
            }
            cantidadDeAdyacenciasPorVertice[NumeroDeLinea] = contadorEspaciosEnBlanco;
            NumeroDeLinea++;
        }
        archivo.close();

        ifstream nuevoArchivo("laberintop.txt");
        if (nuevoArchivo.is_open()) {
            Laberinto laberinto(nuevoArchivo);
            if (cantidadDeVerticesEnElArchivo != laberinto.obtTotVrt()) {
                std::cout << "%TEST_FAILED% time=0 testname=testLaberinto2 (Laberinto) message=(Archivo Pequeño)Cantidad de vertices total no coincide." << std::endl;
            }
            for (int j = 0; j < 10; j++) {
                if (cantidadDeAdyacenciasPorVertice[j] != laberinto.obtCntAdy(j)) {
                    std::cout << "%TEST_FAILED% time=0 testname=testLaberinto2 (Laberinto) message=(Archivo Pequeño)La cantidad de adyacencias del vertice " << j << " no coincide." << std::endl;
                }
            }
            nuevoArchivo.close();
        }
    } else {
        cout << "No se pudo abrir el archivo de entrada" << endl;
    }



    ifstream archivo2("laberintom.txt");
    if (archivo2.is_open()) {
        int cantidadDeVerticesEnElArchivo2;
        string hileraActual2;
        getline(archivo2, hileraActual2);
        cantidadDeVerticesEnElArchivo2 = stoi(hileraActual2);
        int cantidadDeAdyacenciasPorVertice2[10];
        int NumeroDeLinea2 = 0;
        while (getline(archivo2, hileraActual2)) {
            int contadorEspaciosEnBlanco2 = 0;
            int indiceDeLaHilera2 = 0;
            while (hileraActual2[indiceDeLaHilera2] != '\r') {
                if (hileraActual2[indiceDeLaHilera2] == ' ') {
                    contadorEspaciosEnBlanco2++;
                }
                indiceDeLaHilera2++;
            }
            cantidadDeAdyacenciasPorVertice2[NumeroDeLinea2] = contadorEspaciosEnBlanco2;
            NumeroDeLinea2++;
        }
        archivo2.close();

        ifstream nuevoArchivo2("laberintom.txt");
        if (nuevoArchivo2.is_open()) {
            Laberinto laberinto2(nuevoArchivo2);
            if (cantidadDeVerticesEnElArchivo2 != laberinto2.obtTotVrt()) {
                std::cout << "%TEST_FAILED% time=0 testname=testaberinto2 (Laberinto) message=(Archivo Mediano)Cantidad de vertices total no coincide." << std::endl;
            }
            for (int j = 0; j < 10; j++) {
                if (cantidadDeAdyacenciasPorVertice2[j] != laberinto2.obtCntAdy(j)) {
                    std::cout << "%TEST_FAILED% time=0 testname=testLaberinto2 (Laberinto) message=(Archivo Mediano)La cantidad de adyacencias del vertice " << j << " no coincide." << std::endl;
                }
            }
            nuevoArchivo2.close();
        }
    } else {
        cout << "No se pudo abrir el archivo de entrada" << endl;
    }
}

void testLaberinto3() {
    ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        Laberinto laberintoOriginal(archivo);
        Laberinto laberintoCopia(laberintoOriginal);
        int cantidadDeVertices;
        cantidadDeVertices = laberintoCopia.obtTotVrt();
        if (cantidadDeVertices != 10) {
            std::cout << "%TEST_FAILED% time=0 testname=testLaberinto3 (Laberinto) message=la cantidad de vertices no coinciden" << std::endl;
        } else {
            for (int i = 0; i < 10; i++) {
                if (laberintoOriginal.obtCntAdy(i) != laberintoCopia.obtCntAdy(i)) {
                    std::cout << "%TEST_FAILED% time=0 testname=testLaberinto3 (Laberinto) message=la cantidad de adyacencias no coinciden en el vertice: " << i << std::endl;
                }
            }
        }
        archivo.close();
    }
}

void testCaminoMasCorto() {
    /*ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        int idVrtO = 9;
        int idVrtD = 5;
        int* camino;
        Laberinto laberinto(archivo);
        int result = laberinto.caminoMasCorto(idVrtO, idVrtD, camino);
        if (result != 1) {
            std::cout << "%TEST_FAILED% time=0 testname=testCaminoMasCorto (Laberinto) message=Falló el tamaño del camino más corto del vértice "<< idVrtO << " al " << idVrtD <<std::endl;
        }
        int caminoAProbar[] = {9,5};
        for(int i = 0; i < result + 1 ; i++){
            if ( camino[i] != caminoAProbar[i] ){
                std::cout << "%TEST_FAILED% time=0 testname=testCaminoMasCorto (Laberinto) message=falló el camino más corto en la segunda prueba"<<std::endl;
            }
        }
        delete camino;
        archivo.close();
    }
    
    ifstream archivo2("laberintop.txt");
    if (archivo2.is_open()) {
        int idVrtO = 9;
        int idVrtD = 0;
        int* camino2;
        Laberinto laberinto2(archivo2);
        int result2 = laberinto2.caminoMasCorto(idVrtO, idVrtD, camino2);
        if (result2 != 2) {
            std::cout << "%TEST_FAILED% time=0 testname=testCaminoMasCorto (Laberinto) message=Falló el tamaño del camino más corto del vértice "<< idVrtO << " al " << idVrtD <<std::endl;
        }
        int caminoAProbar[] = {9,5,0};
        for(int i = 0; i < result2 + 1 ; i++){
            if ( camino2[i] != caminoAProbar[i] ){
                std::cout << "%TEST_FAILED% time=0 testname=testCaminoMasCorto (Laberinto) message=falló el camino más corto en la segunda prueba"<<std::endl;
            }
        }
        delete camino2;
        archivo2.close();
    }
    
    ifstream archivo3("laberintop.txt");
    if (archivo3.is_open()) {
        int idVrtO = 3;
        int idVrtD = 1;
        int* camino3;
        Laberinto laberinto3(archivo3);
        int result3 = laberinto3.caminoMasCorto(idVrtO, idVrtD, camino3);
        if (result3 != 3) {
            std::cout << "%TEST_FAILED% time=0 testname=testCaminoMasCorto (Laberinto) message=Falló el tamaño del camino más corto del vértice "<< idVrtO << " al " << idVrtD <<std::endl;
        }
        int caminoAProbar[] = {3,8,2,1};
        for(int i = 0; i < result3 + 1 ; i++){
            if ( camino3[i] != caminoAProbar[i] ){
                std::cout << "%TEST_FAILED% time=0 testname=testCaminoMasCorto (Laberinto) message=falló el camino más corto en la tercera prueba"<<std::endl;
            }
        }
        delete camino3;
        archivo3.close();
    } */   
}

void testCaminoEncontrado() {
    /*
    ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        int idVrtO = 9;
        int idVrtD = 5;
        int* camino;
        Laberinto laberinto(archivo);
        int result = laberinto.caminoEncontrado(idVrtO, idVrtD, camino);
        if (result != 2) {
            std::cout << "%TEST_FAILED% time=0 testname=testCaminoMasCorto (Laberinto) message=Falló el tamaño del camino encontrado del vértice "<< idVrtO << " al " << idVrtD <<std::endl;
        }
        int caminoAProbar[] = {9,0};
        for(int i = 0; i < result + 1 ; i++){
            if ( camino[i] != caminoAProbar[i] ){
                std::cout << "%TEST_FAILED% time=0 testname=testCaminoMasCorto (Laberinto) message=falló el camino encontrado"<<std::endl;
            }
        }
        delete camino;
        archivo.close();
    }
    
    ifstream archivo2("laberintop.txt");
    if (archivo2.is_open()) {
        int idVrtO = 3;
        int idVrtD = 1;
        int* camino2;
        Laberinto laberinto2(archivo2);
        int result2 = laberinto2.caminoMasCorto(idVrtO, idVrtD, camino2);
        if (result2 != 3) {
            std::cout << "%TEST_FAILED% time=0 testname=testCaminoMasCorto (Laberinto) message=Falló el tamaño del camino encontrado del vértice "<< idVrtO << " al " << idVrtD <<std::endl;
        }
        int caminoAProbar[] = {3,8,2,1};
        for(int i = 0; i < result2 + 1 ; i++){
            if ( camino2[i] != caminoAProbar[i] ){
                std::cout << "%TEST_FAILED% time=0 testname=testCaminoMasCorto (Laberinto) message=falló el camino encontrado en la segunda prueba"<<std::endl;
            }
        }
        delete camino2;
        archivo2.close();
    }*/
}

void testSumaTotalFerormona() {
    /*ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        Laberinto laberinto(archivo);
        int cntVrts = laberinto.obtTotVrt();
        int cntAdy;
        Adyacencia ady(1.0, 0.0);
        int* vectorAdyacenciasDeCadaVerice;
        for (int verticeOrigen = 0; verticeOrigen < cntVrts; verticeOrigen++) {
            cntAdy = laberinto.obtCntAdy(verticeOrigen);
            laberinto.obtIdVrtAdys(verticeOrigen, vectorAdyacenciasDeCadaVerice);
            for (int verticeDestino = 0; verticeDestino < cntAdy; verticeDestino++) {
                laberinto.asgDatoAdy(verticeOrigen, vectorAdyacenciasDeCadaVerice[verticeDestino], ady);
            }
        }
        archivo.close();
        if (laberinto.sumaTotalFerormona() != laberinto.obtTotAdy()) {
            std::cout << "%TEST_FAILED% time=0 testname=testSumaTotalFerormona (Laberinto) message=error message sample" << std::endl;
        }
    }*/
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% Laberinto" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testLaberinto (Laberinto)" << std::endl;
    testLaberinto();
    std::cout << "%TEST_FINISHED% time=0 testLaberinto (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testLaberinto2 (Laberinto)" << std::endl;
    testLaberinto2();
    std::cout << "%TEST_FINISHED% time=0 testLaberinto2 (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testLaberinto3 (Laberinto)" << std::endl;
    testLaberinto3();
    std::cout << "%TEST_FINISHED% time=0 testLaberinto3 (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testCaminoMasCorto (Laberinto)" << std::endl;
    testCaminoMasCorto();
    std::cout << "%TEST_FINISHED% time=0 testCaminoMasCorto (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testCaminoEncontrado (Laberinto)" << std::endl;
    testCaminoEncontrado();
    std::cout << "%TEST_FINISHED% time=0 testCaminoEncontrado (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testSumaTotalFerormona (Laberinto)" << std::endl;
    testSumaTotalFerormona();
    std::cout << "%TEST_FINISHED% time=0 testSumaTotalFerormona (Laberinto)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

