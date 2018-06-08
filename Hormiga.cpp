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
    memoria.reserve(laberinto_p->obtTotVrt());
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
        for (int i = 1; i < memoria.size(); i++) {                          //recorre el resto de la memoria.
            memoriaHilera += "," + memoria[i];                              //copia una coma y el vértice.
        }
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
    Laberinto& laberinto = *laberinto_p;                                    //para evitar notación ->
    int x = laberinto.obtIdVrtFinal();                                      //ejemplo de uso del laberinto
}

void Hormiga::retroceder() {
    srand (time(NULL));           
    enRetroceso = rand ()% (memoria.size()-1) + 1;                          //genera un random,
    for ( int i = 0; i <= enRetroceso; i++ ){                               //y retrocede esa cantidad de veces.
        memoria.pop_back();
    }
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
            if (vecFerormonas[k] == 0) {
                vecPorcentajes[k] = porcentajeSumado + 0.01;
                porcentajeSumado = porcentajeSumado + 0.01;
            } else {
                vecPorcentajes[k] = porcentajeSumado + ((vecFerormonas[k] / sumaFerormonas) * (1 - (cantidadDeCeros * (0.01))));
                porcentajeSumado = ((vecFerormonas[k] / sumaFerormonas) * (1 - (cantidadDeCeros * (0.01))));
            }
        }
        
    }
    return sgtVrt;
    /*
    int sgtVrt = -1;                                                        //vértice a escoger.
    int *ady;                                                               //crea ady.
    lbrt.obtIdVrtAdys( idVrtActual, ady );                                  //al objeto ady se le asignan las adyacencias del vértice actual.
    int longitudDeAdy = filtraVrtsPosibles( ady, lbrt.obtIdVrtFinal(), lbrt.obtCntAdy( idVrtActual ) ); //filtra los vértices posibles de ady, y obtiene el nuevo tamaño de ady.
    if( longitudDeAdy != 0){
        int cntFerormona[ longitudDeAdy ];                                  //crea un arreglo de ferormonas.
        int sumaFerormona = 0;                                              //suma de todas las ferormonas.
        int cantidadDeCeros = 0;                                            //cantidad de adyacencias con ferormona igual a cero

        for (int i = 0; i < longitudDeAdy; i++) {                           //recorro el arreglo de ferormonas
            cntFerormona[i] = lbrt.obtDatoAdy(idVrtActual, ady[i]).obtCntFerormona(); //asignando la cantidad de ferormona por adyacencia
            sumaFerormona = sumaFerormona + cntFerormona[i];                //suma la ferormona
            if (cntFerormona[i] == 0) {                                     //si la ferormona de la adyacencia es cero
                cantidadDeCeros++;                                          //aumenta cantidadDeCeros
            }
        }

        double porcentajes[longitudDeAdy];                                  //arreglo de porcentajes
        double porcentajeSumado = 0.0;                                      //porcentaje que va de 0 a 1.
        for (int k = 0; k < longitudDeAdy; k++) {                           //recorre el arreglo de porcentajes
            if (cntFerormona[k] == 0) {                                     //si la ferormona de la adyacencia es 0, su porcentaje es 0.01 + porcentajeTotal;
                porcentajes[k] = porcentajeSumado + 0.01;                   //y suma porcentaje.
                porcentajeSumado = porcentajeSumado + 0.01;
            } else {                                                        //sino, asigna el porcentaje correspondiente y suma porcentaje.
                porcentajes[k] = porcentajeSumado + ((cntFerormona[k] / sumaFerormona) * (1 - (cantidadDeCeros * (0.01))));
                porcentajeSumado = ((cntFerormona[k] / sumaFerormona) * (1 - (cantidadDeCeros * (0.01))));
            }
        }
        
        srand (time(NULL));
        double numeroAleatorio = (rand() % 1000 + 1) / 1000.0;              //gerenera un número al azar entre 0 y 1.
        int m = 0;                                                          //índice para recorrer el arreglo de porcentajes.
        if (numeroAleatorio < porcentajes[m]) {                             //si el número aleatorio está en el rango del primer vértice,
            sgtVrt = ady[m];                                                //entonces ese el siguiente vértice a escoger.
        } else {                                                            //sino sigue buscando hasta encontrarlo.
            while ( numeroAleatorio >= porcentajes[m] ) {
                m++;
                if ( numeroAleatorio < porcentajes[m] ) {                   //si encuentra el rango.
                    sgtVrt = ady[m];                                        //asigna el siguiente vértice.
                }
            }
        }
    }
    return sgtVrt;                */
}

void Hormiga::filtraVrtsPosibles(vector<int> vrtsPosibles){
    Laberinto& laberinto = *laberinto_p;
    vector<int>sgts;
    for(auto current: vrtsPosibles){
        if( (find(vrtsPosibles.begin(), vrtsPosibles.end(), current) != vrtsPosibles.end()) || (laberinto.obtCntAdy(current)==0) ){
            vrtsPosibles.erase(vrtsPosibles.begin()+current);
        }
    }   
}
    
    
void Hormiga::asgLaberinto(Laberinto& lbrt) {
    Hormiga::laberinto_p = &lbrt; // asigna valor al puntero, indirectamente a referencia!!
}
