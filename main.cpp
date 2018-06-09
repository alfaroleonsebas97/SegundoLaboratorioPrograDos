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
/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        ifstream archivoEntrada;
        Laberinto laberinto(archivo);
        Simulador simulador(laberinto);
        //preguntar
        simulador.iniciar(0,8,30,0.95,0.3);
        simulador.ejecutar(1000);
        
        simulador.iniciar(0,6,300,0.95,0.3);
        simulador.ejecutar(10000);
        //vector<int> adyacencias;
        //laberinto.obtIdVrtAdys(0, adyacencias); // se modifica "adyacencias"
    }
    return 0;
}