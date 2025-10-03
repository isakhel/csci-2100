#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Convert a sequence string into a vector of chars
vector<char> input(const string& s) {
    vector<char> result;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') result.push_back(c);
    }
    return result;
}

// Function to simulate a salon and count walked-away customers
int countWalkedAway(int beds, const vector<char>& arrivals) {
    vector<char> tanning; // array for customers tanning
    vector<char> ignore;  // array for customers who walked away
    int walkedAway = 0;

    for (char c : arrivals) {
        // Skip if customer already walked away
        bool inIgnore = false;
        for (char x : ignore) {
            if (x == c) { inIgnore = true; break; }
        }
        if (inIgnore) continue;

        // Check if customer is leaving (currently tanning)
        bool inTanning = false;
        for (size_t i = 0; i < tanning.size(); i++) {
            if (tanning[i] == c) {
                inTanning = true;
                tanning.erase(tanning.begin() + i); // free the bed
                beds++;
                break;
            }
        }

        // If customer is arriving
        if (!inTanning) {
            if (beds == 0) {
                ignore.push_back(c); // customer walked away
                walkedAway++;
            } else {
                tanning.push_back(c); // customer starts tanning
                beds--;
            }
        }
    }

    return walkedAway;
}

int main() {
    string line;

    while (true) {
        getline(cin, line);
        if (line == "0") break;

        int beds = line[0] - '0';
        vector<char> arrivals = input(line.substr(2));

        int walkedAway = countWalkedAway(beds, arrivals);

        if (walkedAway == 0)
            cout << "All customers tanned successfully." << endl;
        else
            cout << walkedAway << " customer(s) walked away." << endl;
    }

    return 0;
}
