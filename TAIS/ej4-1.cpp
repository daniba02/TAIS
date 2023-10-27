
/*
@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer>


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>


class GrafoLibre {


private:

    vector<bool> visit;
    vector<int> ant;
    vector<int> dist;
    int s;
    bool free;

    bool bfsLibre(Grafo const& g){

        queue<int> q;
        dist[s] = 0;
        visit[s] = true;
        q.push(s);
        bool libre = true;
        int visitados = 1;

        while (!q.empty() && libre) {
            int v = q.front();
            q.pop();

            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v;
                    dist[w] = dist[v] + 1;
                    visit[w] = true;
                    q.push(w);
                    visitados++;
                }
                else if (visit[w] && ant[v] != w) libre = false;
            }
        }

        if (visitados != g.V()) libre = false;

        return libre;
    }

public:

    GrafoLibre(Grafo const& g, int s) : visit(g.V(), false), ant(g.V()), dist(g.V()), s(s) {

        free = bfsLibre(g);
    }
    
    bool es_libre() {
        return free;
   }


};


bool resuelveCaso() {

    int V, A, primero;
    bool completo = true;

    Grafo g(cin);

    if (!std::cin) {
        return false;
    }


    

    GrafoLibre libre (g, 0);

    if (libre.es_libre()) cout << "SI\n";
    else cout << "NO\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej4-1.txt");
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