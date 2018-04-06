#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int n;
    vector<int> padre, tam;

    UnionFind(int N) : n(N), tam(N, 1), padre(N) {
        while (--N) padre[N] = N;
    }

    int Raiz(int u) {
        if (padre[u] == u) return u;
        return padre[u] = Raiz(padre[u]);
    }
    bool SonConexos(int u, int v) {
        return Raiz(u) == Raiz(v);
    }
    void Unir(int u, int v) {
        int Ru = Raiz(u);
        int Rv = Raiz(v);
        if (Ru == Rv) return;
        --n;
        if(tam[Ru] < tam[Rv]){
            padre[Ru] = Rv;
            tam[Rv] += tam[Ru];
        }else{
            padre[Rv] = Ru;
            tam[Ru] += tam[Rv];
        }
    }
    int Tamano(int u) {
        return tam[Raiz(u)];
    }
};

const int MAXN = 20000;

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

vector<Ponderada> Kruskal() {
    vector<Ponderada> todas;
    for (int u = 0; u < N; ++u)
        for (CostoNodo arista : grafo[u])
            todas.push_back(Ponderada(arista.first,
                        Arista(u, arista.second)));
    sort(todas.begin(), todas.end());
    // reverse(todas.begin(), todas.end());
    vector<Ponderada> mst;
    UnionFind componentes(N);
    for (Ponderada arista : todas) {
        int u = arista.second.first;
        int v = arista.second.second;
        if (!componentes.SonConexos(u, v))
            componentes.Unir(u, v),
                    mst.push_back(arista);
    }
    return mst;
}

int main(){
    int n, m;
    while(true){
        cin>>n>>m;
        if(n==0 && m==0) return 0;
        N=n;
        grafo = vector<vector <CostoNodo> > (N);
        for(int i=0;i<m;i++){
            int u, v, w;
            cin>>u>>v>>w;
            AgregarArista(u, v, w);
        }
        vector<Ponderada> tree = Kruskal();
        if(tree.size()!=n-1){
            cout<<"Impossible\n";
            continue;
        }
        int peso=0;
        for(Ponderada p:tree) peso+=p.first;
        cout<<peso<<"\n";
        vector<pair<int, int> > myvector;
        for(Ponderada p:tree){
            myvector.push_back(make_pair(p.second.first, p.second.second));

        }
        sort(myvector.begin(), myvector.end());
        for(int i=0;i<n-1;i++){
            cout<<myvector[i].first<<" "<<myvector[i].second<<"\n";
        }
    }
}
