/* 
 * File:   LstOrdAdy.h
 * Author: Alan
 *
 * Created on 2 de abril de 2015, 02:32 PM
 */

#ifndef LISTAORDENADA_H
#define	LISTAORDENADA_H

#include <memory>
#include <string>
#include <sstream>
using namespace std;

class ListaOrdenada {
    // Representa la lista ordenada de adyacencias de un nodo en Grafo.
    
public:
    
    // Construye una lista de adyacencias vacía.
    ListaOrdenada();
    
    // Construye una lista ordenada de adyacencias idéntica a orig.
    ListaOrdenada(const ListaOrdenada& orig);
    
    // Destruye a *this retornando toda la memoria asignada dinámicamente.
    ~ListaOrdenada();
    
    // REQ: nPos no esté en *this.
    // MOD: *this
    // EFE: agrega ordenadamente la nueva posición de un vértice adyacente.
    void agregar(int nPos);
    
    // REQ: N/A.
    // MOD: N/A.
    // EFE: retorna true si pos está en *this y false en caso contrario.
    bool buscar(int pos);
    
    // REQ: N/A.
    // MOD: N/A.
    // EFE: retorna una hilera que representa a *this.
    // EJE: "{3,6,10}".    
    string toString();

    // REQ: N/A.
    // MOD: N/A.
    // EFE: retorna un arreglo de enteros que representa a *this.
    // EJE: [3,6,10].    
    // NOTA: un arreglo de enteros se representa mediante un puntero a la primera
    //       posición del arreglo.
    int* adyacencias();
    
    // EFE: retorna la cantidad de adyacencias en *this.
    int cantidadAdy();
    
private:
    struct Nodo { // representa el nodo de una lista ordenada de adyacencias
        int pos; // representa la posición del vértice destino en Laberinto
        shared_ptr<Nodo> sgt; // representa el apuntador inteligente al siguiente nodo
        Nodo(): pos(0), sgt(0){};
        Nodo(int p): pos(p), sgt(0){};
    };
    
    int cntAdy; // representa la cantidad de Nodos o adyacencias en la lista.
    shared_ptr<Nodo> inicio; // representa el apuntador al inicio de la lista
};

#endif	/* LISTAORDENADA_H */

