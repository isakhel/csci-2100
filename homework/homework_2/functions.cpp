#include <iostream>
#include <array>
#include <string>
#include <limits>
using namespace std;

int clamp_to_range(int x,int lo, int hi) {
    
    if (x < lo) {
        return lo;
    } else if (x > hi) {
        return hi;
    } else {
        return x;
    }
}

int count_vowels(string input) {
    int vowelcount = 0;
    
    for(int i=0; i<input.size(); i++){
        if (input[i] == 'A' || input[i] == 'a' ||
            input[i] == 'E' || input[i] == 'e' ||
            input[i] == 'I' || input[i] == 'i' ||
            input[i] == 'O' || input[i] == 'o' ||
            input[i] == 'U' || input[i] == 'u') {

            vowelcount++; }
    }

    return vowelcount;
}

string replace_first(string s, string from, string to) {
    int pos = s.find(from);   
    if (pos != -1) {          
        s = s.substr(0, pos) + to + s.substr(pos + from.length());
    }
    return s;
}



int sum_array(int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return sum;
}

double mean_array(int arr[], int length) {   
    double sum = 0.0;                          
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    double mean = sum / length;    
    return mean;          
}

int main() {
    cout << "Enter your full name: ";
    string name;
    getline(cin, name);
    cout << "Hello, " << name << "!\n";

    int x, lo, hi;
    cout << "Enter x lo hi: ";
    cin >> x >> lo >> hi;
    cout << "Clamp result = " << clamp_to_range(x, lo, hi)<<"\n";

    string word, line;
    cout << "Enter a single word: ";
    cin >> word;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear rest of line
    cout << "Enter a whole line: ";
    getline(cin, line);
    cout << "Vowels(word) = " << count_vowels(word)
         << ", Vowels(line) = " << count_vowels(line) << "\n";
    

    string from, to;
    cout << "Enter from and to strings: ";
    cin >> from >> to;
    string sentence = "this is a test: test cases matter";
    cout << "Before: " << sentence << "\n";
    cout << "After : " << replace_first(sentence, from, to) << "\n";
    int nums1[5] = {1,2,3,4,5};
    int nums2[5] = {10,10,10,10,10};
    cout << "sum(nums1) = " << sum_array(nums1,5)
         << ", mean(nums1) = " << mean_array(nums1,5) << "\n";
    cout << "sum(nums2) = " << sum_array(nums2,5)
         << ", mean(nums2) = " << mean_array(nums2,5) << "\n";

    return 0;
}
