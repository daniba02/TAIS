
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


using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class CamionLlega {

public:
    CamionLlega(GrafoValorado<int> const& g, int& origen, int& destino, int& tam) : visit(g.V(), false), destino(destino), origen(origen), recorrido(false), tam(tam) {

        dfs(g, origen);
    }

    bool getLlegado() {
        return recorrido;
    }


private:

    vector<bool> visit;
    int destino;
    int origen;
    int tam;
    bool recorrido;

    void dfs(GrafoValorado<int> const& g, int v) {

        visit[v] = true;
        if (v == destino) recorrido = true;

        for (auto a : g.ady(v)) {
            
            if (tam <= a.valor()) {
                int w = a.otro(v);

                if (!visit[w]) {
                    dfs(g, w);
                }
            }
        }
    }
};


bool resuelveCaso() {

    // leer los datos de la entrada
    int V, E, K;
    cin >> V;

    if (!std::cin) return false;

    cin >> E;

    GrafoValorado<int> g(V);

    for (int i = 0; i < E; i++) {

        int a1, a2, value;

        cin >> a1 >> a2 >> value;
        
        g.ponArista({ a1 - 1, a2 - 1, value});

    }

    cin >> K;

    for (int i = 0; i < K; i++) {

        int origen, destino, tam;

        cin >> origen >> destino >> tam;
        origen--;
        destino--;
        CamionLlega c(g, origen, destino, tam);

        if (c.getLlegado()) cout << "SI\n";
        else cout << "NO\n";

    }


    

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej6-2.txt");
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
