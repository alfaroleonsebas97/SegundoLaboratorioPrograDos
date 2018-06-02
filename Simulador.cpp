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
    cantidadHormigas = 0;
    decrFerormona = 0.0;
    probMovimientoAzar = 0.0;
}

Simulador::Simulador(const Simulador& orig): laberinto(orig.laberinto){
    cantidadHormigas = orig.cantidadHormigas;
    decrFerormona = orig.decrFerormona;
    probMovimientoAzar = orig.probMovimientoAzar;
}

Simulador::~Simulador() {
}

void Simulador::iniciar(int idVrtInicial, int idVrtFinal, int cntHrm, double decrFerormona, double probMovimientoAzar) {
    Hormiga::asgLaberinto(laberinto); // se asigna laberinto a hormigas
    if ((laberinto.xstVrt(idVrtInicial)) && (laberinto.xstVrt(idVrtFinal))) {
        laberinto.asgIdVrtInicial(idVrtInicial);
        laberinto.asgIdVrtFinal(idVrtFinal);
        cantidadHormigas = cntHrm;
        this->decrFerormona = decrFerormona;
        this->probMovimientoAzar = probMovimientoAzar;
        hormigas.resize(cantidadHormigas);
    }
}

void Simulador::ejecutar(int p) {
}
