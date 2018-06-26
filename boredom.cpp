#include <bits/stdc++.h>
using namespace std;

int n;
long long numeros[100001];
int arr[100001];
long long dp[100001];


long long pun(int m){
    long long &r=dp[m];
    if(r!=-1) return r;
    if(m==2) {
            if(numeros[n-2]==numeros[n-1]-1) {
                    return r=max(dp[1],(numeros[n-1]-1)*arr[numeros[n-1]-1]);
            }
            else return r=(numeros[n-2])*arr[numeros[n-2]]+(numeros[n-1])*arr[numeros[n-1]];
    }
    if(numeros[n-m]==numeros[n-m+1]-1){
        r=pun(m-2)+numeros[n-m]*arr[numeros[n-m]];
        if(numeros[n-m+1]==numeros[n-m+2]-1){
           r=max(r, pun(m-3)+numeros[n-m+1]*arr[numeros[n-m+1]]);
           }
        else{
            r=max(r, pun(m-2)+numeros[n-m+1]*arr[numeros[n-m+1]]);
        }
        return r;
    }
    return r=pun(m-1)+numeros[n-m]*arr[numeros[n-m]];
}

int main(void){
    cin>>n;
    memset(arr, 0, sizeof arr);
    int cont=0;
    for(int i=0;i<n;i++){
        int aux;
        cin>>aux;
        arr[aux]++;
        if(arr[aux]==1) {
            cont++;
            numeros[cont-1]=aux;
        }
    }
    sort(numeros, numeros+cont);
    cout<<numeros[0]<<endl;

    memset(dp, -1, sizeof dp);
    dp[0]=0;
    n=cont;
    dp[1]=numeros[n-1]*arr[numeros[n-1]];
    cout<< pun(cont)<< endl;
}
