
/*
@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 * Daniel Barroso Casado
 * TAIS06
 *
 *@ </authors>
 * 
 * 6 0 0 0
 * 0 7 0 0
 * 0 0 1 0
 * 0 0 0 4
 * 
 * 

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int casilla(int j, vector<int> const& v) {
    if (j < 0 || j >= v.size()) return 0;
    else return v[j];
}


void resolver(Matriz<int> const& m, const int n) {


    vector<int> v(n);
    int pos = 0; 
    int mx = 0;

    //
    // 2 5 8 3      20 23 30 25     2 5 8 3
    // 1 4 2 9      15 18 15 22     6 12 10 12
    // 9 2 8 5      14 7 13  7      21 14 17 
    // 3 5 2 1      3  5  2  1
    //

    int aux = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--) {

            int v1 = casilla(j - 1, v) + m[i][j];
            int v2 = casilla(j, v) + m[i][j];
            int v3 = aux + m[i][j];
            aux = v[j];
            v[j] = max(v1, v2);
            v[j] = max(v[j], v3);

            if (i == n - 1) {
                if (v[j] >= mx) {
                    mx = v[j];
                    pos = j;
                }
            }

        }
    }

    cout << mx << " " << pos + 1 << "\n";
}

bool resuelveCaso() {

    int n;

    cin >> n;

    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones

    Matriz<int> m(n, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    resolver(m, n);

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejA-4.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
*/