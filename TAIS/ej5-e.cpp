/*@ <authors>
 *
 * Daniel Barroso Casado    : TAIS06
 * Mario Campos Sobrino     : TAIS09
 *
 *@ </authors> 

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> 


 // ================================================================
 // Resolvemos este ejercicio recorriendo todos los vértices del grafo, utilizando un recorrido en profundidad. Si hay algun ciclo pero el ultimo vertice es alcanzable, entonces a veces se llega a la ultima instruccion.
 // En caso de que haya un ciclo y el ultimo vertice no sea alcanzable, nunca se va a llegar a la ultima instruccion. Si no hay ciclos pero se llega a la ultima instruccion, siempre
 // es alcanzable. El coste de la funcion es O(V + A)
 // ================================================================
 //@ <answer>

using Camino = deque<int>;

class CicloDirigido {

private:
    std::vector<bool> visit; // visit[v] = ¿se ha alcanzado a v en el dfs?
    std::vector<int> ant; // ant[v] = vértice anterior en el camino a v
    std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
    Camino _ciclo; // ciclo dirigido (vacío si no existe)
    bool hayCicloBoff;   // Ciclo dado por arsista J : Final
    bool alcanzado;

    void dfs(Digrafo const& g, int v) {
        apilado[v] = true;
        visit[v] = true;
        for (int w : g.ady(v)) {  // O(V + A)

            if (!visit[w]) { // encontrado un nuevo vértice, seguimos
                ant[w] = v; dfs(g, w);
            }
            else if (apilado[w]) { // hemos detectado un ciclo
                hayCicloBoff = true;
            }
        }
        apilado[v] = false;
    }

public:
    CicloDirigido(Digrafo const& g) : visit(g.V(), false), ant(g.V()),
        apilado(g.V(), false), hayCicloBoff(false) {
        dfs(g, 0);
        alcanzado = visit[g.V() - 1];
    }

    bool peroHayCicloBoff() const { return hayCicloBoff; }
    Camino const& ciclo() const { return _ciclo; }
    bool destinoAlcanzado() const { return alcanzado; }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int L; cin >> L;     // numero Lineas del caso de prueba

    if (!std::cin)  // fin de la entrada
        return false;

    Digrafo g(L + 1);
    char type;
    for (int i = 0; i < L; i++) {
        cin >> type;
        int v = i + 1;
        if (type == 'J') {
            cin >> v;
            v--;
        }
        else if (type == 'C') {
            cin >> v;
            v--;
            g.ponArista(i, i + 1);
        }
        g.ponArista(i, v);
    }

    CicloDirigido ciclos(g);

    if (ciclos.peroHayCicloBoff()) {
        if (ciclos.destinoAlcanzado() ? cout << "A VECES\n" : cout << "NUNCA\n");
    }
    else
        cout << "SIEMPRE\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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