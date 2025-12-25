#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string subjects[6] = {
    "English", "Urdu", "Maths",
    "Computer", "Islamiat", "History"
};

void addStudent() {
    string name;
    int roll, marks[6];
    int obtainedMarks = 0;
    int totalMarks = 600;   // 6 subjects × 100
    float percentage;
    string result;

    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter Roll Number: ";
    cin >> roll;

    for (int i = 0; i < 6; i++) {
        cout << "Enter marks for " << subjects[i] << ": ";
        cin >> marks[i];
        obtainedMarks += marks[i];
    }

    percentage = (obtainedMarks * 100.0) / totalMarks;

    if (percentage >= 80)
        result = "Pass";
    else
        result = "Fail";

    ofstream file("students.txt", ios::app);
    file << name << " " << roll << " ";
    for (int i = 0; i < 6; i++)
        file << marks[i] << " ";
    file << obtainedMarks << " " << percentage << " " << result << endl;
    file.close();

    cout << "\nStudent record saved successfully!\n";
}

void searchStudent() {
    string searchName, name, result;
    int roll, marks[6], obtainedMarks;
    float percentage;
    bool found = false;

    cin.ignore();
    cout << "Enter student name to search: ";
    getline(cin, searchName);

    ifstream file("students.txt");

    while (file >> name >> roll) {
        for (int i = 0; i < 6; i++)
            file >> marks[i];
        file >> obtainedMarks >> percentage >> result;

        if (name == searchName) {
            found = true;
            cout << "\n--- Student Record Found ---\n";
            cout << "Name: " << name << endl;
            cout << "Roll Number: " << roll << endl;

            for (int i = 0; i < 6; i++)
                cout << subjects[i] << ": " << marks[i] << endl;

            cout << "Total Marks: 600\n";
            cout << "Obtained Marks: " << obtainedMarks << endl;
            cout << "Percentage: " << percentage << "%" << endl;
            cout << "Result: " << result << endl;
            break;
        }
    }

    if (!found)
        cout << "\nStudent not found!\n";

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Result Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}

