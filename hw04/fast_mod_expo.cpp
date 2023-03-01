//fast modular exponentiaion
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

//b ^ n mod m
int b, n, m;

int FastModExpo(int b, int n, int m){
    int x = 1;
    int power = b % m;
    while (n){
        int N = n & 1;
        n >>= 1;
        if (N == 1)  x = (x * power) % m;
        power = (power * power) % m;
    }
    return x;
}

 // b ^ n = (b ^(n / 2)) ^ 2  n chan
 // n le --> b * (b ^(n / 2)) * (b ^(n / 2))
int pow_modulo(long long base, long long exponent, long long m) {
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    long long half = pow_modulo(base, exponent/2, m);
    if (exponent % 2 == 0) {
        return (half * half) % m;
    } else {
        return (((half * half) % m) * base) % m;
    }
}

int main(){
    if(ifstream("ok.inp")){
        freopen("ok.inp", "r", stdin);
        freopen("ok.out", "w", stdout);
    }
    cin >> b >> n >> m;
    cout << FastModExpo(b, n, m) << endl;

}
