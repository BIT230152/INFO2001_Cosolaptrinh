#include <stdio.h>

void selectionSort(int arr[], int n,int choice) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if ((choice && arr[j] < arr[min_idx]) || (!choice && arr[j] > arr[min_idx])) {
                min_idx = j;
            }
        }
        
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int i, n;
    int arr[100];
    int choice;

    printf("Nhập số lượng phần tử trong mảng: ");
    scanf("%d", &n);

    printf("Nhập các phần tử của mảng:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Lựa chọn sắp xếp (1 - Tăng dần, 0 - Giảm dần): ");
    scanf("%d", &choice);

    selectionSort(arr, n, choice);

    printf("\nMảng sau khi sắp xếp: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}