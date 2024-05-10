
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
 *
 *@ </authors> 

#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"
using namespace std;

class Supermercado {
private:
    ConjuntosDisjuntos mar;
};
/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> 


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>
struct rollo {
    int lugar;
    int coste;
};

bool resuelveCaso() {

    int N, C; cin >> N >> C;
    if (!std::cin)  // fin de la entrada
        return false;
    ConjuntosDisjuntos cj(N + 1);
    int origen, destino;
    for (int i = 0; i < C; i++)
    {
        cin >> origen >> destino;
        cj.unir(origen, destino);
    }


    int S; cin >> S;
    vector<rollo> v;
    int lugar, coste;
    for (int i = 0; i < S; i++)
    {
        cin >> lugar >> coste;
        v.push_back({ lugar, coste });
    }
    int k; cin >> k;
    int sitio;

    for (int j = 0; j < v.size(); j++) // bucle de los rollos
    {
        if (cj.unidos(sitio, v[j].lugar)) {

            if (v[j].coste < coste || coste == -1) {
                coste = v[j].coste;
            }

        }
    }

    for (int i = 0; i < k; i++)
    {
        cin >> sitio;
        int coste = -1;
        bool alcanzable = false;
        
        if (!alcanzable)
            cout << "MENUDO MARRON";
        else
            cout << coste;
        cout << "\n";
    }
    cout << "---\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
}
*/