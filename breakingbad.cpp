#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200003;

vector<int> grafo[MAXN];
vector<int> vist;
vector<int> color;
bool bipartita=true;
vector<int> negro;
vector<int> blanco;

int DFS( int source ){
   vist[source] = 1;
   for( auto v : grafo[source] ){
        if(color[v]==color[source]) bipartita=false;
        if(vist[v] == -1){
            color[v]=1-color[source];
            DFS( v );
        }
   }
}

int main(void){
    int n, m;
    cin>>n;
    vist = vector<int>( n+1, -1 );
    color = vector<int>( n+1, -1 );
    color[1]=1;
    map<string, int> mymap;
    map<int, string> inverso;
    string input;
    for(int i=1;i<=n;i++){
        cin>>input;
        mymap[input]=i;
        inverso[i]=input;
    }
    cin>>m;
    string s1, s2;
    int u, v;
    for(int i=1;i<=m;i++){
        cin>>s1>>s2;
        u = mymap.find(s1)->second;
        v = mymap.find(s2)->second;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(vist[i]!=1) {color[i]=1; DFS(i);};
    }

    for(int i=1;i<=n;i++){
        if(color[i]==1) blanco.push_back(i);
        else negro.push_back(i);
    }

    if(!bipartita) cout<<"impossible\n";
    else {
        for(int i=0;i<blanco.size();i++){
            if(i!=0) cout<<" ";
            int actual = blanco[i];
            cout<<inverso.find(actual)->second;

        }
        if(negro.size()!=0) cout<<"\n";
        for(int j=0;j<negro.size();j++){
            if(j!=0) cout<<" ";
            int actual=negro[j];
            cout<<inverso.find(actual)->second;
        }
        cout<<"\n";

    }

    return 0;
}
