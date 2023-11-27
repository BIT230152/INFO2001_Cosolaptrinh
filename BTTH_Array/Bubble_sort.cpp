#include <stdio.h>

void bubbleSort(int arr[], int n, int ascending) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, n;
    int arr[100];
    int ascending;

    printf("Nhập số lượng phần tử trong mảng: ");
    scanf("%d", &n);

    printf("Nhập các phần tử của mảng:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Lựa chọn sắp xếp (1 - Tăng dần, 0 - Giảm dần): ");
    scanf("%d", &ascending);

    bubbleSort(arr, n, ascending);

    printf("\nMảng sau khi sắp xếp: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}