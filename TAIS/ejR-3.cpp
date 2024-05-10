
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
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

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
    int coste;
    void dfs(Grafo const& G, int v, vector<int> const& precio, int& min) {
        if (min > precio[v]) min = precio[v];
        visit[v] = true;
        for (int w : G.ady(v)) {
            if (!visit[w]) {
                ant[w] = v;
                dfs(G, w, precio, min);
            }
        }
    }
public:
    CaminosDFS(Grafo const& g, vector<int> const& precio) : visit(g.V(), false),
        ant(g.V()), coste(0) {

        for (int i = 0; i < g.V(); i++)
        {
            if (!visit[i]) {
                int min = INT_MAX;
                dfs(g, i, precio, min);
                coste += min;
            }
        }
    }
    // ¿hay camino del origen a v?

    int getCoste() const {
        return coste;
    }
};


bool resuelveCaso() {

    // leer los datos de la entrada

    int n, m;

    cin >> n >> m;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    Grafo g(n);

    int a1, a2;

    for (int i = 0; i < m; i++)
    {
        cin >> a1 >> a2;
        g.ponArista(a1 - 1, a2 - 1);
    }

    CaminosDFS dfs(g, v);

    cout << dfs.getCoste() << "\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejR-3.txt");
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