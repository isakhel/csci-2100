#include <iostream>
#include <algorithm> // for swap
#include <cmath>     // for floor

using namespace std;

int calculateMaxPercentage(int A, int B, int C, int D) {
    int x;
    int y;
    if (A > B) {
        swap(A, B);
    }
    if (C > D) {
        swap(C, D);
    }
    if (D * A / B > C) {
        x = C;
        y = (C * B) / A;
    }
    else {
        x = (D * A) / B;
        y = D;
    }
    
    double ratio = static_cast<double>(x) / (A);
    int max_percentage = static_cast<int>(floor(ratio * 100));
    if (max_percentage > 100) {
        max_percentage = 100;
    }
    return max_percentage;
}

int main() {
    int A, B, C, D;
    int line_num = 1;

    while (line_num < 1000) {
        cin >> A >> B >> C >> D;

    
        if (A == 0 && B == 0 && C == 0 && D == 0) {
            break;
        }

        int percentage = calculateMaxPercentage(A, B, C, D);
        cout << percentage << "%" << endl;

        line_num++;
    }

    return 0;
}