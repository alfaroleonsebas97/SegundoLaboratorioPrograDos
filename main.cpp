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
/*
    ifstream archivoEntrada;
    Laberinto laberinto(archivoEntrada);
    Simulador simulador(laberinto);
    vector<int> adyacencias;
    laberinto.obtIdVrtAdys(0, adyacencias); // se modifica "adyacencias"
    return 0;
    //int x = INT_MAX;
    //int x = std::numeric_limits<int>::max();
    //cout<< x <<endl;
    */
    vector<int>a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.erase(a.begin()+3);
    for(auto current:a){
        if(current==4){
            a.erase(a.begin()+current);
        }
        cout<<current<<endl;
    }
}