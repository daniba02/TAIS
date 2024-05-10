
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
#include <unordered_map>
#include <queue>
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
    int s; // vértice origen
    int cont; 
    void dfs(Grafo const& G, int v) {
        visit[v] = true;
        cont++;
        for (int w : G.ady(v)) {
            if (!visit[w]) {
                ant[w] = v;
                dfs(G, w);
            }
        }
    }
public:
    CaminosDFS(Grafo const& g, int s) : visit(g.V(), false),
        ant(g.V()), s(s), cont(0) {
        dfs(g, s);
    }

    int amigos() const {
        return cont;
    }

    // ¿hay camino del origen a v?
    bool hayCamino(int v) const {
        return visit[v];
    }
    using Camino = std::deque<int>; // para representar caminos
    // devuelve un camino desde el origen a v (debe existir)
    Camino camino(int v) const {
        if (!hayCamino(v))
            throw std::domain_error("No existe camino");
        Camino cam;
        // recuperamos el camino retrocediendo
        for (int x = v; x != s; x = ant[x])
            cam.push_front(x);
        cam.push_front(s);
        return cam;
    }
};



bool resuelveCaso() {

    // leer los datos de la entrada

    int n; // usuarios
    int m; // grupos

    cin >> n;
    cin >> m;

    if (!std::cin)  // fin de la entrada
        return false;

    int num, nodo;

    ConjuntosDisjuntos g(n);

    for (int i = 0; i < m; i++) {

        cin >> num;

        if (num > 0) {

            cin >> nodo;
            int ant = nodo;

            for (int i = 1; i < num; i++)
            {
                cin >> nodo;
                if (!g.unidos(ant - 1, nodo - 1)) g.unir(ant - 1, nodo - 1);
                ant = nodo;
            }
        }
    }

    // resolver el caso posiblemente llamando a otras funciones

    for (int i = 0; i < n; i++) {

        cout << g.cardinal(i) << " ";
       
    }
    cout << "\n";

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej4-4.txt");
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