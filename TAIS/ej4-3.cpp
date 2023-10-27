
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
    int conexas;

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

    MaximaComponenteConexa(Grafo const& g, int pos) : visit(g.V(), false), maxim(0), conexas(0) {
        for (int i = 0; i < pos; i++) {
            if (!visit[i]) {
                conexas++;
                if (g.ady(i).size() != 0) {
                    
                }
                int tam = dfs(g, i);
                maxim = max(maxim, tam);
            }
        }
    }

    int maximo() const{
        return maxim;
    }

    int getConexas() const {
        return conexas;
    }

};


bool resuelveCaso() {

    int F, C;

    cin >> F >> C;

    if (!std::cin) return false;

    Grafo g(F * C);
    int pos = 0;
    vector<vector<int>> v(F, vector<int>(C, -1));

    for (int i = 0; i < F; i++) {

        for (int j = 0; j < C; j++) {

            char next;
            cin >> next;

            if (next != '-') {

                v[i][j] = pos;
                pos++;

                if (i - 1 >= 0 && v[i - 1][j] != -1) {
                    g.ponArista(v[i][j], v[i - 1][j]);
                }
                if (j - 1 >= 0 && v[i][j-1] != -1) {
                    g.ponArista(v[i][j], v[i][j -1]);
                }
                if (i + 1 < F && v[i + 1][j] != -1) {
                    g.ponArista(v[i][j], v[i + 1][j]);
                }
                if (j + 1 < C && v[i][j + 1] != -1) {
                    g.ponArista(v[i][j], v[i][j + 1]);
                }
            }
        }
    }



    MaximaComponenteConexa mcc (g, pos);
    cout << mcc.getConexas() << " " << mcc.maximo() << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej4-3.txt");
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