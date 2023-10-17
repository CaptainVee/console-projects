#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check if a user with the given username and password exists in the file
bool userExists(const std::string& username, const std::string& password, std::ifstream& inputFile);

bool updatePassword(const std::string& username, const std::string& newPassword, std::ifstream& inputFile);

int main() {
    string user, oldPassword, newPassword;

    cout << "     Security system  " << endl;
    cout << "_______________________________" << endl;
    cout << "|       1. Register           |" << endl;
    cout << "|       2. Login              |" << endl;
    cout << "|       3. Change Password    |" << endl;
    cout << "|_______4. Exit_______________|" << endl << endl;

    do {
        cout << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            {
                cout << "_______________________________" << endl;
                cout << "|-----------Register-----------|" << endl;
                cout << "|______________________________|" << endl;
                string name, password0;
                cout << "Please enter username: ";
                cin >> name;
                cout << "Please enter password: ";
                cin >> password0;

                // Open the file in append mode to add new users
                std::ofstream outputFile1("file.txt", std::ios::app);

                if (!outputFile1) {
                    cerr << "Failed to open the file." << endl;
                    return 1; // Return an error code
                }

                // Write user data to the file
                outputFile1 << name << '\n';
                outputFile1 << password0 << '\n';

                cout << "Registration successful" << endl;
                outputFile1.close(); // Close the file
            }
            break;

        case 2:
            {
                cout << "_______________________________" << endl;
                cout << "|-----------Login--------------|" << endl;
                cout << "|______________________________|" << endl;
                cout << "Please enter your username: ";
                cin >> user;
                cout << "Please enter your password: ";
                cin >> oldPassword;

                std::ifstream inputFile("file.txt");

                if (userExists(user, oldPassword, inputFile)) {
                    cout << "Login successful!" << endl;
                } else {
                    cout << "Login failed. Invalid username or password." << endl;
                }
                inputFile.close();
            }
            break;

        case 3:
            {
                cout << "_______________________________" << endl;
                cout << "|-------Change Password--------|" << endl;
                cout << "|______________________________|" << endl;
                cout << "Please enter your username: ";
                cin >> user;
                cout << "Please enter your old password: ";
                cin >> oldPassword;
                cout << "Please enter your new password: ";
                cin >> newPassword;

                std::ifstream inputFile("file.txt");

                if (updatePassword(user, newPassword, inputFile)) {
                    cout << "Password changed successfully!" << endl;
                } else {
                    cout << "Password change failed. Invalid username or old password." << endl;
                }
                inputFile.close();
            }
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

    } while (true);

    return 0;
}

bool userExists(const std::string& username, const std::string& password, std::ifstream& inputFile) {
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line == username) {
            if (std::getline(inputFile, line) && line == password) {
                return true; // User found with matching username and password
            }
        }
    }
    return false; // User not found
}

bool updatePassword(const std::string& username, const std::string& newPassword, std::ifstream& inputFile) {
    std::ofstream tempFile("temp.txt");
    std::string line;
    bool userFound = false;

    while (std::getline(inputFile, line)) {
        if (line == username) {
            userFound = true;
            tempFile << line << '\n';         // Write the username
            tempFile << newPassword << '\n';  // Write the new password
            inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skip the old password
        } else {
            tempFile << line << '\n';         // Copy other lines as-is
        }
    }

    tempFile.close();
    inputFile.close();

    if (userFound && std::rename("temp.txt", "file.txt") == 0) {
        return true; // Password updated successfully
    }

    return false; // Password update failed
}
