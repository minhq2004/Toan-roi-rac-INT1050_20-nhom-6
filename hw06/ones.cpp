#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

string bin;

int ones(string s, int i){
    if (i == 0){
        if (s[i] == '1')    return 1;
        return 0;
    }
    if (s[i] == '1')    return ones(s, i - 1) + 1;
    else return ones(s, i - 1);
}

signed main(){
    if(ifstream("ok.inp")){
        freopen("ok.inp", "r", stdin);
        freopen("ok.out", "w", stdout);
    }
    cin >> bin;
    int n = bin.size() - 1;
    cout << ones(bin, n);
}
