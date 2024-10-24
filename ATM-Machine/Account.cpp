//
// Created by radel on 2024-10-24.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "menus.h"
#include "Account.h"
using namespace std;

//check user information is correct
bool loggingIn() {
    string userId, password, user, pass;

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
    string userId, password, user;

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
        file << userId << endl << password;
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