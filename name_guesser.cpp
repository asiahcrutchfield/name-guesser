#include <iostream>
#include "functions.hpp"
#include "functions.hpp"
#include "variables.hpp"
#include <string>
using namespace std;

int main() {
    cout << "Hello, Welcome to the \"Name Game\"! You give me your name and I try to determine if you're lying.\n";
    cout << "If I win, I get to gloat about how superior I am. If you win... I guess I'll give you validation. You humans like that right?\n";
    cout << "Anyway, let's stop wasting time and see if I can catch you in a lie!\n";
    cout << "What is your name? ";
    cin >> name; //user's name
    cout << endl;
    cout << "Ok, \"" << name << "\". Let's see if you're telling the truth.";
    cout << endl; 

}