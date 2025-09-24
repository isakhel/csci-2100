#include <iostream>
using namespace std;

int main() {
    // Lab partner: Tony Kamigaing
    float temperature;
    char unit;

    std::cout << "Enter temperature";
    std::cin >> temperature;
    std::cout << "Enter unit (C or F)";
    std::cin >> unit;

    // TODO: Prompt user to enter temperature (e.g., "Enter temperature value: ")
    // Read into 'temperature'

    // TODO: Prompt user to enter unit (F for Fahrenheit, C for Celsius)
    // Read into 'unit'

    // TODO: Convert temperature to the other unit and print the result
    if ( unit == 'F' || unit == 'f' ) {
        float result;
        result = (temperature - 32) *(5.0/9.0);
        cout << "Your Temperature is " << result << " degrees Celcius";
    } else if ( unit == 'C' || unit == 'c' ) {
        float result;
        result = (temperature *(9.0/5.0)) + 32;
        cout << "Your Temperature is " << result << " degrees Farenheit";
    } else {
        // Handle invalid input
        cout << "Invalid unit entered.";
    }

    return 0;
}