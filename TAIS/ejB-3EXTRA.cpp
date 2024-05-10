
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> 

#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
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
int at(int i, vector<int>const& cubo) {
    if (i < 0 || i >= cubo.size())return -1;
    else return cubo[i];
}
int aComer(int i, int j, vector<int>const& cubos, int N, vector<vector<int>>& M) {
    if (i > j)return 0;
    else if (M[i][j] != -1)return M[i][j];
    else {

        int comerprim = 0;
        if (at(i + 1, cubos) > at(j, cubos)) {
            comerprim = aComer(i + 2, j, cubos, N, M);
        }
        else {
            comerprim = aComer(i + 1, j - 1, cubos, N, M);
        }

        int comerult = 0;
        if (at(j - 1, cubos) > at(i, cubos)) {
            comerult = aComer(i, j - 2, cubos, N, M);
        }
        else {
            comerult = aComer(i + 1, j - 1, cubos, N, M);
        }

        if (comerprim + cubos[i] > comerult + cubos[j]) {
            M[i][j] = comerprim + cubos[i];
        }
        else {
            M[i][j] = comerult + cubos[j];
        }
        return  M[i][j];
    }
}
int resolverDinamico(vector<int>const& cubos, int N) {
    vector<vector<int>> M(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++)
    {
        M[i][i] = cubos[i];
    }
    return aComer(0, N - 1, cubos, N, M);
}

int resolverDinamico2(vector<int>const& cubos, int N) {
    vector<vector<int>> m(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        m[i][i] = cubos[i];
    }
    
    int sol_i;
    int sol_j;

    for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 1; j < N; j++)
        {
            if (cubos[i + 1] > cubos[j]) {
                sol_i = m[i + 2][j];
            }
            else {
                sol_i = m[i + 1][j - 1];
            }

            if (cubos[i] < cubos[j - 1]) {
                sol_j = m[i][j - 2];
            }
            else {
                sol_j = m[i + 1][j - 1];
            }

            m[i][j] = max(cubos[i] + sol_i, cubos[j] + sol_j);
        }
    }

    return m[0][N - 1];
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;
    vector<int> cubos(N);
    for (int i = 0; i < N; i++)
    {
        cin >> cubos[i];
    }
    int res = resolverDinamico2(cubos, N);
    cout << res << "\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ejB-3.txt");
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
