#include <iostream>
using namespace std;

// Compute n choose k without factorials because using factorials causes overflow at 30
// steps
// Time complexity: O(k)
unsigned long long binomial(int n, int k) {
    if (k > n - k) k = n - k; // symmetry
    unsigned long long result = 1;
    for (int i = 1; i <= k; i++) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

// Step calculator using binomial coefficients
// Time complexity: O(n^2)
unsigned long long step_calculator(int number_of_steps) {
    unsigned long long paths = 0;
    for (int i = 0; i <= number_of_steps / 2; i++) {
        paths += binomial(number_of_steps - i, i);
    }
    return paths;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        cout << step_calculator(n) << endl;
    }
    return 0;
}

