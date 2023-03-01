#include <iostream>
#include <cmath>
using namespace std;

long long powerMod(long long a, long long b, long long c) {
    long long ans = 1;
    for(int i = 1; i <= b; i++) {
        ans *= a;
        ans %= c;
    }
    return ans;
 }

int main () {
    long long a, b, m;
    cin >> a >> b >> m;
    cout << powerMod(a, b, m) << endl;
    return 0; 
}