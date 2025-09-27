#include <iostream>
using namespace std;

// Recursive step calculator 
// Time complexity: O(2^n) without memoization (exponential recursion)
long long step_calculator(int n) {
    if (n == 0 || n == 1) return 1;
    return step_calculator(n - 1) + step_calculator(n - 2);
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        cout << step_calculator(n) << endl;
    }
    return 0;
}
