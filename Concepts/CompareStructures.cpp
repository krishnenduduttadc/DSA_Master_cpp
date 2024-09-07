#include <iostream>
#include <cstring> // for strcmp

using namespace std;

struct Student {
    char fname[70];
    char lname[70];
    int age;
};

void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

void sortStudents(Student students[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && 
                (strcmp(students[j - 1].fname, students[j].fname) > 0 ||
                (strcmp(students[j - 1].fname, students[j].fname) == 0 && strcmp(students[j - 1].lname, students[j].lname) > 0) ||
                (strcmp(students[j - 1].fname, students[j].fname) == 0 && strcmp(students[j - 1].lname, students[j].lname) == 0 && students[j - 1].age > students[j].age))) {
            swap(students[j], students[j - 1]);
            j--;
        }
    }
}

int main() {
    int n;

    cout << "Number of students: ";
    cin >> n;

    Student students[n];

    for (int i = 0; i < n; i++) {
        cout << "Firstname of student " << i + 1 << ": ";
        cin >> students[i].fname;
        cout << "Lastname of student " << i + 1 << ": ";
        cin >> students[i].lname;
        cout << "Age of student " << i + 1 << ": ";
        cin >> students[i].age;
    }

    sortStudents(students, n);

    cout << "Sorted order of students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Firstname of student: " << students[i].fname << "\n";
        cout << "Lastname of student: " << students[i].lname << "\n";
        cout << "Age of student: " << students[i].age << "\n";
    }

    return 0;
}
