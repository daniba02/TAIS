/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
 *
 *@ </authors> 

#include <iostream>
#include <fstream>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#include "Grafo.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> 


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

using Camino = deque<int>;

class CaminoMasCorto {

private:
    std::vector<bool> visit; // visit[v] = �hay camino de s a v?
    std::vector<int> ant; // ant[v] = �ltimo v�rtice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s-v m�s corto

    int s;
    //std::vector<int> precio;

    void bfs(Grafo const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        //precio[s1] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    //precio[w] = precio[v] + 1;
                    ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
                    q.push(w);
                }
            }
        }
    }

public:
    CaminoMasCorto(Grafo const& g, int s) : visit(g.V(), false), ant(g.V()), dist(g.V()),s(s) {
        bfs(g);
    }

    // �hay camino del origen a v?
    bool hayCamino(int v) const {
        return visit[v];
    }

    // n�mero de aristas entre s y v
    int distancia(int v) const {
        return dist[v];
    }


    // devuelve el camino m�s corto desde el origen a v (si existe)
    Camino camino(int v) {
        if (!hayCamino(v)) throw std::domain_error("No existe camino");
        Camino cam;
        for (int x = v; x != s; x = ant[x]) {

            cam.push_front(x);
        }
        cam.push_front(s);
        return cam;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int I, C, o1, o2, d;                    // I : Interseccion, C : Calles, o1 - o2 : Origen 1 y 2, d : Destino
    cin >> I >> C >> o1 >> o2 >> d;

    if (!std::cin)  // fin de la entrada
        return false;

    Grafo ciudad(I);

    for (int i = 0; i < C; i++) {
        int u, w;
        cin >> u >> w;
        ciudad.ponArista(u - 1, w - 1);
    }

    CaminoMasCorto c1(ciudad, o1 - 1);
    CaminoMasCorto c2(ciudad, o2 - 1);
    CaminoMasCorto c3(ciudad, d - 1);

    int coste = -1, c = 0;

    for (int i = 0; i < I; i++) {
        c = c1.distancia(i) + c2.distancia(i) + c3.distancia(i);

        if (coste == -1 || coste > c) {
            coste = c;
        }
    }
    
    cout << coste << "\n";


    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej5-e.txt");
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