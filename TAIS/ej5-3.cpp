
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

using par = pair<int, int>;

class BFSDirigido {
public:
    BFSDirigido(Digrafo const& g, int K) : visit(g.V(), false)
        ,
        ant(g.V()), dist(g.V()){
        bfs(g, K, 0, g.V() - 1);
    }
    bool hayCamino(int v) const {
        return visit[v];
    }
    int distancia(int v) const {
        return dist[v];
    }

    int getminimo() const {
        return min;
    }



private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s->v más corto
    int min = 0;

    void bfs(Digrafo const& g, int K, int origen, int destino) {
        std::queue<par> q;
        visit[origen] = true;
        q.push({origen, 0});

        bool terminado = false;

        while (!terminado) {

            par v = q.front();
            q.pop();
            int cont = 1;

            while (!terminado && cont <= K) {

                int ady = v.first + cont;

                if (g.ady(ady).size() > 0) {
                    ady = g.ady(ady)[0];
                }

                if (ady == destino) {
                    terminado = true;
                    min = v.second + 1;
                }
                else if (!visit[ady]) {
                    visit[ady] = true;
                    q.push({ ady, v.second + 1 });
                }

                cont++;
            }
        }
       
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, K, S, E;
    cin >> N >> K >> S >> E;


    if (N == 0 && K == 0 && S == 0 && E == 0)
        return false;

    // resolver el caso posiblemente llamando a otras funciones

    Digrafo g(N * N);

    for (int i = 0; i < S + E; i++) {
        int ini, fin;
        cin >> ini >> fin;

        g.ponArista(ini - 1, fin - 1);
    }
    // escribir la solución

    BFSDirigido dir(g, K);

    cout << dir.getminimo() << "\n";


    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej5-3.txt");
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