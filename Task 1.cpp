#include <bits\stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Birthday {
    string name,email;
    int day;
    int month;
};

vector<Birthday> birthdayList;

void addBirthday() {
    Birthday b;
    cout << "Enter name: ";
    cin >> b.name;
    cout << "Enter day: ";
    cin >> b.day;
    cout << "Enter month: ";
    cin >> b.month;
    cout<< "Enter Email: ";
    cin>>b.email;
    birthdayList.push_back(b);
}

void editBirthday() {
    cout << "Enter name to edit: ";
    string name;
    cin >> name;
    for (auto& b : birthdayList) {
        if (b.name == name) {
            cout << "Enter new day: ";
            cin >> b.day;
            cout << "Enter new month: ";
            cin >> b.month;
            return;
        }
    }
    cout << "Name not found\n";
}

void displayBirthdayList() {
    cout << "Birthday List:\n";
    for (auto& b : birthdayList) {
        cout << b.name << ": " << b.month << "/" << b.day << "\n"<<"Email:"<<b.email;
    }
}

void displayMonthlyBirthdays() {
    int month;
    cout << "Enter month: ";
    cin >> month;
    cout << "Birthdays in month " << month << ":\n";
    for (auto& b : birthdayList) {
        if (b.month == month) {
            cout << b.name << ": " << b.month << "/" << b.day << "\n"<<"Email:"<<b.email;
        }
    }
}

void searchBirthday() {
    cout << "Enter name to search: ";
    string name;
    cin >> name;
    for (auto& b : birthdayList) {
        if (b.name == name) {
            cout << b.name << ": " << b.month << "/" << b.day << "\n"<<"Email:"<<b.email;
            return;
        }
    }
    cout << "Name not found\n";
}

int main() {
    while (true) {
        cout << "Select an option:\n";
        cout << "1. Add a birthday\n";
        cout << "2. Edit a birthday\n";
        cout << "3. Display birthday list\n";
        cout << "4. Display monthly birthdays\n";
        cout << "5. Search for a birthday\n";
        cout << "6. Exit\n";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                addBirthday();
                break;
            case 2:
                editBirthday();
                break;
            case 3:
                displayBirthdayList();
                break;
            case 4:
                displayMonthlyBirthdays();
                break;
            case 5:
                searchBirthday();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid option\n";
        }
    }
    return 0;
}
