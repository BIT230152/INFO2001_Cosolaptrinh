#include <stdio.h>

#define MAX_STUDENTS 50

float AverageScore(float scores[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }return sum / n;
}

int main() {
    int i, n;
    float scores[MAX_STUDENTS];

    printf("Nhập số lượng sinh viên trong lớp: ");
    scanf("%d", &n);

    printf("Nhập điểm của các sinh viên:\n");
    for (i = 0; i < n; i++) {
        printf("Điểm của sinh viên thứ  %d: ", i + 1);
        scanf("%f", &scores[i]);
    }

    float average = AverageScore(scores, n);
    printf("Điểm trung bình của lớp: %.2f\n", average);

    return 0;
}