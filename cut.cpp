#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a, b, c, n;
    cin>>n>>a>>b>>c;
    int coin[3];
    coin[0]=a;
    coin[1]=b;
    coin[2]=c;

    long long int arr[5000];
    memset(arr, 0, sizeof arr);

    arr[a]=1;
    arr[b]=1;
    arr[c]=1;

    for(int i=1;i<n+1;i++){
        for(int j=0;j<3;j++){
            if(i-coin[j]>0){
                if(arr[i-coin[j]]!=0)
                arr[i]=max(arr[i], 1+arr[i-coin[j]]);
            }
        }
    }

    cout<<arr[n]<<"\n";

    return 0;
}
