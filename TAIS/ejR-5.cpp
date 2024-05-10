
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
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase
#include "ConjuntosDisjuntos.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class CaminosDFS {
private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    vector<int> precio;
    int coste;
    ConjuntosDisjuntos d;
    vector<int> minimo;
    Grafo g;

    int dfs(Grafo const& G, int v, int rep) {
        visit[v] = true;

        int n = rep;
        for (int w : G.ady(v)) {

            if (!visit[w]) {
                int aux = minimo[d.buscar(v)];

                if (!d.unidos(v, w)) d.unir(v, w);

                n = d.buscar(v);
                minimo[n] = min(minimo[n], aux); // si el precio de el actual es menor que el del anterior
                minimo[n] = min(minimo[n], precio[w]); //si el precio del actual es menor que el del nuevo nodo

                ant[w] = v;
                n = dfs(G, w, n);
            }
        }

        return n;
    }
public:
    CaminosDFS(Grafo const& g, vector<int> const& precio) : g(g), precio(precio), visit(g.V(), false),
        ant(g.V()), coste(0), d(g.V()), minimo(g.V(), INT_MAX) {
        
        
    }

    int realizarDFS(const int s) {

        int n;
        if (!visit[s]) {
            minimo[s] = precio[s];
            n = dfs(g, s, s);
        }
        else {
            n = d.buscar(s);
        }

        return getCoste(n);
    }
    // ¿hay camino del origen a v?

    int getCoste(const int s) const {
        return minimo[s];
    }
};

bool resuelveCaso() {

    int n, c;

    cin >> n >> c;

    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones

    Grafo g(n);
    int a1, a2;

    for (int i = 0; i < c; i++)
    {
        cin >> a1 >> a2;
        g.ponArista(a1 - 1, a2 - 1);
    }

    int s, num;
    cin >> s;
    vector<int> precio(n, INT_MAX);

    for (int i = 0; i < s; i++)
    {
        cin >> num;
        cin >> precio[num - 1];
    }

    int k;
    cin >> k;

    CaminosDFS d(g, precio);

    int min;

    for (int i = 0; i < k; i++)
    {
        cin >> min;
        min = d.realizarDFS(min - 1);
        if (min == INT_MAX ? cout << "MENUDO MARRON\n" : cout << min << "\n");
    }

    cout << "---\n";
        // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejR-5.txt");
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