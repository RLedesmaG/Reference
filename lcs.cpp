#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b){
    int n, m;
    n=a.length()+1;
    m=b.length()+1;
    int dp[n][m];
    memset(dp, 0, sizeof dp);

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){

            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }

    return dp[n-1][m-1];

}

int main(void){
    string a, b;
    while(getline(cin, a)){
        getline(cin, b);
        cout<<lcs(a, b)<<"\n";
    }

    return 0;
}
