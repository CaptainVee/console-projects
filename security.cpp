#include <iostream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int main() {

    int i = 0;

    string text, old, password1, password2, pass, name, password0, age, user, word, word1;

    string creds[2], cp[2];

    cout << "     Security system  "<< endl;
    cout << "_______________________________"<< endl;
    cout << "|       1. Register           |"<< endl;
    cout << "|       2. Login              |"<< endl;
    cout << "|       3. Change Password    |"<< endl;
    cout << "|_______4. Exit_______________|"<< endl<<endl;

    do
    {
        cout<<endl;
        cout << "Enter your choice :-";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        
        default:
            break;
        }

    } while (true);
    
    return 0;
}