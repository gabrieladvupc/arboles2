#include "pch.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <cstdlib> // srand
#include <ctime>   //time null
#include <string>
using namespace System;
using namespace std;


//NodoArbol representa un nodo en el árbol. 
//Cada nodo tiene un valor enterno y un vector de punteros a sus nodos hijos.
struct NodoArbol {
    int dato;
    vector<NodoArbol*> hijos;
    NodoArbol(int val) : dato(val) {}
};

//Crea un árbol aleatorio con un número dado de nodos. 
//Comienza con un nodo raíz y luego agrega nodos hijos de manera aleatoria.
NodoArbol* generarArbolAleatorio(int numNodos) {
    if (numNodos <= 0) {
        return nullptr;
    }
    NodoArbol* raiz = new NodoArbol(1); // Siempre inicia en 1
    vector<NodoArbol*> nodosP; // visitar nodos o nodos por visitar
    nodosP.push_back(raiz);
    int posNodosP = 0;
    int valor = 2; // Inicia en 2 para el siguiente nodo

    while (numNodos > 1) {
        NodoArbol* actual = nodosP[posNodosP];
        int numHijos = rand() % 3 + 2; // Entre 2 y 4 hijos
        for (int i = 0; i < numHijos && numNodos > 1; ++i) {
            NodoArbol* hijo = new NodoArbol(valor++);
            actual->hijos.push_back(hijo);
            nodosP.push_back(hijo);
            numNodos--;
        }
        posNodosP++;
    }

    return raiz;
}


//imprime el árbol en forma de lista, mostrando los nodos y sus relaciones.
void imprimirArbol(NodoArbol* raiz, string sede, int profundidad = 0) {
    if (!raiz) return;

    for (int i = 0; i < profundidad; ++i) {
        cout << "  " << " |_> ";
    }
    cout << raiz->dato << endl;

    for (NodoArbol* hijo : raiz->hijos) {
        imprimirArbol(hijo, sede, profundidad + 1);
    }
}
//imprime los nodos del árbol por extensión, 
// recorriendo el árbol respecto a su ancho.
void porExtension(NodoArbol* raiz, string sede) {
    if (!raiz) return;

    vector<NodoArbol*> nodosP;
    nodosP.push_back(raiz);

    for (size_t i = 0; i < nodosP.size(); ++i) {
        NodoArbol* actual = nodosP[i];

        cout << actual->dato << " ";

        for (NodoArbol* hijo : actual->hijos) {
            nodosP.push_back(hijo);
        }
    }

    cout << "(" << sede << ")" << endl;
}

//realizan recorridos en inorden y postorden respectivamente, 
// mostrando los valores de los nodos en ese orden.
void inorden(NodoArbol* raiz) {
    if (!raiz) return;

    for (NodoArbol* hijo : raiz->hijos) {
        inorden(hijo);
    }
    cout << raiz->dato << " ";
}

void postorden(NodoArbol* raiz) {
    if (!raiz) return;

    for (NodoArbol* hijo : raiz->hijos) {
        postorden(hijo);
    }
    cout << raiz->dato << " ";
}
void destinoSI(string sede) {
    int numNodos;

    do {
        cout << "Ingrese la cantidad de nodos: ";
        cin >> numNodos;
        if (numNodos < 10 || numNodos > 15) {
            cout << "La cantidad de nodos debe estar entre 10 y 15" << endl;
        }
    } while (numNodos < 10 || numNodos > 15);

    NodoArbol* arbol = generarArbolAleatorio(numNodos);
    //llama a la funcion generar arbol aleatorio
    cout << "Elementos de la \"T\" por extension:" << endl;
    porExtension(arbol, sede);
    cout << endl;

    cout << "Digrafo:" << endl;
    imprimirArbol(arbol, sede);
    cout << endl;
    cout << "DESTINO: Sede San Isidro (padre): " << arbol->dato << endl;
    cout << "    Av. Canevaro: " << arbol->hijos[0]->dato << endl << endl;

    if (arbol->hijos[0]->hijos.size() >= 1) {
        cout << "     -Calle A: " << arbol->hijos[0]->hijos[0]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 2) {
        cout << "     -Calle B: " << arbol->hijos[0]->hijos[1]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 3) {
        cout << "     -Calle C: " << arbol->hijos[0]->hijos[2]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 4) {
        cout << "     -Calle D: " << arbol->hijos[0]->hijos[3]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() > 0 && arbol->hijos[0]->hijos.size() <= 4) {
        cout << endl;
    }

    if (arbol->hijos.size() >= 2) {
        cout << "    Av.Canevaro " << arbol->hijos[1]->dato << endl << endl;
        if (arbol->hijos[1]->hijos.size() >= 1) {
            cout << "     -Calle A: " << arbol->hijos[1]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 2) {
            cout << "     -Calle B: " << arbol->hijos[1]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 3) {
            cout << "     -Calle C: " << arbol->hijos[1]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 4) {
            cout << "     -Calle D: " << arbol->hijos[1]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() > 0 && arbol->hijos[1]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    if (arbol->hijos.size() >= 3) {
        cout << "    Av.Canevaro " << arbol->hijos[2]->dato << endl << endl;
        if (arbol->hijos[2]->hijos.size() >= 1) {
            cout << "     -Calle A: " << arbol->hijos[2]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 2) {
            cout << "     -Calle B: " << arbol->hijos[2]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 3) {
            cout << "     -Calle C: " << arbol->hijos[2]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 4) {
            cout << "     -Calle D: " << arbol->hijos[2]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() > 0 && arbol->hijos[2]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    if (arbol->hijos.size() >= 4) {
        cout << "    Av.Canevaro " << arbol->hijos[3]->dato << endl << endl;
        if (arbol->hijos[3]->hijos.size() >= 1) {
            cout << "     -Calle A: " << arbol->hijos[3]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() >= 2) {
            cout << "     -Calle B: " << arbol->hijos[3]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() >= 3) {
            cout << "     -Calle C: " << arbol->hijos[3]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() >= 4) {
            cout << "     -Calle D: " << arbol->hijos[3]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() > 0 && arbol->hijos[3]->hijos.size() <= 4) {
            cout << endl;
        }
    }


    cout << "Recorrido en inorden:" << endl;
    inorden(arbol);
    cout << endl;

    cout << "Recorrido en postorden:" << endl;
    postorden(arbol);
    cout << endl;
}
void destinoMO(string sede) {
    int numNodos;
    cout << "Ingrese la cantidad de nodos: ";
    cin >> numNodos;
    // 10 <= n <= 15
    do {
        cout << "Ingrese la cantidad de nodos: ";
        cin >> numNodos;
        if (numNodos < 10 || numNodos > 15) {
            cout << "La cantidad de nodos debe estar entre 10 y 15" << endl;
        }
    } while (numNodos < 10 || numNodos > 15);

    //llama la funcion generararbol ...
    NodoArbol* arbol = generarArbolAleatorio(numNodos);

    cout << "Elementos de la \"T\" por extension:" << endl;
    porExtension(arbol, sede);
    cout << endl;

    cout << "Digrafo:" << endl;
    imprimirArbol(arbol, sede);
    cout << endl;
    //luego de llamar a las funciones, se empieza a asignar rutas para
    // llegar a canevaro (UPC)
    //a cada elemento del arbol

    //muestra clase padre
    cout << "DESTINO: Sede Monterrico (padre): " << arbol->dato << endl;
    cout << "    Av. Canevaro: " << arbol->hijos[0]->dato << endl << endl;

    //se analiza si el primer hijo (0) tiene un hijo)
    if (arbol->hijos[0]->hijos.size() >= 1) {
        cout << "     -Calle X: " << arbol->hijos[0]->hijos[0]->dato << endl;
    }
    //mismo proceso para los demás
    if (arbol->hijos[0]->hijos.size() >= 2) {
        cout << "     -Calle Y: " << arbol->hijos[0]->hijos[1]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 3) {
        cout << "     -Calle Z: " << arbol->hijos[0]->hijos[2]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 4) {
        cout << "     -Calle R: " << arbol->hijos[0]->hijos[3]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() > 0 && arbol->hijos[0]->hijos.size() <= 4) { 
        //comprobacion para que se cumpla para cada hijo
        cout << endl; //linea en blanco para separar de la siguiente ruta
    }

    if (arbol->hijos.size() >= 2) {
        cout << "    Av.Canevaro " << arbol->hijos[1]->dato << endl << endl;
        if (arbol->hijos[1]->hijos.size() >= 1) {
            cout << "     -Calle X: " << arbol->hijos[1]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 2) {
            cout << "     -Calle Y: " << arbol->hijos[1]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 3) {
            cout << "     -Calle Z: " << arbol->hijos[1]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 4) {
            cout << "     -Calle R:: " << arbol->hijos[1]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() > 0 && arbol->hijos[1]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    if (arbol->hijos.size() >= 3) {
        cout << "    Av.Canevaro " << arbol->hijos[2]->dato << endl << endl;
        if (arbol->hijos[2]->hijos.size() >= 1) {
            cout << "     -Calle X: " << arbol->hijos[2]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 2) {
            cout << "     -Calle Y: " << arbol->hijos[2]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 3) {
            cout << "     -Calle Z: " << arbol->hijos[2]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 4) {
            cout << "     -Calle R: " << arbol->hijos[2]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() > 0 && arbol->hijos[2]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    if (arbol->hijos.size() >= 4) {
        cout << "    Av.Canevaro " << arbol->hijos[3]->dato << endl << endl;
        if (arbol->hijos[3]->hijos.size() >= 1) {
            cout << "     -Calle X: " << arbol->hijos[3]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() >= 2) {
            cout << "     -Calle Y: " << arbol->hijos[3]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() >= 3) {
            cout << "     -Calle Z: " << arbol->hijos[3]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() >= 4) {
            cout << "     -Calle R: " << arbol->hijos[3]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() > 0 && arbol->hijos[3]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    cout << "Recorrido en inorden:" << endl;
    inorden(arbol);
    cout << endl;

    cout << "Recorrido en postorden:" << endl;
    postorden(arbol);
    cout << endl;
}
void destinoVilla(string sede) {
    int numNodos;
    cout << "Ingrese la cantidad de nodos: ";
    cin >> numNodos;

    do {
        cout << "Ingrese la cantidad de nodos: ";
        cin >> numNodos;
        if (numNodos < 10 || numNodos > 15) {
            cout << "La cantidad de nodos debe estar entre 10 y 15" << endl;
        }
    } while (numNodos < 10 || numNodos > 15);

    NodoArbol* arbol = generarArbolAleatorio(numNodos);

    cout << "Elementos de la \"T\" por extension:" << endl;
    porExtension(arbol, sede);
    cout << endl;

    cout << "Digrafo:" << endl;
    imprimirArbol(arbol, sede);
    cout << endl;

    cout << "DESTINO: Sede Villa (padre): " << arbol->dato << endl;
    cout << "    Av. Canevaro: " << arbol->hijos[0]->dato << endl << endl;

    if (arbol->hijos[0]->hijos.size() >= 1) {
        cout << "     -Calle E: " << arbol->hijos[0]->hijos[0]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 2) {
        cout << "     -Calle I: " << arbol->hijos[0]->hijos[1]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 3) {
        cout << "     -Calle O: " << arbol->hijos[0]->hijos[2]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 4) {
        cout << "     -Calle U: " << arbol->hijos[0]->hijos[3]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() > 0 && arbol->hijos[0]->hijos.size() <= 4) {
        cout << endl;
    }

    if (arbol->hijos.size() >= 2) {
        cout << "    Av.Canevaro " << arbol->hijos[1]->dato << endl << endl;
        if (arbol->hijos[1]->hijos.size() >= 1) {
            cout << "     -Calle E: " << arbol->hijos[1]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 2) {
            cout << "     -Calle I: " << arbol->hijos[1]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 3) {
            cout << "     -Calle O: " << arbol->hijos[1]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 4) {
            cout << "     -Calle U: " << arbol->hijos[1]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() > 0 && arbol->hijos[1]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    if (arbol->hijos.size() >= 3) {
        cout << "    Av.Canevaro " << arbol->hijos[2]->dato << endl << endl;
        if (arbol->hijos[2]->hijos.size() >= 1) {
            cout << "     -Calle E: " << arbol->hijos[2]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 2) {
            cout << "     -Calle I: " << arbol->hijos[2]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 3) {
            cout << "     -Calle O: " << arbol->hijos[2]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 4) {
            cout << "     -Calle U: " << arbol->hijos[2]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() > 0 && arbol->hijos[2]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    if (arbol->hijos.size() >= 4) {
        cout << "    Av.Canevaro " << arbol->hijos[3]->dato << endl << endl;
        if (arbol->hijos[3]->hijos.size() >= 1) {
            cout << "     -Calle E: " << arbol->hijos[3]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() >= 2) {
            cout << "     -Calle I: " << arbol->hijos[3]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() >= 3) {
            cout << "     -Calle O: " << arbol->hijos[3]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() >= 4) {
            cout << "     -Calle U: " << arbol->hijos[3]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() > 0 && arbol->hijos[3]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    cout << "Recorrido en inorden:" << endl;
    inorden(arbol);
    cout << endl;

    cout << "Recorrido en postorden:" << endl;
    postorden(arbol);
    cout << endl;
}
void destinoSM(string sede) {
    int numNodos;
    cout << "Ingrese la cantidad de nodos: ";
    cin >> numNodos;

    do {
        cout << "Ingrese la cantidad de nodos: ";
        cin >> numNodos;
        if (numNodos < 10 || numNodos > 15) {
            cout << "La cantidad de nodos debe estar entre 10 y 15" << endl;
        }
    } while (numNodos < 10 || numNodos > 15);

    NodoArbol* arbol = generarArbolAleatorio(numNodos);

    cout << "Elementos de la \"T\" por extension:" << endl;
    porExtension(arbol, sede);
    cout << endl;

    cout << "Digrafo:" << endl;
    imprimirArbol(arbol, sede);
    cout << endl;

    cout << "DESTINO: San Miguel (padre): " << arbol->dato << endl;
    cout << "    Av. Canevaro: " << arbol->hijos[0]->dato << endl << endl;

    if (arbol->hijos[0]->hijos.size() >= 1) {
        cout << "     -Calle 1: " << arbol->hijos[0]->hijos[0]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 2) {
        cout << "     Calle 2" << arbol->hijos[0]->hijos[1]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 3) {
        cout << "     -Calle 3: " << arbol->hijos[0]->hijos[2]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 4) {
        cout << "     -Calle 4: " << arbol->hijos[0]->hijos[3]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() > 0 && arbol->hijos[0]->hijos.size() <= 4) {
        cout << endl;
    }

    if (arbol->hijos.size() >= 2) {
        cout << "    Av.Canevaro " << arbol->hijos[1]->dato << endl << endl;
        if (arbol->hijos[1]->hijos.size() >= 1) {
            cout << "     -Calle 1: " << arbol->hijos[1]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 2) {
            cout << "     -Calle 2: " << arbol->hijos[1]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 3) {
            cout << "     -Calle 3: " << arbol->hijos[1]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 4) {
            cout << "     -Calle 4: " << arbol->hijos[1]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() > 0 && arbol->hijos[1]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    if (arbol->hijos.size() >= 3) {
        cout << "    Av.Canevaro " << arbol->hijos[2]->dato << endl << endl;
        if (arbol->hijos[2]->hijos.size() >= 1) {
            cout << "     -Calle 1: " << arbol->hijos[2]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 2) {
            cout << "     -Calle 2: " << arbol->hijos[2]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 3) {
            cout << "     -Calle 3: " << arbol->hijos[2]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 4) {
            cout << "     -Calle 4: " << arbol->hijos[2]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() > 0 && arbol->hijos[2]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    if (arbol->hijos.size() >= 4) {
        cout << "    Av.Canevaro " << arbol->hijos[3]->dato << endl << endl;
        if (arbol->hijos[3]->hijos.size() >= 1) {
            cout << "     -Calle 1 " << arbol->hijos[3]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() >= 2) {
            cout << "     -Calle 2: " << arbol->hijos[3]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() >= 3) {
            cout << "     -Calle 3: " << arbol->hijos[3]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() >= 4) {
            cout << "     -Calle 4: " << arbol->hijos[3]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[3]->hijos.size() > 0 && arbol->hijos[3]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    cout << "Recorrido en inorden:" << endl;
    inorden(arbol);
    cout << endl;

    cout << "Recorrido en postorden:" << endl;
    postorden(arbol);
    cout << endl;
}

void marco() {
    char letra1 = 205;
    char letra2 = 186;
    char letra3 = 201;
    char letra4 = 187;
    char letra5 = 200;
    char letra6 = 188;

    Console::SetWindowSize(87, 30);
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    for (int i = 1; i <= 85; i++)
    {
        Console::SetCursorPosition(i, 1);
        cout << letra1;
        Console::SetCursorPosition(i, 28);
        cout << letra1;
    }
    for (int b = 2; b < 28; b++)
    {
        Console::SetCursorPosition(1, b);
        cout << letra2;
        Console::SetCursorPosition(85, b);
        cout << letra2;
    }
    Console::SetCursorPosition(1, 1);
    cout << letra3;
    Console::SetCursorPosition(85, 1);
    cout << letra4;
    Console::SetCursorPosition(1, 28);
    cout << letra5;
    Console::SetCursorPosition(85, 28);
    cout << letra6;
}

void marco2() {

    Console::SetWindowSize(87, 30);
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    for (int i = 1; i <= 85; i++)
    {
        Console::SetCursorPosition(i, 1);
        cout << "_";
        Console::SetCursorPosition(i, 28);
        cout << "_";
    }
    for (int b = 2; b < 28; b++)
    {
        Console::SetCursorPosition(1, b);
        cout << "|";
        Console::SetCursorPosition(85, b);
        cout << "|";
    }
    Console::SetCursorPosition(1, 1);
    cout << "+";
    Console::SetCursorPosition(85, 1);
    cout << "+";
    Console::SetCursorPosition(1, 28);
    cout << "+";
    Console::SetCursorPosition(85, 28);
    cout << "+";
}

void marco3() {

    Console::SetWindowSize(87, 30);
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    for (int i = 15; i <= 70; i++)
    {
        Console::SetCursorPosition(i, 13);
        cout << "_";
        Console::SetCursorPosition(i, 26);
        cout << "_";
    }
    for (int b = 14; b < 26; b++)
    {
        Console::SetCursorPosition(15, b);
        cout << "|";
        Console::SetCursorPosition(70, b);
        cout << "|";
    }
    Console::SetCursorPosition(15, 13);
    cout << "+";
    Console::SetCursorPosition(70, 13);
    cout << "+";
    Console::SetCursorPosition(15, 26);
    cout << "+";
    Console::SetCursorPosition(70, 26);
    cout << "+";
}


void Titulo() {
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(16, 3);
    cout << " _______            __  __     " << endl;
    Console::SetCursorPosition(16, 4);
    cout << "|__   __|          |  \\/  |    " << endl;
    Console::SetCursorPosition(16, 5);
    cout << "   | |_ __ ___  ___| \\  / | __ _ _ __  _ __   ___ _ __ " << endl;
    Console::SetCursorPosition(16, 6);
    cout << "   | | '__/ _ \\/ _ \\ |\\/| |/ _` | '_ \\| '_ \\ / _ \\ '__|" << endl;
    Console::SetCursorPosition(16, 7);
    cout << "   | | | |  __/  __/ |  | | (_| | |_) | |_) |  __/ |   " << endl;
    Console::SetCursorPosition(16, 8);
    cout << "   |_|_|  \\___|\\___|_|  |_|\\__,_| .__/| .__/ \\___|_|   " << endl;
    Console::SetCursorPosition(15, 9);
    cout << "                                 | |   | |              " << endl;
    Console::SetCursorPosition(15, 10);
    cout << "                                 |_|   |_|              " << endl;

}

void Bordeinterior() {
    char letra1 = 205;
    char letra2 = 186;
    char letra3 = 201;
    char letra4 = 187;
    char letra5 = 200;
    char letra6 = 188;

    for (int i = 15; i < 70; i++)
    {
        Console::SetCursorPosition(i, 12);
        cout << letra1;
        Console::SetCursorPosition(i, 25);
        cout << letra1;
    }
    for (int b = 13; b < 25; b++)
    {
        Console::SetCursorPosition(15, b);
        cout << letra2;
        Console::SetCursorPosition(70, b);
        cout << letra2;
    }
    Console::SetCursorPosition(15, 12);
    cout << letra3;
    Console::SetCursorPosition(70, 12);
    cout << letra4;
    Console::SetCursorPosition(15, 25);
    cout << letra5;
    Console::SetCursorPosition(70, 25);
    cout << letra6;
}
void menu() {
    char opcion;
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(76, 3);
    cout << "&&&";
    Console::SetCursorPosition(75, 4);
    cout << "&&&/&";
    Console::SetCursorPosition(74, 5);
    cout << "&\/&|&&&&";
    Console::SetCursorPosition(73, 6);
    cout << "&&&\&|&/&&&";
    Console::SetCursorPosition(74, 7);
    cout << "&&&\|/&&&";
    Console::SetCursorPosition(74, 8);
    cout << "& }}{  &";
    Console::SetCursorPosition(76, 9);
    cout << "}{{";
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(7, 3);
    cout << "&&&";
    Console::SetCursorPosition(6, 4);
    cout << "&&&/&";
    Console::SetCursorPosition(5, 5);
    cout << "&\/&|&&&&";
    Console::SetCursorPosition(4, 6);
    cout << "&&&\&|&/&&&";
    Console::SetCursorPosition(5, 7);
    cout << "&&&\|/&&&";
    Console::SetCursorPosition(5, 8);
    cout << "& }}{  &";
    Console::SetCursorPosition(7, 9);
    cout << "}{{";

    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(33, 10);
    cout << " .:::::::::::::::.";
    Console::SetCursorPosition(33, 11);
    cout << " ::::::.....::::::";
    Console::SetCursorPosition(33, 12);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 13);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 14);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 15);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 16);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 17);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 18);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 19);
    cout << "||:::::::::::::::||";
    Console::SetCursorPosition(33, 20);
    cout << "°:::::......::::::° ";



    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(30, 3);
    cout << " __  __              __";
    Console::SetCursorPosition(29, 4);
    cout << " |  \\/  |            /_/  ";
    Console::SetCursorPosition(29, 5);
    cout << " | \\  / | ___ _ __  _   _ ";
    Console::SetCursorPosition(29, 6);
    cout << " | |\\/| |/ _ \\ '_ \\| | | |";
    Console::SetCursorPosition(29, 7);
    cout << " | |  | |  __/ | | | |_| |";
    Console::SetCursorPosition(29, 8);
    cout << " |_|  |_|\\___|_| |_|\\__,_|";
    Console::SetCursorPosition(27, 22);
    Console::ForegroundColor = ConsoleColor::Red;
    cout << "Digite el número de opción a realizar";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(35, 24);
    cout << "1) TreeMapper";
    Console::SetCursorPosition(35, 25);
    cout << "2) Conceptos";
    Console::SetCursorPosition(35, 26);
    cout << "3) Salir";
}
void arbolito()
{
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(40, 13);
    cout << "####o#";
    Console::SetCursorPosition(36, 14);
    cout << "#o# \\# | _#,#";
    Console::SetCursorPosition(36, 15);
    cout << "###\\|/ # #o#";
    Console::SetCursorPosition(36, 16);
    cout << " ## {} {## #";
    Console::SetCursorPosition(39, 17);
    cout << " } { {";
    Console::SetCursorPosition(39, 18);
    cout << " , '  `";

}

void decoracion()
{

    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(76, 3);
    cout << "&&&";
    Console::SetCursorPosition(75, 4);
    cout << "&&&/&";
    Console::SetCursorPosition(74, 5);
    cout << "&\/&|&&&&";
    Console::SetCursorPosition(73, 6);
    cout << "&&&\&|&/&&&";
    Console::SetCursorPosition(74, 7);
    cout << "&&&\|/&&&";
    Console::SetCursorPosition(74, 8);
    cout << "& }}{  &";
    Console::SetCursorPosition(76, 9);
    cout << "}{{";
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(7, 3);
    cout << "&&&";
    Console::SetCursorPosition(6, 4);
    cout << "&&&/&";
    Console::SetCursorPosition(5, 5);
    cout << "&\/&|&&&&";
    Console::SetCursorPosition(4, 6);
    cout << "&&&\&|&/&&&";
    Console::SetCursorPosition(5, 7);
    cout << "&&&\|/&&&";
    Console::SetCursorPosition(5, 8);
    cout << "& }}{  &";
    Console::SetCursorPosition(7, 9);
    cout << "}{{";

    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(33, 2);
    cout << " .:::::::::::::::.";
    Console::SetCursorPosition(33, 3);
    cout << " ::::::.....::::::";
    Console::SetCursorPosition(33, 4);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 5);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 6);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 7);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 8);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 9);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 10);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 11);
    cout << "||:::::::::::::::||";
    Console::SetCursorPosition(33, 12);
    cout << "°:::::......::::::° ";

    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(40, 5);
    cout << "####o#";
    Console::SetCursorPosition(36, 6);
    cout << "#o# \\# | _#,#";
    Console::SetCursorPosition(36, 7);
    cout << "###\\|/ # #o#";
    Console::SetCursorPosition(36, 8);
    cout << " ## {} {## #";
    Console::SetCursorPosition(39, 9);
    cout << " } { {";
    Console::SetCursorPosition(39, 10);
    cout << " , '  `";


}


void inicio() {
    setlocale(LC_ALL, "spanish");
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(37, 14);
    cout << "Integrantes" << endl;
    Console::SetCursorPosition(17, 15);
    cout << "----------------------------------------------------" << endl;
    Console::SetCursorPosition(17, 16);
    cout << "1. Sotomayor Barrios Lucas - U202323168" << endl;
    Console::SetCursorPosition(17, 17);
    cout << "2. Choquehuanca Núñez Luciana Carolina - U202319431" << endl;
    Console::SetCursorPosition(17, 18);
    cout << "3. Chacaliaza Vilca Christian Bernabe - U202318745" << endl;
    Console::SetCursorPosition(17, 19);
    cout << "4. Durand Valente Gabriela Andrea - U202311957" << endl;
    Console::SetCursorPosition(17, 20);
    cout << "5. Ventura Saldaña William Agustín - U202310536" << endl;
    Console::SetCursorPosition(17, 24);
    cout << "Presione dos veces Enter para empezar el programa..." << endl;
    while (cin.get() != '\n') {}
    system("cls");
}

void reloj()
{
    clock_t start_time = clock();
    while ((clock() - start_time) / CLOCKS_PER_SEC < 4); //SEGUNDOS PARA QUE CARGUE EL PROGRAMA ;)
}


void conceptos() {
    int x = 20;
    int y = 8;
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(x, y);
    cout << "   ___   ___    __  ___   __  ___  _____  ___  __    " << endl;
    Console::SetCursorPosition(x, y + 1);
    cout << "  / __\\ /___\\/\\ \\ \\/ __\\ /__\\/ _ \\/__   \\/___\\/ _\\   " << endl;
    Console::SetCursorPosition(x, y + 2);
    cout << " / /   //  //  \\/ / /   /_\\ / /_)/  / /\\//  //\\ \\    " << endl;
    Console::SetCursorPosition(x, y + 3);
    cout << "/ /___/ \\_// /\\  / /___//__/ ___/  / / / \\_// _\\ \\   " << endl;
    Console::SetCursorPosition(x, y + 4);
    cout << "\\____/\\___/\\_\\ \\/\\____/\\__/\\/      \\/  \\___/  \\__/   " << endl;
    Console::SetCursorPosition(x, y + 6);
    cout << "Arboles o Grafos:" << endl;
    Console::SetCursorPosition(x, y + 7);
    cout << "Un grafo es estructura matemática fundamental para la comprensión y análisis de datos complejos," << endl;
    Console::SetCursorPosition(x, y + 8);
    cout << "generada por vértices que llamamos nodos, los cuales se conectan entre sí mediante aristas" << endl;
    Console::SetCursorPosition(x, y + 10);
    cout << "Se dividen en dos tipos" << endl;
    Console::SetCursorPosition(x, y + 11);
    cout << "Dirigido: Las aristas tienen una dirección específica por ello su relación es unidireccional" << endl;
    Console::SetCursorPosition(x, y + 12);
    cout << " (si A está conectado con un nodo B, no necesariamente implica que B esté conectado con A." << endl;
    Console::SetCursorPosition(x, y + 13);
    cout << "No dirigido: Las aristas no tienen una dirección específica por ello su relación es simétrica" << endl;
    Console::SetCursorPosition(x, y + 14);
    cout << "(si A está conectado con un nodo B, A está conectado con B y B está conectado con A.)" << endl;
    Console::SetCursorPosition(x, y + 16);
    cout << "Los árboles tienen un valor de orden <<n>>, y a eso se le atribuye el nombre de arboles n-arios " << endl;
    Console::SetCursorPosition(x, y + 17);
    cout << "Asimismo, se guia de la cantidad de hijos. Cuando su valor de orden y de hijos es 2 se le llama binario" << endl;
    Console::SetCursorPosition(x, y + 19);
    cout << "Busqueda de arboles: Proceso por el cual se visita cada vértice de un árbol “T” que se puede dar en cierto orden" << endl;
    Console::SetCursorPosition(x, y + 21);
    cout << "especifico. Existen tres tipos de recorridos: Enorden, Preorden y Postorden." << endl;
    Console::SetCursorPosition(x, y + 22);
    cout << "TreeMapper es una aplicación basada en árboles y búsqueda de árboles. Debido a que " << endl;
    Console::SetCursorPosition(x, y + 23);
    cout << "busca mostrar las mejores rutas para llegar a la UPC." << endl;
}


int main() {
    Bordeinterior();
    marco();
    Titulo();
    inicio();

    do {
        while (!kbhit()) {}
        char c = getch();
        if (c == '\r') {
            system("cls");
            break;
        }
    } while (true);

    marco2();
    menu();
    arbolito();


    bool salir = false;
    char opcion;

    while (!salir) {
        opcion = _getch();
        int sedeOption;
        string sede;

        switch (opcion) {
        case '1':
            Console::SetCursorPosition(17, 27);
            cout << "Has seleccionado ejecutar TreeMapper. Espere un momento.\n";
            reloj();
            system("cls");
            marco2();
            Console::SetCursorPosition(20, 3);
            Console::ForegroundColor = ConsoleColor::White;
            srand(time(NULL));
            marco3();
            decoracion();
            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(19, 16);
            cout << "Seleccione la sede :" << endl;
            Console::SetCursorPosition(18, 17);
            Console::ForegroundColor = ConsoleColor::Red;
            cout << "(Presione el numero de opcion y despues enter)" << endl;
            Console::SetCursorPosition(20, 18);
            Console::ForegroundColor = ConsoleColor::White;
            cout << "1. SI - Sede San Isidro" << endl;
            Console::SetCursorPosition(20, 19);
            cout << "2. MO - Sede Monterrico" << endl;
            Console::SetCursorPosition(20, 20);
            cout << "3. Villa - Sede Villa" << endl;
            Console::SetCursorPosition(20, 21);
            cout << "4. SM - Sede San Miguel" << endl;
            Console::SetCursorPosition(20, 22);
            cin >> sedeOption;
            Console::Clear();

            switch (sedeOption) {
            case 1:
                sede = "SI";
                destinoSI(sede);
                break;
            case 2:
                sede = "MO";
                destinoMO(sede);
                break;
            case 3:
                sede = "Villa";
                destinoVilla(sede);
                break;
            case 4:
                sede = "SM";
                destinoSM(sede);
                break;
            default:
                cout << "Opción inválida." << endl;
                return 1;
            }
            _getch();
            break;
        case '2':
            Console::SetCursorPosition(17, 27);
            cout << "Has seleccionado la opción conceptos. Presione dos veces Enter.\n";
            system("cls");
            conceptos();
            _getch();
            break;
        case '3':
            Console::SetCursorPosition(17, 27);
            cout << "Has seleccionado la opción salir. Presione dos veces Enter.\n";
            system("cls");
            Console::ForegroundColor = ConsoleColor::DarkGreen;
            Console::SetCursorPosition(40, 8);
            cout << "GRACIAS POR SU ATENCION" << endl;
            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(40, 10);
            cout << "atentamente, grupo 9" << endl;
            _getch();
            break;
        default:
            Console::SetCursorPosition(17, 27);
            cout << "Opción no válida. Por favor, selecciona una opción válida.\n";
            _getch();
            break;
        }
    }
    return 0;
    _getch();
}
