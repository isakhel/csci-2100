#include "SLinkedList.h"
#include <iostream>
using namespace std;

int main() {
    cout << "You successfully made an empty list!" << endl;

    SLinkedList<int> numList;
    numList.addFront(3);

    SLinkedList<char> charList;
    charList.addFront('h');
    charList.addFront('a');
    charList.addFront('t');

    cout << "numList size = " << numList.size() << endl;
    cout << "numList: ";
    numList.print();

    cout << "charList size = " << charList.size() << endl;
    cout << "charList: ";
    charList.print();

    return 0;
}
