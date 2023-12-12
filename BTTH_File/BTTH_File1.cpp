#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc dữ liệu SinhVien
struct SinhVien {
    char ten[50];
    char maSV[10];
    float diem;
};

// Hàm để thêm SinhVien mới vào tệp tin
void themSinhVien(FILE *file, struct SinhVien sv) {
    fwrite(&sv, sizeof(struct SinhVien), 1, file);
}

// Hàm để hiển thị thông tin SinhVien từ tệp tin
void hienThiDanhSach(FILE *file) {
    struct SinhVien sv;
    fseek(file, 0, SEEK_SET); // Đặt con trỏ tệp tin về đầu tệp
    printf("Danh sach sinh vien:\n");
    
    while (fread(&sv, sizeof(struct SinhVien), 1, file) == 1) {
        printf("Ten: %s\n", sv.ten);
        printf("Ma sinh vien: %s\n", sv.maSV);
        printf("Diem: %.2f\n\n", sv.diem);
    }
}

// Hàm để xóa SinhVien từ tệp tin dựa trên mã sinh viên
void xoaSinhVien(FILE *file, char maSV[]) {
    FILE *tempFile = fopen("temp.dat", "wb");
    struct SinhVien sv;

    fseek(file, 0, SEEK_SET);

    while (fread(&sv, sizeof(struct SinhVien), 1, file) == 1) {
        if (strcmp(sv.maSV, maSV) != 0) {
            fwrite(&sv, sizeof(struct SinhVien), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("sinhvien.dat");
    rename("temp.dat", "sinhvien.dat");
}

// Hàm để cập nhật thông tin SinhVien dựa trên mã sinh viên
void capNhatSinhVien(FILE *file, char maSV[], struct SinhVien svMoi) {
    FILE *tempFile = fopen("temp.dat", "wb");
    struct SinhVien sv;

    fseek(file, 0, SEEK_SET);

    while (fread(&sv, sizeof(struct SinhVien), 1, file) == 1) {
        if (strcmp(sv.maSV, maSV) == 0) {
            fwrite(&svMoi, sizeof(struct SinhVien), 1, tempFile);
        } else {
            fwrite(&sv, sizeof(struct SinhVien), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("sinhvien.dat");
    rename("temp.dat", "sinhvien.dat");
}

int main() {
    FILE *file = fopen("sinhvien.dat", "ab+");

    if (file == NULL) {
        printf("Khong the mo hoac tao tep tin.\n");
        return 1;
    }

    int choice;
    struct SinhVien sv;

    do {
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Cap nhat thong tin sinh vien\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap ten sinh vien: ");
                scanf("%s", sv.ten);
                printf("Nhap ma sinh vien: ");
                scanf("%s", sv.maSV);
                printf("Nhap diem sinh vien: ");
                scanf("%f", &sv.diem);
                themSinhVien(file, sv);
                break;

            case 2:
                hienThiDanhSach(file);
                break;

            case 3:
                printf("Nhap ma sinh vien can xoa: ");
                char maSVXoa[10];
                scanf("%s", maSVXoa);
                xoaSinhVien(file, maSVXoa);
                break;

            case 4:
                printf("Nhap ma sinh vien can cap nhat: ");
                char maSVCapNhat[10];
                scanf("%s", maSVCapNhat);
                printf("Nhap thong tin sinh vien moi:\n");
                printf("Nhap ten: ");
                scanf("%s", sv.ten);
                printf("Nhap ma sinh vien: ");
                scanf("%s", sv.maSV);
                printf("Nhap diem: ");
                scanf("%f", &sv.diem);
                capNhatSinhVien(file, maSVCapNhat, sv);
                break;

            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    fclose(file);

    return 0;
}
