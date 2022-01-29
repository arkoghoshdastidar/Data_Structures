#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> v;
    for(int i=0; i<10; i++)
    {
        cout << "CAPACITY : " << v.capacity() << endl;
        cout << "SIZE : " << v.size() << endl;
        v.push_back(i+1);
    }
    return 0;
}