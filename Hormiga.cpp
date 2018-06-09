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

#include <fstream>
#include <iostream>
using namespace std;

Laberinto* Hormiga::laberinto_p = 0; // inicialización de variable static privada

Hormiga::Hormiga() {
    idVrtActual = -1;
    //cout<<laberinto_p->obtTotVrt()<<endl;
    //memoria.reserve(laberinto_p->obtTotVrt());
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
    int k = 7;
    if (!memoria.empty()) {
        for (auto current: memoria) {
            memoriaHilera += to_string(current);
            memoriaHilera.push_back(','); 
        }
        memoriaHilera.pop_back();
    }
    memoriaHilera += "}";
    return memoriaHilera; 
}

/* MÉTODOS MODIFICADORES */

void Hormiga::salir() {
    Laberinto& laberinto = *laberinto_p;                                    // para evitar notación ->
    idVrtActual = laberinto.obtIdVrtInicial();                              //ubica la hormiga en el nodo inicial.
    memoria.push_back(idVrtActual);
    haSalido = true;
}

void Hormiga::mover() {
    if(haSalido){
        Laberinto& laberinto = *laberinto_p;                                    //para evitar notación ->
        if(!haRegresado){ 
            if(destino == 'F'){
                int sgt = seleccionaAdyMasCargada();
                if(sgt == -1){
                    retroceder();
                    cout<<"retroceso"<<endl;
                }else{
                    if(sgt == laberinto.obtIdVrtFinal()){
                        idVrtActual = sgt;
                        cout<<"meto en memoria: "<<idVrtActual<<endl;
                        memoria.push_back(idVrtActual);
                        longitudSolucion++;
                        destino = 'I';
                        deltaFerormona = 1/longitudSolucion;    
                    } else{
                        idVrtActual = sgt;
                        cout<<"meto en memoria: "<<idVrtActual<<endl;
                        memoria.push_back(idVrtActual);
                        longitudSolucion++;  
                    }  
                }
            } else{
                if(destino == 'I'){  
                    Adyacencia ady(deltaFerormona,0.0);
                    laberinto.asgDatoAdy(idVrtActual, memoria[memoria.size()-1] , ady);
                    idVrtActual = memoria[memoria.size()-1];
                    memoria.pop_back();
                    if(idVrtActual == laberinto.obtIdVrtInicial()){
                        haRegresado = true;
                        memoria.pop_back();
                    }
                }
            }
        }
        for(auto current: memoria){
            cout<<"memoria"<<current<<endl;
        }
    }
}

void Hormiga::retroceder() {
    srand (time(NULL));           
    enRetroceso = rand ()% (memoria.size()-1) + 1;                          //genera un random,
    for ( int i = 0; i <= enRetroceso; i++ ){                               //y retrocede esa cantidad de veces.
        memoria.pop_back();
        longitudSolucion--;
    }
    idVrtActual = memoria[memoria.size()-1];
    enRetroceso = 0;
}

int Hormiga::seleccionaAdyMasCargada(){
    Laberinto& laberinto = *laberinto_p;                                    //para evitar notación ->
    int sgtVrt = -1;
    vector<int> vrtsPosibles;
    laberinto.obtIdVrtAdys(idVrtActual,vrtsPosibles);
    filtraVrtsPosibles(vrtsPosibles);
    
    if(vrtsPosibles.size()>0){
        vector<double> vecFerormonas;
        double sumaFerormonas = 0.0;
        double ferormona=0.0;
        int cantidadDeCeros = 0;  
        for(auto current: vrtsPosibles){
            ferormona = laberinto.obtDatoAdy(idVrtActual,current).obtCntFerormona();
            vecFerormonas.push_back(ferormona);
            sumaFerormonas += ferormona;
            if(ferormona==0.0){
                cantidadDeCeros++;
            }
        }
        
        vector<double> vecPorcentajes;
        double porcentajeSumado = 0.0;
        for (int k = 0; k < vecFerormonas.size(); k++) {
            if (vecFerormonas[k] == 0.0) {
                vecPorcentajes.push_back(porcentajeSumado + 0.01);
                porcentajeSumado = porcentajeSumado + 0.01;
            } else {
                vecPorcentajes.push_back( porcentajeSumado + ( (vecFerormonas[k] / sumaFerormonas) * (1 - (cantidadDeCeros * (0.01))) ) );
                porcentajeSumado = ((vecFerormonas[k] / sumaFerormonas) * (1 - (cantidadDeCeros * (0.01))));
            }
        }
        
        srand (time(NULL));
        double numeroAleatorio = (rand() % 1000 + 1) / 1000.0;
        int m = 0;
        if (numeroAleatorio <= vecPorcentajes[m]) {
            sgtVrt = vrtsPosibles[m];
        } else {
            while ( numeroAleatorio > vecPorcentajes[m] ) {
                m++;
                if ( numeroAleatorio <= vecPorcentajes[m] ) {
                    sgtVrt = vrtsPosibles[m];
                }
            }
        }
    }
    return sgtVrt;
}

void Hormiga::filtraVrtsPosibles(vector<int> &vrtsPosibles){
    Laberinto& laberinto = *laberinto_p;
    for(auto current: vrtsPosibles){
        cout<<"elemento antes: "<<current<<endl;
    }
    vector<int> copia;
    for(auto current: vrtsPosibles){
        if( find(memoria.begin(), memoria.end(), current) == memoria.end() ){
            copia.push_back(current);
        }
    }
    vrtsPosibles = copia;
    for(auto current: vrtsPosibles){
        cout<<"elemento después: "<<current<<endl;
    }
}
    
void Hormiga::asgLaberinto(Laberinto& lbrt) {
    Hormiga::laberinto_p = &lbrt; // asigna valor al puntero, indirectamente a referencia!!
}
