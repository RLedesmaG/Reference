#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200003;

vector<int> grafo[MAXN];
vector<int> vist;
vector<int> colors;
int color=1;

int DFS( int source ){
   vist[source] = 1;
   for( auto v : grafo[source] ){
        colors[v]=colors[source];
        if(vist[v] == -1){
            DFS( v );
        }
   }
}

int main(void){
    int n, m;
    cin>>n>>m;
    int debt[n];
    for(int i=0;i<n;i++){
        cin>>debt[i];
    }
    vist = vector<int>( n+1, -1 );
    colors = vector<int>(n+1, -1);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(vist[i]==-1){
            colors[i]=color;
            DFS(i);
            color++;
        }
    }
    int suma=0;
    bool valid=true;
    for(int i=1;i<=color;i++){
        suma=0;
        for(int j=0;j<n;j++){
            if(colors[j]==i)
            suma+=debt[j];
        }
        if(suma!=0) valid=false;

    }

    if(valid) cout<<"POSSIBLE\n";
    else cout<<"IMPOSSIBLE\n";

    return 0;
}
