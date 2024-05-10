
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

#include "EnterosInf.h"


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct cuerda {
    long long int lon;
    long long int precio;
};

long long int resolverNumManeras(vector<cuerda>& M, const int n, const long long int k) {

    vector<long long int> num(k + 1, 0);

    num[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= M[i].lon; j--) {

            num[j] = num[j] + num[j - M[i].lon];
        }
    }
    return num[k];
}

EntInf resolverMinCuerdas(vector<cuerda>& M, const int n, const int k) {

    vector<EntInf> C(k + 1, Infinito);

    C[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= M[i].lon; j--) {

            C[j] = min(C[j], C[j - M[i].lon] + 1);
        }
    }

    return C[k];
}

EntInf resolverMinCoste(vector<cuerda>& M, const int n, const int k) {

    vector<EntInf> C(k + 1, Infinito);

    C[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= M[i].lon; j--) {

            C[j] = min(C[j], C[j - M[i].lon] + M[i].precio);
        }
    }

    return C[k];
}

void resolver(vector<cuerda>& M, const int n, const int k) {

    long long int num = resolverNumManeras(M, n, k);

    if (num > 0) {
        EntInf min = resolverMinCuerdas(M, n, k);
        EntInf minCoste = resolverMinCoste(M, n, k);

        cout << "SI " << num << " " << min << " " << minCoste << "\n";
    }
    else {
        cout << "NO\n";
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    long long int n, l;

    cin >> n;

    if (!std::cin)  // fin de la entrada
        return false;

    cin >> l;
    // resolver el caso posiblemente llamando a otras funciones

    vector<cuerda> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].lon >> v[i].precio;
    }

    resolver(v, n, l);
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejA-1.txt");
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