
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
#include <vector>
#include <fstream>
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

int resolver(vector<int>& ene, vector<int>& def, const int n) {

    sort(ene.begin(), ene.end(), greater<int>());
    sort(def.begin(), def.end(), greater<int>());

    int cont = 0;

    for (int i = 0; i < n; i++) {

        if (ene[i] <= def[cont]) {
            cont++;
        }
    }
    return cont;
}

bool resuelveCaso() {

    int n;

    cin >> n;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> ene(n);
    vector<int> def(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ene[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> def[i];
    }
    // resolver el caso posiblemente llamando a otras funciones

    cout << resolver(ene, def, n) << "\n";
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej8-2.txt");
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