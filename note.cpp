#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void addNote();
void viewNote();
void deleteNote();

int main() {
    
    int choice;
    while (true){
        cout << "Text File Note \n";
        cout << "1. Add a Note\n";
        cout << "2. View Notes\n";
        cout << "3. Delete a Note\n";
        cout << "4. Exit\n \n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            addNote();
            break;
        case 2:
            viewNote();
            break;        
        case 3:
            deleteNote();
            break;
        case 4:
            return 0;
    
        default:
            cout << "Invalid selection, Please try again";
        }
    }

    return 0;
}

void addNote() {
    string note;
    cout << "Enter your note: \n";
    cin.ignore(); // used to clear the input buffer
    getline(cin, note);

    ofstream file("notes.txt", ios::app);
    if(file.is_open()){
        file << note << endl;
        file.close();
        cout << "Note added successfully \n";
    } else {
        cout << "Unable to open this file\n";
    }

}

void viewNote() {
    ifstream file("notes.txt");
    if(file.is_open()){
        string note;
        int lineNumber = 1;
        while (getline(file, note)){
            cout << lineNumber << ". " << note << endl;
            lineNumber++;
        }
        file.close();
    } else {
        cout << "No notes to display.\n";
    }
}

void deleteNote() {
    int lineToDelete;
    viewNote();
    cout << "Enter the line number of the text you want to delete.\n";
    cin >> lineToDelete;

    ifstream inFile("notes.txt");
    ofstream outFile("temp.txt");

    string note;
    int lineNumber = 1;

    while (getline(inFile, note)) {
        if(lineNumber != lineToDelete){
            outFile << note << endl;
        }
        lineNumber++;
    }
    inFile.close();
    outFile.close();

    remove("notes.txt");
    rename("temp.txt", "notes.txt");

    cout << "Note deleted successfully.\n";
}