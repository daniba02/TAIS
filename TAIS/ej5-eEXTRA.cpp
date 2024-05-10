
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
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer>


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

class CicloDirigido {
public:
    CicloDirigido(Digrafo const& g) : visit(g.V(), false), ant(g.V()),
        apilado(g.V(), false), hayciclo(false), alcanzado(false) {
        
        dfs(g, 0);
        alcanzado = visit[g.V() - 1];
    }
    bool hayCiclo() const { return hayciclo; }
    bool alcanzable() const{ return alcanzado; }
private:
    std::vector<bool> visit; // visit[v] = �se ha alcanzado a v en el dfs?
    std::vector<int> ant; // ant[v] = v�rtice anterior en el camino a v
    std::vector<bool> apilado; // apilado[v] = �est� el v�rtice v en la pila?
    bool hayciclo;
    bool alcanzado;


    void dfs(Digrafo const& g, int v) {
        apilado[v] = true;
        visit[v] = true;
        for (int w : g.ady(v)) {
            
            if (!visit[w]) { // encontrado un nuevo v�rtice, seguimos
                ant[w] = v; dfs(g, w);
            }
            else if (apilado[w]) {
                hayciclo = true;
            }
        }
        apilado[v] = false;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada

    int n;
    cin >> n;

    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones

    Digrafo g(n + 1);

    char letra;
    int nodo;

    for (int i = 0; i < n; i++) {

        cin >> letra;

        if (letra == 'C') {
            cin >> nodo;
            g.ponArista(i, nodo);
            g.ponArista(i, i + 1);
        }
        else if (letra == 'J') {
            cin >> nodo;
            g.ponArista(i, nodo);
        }
        else if (letra == 'A') {
            g.ponArista(i, i + 1);
        }
    }
    // escribir la soluci�n

    CicloDirigido d(g);

    if (!d.hayCiclo() && d.alcanzable()) cout << "SIEMPRE\n";
    else if (!d.alcanzable()) cout << "NUNCA\n";
    else if (d.hayCiclo() && d.alcanzable()) cout << "A VECES\n";


    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej5-e.txt");
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