#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 30

// Định nghĩa cấu trúc Student
struct Student {
    int id;
    char name[50];
    int age;
    int grade;
};

// Khai báo một mảng chứa danh sách sinh viên
Student students[MAX_STUDENTS];
int numStudents = 0;

// Hàm nhập thông tin sinh viên
void inputStudent(Student* student) {
    printf("Nhập mã sinh viên: ");
    scanf("%d", &student->id);

    printf("Nhập tên sinh viên: ");
    scanf(" %[^\n]s", student->name);

    printf("Nhập tuổi sinh viên: ");
    scanf("%d", &student->age);

    printf("Nhập điểm sinh viên: ");
    scanf(" %d", &student->grade);
}

// Hàm hiển thị thông tin sinh viên
void displayStudent(const Student* student) {
    printf("Ten:%s Tuoi:%d  Id:%d  Diem so:%d\n", student->name, student->age, student->id, student->grade);
}

// Hàm hiển thị danh sách sinh viên
void displayStudents() {
    if (numStudents == 0) {
        printf("Danh sách sinh viên rỗng.\n");
        return;
    }

    printf("Danh sách sinh viên:\n");
    for (int i = 0; i < numStudents; i++) {
        displayStudent(&students[i]);
    }
}
// Hàm sắp xếp danh sách sinh viên theo tên
void sortStudentsByName() {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp danh sách sinh viên theo điểm số
void sortStudentsByGrade() {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[i].grade > students[j].grade) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Hàm tìm kiếm sinh viên theo tên
void searchStudentByName(const char* name) {
    int found = 0;

    printf("Kết quả tìm kiếm theo tên '%s':\n", name);
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            displayStudent(&students[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Không tìm thấy sinh viên có tên '%s'.\n", name);
    }
}

// Hàm tìm kiếm sinh viên theo ID
void searchStudentById(int id) {
    int found = 0;

    printf("Kết quả tìm kiếm theo ID '%d':\n", id);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            displayStudent(&students[i]);
            found = 1;
            break;  // Dừng vòng lặp nếu tìm thấy sinh viên có ID tương ứng
        }
    }

    if (!found) {
        printf("Không tìm thấy sinh viên có ID '%d'.\n", id);
    }
}

int main() {
    int studentNumber;
    int studentId;
    int numstu;
    while (1) {
        printf("Nhap so luong sinh vien:");
        scanf("%d", &numstu);

        if (numstu <= MAX_STUDENTS && numstu >= 1) {
            break;
        } else {
            printf("Vui long nhap lai (1->%d): ", MAX_STUDENTS);
        }
    }
    for (int i = 0; i < numstu; ++i) {
        printf("Nhập thông tinh sinh viên thứ %d:\n", i+1);
        Student newStudent;
        inputStudent(&newStudent);

        students[numStudents++] = newStudent;
    }
    displayStudents();
    
    // Sắp xếp danh sách sinh viên theo điểm số
    sortStudentsByGrade();

    printf("\nDanh sách sinh viên sau khi sắp xếp theo điểm số:\n");
    displayStudents();

    // Tìm kiếm sinh viên theo tên
    char searchName[50];
    printf("Nhập tên sinh viên cần tìm: ");
    scanf(" %[^\n]s", searchName);
    searchStudentByName(searchName);

    // Tìm kiếm sinh viên theo ID
    int searchId;
    printf("Nhập ID sinh viên cần tìm: ");
    scanf("%d", &searchId);
    searchStudentById(searchId);

    
    return 0;
}
