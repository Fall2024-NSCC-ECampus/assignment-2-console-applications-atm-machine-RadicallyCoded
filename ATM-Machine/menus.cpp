//
// Created by radel on 2024-10-24.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "menus.h"
#include "Account.h"
using namespace std;

// global variables
char menuInput;

void printIntroMenu() {

    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
    cin >> menuInput;
}

void printMainMenu() {

    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
    cout << "> " << endl;
    //cin >> menuInput;

    cout << "This will be functional in Part B of the assignment!\n";
}

void start() {

    cout << "Please select an option from the menu below:" << endl;
    // call the intro menu function
    printIntroMenu();

    if (menuInput == 'L' || menuInput == 'l') {
        login();
    } else if (menuInput == 'C' || menuInput == 'c') {
        createAccount();
    } else if (menuInput == 'Q' || menuInput == 'q') {
        quit();
    } else {
        cout << "\n";
        cout << "Error : Invalid input. Please try again.\n" << endl;
        start();
    }

}

void quit() {

    cout << "\n";
    cout << "Thank you for using Rebecca's ATM Machine!\n";

    exit(0);
}
