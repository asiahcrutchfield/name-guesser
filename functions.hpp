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


void initialConfidence(string name) {
    srand(time(0));
    int confidence = rand() % 101;
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
        return;
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
    } else {
        cout << "That's a strange name. I won't let you fool me.\n";
    }
};