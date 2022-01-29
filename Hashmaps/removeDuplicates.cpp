#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicate(int *arr, int size)
{
    vector<int> output;
    unordered_map<int, bool> previous;
    for(int i=0; i<size; i++)
    {
        if(previous.count(arr[i]) > 0)
            continue;
        previous[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int main(void)
{
    int arr[10] = {1,2,3,3,2,1,4,4,5,8};
    vector<int> output = removeDuplicate(arr, 10);
    for(int i=0; i<output.size(); i++)
    {
        cout << output.at(i) << endl;
    }
    return 0;
}