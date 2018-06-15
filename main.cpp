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
/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        vector<int> vecCamino;
        Laberinto laberinto(archivo);
        int verticeInicial = 0;
        int verticeFinal = 8;
        Simulador simulador(laberinto);
        simulador.iniciar(verticeInicial,verticeFinal,30,0.95,0.11);
        simulador.ejecutar(1000);
        int longitud = laberinto.caminoEncontrado(verticeInicial,verticeFinal,vecCamino);
        cout<<"Primer camino encontrado en el laberinto pequeño: "<<endl;
        for(auto current: vecCamino){
            cout<<current<<endl;
        }
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        archivo.close();
    }
    
    ifstream archivo2("laberintop.txt");
    if (archivo2.is_open()) {
        vector<int> vecCamino2;
        Laberinto laberinto2(archivo2);
        int verticeInicial = 0;
        int verticeFinal = 8;
        Simulador simulador2(laberinto2);
        simulador2.iniciar(verticeInicial,verticeFinal,300,0.95,0.11);
        simulador2.ejecutar(10000);
        int longitud = laberinto2.caminoEncontrado(verticeInicial,verticeFinal,vecCamino2);
        cout<<"Segundo camino encontrado en el laberinto pequeño: "<<endl;
        for(auto current: vecCamino2){
            cout<<current<<endl;
        }
         cout<<"------------------------------------------------------------------"<<endl;
         archivo2.close();
    }
    
    ifstream archivo3("laberintom.txt");
    if (archivo3.is_open()) {
        vector<int> vecCamino3;
        Laberinto laberinto3(archivo3);
        int verticeInicial = 0;
        int verticeFinal = 35;
        Simulador simulador3(laberinto3);
        simulador3.iniciar(verticeInicial,verticeFinal,30,0.95,0.99);
        simulador3.ejecutar(1000);
        int longitud = laberinto3.caminoEncontrado(verticeInicial,verticeFinal,vecCamino3);
        cout<<"Primer camino encontrado en el laberinto mediano: "<<endl;
        for(auto current: vecCamino3){
            cout<<current<<endl;
        }
         cout<<"''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
         archivo3.close();
    }
    
    ifstream archivo4("laberintom.txt");
    if (archivo4.is_open()) {
        vector<int> vecCamino4;
        Laberinto laberinto4(archivo4);
        int verticeInicial = 0;
        int verticeFinal = 35;
        Simulador simulador4(laberinto4);
        simulador4.iniciar(verticeInicial,verticeFinal,300,0.95,0.99);
        simulador4.ejecutar(10000);
        int longitud = laberinto4.caminoEncontrado(verticeInicial,verticeFinal,vecCamino4);
        cout<<"Segundo camino encontrado en el laberinto mediano: "<<endl;
        for(auto current: vecCamino4){
            cout<<current<<endl;
        }
         cout<<"*********************************************************************"<<endl;
         archivo4.close();
    }
    return 0;
}