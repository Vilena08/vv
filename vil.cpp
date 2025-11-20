/********************
* Author:Saibuu V.M *
* Date: 20.11.2025  *
********************/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

constexpr int ALPHABET_SIZE = 26;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening the input file." << endl;
        return 1;
    }

    int letterFrequency[ALPHABET_SIZE]{};
    int pairLetterFrequency[ALPHABET_SIZE][ALPHABET_SIZE]{};

    int totalLetters = 0;
    int previousLetterIndex = -1;
    char currentChar;

    while (inputFile.get(currentChar)) {
        if (isalpha(currentChar)) {
            currentChar = tolower(currentChar);
            int currentLetterIndex = currentChar - 'a';
            ++letterFrequency[currentLetterIndex];
            ++totalLetters;

            if (previousLetterIndex != -1) {
                ++pairLetterFrequency[previousLetterIndex][currentLetterIndex];
            }

            previousLetterIndex = currentLetterIndex;
        }
    }

    double frequencySum = 0.0;
    cout << "Letter frequencies (%):\n";
    for (int index = 0; index < ALPHABET_SIZE; index++) {
        if (letterFrequency[index] > 0) {
            double freq = static_cast<double>(letterFrequency[index]) / totalLetters * 100.0;
            cout << (char)(index + 'a') << ": " << fixed << setprecision(2) << freq << "%\n";
            frequencySum += freq;
        }
    }
    cout << "Total letters processed: " << totalLetters << ", Total sum of frequencies: " << fixed << setprecision(2) << frequencySum << "%\n";

    cout << "\nPair Letter frequencies (%):\n";
    for (int firstLetterIndex = 0; firstLetterIndex < ALPHABET_SIZE; firstLetterIndex++) {
        for (int secondLetterIndex = 0; secondLetterIndex < ALPHABET_SIZE; secondLetterIndex++) {
            if (pairLetterFrequency[firstLetterIndex][secondLetterIndex] > 0) {
                double freq = static_cast<double>(pairLetterFrequency[firstLetterIndex][secondLetterIndex]) / totalLetters * 100.0;
                cout << (char)(firstLetterIndex + 'a') << (char)(secondLetterIndex + 'a') << ": " << fixed << setprecision(2) << freq << "%\n";
            }
        }
    }

    return 0;
}
