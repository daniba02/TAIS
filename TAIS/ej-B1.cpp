
/*
@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
 *
 * Daniel Barroso Casado
 * TAIS06
 *
 *@ </authors>

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Matriz.h"


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer>


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

struct cofre {
    int profundidad;
    int oro;
};

struct solucion {
    int oro;
    int numCofres;
    vector<cofre> v;
};

int cofres(int i, int j, vector<cofre> const& v, Matriz<int>& M) {

}


void resolver(int T, vector<cofre> v) {

    Matriz<int> M(T, -1);

    int max = cofres(v.size(), T, v, M);
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int T; 
    cin >> T;

    if (!std::cin)  // fin de la entrada
        return false;

    int n;
    cin >> n;

    vector<cofre> v(n);

    for (int i = 0; i < n; i++)
    {   
        cin >> v[i].profundidad >> v[i].oro;
    }

    resolver(T, v);

    int n;
    cin >> n;


    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}*/