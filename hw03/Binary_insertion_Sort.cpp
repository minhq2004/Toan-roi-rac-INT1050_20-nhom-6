#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, a[10010];

void insertion_sort(int a[], int n);
void Binary_insertion_sort(int a[], int n);
void print_array(int a[], int n);
int find_pos(int a[], int ind, int key, int &cnt);

int main(){
    if(ifstream("ok.inp")){
        freopen("ok.inp", "r", stdin);
        freopen("ok.out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++)    cin >> a[i];

    insertion_sort(a, n);
    //Binary_insertion_sort(a, n);
    print_array(a, n);
}

void insertion_sort(int a[], int n){
    int cnt = 0;
    for (int i = 2; i <= n; i++){
        int j = 1;
        while (a[j] < a[i]){ //tim cho den khi nao a[j] >= a[i]
            j++; 
            cnt++;
        }
        cnt++;
        int temp = a[i];
        for (int k = i; k > j; k--){
            a[k] = a[k - 1];
        }
        a[j] = temp;
    }
    cout << "so phep so sanh khi dung sx chen la " << cnt << endl;
}

void Binary_insertion_sort(int a[], int n){
    int Bcnt = 0;
    for (int i = 2; i <= n; i++){
        int j = find_pos(a, i, a[i], Bcnt);
        int temp = a[i];
        for (int k = i; k > j; k--){
            a[k] = a[k - 1];
        }
        a[j] = temp;
    }
    cout << "so phep so sanh khi dung sx chen nhi phan la " << Bcnt << endl;
}
void print_array(int a[], int n){
    for (int i = 1; i <= n; i++)    cout << a[i] << ' ';
}

int find_pos(int a[], int ind, int key, int &Bcnt){ //mang tu 1 denn ind luon dc sort roi
    //tim pos gan ind nhat sao cho a[pos] >= key
    
    int st = 1, en = ind;
    while (st < en){
        int mid = (st + en) / 2;
        if (a[mid] < key){
            st = mid + 1;
            Bcnt++;
        }
        else if (a[mid] >= key){
            en = mid;
            Bcnt++;
        }
        Bcnt++;
    }
    return en;
}
