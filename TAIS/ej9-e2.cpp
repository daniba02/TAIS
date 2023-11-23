/*@ <authors>
 *
 * DANIEL BARROSO CASADO	: TAIS06
 * MARIO CAMPOS SOBRINO		: TAIS09
 *
 *@ </authors> 

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "DigrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "Index_PQ.h"


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 VORAZ :
	El método voraz consiste en contemplar los costes de llegada (distancias) de manera creciente separados en dos vectores (n y s) cada uno con la distancia
	desde el pueblo i : i { s + 1, ... , n - 1 }.
	Estos vectores creados mediante Dijkstra ( tenemos que calcular las distancias desde un nodo origen (sea s (sur) o n (norte)) hasta cada pueblo.
	Cada uno de estos vectores se reordenan de manera menor a mayor segun el valor la arista que une los pueblos (i, i+1) -> funcion sort
	El metodo voraz consiste en escoger las aristas con menor coste (valor) siempre y cuando no se pase el numero máximo de aristas que se puede poner
	desde los vertices sumideros : ((N −2)/2) siendo N = numero total de pueblos (incluyendo a los sumideros o (norte y sur)).

 DEMOSTRACION SOLUCION :
	Sea v = v1 ... vn la solución de un problema voraz si para cualquier solucion optima s que coincida en las primeras k-1 etapas con v,
	existen rk+1, ... , rn tales que s' = v1...vkrk+1...rn es solucion válida y s'<=s

	vemos como por etapas la solucion voraz y la optima se van construyendo tal que en la etapa k:
	v1 ... vk-1  vk  vk+1 ... vn
	============= | != != != !=
	v1 ... vk-1  sk  sk+1 ... sn

	si sk != vk => sk < vk || sk > vk

	sk < vk => Algoritmo voraz no escogió sk dado que sería una sk menor a la vk pero significaria que aun al ser menor el
				valor se estaria pasando el número de pueblos maximos (N-2/2) alcanzados por el origen (S o N)
	sk > vk => Algoritmo voraz comprueba que se puede meter una arista con menor valor a la de sk sin sobrepasar limites, ha de meteer la de voraz


 COSTE ALGORITMO : Siendo N el número de pueblos
	Usamos un DigrafoValorado : O(n) al insertar n pueblos con sus respectivas aristas (coste constante en cada iteracion del bucle)
	Usamos dos vectores para guardar la informacion de la estructura "par" (indexPueblo, DistanciaPueblo-Origen) : O(n) crearlos + informacion
	Usamos dos funciones sort para ordenar cada vector crecientemente : O(n log n)
	Resolvemos con un bucle while : O(n - 2) = O(n) puesto que recorremos exactamente n-2 pueblos (todos menos los extremos)

 @ </answer> 


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

struct par {
	int elem;
	int value;
};

bool operator<(par const& a, par const& b) {
	return a.value < b.value;
}

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int orig, int dest) : origen(orig),
		dist(g.V(), INF), ulti(g.V()), pq(g.V()), mapa(g.V()), dest(dest) {
		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}
	vector<par> getmapa() {
		return mapa;
	}
	Valor distancia(int v) const { return dist[v]; }

private:
	const Valor INF = std::numeric_limits<Valor>::max();
	int origen;
	int dest;
	std::vector<Valor> dist;
	std::vector<AristaDirigida<Valor>> ulti;
	IndexPQ<Valor> pq;
	vector<par> mapa;
	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor(); ulti[w] = a;
			pq.update(w, dist[w]);
			mapa[w] = { w, dist[w] };
		}
	}
};

long int voraz2(Dijkstra<int> a1, Dijkstra<int> a2, DigrafoValorado<int> g) {

	int cont = 0;
	int contN = 0, contS = 0;
	long int suma = 0;
	int max = (g.V() - 2) / 2;

	vector<par> n = a1.getmapa();
	vector<par> s = a2.getmapa();
	vector<bool> visit(g.V(), false);
	visit[0] = true;
	visit[g.V() - 1] = true;

	sort(n.begin(), n.end());
	sort(s.begin(), s.end());


	while (cont < g.V() - 2) {

		if (n[contN].value < s[contS].value && contN < max) {
			if (!visit[n[contN].elem]) {
				suma += a1.distancia(n[contN].elem) * 2;
				visit[n[contN].elem] = true;
				cont++;
			}
			contN++;
		}
		else if (s[contS].value < n[contN].value && contS < max) {
			if (!visit[s[contS].elem]) {
				suma += a2.distancia(s[contS].elem) * 2;
				visit[s[contS].elem] = true;
				cont++;
			}
			contS++;
		}
		else if (contN >= max) {
			if (!visit[s[contS].elem]) {
				suma += a2.distancia(s[contS].elem) * 2;
				visit[s[contS].elem] = true;
				cont++;
			}
			contS++;
		}
		else if (contS >= max) {
			if (!visit[n[contN].elem]) {
				suma += a1.distancia(n[contN].elem) * 2;
				visit[n[contN].elem] = true;
				cont++;
			}
			contN++;
		}
		else if (n[contN].value == s[contS].value) {
			suma += a1.distancia(n[contN].elem) * 2;
			if (n[contN].value != 0) {
				cont++;
			}
			contN++;
			contS++;
			max++;
		}
	}

	return suma;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n, m;
	cin >> n >> m;
	if (!std::cin)  // fin de la entrada
		return false;

	DigrafoValorado<int> g(n);

	int a1, a2, value;

	for (int i = 0; i < m; i++) {
		cin >> a1 >> a2 >> value;

		g.ponArista({ a1 - 1, a2 - 1, value });
		g.ponArista({ a2 - 1, a1 - 1, value });

	}
	// resolver el caso posiblemente llamando a otras funciones

	Dijkstra<int> d1(g, 0, g.V() - 1);
	Dijkstra<int> d2(g, g.V() - 1, 0);

	cout << voraz2(d1, d2, n) << "\n";

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("ej9-e.txt");
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