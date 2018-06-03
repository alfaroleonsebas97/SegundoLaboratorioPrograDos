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
    vertices.resize(cantidadVrts);                                          //le da tamaño al vector de vértices.
    idVrtInicial = -1;                                                      //inicializa en inválido
    idVrtFinal = -1;                                                        //inicializa en inválido
    Adyacencia adys;                                                        //crea el objeto adyacencia
    
    double numeroAleatorio = 0.0;                                           //inicializa en 0.
    srand(time(NULL));
    for (int i = 0; i < cantidadVrts; i++) {                                //para cada vértice del laberinto
        for (int j = i + 1; j < cantidadVrts; j++) {                        //en cada posible adyacencia.
            numeroAleatorio = (rand() % 1000 + 1) / 1000.0;                 //genera un número aleatorio entre 0 y 1.
            if (numeroAleatorio <= probabilidadAdy) {                       //si es menor o igual a la probabilidad.
                datosAdys.insert( map<int,Adyacencia>::value_type(obtIndiceAdy(i,j), adys));//agrega la adyacencia entre ambos vértices.
                vertices[i].lstAdy.push_back(j);                            //agrega j como adyacencia de i.
                vertices[j].lstAdy.push_back(i);                            //agrega i como adyacencia de j.
            }
        }
    }
}

Laberinto::Laberinto(ifstream& archivo){
    idVrtInicial = -1;                                                      //inicializa en inválido.
    idVrtFinal = -1;                                                        //inicializa en inválido.
    string hileraActual;                                                    //hilera actual.
    getline(archivo, hileraActual);                                         //lee la primer línea del archivo y la agrega a la hileraActual
    int cntVrts = stoi(hileraActual);                                       //convierte la hileraActual en un entero que representa la cantidad  de vértices.
    Adyacencia adys;                                                        //crea objeto adyacencia.
    vertices.resize(cntVrts);                                               //le da tamaño al vector de vértices.
    
    int numeroDeAdyacencia;                                                 //entero temporal para vértices adyacentes.
    string hileraTemporal = "";                                                  //hilera temporal de cada vértice adyacente.
    int numeroDeLinea = 0;                                                  //número de línea en el archivo.
    while (getline(archivo, hileraActual)) {                                //recorre el archivo hasta el final.
        int i = 0;                                                          //índice en la hileraActual.
        while (hileraActual[i] != '\r') {                                   //recorre la hileraActual hasta el final de la línea.
            if (hileraActual[i] != ' ') {                                   //si no ha llegado a un blanco,
                hileraTemporal += hileraActual[i];                          //copia el número en la hilera temporal.
            } else {                                                        //cuando encuentra un blanco, agrega la adyacencia entre el vértice numeroDeLinea y el vértice que hay en hileraTemporal.
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
}

Laberinto::~Laberinto() {
}

/* MÉTODOS OBSERVADORES BÁSICOS */
bool Laberinto::xstVrt(int idVrt) const {
    return( (0<=idVrt) && (idVrt<=vertices.size()) );
}

bool Laberinto::xstAdy(int idVrtO, int idVrtD) const {
    bool adyacencia = false;
    if ((xstVrt(idVrtO)) && (xstVrt(idVrtD))) {                             //si ambos vértices existen,                                  //busca si hay adyacencia entre el vértice origen y el destino.
        for (auto current: vertices[idVrtO].lstAdy ){                       //recorre la lista de adyacencias del vértice origen.
            if (idVrtD == current){                                         //si encuentra el vértice destino,
                adyacencia = true;                                          //asigna true.
            }
        }
    }
    return adyacencia;
}

int Laberinto::obtIdVrtInicial() const {
    return idVrtInicial;                                                    //retorna el índice del vértice inicial.
}

int Laberinto::obtIdVrtFinal() const {
    return idVrtFinal;                                                      //retorna el índice del vértice final.
}

void Laberinto::obtIdVrtAdys(int idVrt, vector<int>& rsp) const {
    if (xstVrt(idVrt)) {                                                    //si existe el vértice,
        for (auto current: vertices[idVrt].lstAdy ){                        //recorre su lista de adyacencias
            rsp.push_back(current);                                         //agregando cada una al vector rsp.
        } 
    }
}

Adyacencia Laberinto::obtDatoAdy(int idVrtO, int idVrtD) const {
    Adyacencia result;
    if ((xstVrt(idVrtO)) && (xstVrt(idVrtD))){                              //si existen ambos vértices,
        if (xstAdy(idVrtO, idVrtD)) {                                       //y si existe adyacencia entre ambos.
            int k = obtIndiceAdy(idVrtO, idVrtD);                           //obtiene la clave,
            result = datosAdys.find(k)->second;                             //devuelve el objeto ady de la clave k.
        }
    }
    return result;
}

int Laberinto::obtCntAdy(int idVrt) const {
    return vertices[idVrt].lstAdy.size();                                   //retorna la cantidad de adyacencias del vértice idVrt.
}

int Laberinto::obtTotAdy() const {
    int cntTtlAdy = 0;                                                      //La cantidad total de adyacencias se inicia en 0.
    for (int i = 0; i < vertices.size() ; i++) {                            //recorre todos los vértices,
        cntTtlAdy += vertices[i].lstAdy.size();                             //sumando la cantidad de adyacencias por vértice.
    }
    return cntTtlAdy;
}

int Laberinto::obtTotVrt() const {
    return vertices.size();                                                 //retorna el total de vérties.
}

int Laberinto::caminoMasCorto(int idVrtO, int idVrtD, vector<int>& camino) const {
    int size = -1;                                                          //inicializa el tamaño del camino más corto en inválido.
    if (xstVrt(idVrtO) && xstVrt(idVrtD)) {                                 //verifica la existencia de ambos vértices.
        int cntVrts = vertices.size();                                      //variable para saber la cantidad de vértices del laberinto.
        int distancia[cntVrts];                                             //distancias de los caminos más cortos.
        bool visto[cntVrts];                                                //para controlar los vértices visitados.
        for (auto& currentElement: visto) {                                 //inicializa el arreglo visto en false
           currentElement = false;
        }
        int antecesores[cntVrts];                                           //arreglo de antecesores.
        for (int i = 0; i < cntVrts; i++) {                                 //recorre todos los vérties.
            if (!xstAdy(idVrtO, i)) {                                       //si no existe adyacencia con el vértice origen,
                distancia[i] = INT_MAX;                                     //asigna infinito.
                antecesores[i] = -2;                                        //y un antecesor inválido.
            } else {                                                        //en el caso de que si exista adyacencia
                distancia[i] = 1;                                           //asigna peso 1
                antecesores[i] = idVrtO;                                    //y asigna antecesor el vértice origen.
            }
        }
        distancia[idVrtO] = 0;                                              //invalida el vértice origen y lo pone visitado
        antecesores[idVrtO] = -1;
        visto[idVrtO] = true;

        while (visto[idVrtD] == false) {                                    //mientras no estén todos en visto.
                                                                            //encuentra el menor del arreglo distancia y que no esté visto:
            int verticeMinimo = 0;                                          //lo inicializa en 0.
            while( visto[verticeMinimo] ){                                  //y encuentra el primer vértice no visitado.
                verticeMinimo++;
            }
            for (int m = 0; m < cntVrts; m++) {                             //encuentra si hay algún vértice menor no visitado.
                if ( ( !visto[m] ) && ( distancia[m] < distancia[verticeMinimo] ) ) {
                    verticeMinimo = m;                                      //y lo asigna.
                }
            }
            
            visto[verticeMinimo] = true;                                    //pone en visitado el vértice minimo.
            
            list<int> sucesores = vertices[verticeMinimo].lstAdy;           //al vector sucesores le asigna la lista de adyacencias del vértice minimo.
            for (int& current: sucesores){                                  // sucesores[j] = current
                if( distancia[current] > ( distancia[verticeMinimo] + 1 ) ){//si el nuevo peso es menor.
                    distancia[current] = distancia[verticeMinimo] + 1;      //asigna el nuevo peso.
                    antecesores[current] = verticeMinimo;                   //y cambia el antecesor.
                }
            }
        }
        
        //recorre el camino más corto, desde el vértice destino hasta el vértice origen agregándolo en caminoTemp
        int k = idVrtD;
        vector<int> caminoTemp;                                             //donde se almacenatá el camino más corto temporalmente.
        while( antecesores[k] != -1){                                       //mientras no llegue al primer vértice.
            caminoTemp.push_back(k);                                        //agregue el último del camino más corto.
            k = antecesores[k];                                             //cambia el último por el antecesor de este.
        }
        caminoTemp.push_back(idVrtO);                                      //agrega el vértie origen.
        size = distancia[idVrtD];                                          //distancia del camino más corto.
        
        for (int i = caminoTemp.size(); i > 0 ; i--){                       //le da vuelta y lo agrega en camino.
            camino.push_back( caminoTemp.at(i-1) );
        }
    }
    return size;
}

int Laberinto::caminoEncontrado(int idVrtO, int idVrtD, vector<int>& camino) const {
}

double Laberinto::sumaTotalFerormona() const {
}

void Laberinto::asgIdVrtInicial(int idVrtInicialN) {
    if(xstVrt(idVrtInicialN)){                                              //si existe el vértice,
        idVrtInicial = idVrtInicialN;                                       //lo asigna como vértice inicial.
    }
}

void Laberinto::asgIdVrtFinal(int idVrtFinalN) {
    if(xstVrt(idVrtFinalN)){                                                //si existe el vértice,
        idVrtFinal = idVrtFinalN;                                           //lo asigna como vértice final.
    }
}

void Laberinto::asgDatoAdy(int idVrtO, int idVrtD, const Adyacencia& ady) {
    if( (xstVrt(idVrtO)) && (xstVrt(idVrtD)) ){                             //si existen ambos vértices,
        datosAdys.insert( map<int,Adyacencia>::value_type( obtIndiceAdy(idVrtO,idVrtD), ady) );//asigna el dato de adyacencia.
    }
}

void Laberinto::decrementarFerormonaAdys(double decrFerormona) {
    for(auto current: datosAdys){                                           //recorre el mapa.
       if ( current.second.obtCntFerormona() != (-1.0) ){                   //si la cantidad de ferormona es distinta de -1.
           current.second.asgCntFerormona( (current.second.obtCntFerormona()) * (decrFerormona));//descrementa la cantidad de ferormona.
       } 
    }
}

void Laberinto::actualizarValoracionAdys() {
    /*map<int,Adyacencia>::iterator it;
    for (it = datosAdys.begin(); it != datosAdys.end(); it++) {
        if (it->second.obtValoracion() != (-1.0)) {
            it->second.asgValoracion((it->second.obtCntFerormona()) / (sumaTotalFerormona()));
        }
    }*/
    for(auto current: datosAdys){                                           //recorre el mapa.
       if ( current.second.obtValoracion() != (-1.0) ){                   //si la cantidad de ferormona es distinta de -1.
           current.second.asgValoracion( (current.second.obtCntFerormona()) / (sumaTotalFerormona()) );//actualiza la valoración.
       } 
    }
}

int Laberinto::obtIndiceAdy(int f, int c) const {
    if ( f > c){
        int t = f;
        f = t;
        c = f;
    }
    return f * vertices.size() + c - f * (f + 1) / 2;
}
