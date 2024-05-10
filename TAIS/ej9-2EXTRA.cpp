
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

struct trabajo {

    int ini;
    int fin;
};

bool operator<(trabajo const& a, trabajo const& b) {
    return a.ini < b.ini;
}

void resolver(vector<trabajo>& v, const int n, const int C, const int F) {

    sort(v.begin(), v.end());

    int nTrabajos = 0;
    int final = C;
    int cont = 0;
    
    bool termina = true;
    
    while (termina && final < F) {

        int mejorFin = -1;

        if (cont >= v.size() || v[cont].ini > final) {
            termina = false;
        }

        while (termina && cont < v.size() && v[cont].ini <= final) {

            if (v[cont].fin > mejorFin && v[cont].fin > final) {
                mejorFin = v[cont].fin;
            }
            cont++;
        }
       
        if (mejorFin == -1) {
            termina = false;
        }

        final = mejorFin;
        nTrabajos++;
    }

    if (termina) {
        cout << nTrabajos;
    }
    else {
        cout << "Imposible";
    }

    cout << "\n";
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int c, f, n;

    cin >> c >> f >>  n;

    if (c == 0 && f == 0 && n == 0)  // fin de la entrada
        return false;


    vector<trabajo> v(n);

    for (int i = 0; i < n; i++)
    {
        
        cin >> v[i].ini;
        cin >> v[i].fin;
    }

    resolver(v, n, c, f);

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej9-2.txt");
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