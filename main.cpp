/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alan.calderon
 *
 * Created on 2 de abril de 2018, 10:31 AM
 */

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include "Laberinto.h"
#include "Simulador.h"
#include "Hormiga.h"
#include "Hormiga.h"
/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        vector<int> vecCamino;
        Laberinto laberinto(archivo);
        Adyacencia ady(10.0,0.0);
        laberinto.asgDatoAdy(0,6,ady);
        laberinto.asgDatoAdy(6,8,ady);
        Simulador simulador(laberinto);
        simulador.iniciar(0,8,30,0.95,0.11);
        simulador.ejecutar(1000);
        laberinto.caminoEncontrado(0,8,vecCamino);
        cout<<"Primer camino encontrado en el laberinto pequeño: "<<endl;
        for(auto current: vecCamino){
            cout<<current<<endl;
        }
    }
    
    ifstream archivo2("laberintop.txt");
    if (archivo2.is_open()) {
        vector<int> vecCamino2;
        Laberinto laberinto2(archivo2);
        Adyacencia ady2(10.0,0.0);
        laberinto2.asgDatoAdy(0,6,ady2);
        laberinto2.asgDatoAdy(6,8,ady2);
        Simulador simulador2(laberinto2);
        simulador2.iniciar(0,8,300,0.95,0.11);
        simulador2.ejecutar(10000);
        laberinto2.caminoEncontrado(0,8,vecCamino2);
        cout<<"Segundo camino encontrado en el laberinto pequeño: "<<endl;
        for(auto current: vecCamino2){
            cout<<current<<endl;
        }
    }
    
        ifstream archivo3("laberintom.txt");
    if (archivo3.is_open()) {
        vector<int> vecCamino3;
        Laberinto laberinto3(archivo3);
        Adyacencia ady3(10.0,0.0);
        laberinto3.asgDatoAdy(0,3,ady3);
        laberinto3.asgDatoAdy(3,14,ady3);
        laberinto3.asgDatoAdy(14,20,ady3);
        laberinto3.asgDatoAdy(20,35,ady3);
        Simulador simulador3(laberinto3);
        simulador3.iniciar(0,35,30,0.95,0.99);
        simulador3.ejecutar(1000);
        laberinto3.caminoEncontrado(0,35,vecCamino3);
        cout<<"Primer camino encontrado en el laberinto mediano: "<<endl;
        for(auto current: vecCamino3){
            cout<<current<<endl;
        }
    }
    
    ifstream archivo4("laberintom.txt");
    if (archivo4.is_open()) {
        vector<int> vecCamino4;
        Laberinto laberinto4(archivo4);
        Adyacencia ady4(10.0,0.0);
        laberinto4.asgDatoAdy(0,3,ady4);
        laberinto4.asgDatoAdy(3,14,ady4);
        laberinto4.asgDatoAdy(14,20,ady4);
        laberinto4.asgDatoAdy(20,35,ady4);
        Simulador simulador4(laberinto4);
        simulador4.iniciar(0,35,300,0.95,0.99);
        simulador4.ejecutar(10000);
        laberinto4.caminoEncontrado(0,35,vecCamino4);
        cout<<"Segundo camino encontrado en el laberinto mediano: "<<endl;
        for(auto current: vecCamino4){
            cout<<current<<endl;
        }
    }
    return 0;
}