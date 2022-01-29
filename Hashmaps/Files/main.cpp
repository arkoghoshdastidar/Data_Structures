#include <iostream>
#include "hashmap.h"

int main(void)
{
    hashmap<int> h1;
    h1.insert("Arko", 1);
    cout << "loadFactor : " << h1.loadFactor() << endl;
    h1.insert("Arko", 2);
    cout << "loadFactor : " << h1.loadFactor() << endl;
    h1.insert("Arko2", 3);
    cout << "loadFactor : " << h1.loadFactor() << endl;
    h1.insert("Arko3", -5);
    cout << "loadFactor : " << h1.loadFactor() << endl;
    h1.insert("Arko4", 7);
    cout << "loadFactor : " << h1.loadFactor() << endl;
    h1.insert("Arko5", 9);
    cout << "loadFactor : " << h1.loadFactor() << endl;
    h1.insert("Arko6", 11);
    cout << "loadFactor : " << h1.loadFactor() << endl;
    h1.insert("Arko7", 2);
    cout << "loadFactor : " << h1.loadFactor() << endl;
    return 0;
}