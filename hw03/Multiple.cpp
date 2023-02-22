#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string dec2bin (int num){
    string ans = "";
    while (num){
        ans = char(num % 2 + '0') + ans;
        num /= 2;
    }
    return ans;
}

int add (int a, int b){
    string A = dec2bin(a);
    string B = dec2bin(b);
    while (A.size() < B.size())    A = '0' + A;
    while (B.size() < A.size())    B = '0' + B;
    //cout << A << ' ' << B << endl;
    string sum = "";
    int n = A.size();
    int nho = 0;
    for (int i = n - 1; i >= 0; i--){
        int temp = (A[i] - '0' + B[i] - '0' + nho) / 2;
        sum = char((A[i] - '0' + B[i] - '0' + nho - 2 * temp) + '0') + sum;
        nho = temp;
    }
    sum = char(nho + '0') + sum;
    int SUM = 0, pow = 1;
    for (int i = sum.size() - 1; i >= 0; i--){
        SUM += (sum[i] - '0') * pow;
        pow *= 2;
    }
    return SUM;
}

int multiple(int a, int b){
    string A = dec2bin(a);
    string B = dec2bin(b);
    while (A.size() < B.size())    A = '0' + A;
    while (B.size() < A.size())    B = '0' + B;
    int n = A.size();
    int c[n];

    for (int i = n - 1; i >= 0; i--){
        //cout << "B[" << (n - i - 1) << "] : " << B[i] << endl;
        if (B[i] == '1'){
            c[i] = (a << (n - i - 1));
        }
        else c[i] = 0;
        //cout << "c[" << (n - i - 1) << "] : " << c[i] << endl;
        //cout << "****************" << endl;
    }
    int pro = 0;
    for (int i = 0; i < n; i++){
        pro = add(pro, c[i]);
        //cout << c[i] << ' ' << pro << endl;
    }
    return pro;
}


int main(){
    if(ifstream("ok.inp")){
        freopen("ok.inp", "r", stdin);
        freopen("ok.out", "w", stdout);
    }
    int a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
    //cout << a << " : " << dec2bin(a) << endl << b << " : " << dec2bin(b) << endl;

    cout << multiple(a, b);

}
