/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hormiga.cpp
 * Author: Alan
 * 
 * Created on 7 de febrero de 2018, 05:53 PM
 */

#include "Hormiga.h"

Laberinto* Hormiga::laberinto_p = 0; // inicialización de variable static privada

Hormiga::Hormiga() {
    idVrtActual = -1; 
    memoria.resize(laberinto_p->obtTotVrt());
    for (int i = 0; i < memoria.size(); i++) {                                     //asigna -1 en toda la memoria.
        memoria[i] = -1;
    }
    haSalido = false; 
    haRegresado = false;
    destino = 'F'; 
    enRetroceso = 0;
    longitudSolucion = 0;
    deltaFerormona = 0.0;
}

Hormiga::Hormiga(const Hormiga& orig) {
    idVrtActual = orig.idVrtActual;
    memoria = orig.memoria;
    haSalido = orig.haSalido;
    haRegresado = orig.haRegresado;
    destino = orig.destino;
    enRetroceso = orig.enRetroceso;
    longitudSolucion = orig.longitudSolucion;
    deltaFerormona = orig.deltaFerormona;
}

Hormiga::~Hormiga() {
}

/* OBSERVADORES */

bool Hormiga::salio() {
    return haSalido;
}

bool Hormiga::regreso() {
    return haRegresado;
}

char Hormiga::obtDestino() {
    return destino;
}

string Hormiga::obtMemoria() {
    string memoriaHilera = "{";
    if (-1 != memoria[0]) {                                                 //si hay vértices en memoria,
        memoriaHilera += memoria[0];                                        //copia el primer vértice en la string.
        for (int i = 1; i < memoria.size(); i++) {                                 //recorre el resto de la memoria.
            memoriaHilera += "," + memoria[i];                              //copia una coma y el vértice.
        }
    }
    memoriaHilera += "}";
    return memoriaHilera;                                                   //retorna la hilera de memoria.
}

/* MÉTODOS MODIFICADORES */

void Hormiga::salir() {
    Laberinto& laberinto = *laberinto_p; // para evitar notación ->
    int x = laberinto.obtIdVrtFinal(); // ejemplo de uso del laberinto
}

void Hormiga::mover() {
    Laberinto& laberinto = *laberinto_p; // para evitar notación ->
    int x = laberinto.obtIdVrtFinal(); // ejemplo de uso del laberinto
}

void Hormiga::asgLaberinto(Laberinto& lbrt) {
    Hormiga::laberinto_p = &lbrt; // asigna valor al puntero, indirectamente a referencia!!
}
