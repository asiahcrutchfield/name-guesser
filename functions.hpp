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

    int user;
    bool valid = false;
    while (!valid) {
        cout << "Do people often mispronounce your name? Y[1]/N[2] ";
        cin >> user;

        switch (user) {
            case 1: 
                roundOneConfidence += 1;
                valid = true;
                break;
            case 2: 
                roundOneConfidence += 2;
                valid = true;
                break;
            default:
                cout << "Choose either 'yes'[1] or 'no'[2]. Try again.\n";
                break;
        }
    }

    while (!valid) {
        cout << "Do you ever get confused for someone else? Y[1]/N[2] ";
        cin >> user;

        switch (user) {
            case 1: 
                roundOneConfidence += 2;
                valid = true;
                break;
            case 2: 
                roundOneConfidence += 1;
                valid = true;
                break;
            default:
                cout << "Choose either 'yes'[1] or 'no'[2]. Try again.\n";
                break;
        }
    }

    return roundOneConfidence;
}

int roundTwo(string name) {
    int roundTwoConfidence = 0;
    fstream celebrities;
    vector<string> celebritiesList;
    string user;

    celebrities.open("celebrities.txt", ios::in);
    if (celebrities.is_open()) {
        string list;
        while (getline(celebrities, list)) {
            celebritiesList.push_back(list);
        }
    } else {
        cout << "Error opening file";
        return -1;
    }
    celebrities.close();
    
    cout << "Is your name the same as a celebrity's? ";
    cin >> user;
    bool found = false;
    for (int i = 0; i < celebritiesList.size(); i++) {
        if (user == celebritiesList[i]) {
            found = true;
            break;
        }
    }

    if (found) {
        roundTwoConfidence += 2;
    } else {
        roundTwoConfidence -= 5;
    }

    return roundTwoConfidence;
}

string getOrdinalSuffix(int num) {
    if (num % 100 >= 11 && num % 100 <= 13) return "th";
    switch (num % 10) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}

int roundThree(string name) {
    int roundThreeConfidence = 0;
    vector<string> nameLetters;
    int randIndex = rand() % name.length();
    string user;

    for (int i = 0; i < name.size(); i++) {
        nameLetters.push_back(string(1, name[i]));  // Convert char to string
    }
    string randomLetter = nameLetters[randIndex];
    int position = randIndex + 1;

    cout << "What is the " << position << getOrdinalSuffix(position) << " letter of your name? ";
    cin >> user;

    if (user == randomLetter) {
        roundThreeConfidence += 2;
    } else {
        roundThreeConfidence -= 5;
    }

    return roundThreeConfidence;
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