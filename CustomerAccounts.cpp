/******************************************************************************
Rachel Eden
11/25/2018
This program creates a list of customer's an lets the user input data to those customers
*******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <iomanip>
#include <vector>

using namespace std;

struct address {
    string street;
    string city;
    string state;
    string ZIP;
};

struct customer {
    string name = "N/A";
    address customerAddress;
    string telephoneNumber;
    double accountBalance;
    string lastPaymentDate;
};

int mainMenu();
void chooseOption(int);
void addNewCustomer();
void addNewCustomerMenu(int);
void modifyCustomer();
void displayCustomer();

//create array of customers in global scope to be accessible to all functions
customer customer1;
customer customer2;
customer customer3;
customer customer4;
customer customer5;
customer accounts[5] = { customer1, customer2, customer3, customer4, customer5};

bool working = true;

int main()
{
    
    
    //menu interface start
    do {
        int choice = mainMenu();
        chooseOption(choice);
        
    } while (working);
    
    return 0;
}

//main menu for program. ask customers to choose from 3 options or exit.
int mainMenu() {
    int choice = 0;
    cout << "Menu:\n";
    cout << "1. Add a new customer.\n";
    cout << "2. Change an existing customer's information.\n";
    cout << "3. Display a customer's information.\n";
    cout << "4. Exit.\n";
    cout << "Please enter option 1, 2, 3, or 4: ";
    cin >> choice;
    while (choice < 1 || choice > 4) {
        cout << "\nPlease enter a choice from 1 to 4: ";
        cin >> choice;
    }
    cin.ignore();
    return choice;
}

//call additional functions from the main menu depending on the user's choice
void chooseOption(int choice) {
    if (choice == 1) {
        addNewCustomer();
    } else if (choice == 2) {
        modifyCustomer();
    } else if (choice == 3) {
        displayCustomer();
    } else if (choice == 4) {
        cout << "\nExiting...";
        working = false;
    }
}

//decide which slot in the customer array to put the new customer being added into.
//if all slots are full, ask the user to modify an existing slot
void addNewCustomer() {
    if (accounts[0].name == "N/A") {
        addNewCustomerMenu(0);
    } else if (accounts[1].name == "N/A") {
        addNewCustomerMenu(1);
    } else if (accounts[2].name == "N/A") {
        addNewCustomerMenu(2);
    } else if (accounts[3].name == "N/A") {
        addNewCustomerMenu(3);
    } else if (accounts[4].name == "N/A") {
        addNewCustomerMenu(4);
    } else {
        cout << "\nAll available customer slots have been added. Please modify an existing customer.\n";
    }
}

//menu for adding a new customer. user must enter each data point at this time.
void addNewCustomerMenu(int num) {
    cout << "Please enter a name: ";
    getline(cin, accounts[num].name);
    cout << "Enter their street address: ";
    getline(cin, accounts[num].customerAddress.street);
    cout << "Enter their city: ";
    getline(cin, accounts[num].customerAddress.city);
    cout << "Enter their state: ";
    getline(cin, accounts[num].customerAddress.state);
    cout << "Enter their ZIP code: ";
    getline(cin, accounts[num].customerAddress.ZIP);
    cout << "Enter their telephone number: ";
    getline(cin, accounts[num].telephoneNumber);
    cout << "Enter their account balance: ";
    cin >> accounts[num].accountBalance;
    while (accounts[num].accountBalance < 0) {
        cout << "Please enter a non-negative account balance: ";
        cin >> accounts[num].accountBalance;
    }
    cin.ignore();
    cout << "Enter the date of their last payment: ";
    getline(cin, accounts[num].lastPaymentDate);
    
}

//modify an existing customer menu. user can modify each data point in the customer variable that they choose.
//must go back to main menu to modify multiple data points.
void modifyCustomer() {
    int accountNum;
    cout << "Please enter the number of the customer you would like to modify: ";
    cin >> accountNum;
    while (accountNum < 1 || accountNum > 5) {
        cout << "Please enter an account number from 1 to 5: ";
        cin >> accountNum;
    }
    int choice;
    cout << "Modify Customer Menu:\n";
    cout << "1. Name.\n";
    cout << "2. Street address\n";
    cout << "3. City\n";
    cout << "4. State\n";
    cout << "5. ZIP code\n";
    cout << "6. Telephone number\n";
    cout << "7. Account balance\n";
    cout << "8. Date of last payment\n";
    cout << "9. Exit\n";
    cout << "Please enter a choice 1-9: ";
    cin >> choice;
    
    cin.ignore();
    accountNum--;
    if (choice == 1) {
        cout << "Enter a name: ";
        getline(cin, accounts[accountNum].name);
    } else if (choice == 2) {
        cout << "Enter a street address: ";
        getline(cin, accounts[accountNum].customerAddress.street);
    } else if (choice == 3) {
        cout << "Enter a city: ";
        getline(cin, accounts[accountNum].customerAddress.city);
    } else if (choice == 4) {
        cout << "Enter a state: ";
        getline(cin, accounts[accountNum].customerAddress.state);
    } else if (choice == 5) {
        cout << "Enter a ZIP code: ";
        getline(cin, accounts[accountNum].customerAddress.ZIP);
    } else if (choice == 6) {
        cout << "Enter a telephone number: ";
        getline(cin, accounts[accountNum].telephoneNumber);
    } else if (choice == 7) {
        cout << "Enter an account balance: ";
        cin >> accounts[accountNum].accountBalance;
        cin.ignore();
    } else if (choice == 8) {
        cout << "Enter the date of last payment: ";
        getline(cin, accounts[accountNum].lastPaymentDate);
    } else {
        cout << "Returning to main menu... \n";
    }
}

//displays a table to of the information in a specific customer variable to the user
//goes back to the main menu after.
void displayCustomer() {
    int choice;
    cout << "\nWhich customer would you like to display? (1-5) ";
    cin >> choice;
    while (choice < 0 || choice > 5) {
        cout << "Please enter a choice 1-5: ";
        cin >> choice;
    }
    cin.ignore();
    choice--;
    
    cout << "1. Name: " << accounts[choice].name << endl;
    cout << "2. Street address: " << accounts[choice].customerAddress.street << endl;
    cout << "3. City: " << accounts[choice].customerAddress.city << endl;
    cout << "4. State: " << accounts[choice].customerAddress.state << endl;
    cout << "5. ZIP code: " << accounts[choice].customerAddress.ZIP << endl;
    cout << "6. Telephone number: " << accounts[choice].telephoneNumber << endl;
    cout << "7. Account balance: " << accounts[choice].accountBalance << endl;
    cout << "8. Date of last payment: " << accounts[choice].lastPaymentDate << endl << endl;
}

