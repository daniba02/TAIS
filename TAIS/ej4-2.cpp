
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
#include <functional>
#include <queue>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include "Grafo.h"
 //#include <xtree>
 //#include "BInTree.h";
 //#include "Index_PQ.h"

using namespace std;

// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


class MaximaComponenteConexa {


private:

    vector<bool> visit;
    int maxim;

    int dfs(Grafo const& g, int v) {

        visit[v] = true;

        int tam = 1;

        for (int w : g.ady(v)) {

            if (!visit[w]) {
                tam += dfs(g, w);
            }
        }
        return tam;
    }
    

public:

    MaximaComponenteConexa(Grafo const& g) : visit(g.V(), false), maxim(0) {
        for (int i = 0; i < g.V(); i++) {
            if (!visit[i]) {
                int tam = dfs(g, i);
                maxim = max(maxim, tam);
            }
        }
    }

    int maximo() const{
        return maxim;
    }
    
};


void resuelveCaso() {

    int N, M;

    cin >> N >> M;
    Grafo g(N);

    for (int i = 0; i < M; i++) {

        int a, b;

        cin >> a >> b;
        g.ponArista(a -1 , b -1 );

    }
   


    MaximaComponenteConexa mcc (g);
    cout << mcc.maximo() << "\n";

}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej4-2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}*/