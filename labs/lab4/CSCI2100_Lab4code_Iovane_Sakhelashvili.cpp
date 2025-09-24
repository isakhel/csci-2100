#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int double_checker() {
    vector<int> vec;
    string line;

    cout << "Enter numbers (press Enter when done):\n";
    getline(cin, line);

    stringstream ss(line);
    int num;
    while (ss >> num) {
        vec.push_back(num);
    }

    if (!vec.empty() && vec[0] == -1) {
        return 1;
    }

    vector<int> doubled;
    for (int x : vec) {
        doubled.push_back(x * 2);
    }

    int matches = 0;
    for (int x : vec) {
        if (find(doubled.begin(), doubled.end(), x) != doubled.end()) {
            matches++;
        }
    }

    cout << "Number of Matches: " << matches << endl;
    return 0;
}

int main() {
    while (double_checker() != 1) {
    }
    return 0;
}
