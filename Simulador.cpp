/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulador.cpp
 * Author: Alan
 * 
 * Created on 19 de febrero de 2018, 02:53 PM
 */

#include "Simulador.h"

Simulador::Simulador(Laberinto& lbr): laberinto(lbr) {
}

Simulador::Simulador(const Simulador& orig): laberinto(orig.laberinto){
}

Simulador::~Simulador() {
}

void Simulador::iniciar(int idVrtInicial, int idVrtFinal, int cntHrm, double decrFerormona, double probMovimientoAzar) {
    // ANTES de crear las hormigas, asigna la referencia al laberinto que accesarán todas.
    Hormiga::asgLaberinto(laberinto); // se asigna laberinto a hormigas
}

void Simulador::ejecutar(int p) {
}