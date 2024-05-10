/*@ <authors>
 *
 * Daniel Barroso: F06
 * Mario Campos: F09
 *
 *@ </authors> 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "Matriz.h"

/*@ <answer>

 RECURSION:
 ----------

 v1 = primer vector de canciones
 v2 = segundo vector de canciones

 resolver(i, j) = numero de canciones que coinciden en los dos vectores

 resolver(i, j) = resolver(i - 1, j - 1)                        si v1[i - 1] = v2[j - 1]
                  max(resolver(i - 1, j), resolver(i, j - 1))   si v1[i - 1] != v2[j - 1]

 > Casos Base: resolver(i, j) = 0     si i = 0 || j = 0

 > Llamada inicial: resolver(N, M), siendo N el numero de elementos del primer vector y M el numero de elementos del segundo vector


 COSTE

 El coste de la funcion es O(n * m), siendo m el numero de elementos de la lista 2 y siendo n el  numero de elementos de la lista 1

 @ </answer> 


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>



//No nos funcionaba y no daba tiempo
int resolver(int i, int j, Matriz<int>& M, vector<string> const& v1, vector<string> const& v2) {
    if (i == 0 || j == 0) {
        return 0;
    }
    else if (M[i][j] != -1) {
        return M[i][j];
    }
    if (v1[i - 1] == v2[j - 1]) {
        M[i][j] =  1 + resolver(i - 1, j - 1, M, v1, v2);
        return M[i][j];
    }
    else {
        M[i][j] = max(resolver(i - 1, j, M, v1, v2), resolver(i, j - 1, M, v1, v2));
        return M[i][j];
    }
}

vector<string> solucion(vector<string> const& v1, vector<string> const& v2) {

    Matriz<int> M(v1.size() + 1, v2.size() + 1, 0);
    Matriz<int> M2(v1.size() + 1, v2.size() + 1, -1);
    vector<string> sol;

    
    for (int i = 1; i <= v1.size(); i++) {
        for (int j = 1; j <= v2.size(); j++) {
            if (v1[i - 1] == v2[j - 1]) {
                M[i][j] = M[i - 1][j - 1] + 1;
            }
            else {
                M[i][j] = max(M[i - 1][j], M[i][j - 1]);
            }
        }
    }

    resolver(v1.size(), v2.size(), M2, v1, v2);

    int i = v1.size();
    int j = v2.size();

    while (i > 0 && j > 0) {

        if (v1[i - 1] == v2[j - 1]) {
            sol.push_back(v1[i - 1]);
            i--;
            j--;
        }
        else if (M2[i - 1][j] > M2[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(sol.begin(), sol.end());
    return sol;

}

bool resuelveCaso() {

    // leer los datos de la entrada
    string s1, s2;

    getline(cin, s1);
    if (!std::cin)  // fin de la entrada
        return false;

    getline(cin, s2);
    int j = 0;
    vector<string> v1(s1.size());

    for (int i = 0; i < s1.size(); i++) {
        char c = s1[i];

        if (c != ' ') {
            v1[j] += c;
        }
        else {
            j++;
        }
    }
    v1.resize(j + 1);

    vector<string> v2(s2.size());
    j = 0;
    for (int i = 0; i < s2.size(); i++) {
        char c = s2[i];

        if (c != ' ') {
            v2[j] += c;
        }
        else {
            j++;

        }
    }
    v2.resize(j + 1);

    // resolver el caso posiblemente llamando a otras funciones
    vector<string> sol = solucion(v1, v2);
    // escribir la solución

    for (string s : sol) {
        cout << s << " ";
    }
    cout << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej-BE.txt");
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