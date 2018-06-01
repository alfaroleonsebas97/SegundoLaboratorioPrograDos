/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Laberinto.cpp
 * Author: Alan
 * 
 * Created on 7 de febrero de 2018, 04:46 PM
 */

#include "Laberinto.h"

Laberinto::Laberinto(int cantidadVrts, double probabilidadAdy){
    vertices.resize(cantidadVrts);                                              //le da tamaño al vector de vértices.
    idVrtInicial = -1;                                                          //inicializa en inválido
    idVrtFinal = -1;                                                            //inicializa en inválido
    Adyacencia adys;
    
    double numeroAleatorio = 0.0;
    srand(time(NULL));
    for (int i = 0; i < cantidadVrts; i++) {
        for (int j = i + 1; j < cantidadVrts; j++) {
            numeroAleatorio = (rand() % 1000 + 1) / 1000.0;
            if (numeroAleatorio <= probabilidadAdy) {
                datosAdys.insert( map<int,Adyacencia>::value_type(obtIndiceAdy(i,j), adys));
                vertices[i].lstAdy.push_back(j);
                vertices[j].lstAdy.push_back(i);
            }
        }
    }
}

Laberinto::Laberinto(ifstream& archivo){
    idVrtInicial = -1;                                                      //inicializa variables.
    idVrtFinal = -1;
    string hileraActual;
    getline(archivo, hileraActual);
    int cntVrts = stoi(hileraActual);
    Adyacencia adys;
    vertices.resize(cntVrts);
    
    int numeroDeAdyacencia;
    string hileraTemporal;
    int numeroDeLinea = 0;
    while (getline(archivo, hileraActual)) {                                //recorre el archivo hasta el final
        int i = 0;
        while (hileraActual[i] != '\r') {                                   //recorre la hilera hasta el final de la línea.
            if (hileraActual[i] != ' ') {                                   //guarda en hilera temporal el número, hasta llegar a un blanco
                hileraTemporal += hileraActual[i];
            } else {                                                        //cuando encuentra un blanco, agrega al arreglo de vértices lo que había en hilera temporal.
                numeroDeAdyacencia = stoi(hileraTemporal);
                hileraTemporal = "";
                datosAdys.insert( map<int,Adyacencia>::value_type( obtIndiceAdy(numeroDeLinea,numeroDeAdyacencia), adys) );
                vertices[numeroDeLinea].lstAdy.push_back(numeroDeAdyacencia);
            }
            i++;
        }
        numeroDeLinea++;
    }
}

Laberinto::Laberinto(const Laberinto& orig){
    int cntVrts = orig.vertices.size();
    idVrtInicial = -1;
    idVrtFinal = -1;
    Adyacencia adys;
    vertices.resize(cntVrts);
    
    vertices = orig.vertices;
    datosAdys = orig.datosAdys;
    //for (int i = 0; i < cntVrts; i++) {                                         //recorre el laberinto copiándolo.
      //  vertices[i].lstAdy = orig.vertices[i].lstAdy;
    //}
    
}

Laberinto::~Laberinto() {
    //std::map::~map();
}

/* MÉTODOS OBSERVADORES BÁSICOS */
bool Laberinto::xstVrt(int idVrt) const {
    return((0<=idVrt)&&(idVrt<=vertices.size()));
}

bool Laberinto::xstAdy(int idVrtO, int idVrtD) const {
bool adyacencia = false;
    if ((xstVrt(idVrtO)) && (xstVrt(idVrtD))) {                             //si ambos vértices existen,
        list<int>::iterator it;                                             //busca si hay adyacencia entre el vértice origen y el destino.
        for ( it = vertices[idVrtO].lstAdy.begin(); it != vertices[idVrtO].lstAdy.end(); it++ ){
            if( idVrtD == *it ) {
                adyacencia = true;
            }    
        }
    }
    return adyacencia;
}

int Laberinto::obtIdVrtInicial() const {
    return idVrtInicial;
}

int Laberinto::obtIdVrtFinal() const {
    return idVrtFinal;
}

void Laberinto::obtIdVrtAdys(int idVrt, vector<int>& rsp) const {
    
}

Adyacencia Laberinto::obtDatoAdy(int idVrtO, int idVrtD) const {
}

int Laberinto::obtCntAdy(int idVrt) const {
}

int Laberinto::obtTotAdy() const {
}

int Laberinto::obtTotVrt() const {
}

int Laberinto::caminoMasCorto(int idVrtO, int idVrtD, vector<int>& camino) const {
}

int Laberinto::caminoEncontrado(int idVrtO, int idVrtD, vector<int>& camino) const {
}

double Laberinto::sumaTotalFerormona() const {
}

void Laberinto::asgIdVrtInicial(int idVrtInicialN) {
}

void Laberinto::asgIdVrtFinal(int idVrtFinalN) {
}

void Laberinto::asgDatoAdy(int idVrtO, int idVrtD, const Adyacencia& ady) {
}

void Laberinto::decrementarFerormonaAdys(double decrFerormona) {
}

void Laberinto::actualizarValoracionAdys() {
}

int Laberinto::obtIndiceAdy(int f, int c) const {
    if ( f > c){
        int t = f;
        f = t;
        c = f;
    }
    return f * vertices.size() + c - f * (f + 1) / 2;
}
