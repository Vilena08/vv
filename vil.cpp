/********************
* Author:Saibuu V.M *
*                   *
* Date: 06.11.2025  *
*                   *
********************/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Failed to open the input file." << endl;
        return 1;
    }

    int letterFrequency[26];
    for (int index = 0; index < 26; index++) {
        letterFrequency[index] = 0;
    }

    int pairLetterFrequency[26][26];
    for (int firstLetterIndex = 0; firstLetterIndex < 26; firstLetterIndex++) {
        for (int secondLetterIndex = 0; secondLetterIndex < 26; secondLetterIndex++) {
            pairLetterFrequency[firstLetterIndex][secondLetterIndex] = 0;
        }
    }

    int previousLetterIndex = -1;
    char currentChar;

    while (inputFile >> currentChar) {
        if (isalpha(currentChar)) {
            currentChar = tolower(currentChar);
            int currentLetterIndex = currentChar - 'a';

            letterFrequency[currentLetterIndex]++;

            if (previousLetterIndex != -1) {
                pairLetterFrequency[previousLetterIndex][currentLetterIndex]++;
            }

            previousLetterIndex = currentLetterIndex;
        }
    }

    cout << "Letter Frequencies:\n";
    for (int index = 0; index < 26; index++) {
        if (letterFrequency[index] > 0) {
            cout << (char)(index + 'a') << " = " << letterFrequency[index] << endl;
        }
    }

    cout << "\nTwo-Letter Pair Frequencies:\n";
    for (int firstLetterIndex = 0; firstLetterIndex < 26; firstLetterIndex++) {
        for (int secondLetterIndex = 0; secondLetterIndex < 26; secondLetterIndex++) {
            if (pairLetterFrequency[firstLetterIndex][secondLetterIndex] > 0) {
                cout << (char)(firstLetterIndex + 'a') << (char)(secondLetterIndex + 'a') << " = " << pairLetterFrequency[firstLetterIndex][secondLetterIndex] << endl;
            }
        }
    }

    return 0;
}