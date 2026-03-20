#include<iostream>
using namespace std;

struct student {
    string studentID;
    string name;
    string course;
    int gpa;
};

void input(int num, student s[]) {
    for (int i = 0; i < num; i++) {
        cout << "Enter ID number: ";
        getline(cin, s[i].studentID);

    
        for (int j = 0; j < i; j++) {
            while (s[i].studentID == s[j].studentID) {
                cout << "Student ID already exists. Please enter a different one: ";
                getline(cin, s[i].studentID);
                j = 0; 
            }
        }

        cout << "Enter Name: ";
        getline(cin, s[i].name);
        cout << "Enter Course: ";
        getline(cin, s[i].course);
        cout << "Enter GPA (0-100): ";
        cin >> s[i].gpa;
        cin.ignore();
    }
}

void display(int num, student s[]) {
    cout << "\n--- Student Records ---\n";
    cout << "StudentID\tName\tCourse\tGPA\tAcademic Standing\n";

    for (int i = 0; i < num; i++) {
        string standing;

        if      (s[i].gpa >= 90) standing = "Excellent";
        else if (s[i].gpa >= 80) standing = "Very Good";
        else if (s[i].gpa >= 70) standing = "Good";
        else if (s[i].gpa >= 60) standing = "Passing";
        else                     standing = "Failed";

        cout << s[i].studentID << "\t"
             << s[i].name      << "\t"
             << s[i].course    << "\t"
             << s[i].gpa       << "\t"
             << standing       << "\n";
    }
}

int main() {
    char tryAgain;

    do {
        int num;
        cout << "How many students: ";
        cin >> num;
        cin.ignore();

        student s[num];

        input(num, s);
        display(num, s);

        cout << "\nDo you want to try again? (y/n): ";
        cin >> tryAgain;
        cin.ignore();

    } while (tryAgain == 'y' || tryAgain == 'Y');

    return 0;
}