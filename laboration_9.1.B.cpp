#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

enum Specialnost { Computer_Science, Informatics, Mathematics_And_Economics, Physics_And_Informatics, Labor_Education };

union Grade {
    double programmingGrade;
    double numericalMethodsGrade;
    double pedagogyGrade;
};

struct Student {
    int studentNumber;
    string prizv;
    int course;
    Specialnost specialnost;
    double physicsGrade;
    double mathGrade;
    Grade thirdGrade;
};

void Create(Student* students, const int N);
void Print(Student* students, const int N);
int Count5(Student* S, const int N);
int Count4(Student* S, const int N);
int Count3(Student* S, const int N);
void Students_With_Grade_5_In_Physics_And_Math(Student* S, const int N);

int main() {
    int N;
    cout << "Enter the number of students: ";
    cin >> N;

    Student* students = new Student[N];
    int grade3Count;
    int grade4Count;
    int grade5Count;

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Select an action: " << endl << endl;
        cout << " [1] - entering data from the keyboard " << endl;
        cout << " [2] - cout data in display" << endl;
        cout << " [3] - count grade of 3 from math" << endl;
        cout << " [4] - count grade of 4 from math" << endl;
        cout << " [5] - count grade of 5 from math" << endl;
        cout << " [6] - print students who got 5 from physics and math" << endl;
        cout << " [0] - Exit" << endl << endl;
        cout << "Input value: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            Create(students, N);
            break;
        case 2:
            Print(students, N);
            break;
        case 3:
            grade3Count = Count3(students, N);
            cout << " Count grade of 3 from math: " << grade3Count << endl;
            break;
        case 4:
            grade4Count = Count4(students, N);
            cout << " Count grade of 4 from math: " << grade4Count << endl;
            break;
        case 5:
            grade5Count = Count5(students, N);
            cout << " Count grade of 5 from math: " << grade5Count << endl;
            break;
        case 6:
            cout << " Students who got 5 from physics and math: " << endl;
            Students_With_Grade_5_In_Physics_And_Math(students, N);
            break;
        case 0:
            break;
        default:
            cout << "You choose fake value! " << endl;
        }
    } while (menuItem != 0);

    delete[] students;

    return 0;
}

void Create(Student* students, const int N) {
    for (int i = 0; i < N; ++i) {
        students[i].studentNumber = i + 1;

        cout << "Student #" << students[i].studentNumber << ":" << endl;
        cin.ignore();

        cout << "Last Name: ";
        getline(cin, students[i].prizv);

        cout << "Course: ";
        cin >> students[i].course;

        cout << "Specialnost (0 - Computer_Science, 1 - Informatics, 2 - Mathematics_And_Economics, 3 - Physics_And_Informatics, 4 - Labor_Education): ";
        int specValue;
        cin >> specValue;
        students[i].specialnost = static_cast<Specialnost>(specValue);

        cout << "Physics Grade: ";
        cin >> students[i].physicsGrade;

        cout << "Math Grade: ";
        cin >> students[i].mathGrade;


        switch (students[i].specialnost) {
        case Computer_Science:
            cout << "Programming Grade: ";
            cin >> students[i].thirdGrade.programmingGrade;
            break;
        case Informatics:
            cout << "Numerical Methods Grade: ";
            cin >> students[i].thirdGrade.numericalMethodsGrade;
            break;
        case Mathematics_And_Economics:
        case Physics_And_Informatics:
        case Labor_Education:
            cout << "Pedagogy Grade: ";
            cin >> students[i].thirdGrade.pedagogyGrade;
            break;
        }

        cout << "-----------------------------\n";
    }
}

void Print(Student* students, const int N) {
    cout << "=========================================================================================================================="
        << endl;
    cout << "| # | Last Name             | Course | Specialnist                | Physics | Math | Programming | Num. Meth.  | Pedagogy |"
        << endl;

    for (int i = 0; i < N; ++i) {
        cout << "| " << setw(1) << left << students[i].studentNumber << " ";
        cout << "| " << setw(21) << left << students[i].prizv << " | " << setw(6) << left << students[i].course;

        switch (students[i].specialnost) {
        case Computer_Science:
            cout << " | Computer_Science ";
            break;
        case Informatics:
            cout << " | Informatics ";
            break;
        case Mathematics_And_Economics:
            cout << " | Mathematics_And_Economics ";
            break;
        case Physics_And_Informatics:
            cout << " | Physics_And_Informatics ";
            break;
        case Labor_Education:
            cout << " | Labor_Education ";
            break;
        }

        cout << "          | " << setw(7) << right << students[i].physicsGrade << " | " << setw(4) << left << students[i].mathGrade;

        switch (students[i].specialnost) {
        case Computer_Science:
            cout << " | " << setw(11) << left << students[i].thirdGrade.programmingGrade;
            cout << " | " << setw(11) << left << "N/A";
            cout << " | " << setw(11) << left << "N/A";
            break;
        case Informatics:
            cout << " | " << setw(11) << left << "N/A";
            cout << " | " << setw(11) << left << students[i].thirdGrade.numericalMethodsGrade;
            cout << " | " << setw(11) << left << "N/A";
            break;
        case Mathematics_And_Economics:
        case Physics_And_Informatics:
        case Labor_Education:
            cout << " | " << setw(11) << left << "N/A";
            cout << " | " << setw(11) << left << "N/A";
            cout << " | " << setw(11) << left << students[i].thirdGrade.pedagogyGrade;
            break;
        }

        cout << "|   " << endl;
    }

    cout << "=========================================================================================================================="
        << endl;
    cout << endl;
}

int Count5(Student* S, const int N) {
    int grade5Count = 0;
    for (int i = 0; i < N; i++) {
        if (S[i].mathGrade == 5) {
            grade5Count++;
        }
    }

    return grade5Count;
}

int Count4(Student* S, const int N) {
    int grade4Count = 0;
    for (int i = 0; i < N; i++) {
        if (S[i].mathGrade == 4) {
            grade4Count++;
        }
    }

    return grade4Count;
}

int Count3(Student* S, const int N) {
    int grade3Count = 0;
    for (int i = 0; i < N; i++) {
        if (S[i].mathGrade == 3) {
            grade3Count++;
        }
    }

    return grade3Count;
}

void Students_With_Grade_5_In_Physics_And_Math(Student* S, const int N) {
    for (int i = 0; i < N; i++) {
        if (S[i].physicsGrade == 5 && S[i].mathGrade == 5) {
            cout << S[i].prizv << endl;
        }
    }
}