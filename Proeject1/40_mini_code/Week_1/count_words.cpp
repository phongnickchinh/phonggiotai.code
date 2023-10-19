#include<bits/stdc++.h>
using namespace std;


int countWords(const string& text) {
    int wordCount = 0;
    bool inWord = false;

    for (char c : text) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (inWord) {
                inWord = false;
                wordCount++;
            }
        } else {
            inWord = true;
        }
    }

    if (inWord) {
        wordCount++;
    }

    return wordCount;
}

int main() {
    int wordCount=0;
    string input_text;
    while (getline(cin, input_text)) {
    wordCount += countWords(input_text);
    
    }cout << wordCount << endl;


    return 0;
}