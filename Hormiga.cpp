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
}

Hormiga::Hormiga(const Hormiga& orig) {
}

Hormiga::~Hormiga() {
}

/* OBSERVADORES */

bool Hormiga::salio() {
}

bool Hormiga::regreso() {
}

char Hormiga::obtDestino() {
}

string Hormiga::obtMemoria() {
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
