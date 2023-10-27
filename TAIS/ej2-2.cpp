
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
#include <vector>
#include <functional>
#include <queue>



// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer>


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


struct tEstudiante {

    int momento;
    int id;
    int periodo;

};



bool operator<(tEstudiante const& a, tEstudiante const& b) {


    return b.momento < a.momento || (a.momento == b.momento && b.id < a.id);
}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, k;

    cin >> n;

    if (n == 0)
        return false;

    priority_queue<tEstudiante> cola;

    for (int i = 0; i < n; i++) {

        int id, periodo;
        cin >> id >> periodo;
        cola.push({periodo, id, periodo});

    }

    cin >> k;

    while (k > 0) {

        auto e = cola.top();
        cola.pop();

        cout << e.id << '\n';

        e.momento += e.periodo;
        cola.push(e);
        k--;
    }

    cout << "---\n";

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej2-2.txt");
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