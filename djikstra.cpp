#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100003;

typedef long long int Costo;
typedef pair<long long int, long long int> Arista;
const Costo INF = 1000000000000000000;
typedef pair<Costo, long long int> CostoNodo;
typedef pair<Costo, Arista> Ponderada;
 int visited[MAXN];

int N = MAXN;

vector<vector<CostoNodo>> grafo;

void AgregarArista(int u, int v, Costo c) {
    grafo[u].push_back(CostoNodo(c, v));
}

vector<Costo> Dijkstra(int s) {
    vector<Costo> dist(N, INF);
    priority_queue<CostoNodo> pq;
    pq.push(CostoNodo(0, s));
    dist[s] = 0;
    while (!pq.empty()) {
        Costo p = -pq.top().first;
        int u = pq.top().second;

        pq.pop();
        if (dist[u] < p) continue;
        for (CostoNodo arista : grafo[u]) {
            int v = arista.second;

            p = dist[u] + arista.first;
            if (p < dist[v]){
                dist[v] = p;
                pq.push(CostoNodo(-p, v));
                visited[v]=1;
            }
        }
    }
    return dist;
}

int main(){
    memset(visited, -1, sizeof visited);
    visited[1]=1;
    int n, m;
    cin>>n>>m;
    int u, v, w;
     grafo = vector<vector<CostoNodo>>(n+1);
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        AgregarArista(u, v, w);
        AgregarArista(v, u, w);
    }

    vector<Costo> costos =  Dijkstra(1);
    long long int maximo = costos[n];

    if(visited[n]!=1){ cout<<"-1\n"; return 0;}
    vector<int> camino;
    camino.push_back(n);
    int actual=n;
    while(maximo!=0){
        for(CostoNodo arista: grafo[actual]){
            int v = arista.second;
            int w = arista.first;
            if(costos[v]+w == maximo){
                maximo-=w;
                actual=v;
                camino.push_back(v);
                continue;
            }
        }
    }
    for(int i=camino.size()-1;i>=0;i--){
        cout<<camino[i];
        if(i!=0) cout<<" ";
    }
    cout<<"\n";
    return 0;
}
