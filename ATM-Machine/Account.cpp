//
// Created by radel on 2024-10-24.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <limits>
#include <stdexcept>
#include "menus.h"
#include "Account.h"
using namespace std;

string userId, password, user, pass;
double balance, amount;

//check user information is correct
bool loggingIn() {

    cout << "\n";
    cout << "Please enter your User ID: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    ifstream read(userId + ".txt");
    getline(read, user);
    getline(read, pass);

    if (user == userId && pass == password) {
        return true;
    } else {
        return false;
    }
}

void login() {

    bool status = loggingIn();
    if (!status) {
        cout << "\n";
        cout << "******** LOGIN FAILED! ********\n" << endl;
        start();
    } else {
        cout << "\n";
        cout << "Access Granted!\n" << endl;
        printMainMenu();
    }

}

bool checkUser() {

    cout << "\n";
    cout << "Please enter a User ID: ";
    cin >> userId;
    cout << "Please enter a password: ";
    cin >> password;

    ifstream read(userId + ".txt");
    getline(read, user);

    if (user == userId) {
        return true;
    } else {
        ofstream file;
        //creates new text file with inputted userId as the name
        file.open(userId + ".txt");
        file << userId << endl << password << endl << balance;
        file.close();
        return false;
    }
}

void createAccount() {

    bool isCreated = checkUser();

    if (isCreated) {
        cout << "\n";
        cout << "User already exists. Please try again.\n" << endl;
        start();
    } else {
        cout << "\n";
        cout << "Thank you! Your account has been created!\n" << endl;
        start();
    }

}

//finds the line in the text file for the balance
fstream& GotoLine(fstream& file, unsigned int num) {
    file.seekg(std::ios::beg);
    for(int i = 0; i < num - 1; ++i) {
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return file;
}

double getDepositBalance() {

    try {
        cout << "\n";
        cout << "Amount of deposit: $";
        cin >> amount;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            throw runtime_error("Invalid input. Please enter a number.");
        }

    }
    catch (exception &e) {
        cout << "\n";
        cout << "Error: " << e.what() << endl;
        return 0;
    }

    fstream file(userId + ".txt");

    GotoLine(file, 3);

    double line3;
    file >> line3;
    balance = line3 + amount;

    file.close();
    return balance;
}

void deposit() {

    getDepositBalance();

    ofstream file(userId + ".txt");
    if (file.is_open()) {
        file << userId << endl << password << endl << balance;
        file.close();
        cout << "\n";
        printMainMenu();
    }

}

double getWithdrawalBalance() {

    try {
        cout << "\n";
        cout << "Amount of withdrawal: $";
        cin >> amount;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            throw runtime_error("Invalid input. Please enter a number.");
        }

    }
    catch (exception &e) {
        cout << "\n";
        cout << "Error: " << e.what() << endl;
        return 0;
    }

    fstream file(userId + ".txt");

    GotoLine(file, 3);

    double line3;
    file >> line3;
    balance = line3 - amount;

    file.close();
    return balance;
}

void withdraw() {

    getWithdrawalBalance();

    ofstream file(userId + ".txt");
    if (file.is_open()) {
        file << userId << endl << password << endl << balance;
        file.close();
        cout << "\n";
        printMainMenu();
    }

}

void requestBalance() {

    fstream file(userId + ".txt");

    GotoLine(file, 3);

    double line3;
    file >> line3;

    cout << "\n";
    cout << "Your balance is $" << line3 << "\n" << endl;
    file.close();
    printMainMenu();

}