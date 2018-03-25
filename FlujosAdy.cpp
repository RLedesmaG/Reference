#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;
const int MAXN = 1000;

typedef int Costo;
typedef pair<Costo, int> CostoNodo;

int N = MAXN;
vector <vector<CostoNodo>> grafo(N);
vector <int> parent(N,-1);
vector <vector<int>> indices(N, vector<int> (N, -1));

void ModificarArista(int u, int v, Costo c){
  if(indices[u][v] == -1){
    indices[u][v] = grafo[u].size();
    grafo[u].push_back(CostoNodo(c, v));
  }else{
    int ind = indices[u][v];
    grafo[u][ind].first += c;
  }
}

bool bfs(int s, int t){
  vector <bool> vis(N, false);
  stack<int> q;
  vis[s] = true;
  q.push(s);

  while(!q.empty()){
    int u = q.top();
    q.pop();
    for(auto arista : grafo[u]){
      int v = arista.second;
      Costo p = arista.first;
      if(!vis[v] && p>0){
        parent[v] = u;
        vis[v] = true;
        if(v == t) return true;
        q.push(v);
      }
    }
  }
  return false;
}

Costo mf(int s, int t){
  Costo maxflow = 0;

  while(bfs(s, t)){
    Costo flow = INF;
    for(int i = t; i != s; i = parent[i]){
      int j = parent[i];
      int ind = indices[j][i];
      flow = min(flow, grafo[j][ind].first);
    }

    for(int i = t; i != s; i = parent[i]){
      int j = parent[i];
      ModificarArista(j, i, -flow);
      ModificarArista(i, j, flow);
    }

    maxflow += flow;
  }

  return maxflow;
}

struct punto{
    double x;
    double y;
};

int main(void){
    int n, m, s, v;
    double x, y;
    while(cin>>n>>m>>s>>v){
        punto topos[n];
        punto hoyos[m];
        punto p;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            p.x=x;
            p.y=y;
            topos[i]=p;
        }
        for(int i=0;i<m;i++){
            cin>>x>>y;
            p.x=x;
            p.y=y;
            hoyos[i]=p;
        }
        int N=m+n+2;
        grafo=vector<vector<CostoNodo> >(N);
        parent=vector<int> (N, -1);
        indices=vector<vector<int> > (N, vector<int>(N, -1));
        for(int i=0;i<n;i++){
            ModificarArista(0, i+1, 1);
        }
        for(int i=0;i<m;i++){
            ModificarArista(1+n+i, n+m+1, 1);
        }
        punto p1, p2;

        for(int i=0;i<n;i++){
            p1=topos[i];
            for(int j=0;j<m;j++){
                p2=hoyos[j];
                if(hypot(p1.x-p2.x, p1.y-p2.y)/v <=s) ModificarArista(i+1, n+j+1, 1);
            }
        }
        cout<<n-mf(0, n+m+1)<<"\n";
    }

  return 0;
}
