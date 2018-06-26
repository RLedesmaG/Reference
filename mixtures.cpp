#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int n;

int arr[10000];
int solve(int i, int j){
    int a=arr[i], b=arr[j];
    if(j==i) return dp[i][j]=0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(j-i==1){
        return dp[i][j]=a*b;
    }
    dp[i][j]=1e9;
    for(int i=1;i<n-1;i++){
        dp[i][j]=min(dp[i][j], solve(a, a+i)*solve(a+i+1, b));
    }
}

int main(void){
    cin>>n;

    memset(dp, -1, sizeof dp);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    cout<<solve(0, n-1)<<endl;


    return 0;
}
