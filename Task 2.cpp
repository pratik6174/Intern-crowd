#include <bits/stdc++.h>


using namespace std;

// function to register a new user
void registerUser(string username, string password) {
    ofstream userFile;
    userFile.open("users.txt" + username + ".txt");
    userFile << password;
    userFile.close();
    cout << "User registered successfully!" << endl;
}

// function to check if a user exists
bool userExists(string username) {
    ifstream userFile;
    userFile.open("users.txt" + username + ".txt");
    if (userFile) {
        userFile.close();
        return true;
    } else {
        return false;
    }
}

// function to login a user
void loginUser(string username, string password) {
    ifstream userFile;
    userFile.open("users.txt" + username + ".txt");
    string storedPassword;
    getline(userFile, storedPassword);
    userFile.close();
    if (password == storedPassword) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Incorrect password." << endl;
    }
}

int main() {
    string username, password;
    int choice;

    do {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                cin >> username;
                if (userExists(username)) {
                    cout << "User already exists." << endl;
                } else {
                    cout << "Enter password: ";
                    cin >> password;
                    registerUser(username, password);
                }
                break;
            case 2:
                cout << "Enter username: ";
                cin >> username;
                if (!userExists(username)) {
                    cout << "User does not exist." << endl;
                } else {
                    cout << "Enter password: ";
                    cin >> password;
                    loginUser(username, password);
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}

