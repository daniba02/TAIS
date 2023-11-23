
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

int resolver(vector<int> const& ene, vector<int> const& ata) {

    sort(ene.begin(), ene.end());
    sort(ata.begin(), ata.end());

    int victorias = 0;
    int contDef = 0;

    for (int i = 0; i < ene.size(); i++) {

        if (ene[contDef] <= ata[i]) {
            victorias++;
            contDef++;
        }
    }

    return victorias;
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n;
    cin >> n;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> ene(n);
    vector<int> ata(n);

    for (int i = 0; i < n; i++) {
        cin >> ene[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> ata[i];
    }

    int sol = resolver(ene, ata);

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    cout << sol << '\n';
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