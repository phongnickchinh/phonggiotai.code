#include<bits/stdc++.h>
using namespace std;


int main() {
    string input_text;
    while (getline(cin, input_text)) {
        for (char &c : input_text) c = toupper(c);
        cout << input_text << endl;
    }
    return 0;
}