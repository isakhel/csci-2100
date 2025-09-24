#include "TravelLog.hpp"
#include <iostream>
using namespace std;

int main() {
    TravelLog log;
    log.addEntry();
    cout << "Total miles traveled: " << log.getTotalMiles() << endl;
    return 0;
}
