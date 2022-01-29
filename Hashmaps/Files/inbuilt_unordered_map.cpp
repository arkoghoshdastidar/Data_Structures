#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// unordered_map has complexity of O(1) for insert, search and delete functions. It uses hashtables.
// map has time complexity of O(logn) for insert, search and delete functions. It uses linked list to implement hashmaps.

int main(void)
{
    unordered_map<string ,int> newMap;
    pair<string, int> tempVariable;
    tempVariable.first = "arko";
    tempVariable.second = 1;
    newMap.insert(tempVariable);
    newMap["ghosh"] = 2;
    newMap["dastidar"] = 3;
    // If a key is not present in the unordered map and we try to access it using at() method then the compiler throws an exception whereas if we try to access the key-value using [] operator then the compiler inserts the key inside the map and set it's value to 0.

    if(newMap.empty())
    {
        cout << "newMap is empty!" << endl;
    }
    else
    {
        cout << "Size : " << newMap.size() << endl;
        cout << "Count of \"arko\" in newMap : " << newMap.count("arko") << endl;
        cout << newMap.at("arko") << endl;
        cout << newMap.at("ghosh") << endl;
        cout << newMap.at("dastidar") << endl;
    }

    newMap.erase("ghosh");
    
    if(!newMap.count("ghosh"))
    {
        cout << "\"ghosh\" has been deleted form the unordered map." << endl;
    }

    newMap.clear();
    return 0;
}