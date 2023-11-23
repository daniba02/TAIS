
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


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct intervalo {
    int ini;
    int fin;
};

bool operator<(intervalo const& a, intervalo const& b) {
    return a.ini < b.ini;
}

int voraz(vector<intervalo> v, int const& C, int const& F) {

    sort(v.begin(), v.end());

    bool termina = true;
    int cont = 0;

    int ultfin = 0;
    int dist = 0;

    while (ultfin < F && termina) {
        int dist = -1;
        
        if (cont > v.size() || v[cont].ini > ultfin) termina = false;

        while (termina && cont < v.size() && v[cont].ini <= ultfin) {
            if (v[cont].fin > ultfin && v[cont].fin > dist) {
                dist = v[cont].fin;
            }
            cont++;
        }

        if (ultfin < C) termina = false;
    }

    if (ultfin < F || !termina) cont = -1;
    
    return cont;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int C, F, N;

    cin >> C >> F >> N;

    if (C == 0 && F == 0 && N == 0) {
        return false;
    }

    vector<intervalo> v(N);

    int ini, fin;
    for (int i = 0; i < N; i++) {
        cin >> ini >> fin;
        v[i] = { ini, fin };
    }

    cout << voraz(v, C, F) << "\n";
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej9-2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
*/