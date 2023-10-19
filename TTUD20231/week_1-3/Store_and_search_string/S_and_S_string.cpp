#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<string> database; // Initialize a set to store the keys

    // Read the first block of keys
    while (true) {
        string key;
        cin >> key;
        if (key == "*") {
            break;
        }
        database.insert(key);
    }

    // Read the second block of actions
    while (true) {
        string cmd, k;
        cin >> cmd;
        if (cmd == "***") {
            break; // Terminate the loop when "***" is encountered
        } else if (cmd == "find") {
            cin >> k;
            // Check if the key exists in the database and print the result
            if (database.find(k) != database.end()) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else if (cmd == "insert") {
            cin >> k;
            // Attempt to insert the key into the database and print the result
            if (database.insert(k).second) {
                cout << "1" << endl; // Insertion successful
            } else {
                cout << "0" << endl; // Key already exists
            }
        }
    }

    return 0;
}
