#include <iostream>

using namespace std;

int main () {
    int n, a[100];
    cout << "Nhap so phan tu cua day: " ; 
    cin >> n;
    cout << "Nhap day tang dan: " ;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << "Nhap khoa tim kiem: ";
    int x;
    cin >> x;
    int location;
    int i = 1;
    int j = n;
    int m1;
    int m2;
    while (i < j ) {
    	m1 = i + (j - i)/3;
		m2 = j - (j - i)/3;
        if (x < a[m1]) j = m1 - 1;
        else if (x > a[m2]) {
            i = m2 + 1;
        }
        else {
        	i = m1 + 1;
        	j = m2 - 1;
		}
    }
    if (x == a[i]) {
        location = i;
    }
    else if (x == a[j]) {
        location = j;
    }
    else location = 0;
    cout << "Vi tri cua khoa la: " << location;

    return 0;
}
