
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

    // escribir la soluci�n

    cout << sol << '\n';
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
}*/