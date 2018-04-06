#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100003;

vector<int> grafo[MAXN];
int N;

int BFS( int source, int dest ){
    queue<int> cola;
    vector<int> dist( N, -1 );
    dist[source] = 0;
    cola.push( source );

    while( !cola.empty() ){
        int u = cola.front();
        cola.pop();
        for( auto v : grafo[u] ){
            if( dist[ v ] == -1 ){
                dist[v] = dist[u] + 1;
                cola.push( v );
            }
        }
    }
    return dist[dest];
}

int main()
{
    int M, x, y;
    cin >> N >> M;

    for(  int i = 0; i < M; i++){
        cin >> x >> y;
        grafo[--x].push_back(--y);
        grafo[y].push_back(x);
    }

    cin >> x >> y;

    cout << BFS( --x, --y ) << '\n';

    return 0;
}
