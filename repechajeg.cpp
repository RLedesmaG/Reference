#include <bits/stdc++.h>
using namespace std;
long long int sieve_size;
std::bitset<1300000> bs;
std::vector<int> primes;

void sieve(long long int up){
    sieve_size = up+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(long long int i=2;i<=sieve_size;i++) if(bs[i]){
        for(long long int j=i*i;j<=sieve_size;j+=i) bs[j]=0;
        primes.push_back((int) i);
    }
}

bool isPrime(long long int N){
    if(N<=sieve_size) return bs[N];
    for(int i=0;i<(int)primes.size();i++)
        if(N%primes[i]==0) return false;
    return true;
}

//main nos da el n-esimo primo;
int main(void){
    sieve(1300000);
    int n, m;
    while(true){
        cin>>n>>m;
        if(n==0 && m==0) return 0;
        int res=-1;
        if(n>m) swap(n, m);
        vector<int>::iterator it1, it2;
        it1=lower_bound(primes.begin(), primes.end(), n);
        int p = it1-primes.begin();
        int q = p+1;
        while(primes[q]<=m){

            res=max(res, primes[q]-primes[p]);
            p++;
            q++;

        }
        if(res==-1) cout<<"NULL\n";
        else
            cout<<res<<"\n";

    }
    return 0;
}
