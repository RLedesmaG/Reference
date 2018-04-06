
#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
const int INF = INT_MAX;

int tree[400004];
int posicion[400004];
int A[100002];

void Build(int node, int start, int end){
    if(start == end){
        tree[node] = A[start];
        posicion[start] = node;
    }else{
        int mid = (start + end) / 2;
        Build(2*node, start, mid);
        Build(2*node+1, mid+1, end);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

void Update(int ind, int x){
    A[ind] = x;
    int pos = posicion[ind];
    tree[pos] = x;

    while(pos != 1){
        pos /= 2;
        tree[pos] = min(tree[pos*2],tree[pos*2+1]);
    }

}

int Query(int node, int start, int end, int l, int r){
    if(start > end || r < start || end < l)
        return INF;

    if(l <= start && end <= r)
        return tree[node];

    int mid = (start + end) / 2;
    int iz = Query(node*2, start, mid, l, r);
    int der = Query(node*2 + 1, mid + 1, end, l, r);
    return min(iz, der);
}


int main(void){
    optimizar_io
    return 0;
}
