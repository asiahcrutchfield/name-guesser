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
    string input;
    string country;
    fstream countries;
    vector<string> countriesList;

    cout << "Ok, time to see how honest you are.\n";
    cout << "What country are you from? ";
    getline(cin >> ws, country);  // The 'ws' eats any leftover whitespace/newline
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
        getline(cin >> ws, input);  // use getline to safely capture all input

        if (input == "1" || input == "y") {
            roundOneConfidence += 2;
            valid = true;
        } else if (input == "2" || input == "n") {
            roundOneConfidence += 1;
            valid = true;
        } else {
            cout << "Choose either 'yes'[1] or 'no'[2]. Try again.\n";
        }
    }

    while (!valid) {
        cout << "Do you ever get confused for someone else? Y[1]/N[2] ";
        getline(cin >> ws, input);  // use getline to safely capture all input

        if (input == "1" || input == "y") {
            roundOneConfidence += 2;
            valid = true;
        } else if (input == "2" || input == "n") {
            roundOneConfidence += 1;
            valid = true;
        } else {
            cout << "Choose either 'yes'[1] or 'no'[2]. Try again.\n";
        }
    }

    return roundOneConfidence;
}

int roundTwo(string name) {
    int roundTwoConfidence = 0;
    string input;
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

    bool isCelebrity = false;
    for (const string &celeb : celebritiesList) {
        if (name == celeb) {
            isCelebrity = true;
            break; // no need to check further
        }
    }

    bool valid = false;
    while (!valid) {
        cout << "Is your name the same as a celebrity's? Y[1]/N[2] ";
        getline(cin >> ws, user);  // clears whitespace and gets input

        if (user == "1" || user == "y") {
            valid = true;
            if (isCelebrity) {
                roundTwoConfidence += 2;
            } else {
                roundTwoConfidence -= 5;
            }
        } else if (user == "2" || user == "n") {
            valid = true;
            if (!isCelebrity) {
                roundTwoConfidence += 1;
            } else {
                roundTwoConfidence -= 3;
            }
        } else {
            cout << "Choose either 'yes'[1] or 'no'[2]. Try again.\n";
        }
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
    srand(time(0));
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
        confidence = 60 + (rand() % 11);
        return confidence;
    } else {
        cout << "That's a strange name. I won't let you fool me.\n";
        confidence = 50 + (rand() % 11);
        return confidence;
    }
}

int judgement(int first, int second, int third) {
    int finalJudgement = 0;
    int totalJudgement = first + second + third;
    int maxJudgement = 100;

    if (totalJudgement > 100) {
        cout << "I'm surprised by your honesty. I guess humans aren't all liars.\n";
        finalJudgement += totalJudgement;
        return finalJudgement;
    } else if (totalJudgement >= 90) {
        cout << "I'm " << totalJudgement << "% certain you're telling the truth.\n";
        finalJudgement += totalJudgement;
        return finalJudgement;
    } else if (totalJudgement >= 80) {
        cout << "I'm fairly sure I figured it out.\n";
        finalJudgement += totalJudgement;
        return finalJudgement;
    } else if (totalJudgement >= 70) {
        cout << "I'm currently analyzing your answers.\n";
        finalJudgement += totalJudgement;
        return finalJudgement;
    } else if (totalJudgement >= 60) {
        cout << "You're really working my circuits.\n";
        finalJudgement += totalJudgement;
        return finalJudgement;
    } else if (totalJudgement >= 50) {
        cout << "Even I'm not sure if you're lying.\n";
        finalJudgement += totalJudgement;
        return finalJudgement;
    } else if (totalJudgement >= 40) {
        cout << "You aren't fooling anyone.\n";
        finalJudgement += totalJudgement;
        return finalJudgement;
    } else if (totalJudgement >= 30) {
        cout << "You should learn to lie better.\n";
        finalJudgement += totalJudgement;
        return finalJudgement;
    } else if (totalJudgement >= 20) {
        cout << "That can't be your real name.\n";
        finalJudgement += totalJudgement;
        return finalJudgement;
    } else if (totalJudgement >= 10) {
        cout << "I caught you in a lie!\n";
        finalJudgement += totalJudgement;
        return finalJudgement;
    } else if (totalJudgement > 0) {
        cout << "You are almost certainly lying.\n";
        finalJudgement += totalJudgement;
        return finalJudgement;
    } else if (totalJudgement <= 0) {
        cout << "You surpassed my already low expectations.\n";
        finalJudgement += totalJudgement;
        return finalJudgement;
    } 

    return finalJudgement;   
}

#endif