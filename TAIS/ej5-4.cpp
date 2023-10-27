
/*
@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 * Daniel Barroso Casado
 * TAIS06
 *
 *@ </authors>

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include "Digrafo.h"
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

using sum = pair<bool, int>;

class Sumidero {

private:

    vector<bool> visit;
    vector<int> grado;
    bool sumidero;
    sum hay;


    void dfs(Digrafo const& g, int v) {

        visit[v] = true;

        for (int w : g.ady(v)) {
            
            grado[w]++;

            if (grado[w] == g.V() - 1 && g.ady(w).size() == 0) {
                hay.first = true;
                hay.second = w;
            }
            if (!visit[w]) { // encontrado un nuevo vértice, seguimos
                dfs(g, w);
            }

        }
    }

public:

    Sumidero(Digrafo const& g) : visit(g.V(), false), sumidero(false), grado(g.V(), 0), hay(false, -1) {
        for (int v = 0; v < g.V(); ++v)
            if (!visit[v])
                dfs(g, v);
    }

    sum getSumidero() {
        return hay;
    }
};




bool resuelveCaso() {

    // leer los datos de la entrada
    Digrafo g(cin);


    if (!std::cin)
        return false;

    Sumidero sum(g);

    if (sum.getSumidero().first ? cout << "SI " << sum.getSumidero().second << "\n" : cout << "NO\n");

    


    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej5-4.txt");
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