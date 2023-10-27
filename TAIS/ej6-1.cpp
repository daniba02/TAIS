
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


using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class MaxConjuntosDisjuntos {

private:

    int maximo;
    const int F;
    const int C;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {1, 1}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1} };
    vector<vector<char>> v; //vector de petroleros
    ConjuntosDisjuntos c;

    int posicion(int i, int j) {

        return i * C + j;
    }

    bool valida(int fila, int colum) {

        return (fila >= 0 && fila < F && colum >= 0 && colum < C && v[fila][colum] == '#');
    }


    void introducirManchas() {
        int n;
        cin >> n;

        if (n != 0) {
            for (int i = 0; i < n; i++) {

                int f, col;
                cin >> f >> col;
                f--;
                col--;
                v[f][col] = '#';

                int pos = posicion(f, col);
                for (pair<int, int> direccion : dir) {

                    int fila = f + direccion.first;
                    int columna = col + direccion.second;

                    if (valida(fila, columna) && !c.unidos(pos, posicion(fila, columna))) {
                        c.unir(pos, posicion(fila, columna));
                        
                    }
                }

                maximo = max(maximo, c.cardinal(pos));

                cout << maximo << ' ';
            }
        }

        
        cout << '\n';
    }


public:

    MaxConjuntosDisjuntos(const int filas, const int columnas) : F(filas), C(columnas), v(F, vector<char>(C, '\0')), c(F * C), maximo(0) {

        for (int i = 0; i < F; i++) {
            cin.ignore(1, '\n');
            for (int j = 0; j < C; j++) {

                cin.get(v[i][j]);

                int pos = posicion(i, j);

                if (v[i][j] == '#') {

                    if (maximo == 0) maximo = 1;

                    for (pair<int, int> direccion : dir) {

                        int fila = i + direccion.first;
                        int columna = j + direccion.second;

                        if (valida(fila, columna) && !c.unidos(pos, posicion(fila, columna))) {
                            c.unir(pos, posicion(fila, columna));
                            
                        }
                    }
                    maximo = max(maximo, c.cardinal(pos));
                }
            }
        }

        cout << maximo << " ";

        introducirManchas();
    }


};



bool resuelveCaso() {

    // leer los datos de la entrada

    int F, C;

    cin >> F >> C;

    if (!std::cin)  // fin de la entrada
        return false;

   
    // resolver el caso posiblemente llamando a otras funciones

    MaxConjuntosDisjuntos(F, C);

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej6-1.txt");
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
