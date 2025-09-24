#include "TravelLog.hpp"
#include <iostream>
using namespace std;

TravelLog::TravelLog() : prevTime(0), totalMiles(0) {}

void TravelLog::addEntry() {
    while (true) {
        int speed, clockTime;
        cout << "Enter speed and time (or anything else to quit): ";
        cin >> speed >> clockTime;

        if (!(speed>0)) 
        break;

        int deltaTime = clockTime - prevTime;
        totalMiles += speed * deltaTime;
        prevTime = clockTime;
    }
}

int TravelLog::getTotalMiles() const {
    return totalMiles;
}
