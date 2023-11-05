// File: ..........cpp
// Purpose: program that reads in a sentence of up to 100 characters
// Author: mohammed luai
// Section: 15
// ID: 20210856
// TA: mohammed talat
// Date: 5 nov 2023
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string correctSentence(string input_sentence) {
    // Remove leading and trailing whitespace
    size_t start = input_sentence.find_first_not_of(" \t\n\r");
    size_t end = input_sentence.find_last_not_of(" \t\n\r");

    if (start == string::npos) {
        // The input is empty or contains only whitespace
        return "";
    }

    string trimmed = input_sentence.substr(start, end - start + 1);

    // Replace multiple spaces with a single space
    string corrected_sentence;
    bool prevSpace = false;

    for (char c : trimmed) {
        if (isspace(c)) {
            if (!prevSpace) {
                corrected_sentence += ' ';
                prevSpace = true;
            }
        }
        else {
            corrected_sentence += c;
            prevSpace = false;
        }
    }

    // Ensure the sentence starts with an uppercase letter
    corrected_sentence[0] = toupper(corrected_sentence[0]);

    // Ensure there are no uppercase letters in the middle of the sentence
    for (size_t i = 1; i < corrected_sentence.length(); i++) {
        if (isalpha(corrected_sentence[i]) && isupper(corrected_sentence[i])) {
            corrected_sentence[i] = tolower(corrected_sentence[i]);
        }
    }

    // Ensure the sentence ends with a period
    if (corrected_sentence.back() != '.') {
        corrected_sentence += '.';
    }

    return corrected_sentence;
}

int main() {
    string input_sentence;
    cout << "Enter a sentence (up to 100 characters) ending with a period: ";
    getline(cin, input_sentence);

    if (input_sentence.length() <= 100 && input_sentence.back() == '.') {
        string corrected_output = correctSentence(input_sentence);
        cout << "Corrected Sentence:" << endl << corrected_output << endl;
    }
    else {
        cout << "Input does not meet the requirements." << endl;
    }

    return 0;
}
