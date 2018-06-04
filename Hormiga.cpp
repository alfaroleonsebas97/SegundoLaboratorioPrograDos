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
    //memoria.resize(laberinto_p->obtTotVrt());
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
    if (!memoria.empty()) {                                                 //si hay vértices en memoria,
        memoriaHilera += memoria[0];                                        //copia el primer vértice en la string.
        for (int i = 1; i < memoria.size(); i++) {                                 //recorre el resto de la memoria.
            memoriaHilera += "," + memoria[i];                              //copia una coma y el vértice.
        }
    }
    memoriaHilera += "}";
    return memoriaHilera; 
}

/* MÉTODOS MODIFICADORES */

void Hormiga::salir() {
    Laberinto& laberinto = *laberinto_p; // para evitar notación ->
    idVrtActual = laberinto.obtIdVrtInicial();                              //ubica la hormiga en el nodo inicial.
    memoria.push_back(idVrtActual);
    haSalido = true;
}

void Hormiga::mover() {
    Laberinto& laberinto = *laberinto_p; // para evitar notación ->
    int x = laberinto.obtIdVrtFinal(); // ejemplo de uso del laberinto
   /*for (int i = 0; i < cntVrts; i++) {                                     //asigna -1 en toda la memoria.
    memoria[i] = -1;
    }
    if ( ( haSalido ) && ( !haRegresado) ){                                 //si ya ya salió y no ha regresado.
        if ( idVrtActual == lbrt.obtIdVrtFinal() ){                         //si ya llegó al vértice final, cambia el destino                                                           //pregtuntar que si ya llegó al final, para empezar a devoverse.
            destino = 'I';
            longitudSolucion = ultMemo + 1;                                     //y asigna la longitud de la solución.
            deltaFerormona = 1.0 / longitudSolucion ;
        }
        if( destino == 'I'){                                                //se mueve un vértice de regreso.
            double  f = lbrt.obtDatoAdy(memoria[ultMemo -1],idVrtActual).obtCntFerormona();
            lbrt.obtDatoAdy(memoria[ultMemo -1],idVrtActual).asgCntFerormona(f+deltaFerormona);
            popMemo();
            if( lbrt.obtIdVrtInicial() == idVrtActual ){
                haRegresado = true;
             }
        }else{   
            int sgtVrt = seleccionaAdyMasCargada(lbrt);                     //elige el siguiente vértice.
            if( sgtVrt == -1 ){                                             //si el siguiente vértice es inválido,
                retroceder();
            }else{                                                          //sino es un vértice válido.                                                        //se mueve un vértice.
                if( idVrtActual == lbrt.obtIdVrtFinal()){
                    longitudSolucion = ultMemo;
                }    
                idVrtActual = sgtVrt;
                pushMemo();
            }
        }
    }*/
}

void Hormiga::asgLaberinto(Laberinto& lbrt) {
    Hormiga::laberinto_p = &lbrt; // asigna valor al puntero, indirectamente a referencia!!
}
