#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text;
    string upper_text="";

    while (getline(cin, text)) {

        for (char &c : text) {

            c = toupper(c);
            upper_text+=c;
        }
}
        cout << upper_text << endl;
    return 0;
}
