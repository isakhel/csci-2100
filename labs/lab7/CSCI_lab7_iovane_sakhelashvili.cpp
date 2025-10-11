#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    int setNum = 1;
    bool firstSet = true;

    while (cin >> n && n != 0) {
        if (!firstSet) cout << endl; // blank line before next set
        firstSet = false;

        cout << "SET " << setNum++ << endl;

        vector<string> names(n);
        for (int i = 0; i < n; ++i)
            cin >> names[i];

        stack<string> s;

        // Push the second half (including middle if odd)
        for (int i = n - 1; i >= n / 2; --i)
            s.push(names[i]);

        // Print first half (shorter names)
        for (int i = 0; i < n / 2; ++i)
            cout << names[i] << endl;

        // Print remaining names from stack (longer ones reversed)
        while (!s.empty()) {
            cout << s.top() << endl;
            s.pop();
        }
    }

    return 0;
}
