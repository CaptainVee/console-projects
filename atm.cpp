

#include <iostream>
#include <string> 

using namespace std;

double balance = 500;

void showMenu();
void showBalance();

int main() {

    int option;
    do
    {
    showMenu();
    cout << "Option: ";

    cin >> option;

    switch (option)
    {
    case 1:
        showBalance();
        break;

    case 2:
        cout << "How much would you like to deposit? :"<< endl;
        double depositamount;
        cin >> depositamount;
        balance += depositamount;
        showBalance();
        break;
    
    case 3:
        cout << "How much would you like to Withdraw? :"<< endl;
        double withdrawamount;
        cin >> withdrawamount;
        if (withdrawamount <= balance)
        {   
            balance -= withdrawamount;
            cout << "You have successfully withdrawn" << withdrawamount <<endl;
            showBalance();
        }else
            cout << "Insufficient Balance" << endl;
        
        break;
    }
    } while (option !=4);
    

    return 0;
}

void showMenu(){
    cout << "**************MENU*****************" << endl;
    cout << "1. Check balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cout << "***********************************" << endl;
    cout << endl << endl;

}

void showBalance(){
    cout << "Your account balance is : $" << balance << endl;
}

