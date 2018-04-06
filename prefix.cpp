
#include <bits/stdc++.h>
using namespace std;

vector <int> b;

void border(string s){
    int n = s.length();
    for(int i = 1; i < n; ++i){
        int k = b[i-1];
        while(k > 0 && s[k] != s[i])
            k = b[k-1];
        if(s[k] == s[i])
            b[i] = k + 1;
    }
}

int main(void){
    string s;
    cin >> s;
    int n = s.length();
    b = vector <int>(n, 0);
    border(s);
    for (int i = 0; i < n; ++i){
        cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}
