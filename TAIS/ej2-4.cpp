
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
#include <string>



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


struct tTareas {

    int ini;
    int fin;
    int periodo;

};

bool operator<(tTareas const& a, tTareas const& b) {

    return b.ini < a.ini || (b.ini == a.ini && b.fin < a.fin);

}

bool resuelveCaso() {

    // leer los datos de la entrada

    int n, m, t;
    bool conflicto = false;

    cin >> n >> m >> t;

    if (!cin)
        return false;

    priority_queue<tTareas> cola;

    for (int i = 0; i < n; i++) {

        int ini;
        int fin;
        cin >> ini >> fin;

        cola.push({ ini, fin, 0 });
    }
    for (int i = 0; i < m; i++) {

        int ini;
        int fin;
        int periodo;
        cin >> ini >> fin >> periodo;

        cola.push({ ini, fin, periodo });
    }

    int tiempo = 0;

    while (tiempo < t && !cola.empty() && !conflicto) {

        auto a = cola.top();
        cola.pop();

        if (!cola.empty()) {

            auto b = cola.top();
            //cola.pop();

            if (a.fin > b.ini && b.ini < t) conflicto = true;

            if (a.periodo != 0) {
                cola.push({ a.ini + a.periodo, a.fin + a.periodo, a.periodo });

            }

        }
        tiempo = a.fin;
        
    }

    if (!conflicto) cout << "NO\n";
    else cout << "SI\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej2-4.txt");
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
