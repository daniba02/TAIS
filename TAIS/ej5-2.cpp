
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
#include <queue>
#include "Digrafo.h"
using namespace std;


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer>


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

using Camino = deque<int>;

class OrdenTopologico {

private:

    vector<bool> visit;
    vector<int> ant;
    vector<bool> apilado;
    bool _hayCiclo;
    deque<int> _orden;
    Camino ciclo;

    void dfs(Digrafo const& g, int v) {
        apilado[v] = true;
        visit[v] = true;
        
        for (int w : g.ady(v)) {
            if (_hayCiclo) return;

            
            if (apilado[w]) {
                _hayCiclo = true;
            }
            else if (!visit[w]) {
                ant[w] = v;
                dfs(g, w);
            }
        }
        apilado[v] = false;
        _orden.push_front(v);
    }

public:

    OrdenTopologico(Digrafo const& g) : visit(g.V(), false), ant(g.V()), apilado(g.V(), false), _hayCiclo(false) {

        for (int v = 0; v < g.V(); v++) {
            if (!visit[v]) {
                dfs(g, v);
            }
        }

    }

    bool hayCiclo() const{
        return _hayCiclo;
    }

    deque<int> orden() {
        return _orden;
    }



};


bool resuelveCaso() {

    // leer los datos de la entrada
    Digrafo g(cin, 1);

    if (!std::cin)return false;

    // resolver el caso posiblemente llamando a otras funciones


    OrdenTopologico tareas(g);

    deque<int> orden = tareas.orden();

    if (tareas.hayCiclo()) cout << "Imposible\n";
    else {
        for (int w: tareas.orden()) {
            cout << w + 1 << ' ';
           
        }
        cout << "\n";
    }

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej5-2.txt");
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