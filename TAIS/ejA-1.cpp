
/*
@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 * Daniel Barroso Casado
 * TAIS06
 *
 *@ </authors>*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "EnterosInf.h"
#include "Matriz.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>*/

struct cuerda {
    int longitud;
    int coste;
};

struct sol {
    long long int combinaciones;
    EntInf minCuerdas;
    EntInf minCoste;
};

long long int num_combi(int i, int j, vector<cuerda> const& v, Matriz<long long int>& C) {

    if (i == -1 && j == 0)
        return 1;
    else if (j == 0)
        return 1;
    else if (i == -1)
        return 0;
    else if (C[i][j] != -1)
        return C[i][j];
    else {
        if (v[i].longitud > j) {
            C[i][j] = num_combi(i - 1, j, v, C);
            return C[i][j];
        }
        else {
            C[i][j] = num_combi(i - 1, j, v, C) + num_combi(i - 1, j - v[i].longitud, v, C);
            return C[i][j];
        }

    }
}

long long int num_combi(int i, int j, vector<cuerda> const& v, vector<long long int>& C) {

    if (i == -1 && j == 0)
        return 1;
    else if (j == 0)
        return 1;
    else if (i == -1)
        return 0;
    else if (C[j] != -1)
        return C[j];
    else {
        if (v[i].longitud > j) {
            C[j] = num_combi(i - 1, j, v, C);
            return C[j];
        }
        else {
            C[j] = C[j], num_combi(i - 1, j, v, C) + num_combi(i - 1, j - v[i].longitud, v, C);
            return C[j];
        }

    }
}

long long int num_combi(vector<cuerda> const& v, vector<long long int>& C) {

    int N = v.size();
    int L = C.size() - 1;
    C[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = L; j >= v[i - 1].longitud; j--) {

            C[j] = C[j] + C[j - v[i - 1].longitud];
        }
    }
    return C[L];
}

EntInf minCuerdas(int i, int j, vector<cuerda> const& v, Matriz<EntInf>& C) {

    if (i == -1 && j == 0)
        return EntInf(0);
    else if (j == 0)
        return EntInf(0);
    else if (i == -1)
        return EntInf(Infinito);
    else if (C[i][j] != -1)
        return C[i][j];
    else {

        if (v[i].longitud > j){
            C[i][j] = minCuerdas(i - 1, j, v, C);
            return C[i][j];
        }
        else {
            C[i][j] = min(minCuerdas(i - 1, j, v, C), minCuerdas(i - 1, j - v[i].longitud, v, C) + 1);
            return C[i][j];
        }
    }
}

EntInf minCoste(int i, int j, vector<cuerda> const& v, Matriz<EntInf>& C) {

    if (i == -1 && j == 0)
        return EntInf(0);
    else if (j == 0)
        return EntInf(0);
    else if (i == -1)
        return EntInf(Infinito);
    else if (C[i][j] != -1)
        return C[i][j];
    else {

        if (v[i].longitud > j) {
            C[i][j] = minCoste(i - 1, j, v, C);
            return C[i][j];
        }
        else {
            C[i][j] = min(minCoste(i - 1, j, v, C), minCoste(i - 1, j - v[i].longitud, v, C) + v[i].coste);
            return C[i][j];
        }
    }
}

sol resolver(vector<cuerda> const& v, int L) {

    Matriz<long long int> m1(v.size() + 1, L + 1, -1);
    vector<long long int> v1(L + 1, 0);
    sol solucion = { 0, -1, -1 };
    solucion.combinaciones = num_combi(v, v1);

    if (solucion.combinaciones != 0) {

        Matriz<EntInf> m2(v.size() + 1, L + 1, -1);
        solucion.minCuerdas = minCuerdas(v.size() - 1, L, v, m2);
        Matriz<EntInf> m3(v.size() + 1, L + 1, -1);
        solucion.minCoste = minCoste(v.size() - 1, L, v, m3);
    }

    return solucion;
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, l;

    cin >> n;

    if (!std::cin)  // fin de la entrada
        return false;

    cin >> l;

    vector<cuerda> c(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i].longitud >> c[i].coste;
    }
    // resolver el caso posiblemente llamando a otras funciones

    sol solucion = resolver(c, l);

    if (solucion.combinaciones != 0) {
        cout << "SI: " << solucion.combinaciones << " " << solucion.minCuerdas << " " << solucion.minCoste;
    }
    else {
        cout << "NO";
    }

    cout << '\n';
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
}