#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid; // Trả về chỉ số của x nếu tìm thấy
        }

        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Trả về -1 nếu không tìm thấy x
}

int main() {
    int i, n, x;
    int arr[100];

    printf("Nhập số lượng phần tử trong mảng: ");
    scanf("%d", &n);

    printf("Nhập các phần tử của mảng theo thứ tự tăng dần:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1) {
        printf("Không tìm thấy giá trị %d trong mảng.\n", x);
    } else {
        printf("Giá trị %d được tìm thấy tại vị trí %d trong mảng.\n", x, result);
    }

    return 0;
}