/********************
* Author:Saibuu V.M *
* Date: 20.11.2025  *
********************/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

const int alphabetSize = 26;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Failed to open the input file." << endl;
        return 1;
    }

    int letterFrequency[alphabetSize];
    for (int index = 0; index < alphabetSize; ++index;
        letterFrequency[index] = 0;

    int pairLetterFrequency[alphabetSize][alphabetSize];
    for (int firstLetterIndex = 0; firstLetterIndex < alphabetSize;++firstLetterIndex{
        for (int secondLetterIndex = 0; secondLetterIndex < alphabetSize; ++secondLetterIndex;
            pairLetterFrequency[firstLetterIndex][secondLetterIndex] = 0;
    }

    int previousLetterIndex = -1;
    char currentChar;
    int totalLetters = 0;

    while (inputFile >> currentChar) {
        if (isalpha(currentChar)) {
            currentChar = tolower(currentChar);
            int currentLetterIndex = currentChar - 'a';

            ++letterFrequencyrrentLetterIndex];
            ++totalLetters;

            if (previousLetterIndex != -1) {
                ++pairLetterFrequencyeviousLetterIndex][currentLetterIndex];
            }

            previousLetterIndex = currentLetterIndex;
        }
    }

    cout << "Letter Frequencies (%):\n";
    for (int index = 0; index < alphabetSize;++index) {
        if (letterFrequency[index] > 0)
            cout << (char)(index + 'a') << ": "
                 << static_cast<double>(letterFrequency[index]) / totalLetters * 100 << "%\n";
    }

    cout << "\nTwo-Letter Pair Frequencies (%):\n";
    for (int firstLetterIndex = 0; firstLetterIndex < alphabetSize; ++firstLetterIndex) {
        for (int secondLetterIndex = 0; secondLetterIndex < alphabetSize; ++secondLetterIndex) {
            if (pairLetterFrequency[firstLetterIndex][secondLetterIndex] > 0)
                cout << (char)(firstLetterIndex + 'a') << (char)(secondLetterIndex + 'a') << ": "
                     << static_cast<double>(pairLetterFrequency[firstLetterIndex][secondLetterIndex]) / totalLetters * 100 << "%\n";
        }
    }

    return 0;
}
