
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
#include <algorithm>
using namespace std;

#include "Index_PQ.h"


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct actividad {
    int ini; 
    int fin;
};

bool operator<(actividad const& a, actividad const& b) {
    return a.ini < b.ini;
}

int resolver(vector<actividad>& v) {

    sort(v.begin(), v.end());

    vector<int> amigos(v.size());
    int tiempo = v[0].fin;
    amigos[0] = 0;

    int cont = 1;
    IndexPQ<int> am(v.size());
    int numAmigos = 0;
    am.update(numAmigos, v[0].fin);

    while (cont < v.size()) {

        if (am.top().prioridad <= v[cont].ini) {
            am.update(am.top().elem, v[cont].fin);
        }
        else {
            numAmigos++;
            am.update(numAmigos, v[cont].fin);
        }
        
        cont++;
    }

    return numAmigos;
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n;

    cin >> n;

    if (n == 0)
        return false;

    vector<actividad> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].ini >> v[i].fin;
    }

    cout << resolver(v) << "\n";

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejR-4.txt");
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