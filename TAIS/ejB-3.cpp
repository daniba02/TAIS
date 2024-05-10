
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
#include <algorithm>
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

int casilla(int i, vector<int> const& v) {

    if (i < 0 || i >= v.size()) return 0;
    else return v[i];
}

int resolver(vector<int> const& v, int i, int j, Matriz<int> & M) {

    if (i < j) return 0;
    else if (i == j) return v[i];
    else {

        int sol1 = max(resolver(v, i - 1, j - 1, M), resolver(v, i, j - 1, M));


    }
}

bool resuelveCaso() {

    int n;

    cin >> n;

    if (n == 0)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    resolver(v, n);
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejB-3.txt");
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