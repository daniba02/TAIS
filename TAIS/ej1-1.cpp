
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
#include "BInTree.h"
 //#include "TreeSet_AVL.h"


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

struct sol {

    bool avl;
    int altura;
    int min;
    int max;
};

sol recorrer(const BinTree<int>& tree) {


    if (tree.empty()) {

        return { true, 0, -1, -1 };
    }
    else {

        

        sol izq = recorrer(tree.left());

        sol der = recorrer(tree.right());


        bool avl = der.avl && izq.avl;

        avl = avl && (izq.max == -1 || izq.max < tree.root()) && (der.min == -1 || der.min > tree.root());
        avl = avl && abs(izq.altura - der.altura) <= 1;

        int mx, mn;
        if (tree.right().empty()) {
            mx = tree.root();
        }
        else {
            mx = der.max;
        }

        if (tree.left().empty()) {
            mn = tree.root();
        }
        else {
            mn = izq.max;
        }

        return { avl, max(izq.altura, der.altura) + 1, mn, mx };
    }

}

void resuelveCaso() {

    // leer los datos de la entrada

    
    //BinTree<int> a = read_tree<int>(cin);
    BinTree<int> a = BinTree<int>::leerArbolInorden();
    

    sol avl = recorrer(a);

    // resolver el caso posiblemente llamando a otras funciones

    if (avl.avl) cout << "SI\n";
    else cout << "NO\n";

    // escribir la soluci�n
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej1-1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}*/
