#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

void roundOne(string name) {
    string country;

    cout << "What country are you from? ";
    cin >> country;
}

int initialConfidence(string name) {
    int confidence;
    fstream commonNames;
    vector<string> commonNamesList;

    commonNames.open("common_names.txt", ios::in); // reads from common_names.txt
    if (commonNames.is_open()) {
        string list;
        while (getline(commonNames, list)) {
            commonNamesList.push_back(list);
        }
    } else {
        cout << "Error opening file";
        return -1;
    }

    bool found = false;
    for (int i = 0; i < commonNamesList.size(); i++) {
        if (name == commonNamesList[i]) {
            found = true;
            break;
        } 
    }

    if (found) {
        cout << "That name seems to be pretty common, so you might be telling the truth.\n";
        confidence = 80 + (rand() % 21);
        cout << "Random confidence (should be 80–100): " << confidence << endl;
        return confidence;
    } else {
        cout << "That's a strange name. I won't let you fool me.\n";
        confidence = 30 + (rand() % 31);
        return confidence;
    }
}

#endif