#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    // Tìm giá trị lớn nhất trong mảng
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Tạo mảng tạm để đếm số lần xuất hiện của mỗi giá trị
    int count[max_val + 1] = {0};

    // Đếm số lần xuất hiện của mỗi giá trị
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Tính số lượng các giá trị nhỏ hơn hoặc bằng mỗi giá trị
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }

    // Tạo mảng kết quả và đặt các phần tử vào vị trí thích hợp
    int result[n];
    for (int i = n - 1; i >= 0; i--) {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Sao chép mảng kết quả vào mảng ban đầu
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

// Hàm in ra mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang ban dau: ";
    printArray(arr, n);

    countingSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    printArray(arr, n);
}
