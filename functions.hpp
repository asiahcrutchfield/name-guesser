#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

int roundOne(string name) {
    int roundOneConfidence = 0;
    string country;
    fstream countries;
    vector<string> countriesList;

    cout << "Ok, time to see how honest you are.\n";
    cout << "What country are you from? ";
    cin >> country;
    cout << endl;
    countries.open("countries.txt", ios::in); // reads from countries.txt
    if (countries.is_open()) {
        string list;
        while (getline(countries, list)) {
            countriesList.push_back(list);
        } 
    } else {
        cout << "Error opening file";
        return -1;
    }
    countries.close();

    bool found = false;
    for (int i = 0; i < countriesList.size(); i++) {
        if (country == countriesList[i]) {
            found = true;
            break;
        }
    }

    if (found) {
        roundOneConfidence += 2;
    } else {
        roundOneConfidence -= 5;
    }

    return roundOneConfidence;
}

void roundTwo(string name) {

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
    commonNames.close();

    if (found) {
        cout << "That name seems to be pretty common, so you might be telling the truth.\n";
        confidence = 80 + (rand() % 21);
        return confidence;
    } else {
        cout << "That's a strange name. I won't let you fool me.\n";
        confidence = 30 + (rand() % 31);
        return confidence;
    }
}

void judgement(int first, int second, int third) {
    int finalJudgement = 0;

    
}

#endif