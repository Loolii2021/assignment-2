// File: ..........cpp
// Purpose: domino
// Author: mohammed luai
// Section: 15
// ID: 20210856
// TA: mohammed talat
// Date: 5 nov 2023
#include <iostream>
#include <vector>
using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

bool FormsDominoChain(vector<dominoT> &dominos, vector<dominoT> &chain) {
    if (dominos.empty()) {
        return true; // Successfully formed a chain.
    }

    // Try to find a matching domino and recursively form a chain.
    for (size_t i = 0; i < dominos.size(); i++) {
        if (i == 0 || dominos[i].leftDots == dominos[i - 1].rightDots) {
            // Found a matching domino, remove it from the vector and try to form a chain.
            dominoT matchedDomino = dominos[i];
            dominos.erase(dominos.begin() + i);
            chain.push_back(matchedDomino);

            if (FormsDominoChain(dominos, chain)) {
                return true; // Successfully formed a chain.
            }

            // Put the matched domino back for backtracking.
            dominos.insert(dominos.begin() + i, matchedDomino);
            chain.pop_back();
        }
    }

    return false; // No matching domino found, cannot form a chain.
}

void printDominoChain(const vector<dominoT> &chain) {
    for (size_t i = 0; i < chain.size(); i++) {
        cout << chain[i].leftDots << "|" << chain[i].rightDots;
        if (i < chain.size() - 1) {
            cout << " - ";
        }
    }
    cout << endl;
}

int main() {
    vector<dominoT> dominoSet = {
        {1, 4}, {4, 5}, {5, 7}, {7, 2}, {2, 1}
    };

    vector<dominoT> chain;
    if (FormsDominoChain(dominoSet, chain)) {
        cout << "It is possible to form a domino chain." << endl;
        cout << "Domino Chain: ";
        printDominoChain(chain);
    } else {
        cout << "It is not possible to form a domino chain." << endl;
    }

    return 0;
}
