#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a, b, x, y, d;

void extended_euclid(int a, int b){
    if (b == 0){
        x = 1;
        y = 0;
        d = a;
    }
    else{
        extended_euclid(b, a % b);
        //x' = y, y' = x - y * a/b
        int tmp = y;
        y = x - tmp * (a / b);
        x = tmp;
        //cout << x << ' ' << y << endl;
    }
}

int modulo_inverse (int n, int m){
    extended_euclid(n, m);
    if (d != 1) return -1; // not exist;
    return (x % m + m) % m; // x la nghich dao modulo cua n;
}

int main(){
    if(ifstream("ok.inp")){
        freopen("ok.inp", "r", stdin);
        freopen("ok.out", "w", stdout);
    }
    int a, b;
    cin >> a >> b;
    extended_euclid(a, b);
    // cout << "x: " << x << "   y: " << y << endl << d;
    cout << modulo_inverse(a, b);
}
