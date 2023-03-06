#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Record {
    string name;
    string phone;
};

void addRecord(Record record) {
    ofstream outfile;
    outfile.open("phonebook.txt", ios::app);
    outfile << record.name << " " << record.phone << endl;
    outfile.close();
}

vector<Record> readRecords() {
    vector<Record> records;
    ifstream infile;
    infile.open("phonebook.txt");
    string name, phone;
    while (infile >> name >> phone) {
        records.push_back({name, phone});
    }
    infile.close();
    return records;
}

void listRecords() {
    vector<Record> records = readRecords();
    for (Record record : records) {
        cout << record.name << " " << record.phone << endl;
    }
}

void searchRecord(string name) {
    vector<Record> records = readRecords();
    for (Record record : records) {
        if (record.name == name) {
            cout << record.name << " " << record.phone << endl;
            return;
        }
    }
    cout << "Record not found" << endl;
}

void modifyRecord(string name, string phone) {
    vector<Record> records = readRecords();
    for (Record& record : records) {
        if (record.name == name) {
            record.phone = phone;
            ofstream outfile;
            outfile.open("phonebook.txt", ios::trunc);
            for (Record r : records) {
                outfile << r.name << " " << r.phone << endl;
            }
            outfile.close();
            cout << "Record modified successfully" << endl;
            return;
        }
    }
    cout << "Record not found" << endl;
}

void deleteRecord(string name) {
    vector<Record> records = readRecords();
    auto it = remove_if(records.begin(), records.end(),
                        [name](Record r) { return r.name == name; });
    if (it == records.end()) {
        cout << "Record not found" << endl;
    } else {
        records.erase(it, records.end());
        ofstream outfile;
        outfile.open("phonebook.txt", ios::trunc);
        for (Record r : records) {
            outfile << r.name << " " << r.phone << endl;
        }
        outfile.close();
        cout << "Record deleted successfully" << endl;
    }
}

int main() {
    int choice;
    Record record;

    do {
        cout << "Phone Book Menu" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. List Records" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Modify Record" << endl;
        cout << "5. Delete Record" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> record.name;
                cout << "Enter phone number: ";
                cin >> record.phone;
                addRecord(record);
                break;
            case 2:
                listRecords();
                break;
            case 3:
                cout << "Enter name to search: ";
                cin >> record.name;
                searchRecord(record.name);
                break;
            case 4:
            	cout<<"Enter modify name:";
            	cin>>record.name;
            	cout<<"Enter new phone number:";
            	cin>>record.phone;
            	modifyRecord(record.name, record.phone);
            	break;
            case 5:
            	cout<<"Enter name you want to delete:";
            	cin>>record.name;
            	deleteRecord(record.name);
            	break;
            case 6:
            	cout<<"..Exiting..";
            	break;
            default:
            	cout<<"Invalid choice..";
            	break;
            }
        }while(choice!=6);
        
        return 0;
    }
            	
                

