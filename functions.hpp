#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

void initialConfidence() {
    srand(time(0));
    int confidence = rand() % 101;

    if (confidence >= 100) {
        cout << "Somehow, my sensors are indicating that there is a " << confidence << "% chance that you're telling the truth. I must be malfunctioning because no human can be that honest.\n";
    } else if (confidence >= 90) {
        cout << "There's a " << confidence << "% chance that you're telling the truth. You must be the most honest person alive! Or are you just *really* good at lying? 🤔\n";
    } else if (confidence >= 80) {
        cout << "There's a " << confidence << "% chance that you're telling the truth. But let's test that.\n";
    } else if (confidence >= 70) {
        cout << "There's a " << confidence << "% chance that you're telling the truth. You're probably telling the truth... but I'll be keeping an eye on you. 👀\n";
    } else if (confidence >= 60) {
        cout << "There's a " << confidence << "% chance that you're telling the truth. I'm going to get to the bottom of this.\n";
    } else if (confidence >= 50) {
        cout << "There's a " << confidence << "% chance that you're telling the truth. This could go either way. I wouldn't trust you with my bank password. 😂\n";
    } else if (confidence >= 40) {
        cout << "There's a " << confidence << "% chance that you're telling the truth. Let's see if you can outsmart me.\n";
    } else if (confidence >= 30) {
        cout << "There's a " << confidence << "% chance that you're telling the truth. Suspicious... very suspicious. Are you a spy? 🕵️‍♂️\n";
    } else if (confidence >= 20) {
        cout << "There's a " << confidence << "% chance that you're telling the truth. It's always funny when humans think they're smarter than us.\n";
    } else if (confidence >= 10) {
        cout << "There's a " << confidence << "% chance that you're telling the truth. You are definitely not beating any stereotypes computers have about humans.\n";
    } else {
        cout << "There's a " << confidence << "% chance that you're telling the truth. You're definitely lying! Either that or my sensors are broken. But I trust my sensors more than I trust you. 😈\n";
    };

};