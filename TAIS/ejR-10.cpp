
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

struct festival {
    int grupos;
    int precio;
};

void resolver(vector<festival>& v, const int p) {

    int n = v.size();
    vector<int> M(p + 1, 0);


    for (int i = 0; i < n; i++)
    {
        for (int j = p; j >= v[i].precio; j--) {

            M[j] = max(M[j], M[j - v[i].precio] + v[i].grupos);
        }
    }

    cout << M[p] << "\n";

}


bool resuelveCaso() {

    // leer los datos de la entrada
    int p, n;
    cin >> p >> n;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<festival> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].grupos >> v[i].precio;
    }
    // resolver el caso posiblemente llamando a otras funciones

    resolver(v, p);
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejR-10.txt");
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