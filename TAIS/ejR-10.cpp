
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
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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