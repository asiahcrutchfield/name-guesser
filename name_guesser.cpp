#include <iostream>
#include "functions.hpp"
#include "variables.hpp"
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <string>
using namespace std;

int main() {
    cout << "Hello, Welcome to the \"Name Game\"! You give me your name and I try to determine if you're lying.\n";
    cout << "If I win, I get to gloat about how superior I am. If you win... I guess I'll give you validation. You humans like that right?\n";
    cout << "Anyway, let's stop wasting time and see if I can catch you in a lie!\n";
    cout << "What is your name? ";
    cin >> initialName; //user's name
    cout << "Ok, \"" << initialName << "\". Let's see if you're telling the truth.\n";
    cout << endl;

    initialConfidence();

    return 0;
}