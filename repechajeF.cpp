
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 51;

typedef long long int Costo;
typedef pair<int, int> Arista;
const Costo INF = 1e18;
typedef pair<Costo, int> CostoNodo;
typedef pair<Costo, Arista> Ponderada;
int visited[MAXN];
map<pair<int, int>, int> tele;
map<int, int> camino;

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
                camino[v]=u;
                pair<int, int> pr = make_pair(u, v);

                dist[v] = p;
                pq.push(CostoNodo(-p, v));
                visited[v]=1;
            }
        }
    }
    return dist;
}

int main(void){
    int t;
    cin>>t;
    int cases=0;
    while(t--){
        memset(visited, -1, sizeof visited);
        tele.clear();
        cases++;
        camino.clear();
        int V, t;
        cin>>V>>t;
        N = V;
        grafo=vector<vector<CostoNodo> > (N);
        int u, v, w;
        for(int i=0;i<V;i++){
            cin>>u;
            char s[1000];
            fgets(s, 1000, stdin);
            //printf("%d: %s", u, s);
            stringstream ss(s);

            int v;
            long long int w;
            while ((ss >> v >> w).good()) {
                AgregarArista(u, v, w);
            }

        }
        for(int i=0;i<t;i++){
            cin>>u>>v;
            AgregarArista(u, v, 0);
            AgregarArista(v, u, 0);
            tele[make_pair(u, v)]=1;
            tele[make_pair(v, u)]=1;
        }
        int start, finish;
        cin>>start>>finish;
        vector<Costo> costos = Dijkstra(start);
        cout<<"Case #"<<cases<<": ";
        if(visited[finish]==-1){
            cout<<"Path does not exist\n";
        }
        else{
            cout<<costos[finish]<<"\n";
            map<int, int>::iterator it=camino.begin();
            cout<<start;
            vector<int> output;
            int aux = finish;
            while(aux!=start){
                output.push_back(aux);
                aux=camino[aux];
            }
            reverse(output.begin(), output.end());
            for(int i=0;i<output.size();i++){
                cout<<" "<<output[i];
            }

            cout<<"\n";
        }
    }
    return 0;
}
