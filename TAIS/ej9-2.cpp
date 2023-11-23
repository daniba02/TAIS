
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
#include <algorithm>
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
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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