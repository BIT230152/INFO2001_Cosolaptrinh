#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

int main() {
    int i, n, x;
    int arr[100];

    printf("Nhập số lượng phần tử trong mảng: ");
    scanf("%d", &n);

    printf("Nhập các phần tử của mảng:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhập số cần tìm: ");
    scanf("%d", &x);

    int result = linearSearch(arr, n, x);

    if (result == -1) {
        printf("Không tìm thấy số %d trong mảng.\n", x);
    } else {
        printf("Số %d được tìm thấy tại vị trí %d trong mảng.\n", x, result);
    }

    return 0;
}