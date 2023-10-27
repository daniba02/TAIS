
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
#include "BInTree.h"
#include "Arbin.h"
 //#include "TreeSet_AVL.h"


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

template <typename T>
struct sol {
    bool avl;
    int altura;
    T min;
    T max;
};

template <typename T>
sol<T> recorrer(const Arbin<T>& tree) {


    if (tree.esVacio()) {

        return { true, 0, T(), T()};
    }
    else {



        sol izq = recorrer(tree.hijoIz());

        sol der = recorrer(tree.hijoDr());


        bool avl = der.avl && izq.avl;

        avl = avl && (izq.max == -1 || izq.max < tree.raiz()) && (der.min == -1 || der.min > tree.raiz());
        avl = avl && abs(izq.altura - der.altura) <= 1;

        T mx, mn;
        if (tree.hijoDr().esVacio()) {
            mx = tree.raiz();
        }
        else {
            mx = der.max;
        }

        if (tree.hijoIz().esVacio()) {
            mn = tree.raiz();
        }
        else {
            mn = izq.max;
        }

        return { avl, max(izq.altura, der.altura) + 1, mn, mx };
    }

}

template <typename T>
void resuelveCaso() {

    // leer los datos de la entrada

    //BinTree<int> a = read_tree<int>(cin);

    Arbin<T> a = Arbin<T>::leerArbolInorden();

    sol<T> avl = recorrer<T>(a);

    if (avl.avl) cout << "SI\n";
    else cout << "NO\n";

    // resolver el caso posiblemente llamando a otras funciones
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej1-2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    char c;
    cin >> c;
    while (cin) {
        if (c == 'N')
            resuelveCaso<int>();
        else
            resuelveCaso<string>();
        cin >> c;
    }

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}*/
