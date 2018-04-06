
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long int

const int MAXN = 100000;

typedef int Costo;
typedef pair<int, int> Arista;
const Costo INF = 1 << 30;
typedef pair<Costo, int> CostoNodo;
typedef pair<Costo, Arista> Ponderada;

int N = MAXN;//número de nodos

vector<vector<CostoNodo>> grafo;

void AgregarArista(int u, int v, Costo c) {
    grafo[u].push_back(CostoNodo(c, v));
    grafo[v].push_back(CostoNodo(c, u));
}

// Obtiene el arbol de expansion minima de un
// grafo bidireccional. Para obtener el arbol
// de expansion maxima quitar los negativos del
// peso. Solo funciona si la grafica es conexa.
vector<Ponderada> Prim(int s){
    vector<Ponderada> mst;
    vector <int> MST(N,0);//indica pertenencia a MST
    int elem = 0;
    int u = s;
    priority_queue<Ponderada> pq;
    while(elem != N){
        MST[u]++;
        elem++;
        Ponderada ar;
        for (CostoNodo arista : grafo[u]) {
            int v = arista.second;
            Costo p = arista.first;
            if(!MST[v])pq.push(Ponderada(-p,Arista(u,v)));
        }
        while(!pq.empty() && MST[u]){
            ar = pq.top();
            pq.pop();
            u = ar.second.second;
            ar.first = -ar.first;
        }
        if(!MST[u]) mst.push_back(ar);
    }
    return mst;
}




int main(void){
    return 0;
}
