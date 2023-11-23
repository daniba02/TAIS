
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

struct edificio {
    int ini; 
    int fin;
};

bool operator<(edificio const& a, edificio const& b) {
    return a.fin < b.fin;
}

int voraz(vector<edificio>& ed) {

    sort(ed.begin(), ed.end());

    int cont = 1;
    int last = ed[0].fin;

    for (int i = 1; i < ed.size(); i++) {
        if (ed[i].ini >= last) {
            cont++;
            last = ed[i].fin;
        }
    }

    return cont;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<edificio> ed(n);
    int ini, fin;

    for (int i = 0; i < n; i++) {
        cin >> ini >> fin;
        ed[i] = { ini, fin };

    }
    // resolver el caso posiblemente llamando a otras funciones

    cout << voraz(ed) << "\n";
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej9-1.txt");
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
