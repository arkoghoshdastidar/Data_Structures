#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    vector<int> v1;
    for (int i = 0; i <= 10; i++)
        v1.push_back(i);
    vector<int>::iterator it1 = v1.begin();
    while (it1 != v1.end())
        cout << *(it1++) << " ";
    cout << endl;
    v1.erase(v1.begin(), v1.end());
    cout << v1.size() << endl;

    unordered_map<string, int> rank;
    rank.insert({"Arko", 1});
    rank.insert({"Rick", 2});
    unordered_map<string, int>::iterator it = rank.begin();
    while(it != rank.end())
    {
        cout << "Name : " << it->first << " Rank : " << it->second << endl;
        it++; 
    }
    it = rank.find("Ghosh");
    if(it != rank.end())
    {
        cout << it->first << " " << it->second << endl;
    }
    rank.erase(rank.begin(), rank.end());

    map<int, float> m1;
    m1.insert({2, 2.98});
    m1.insert({1, 1.01});
    m1.insert({3, 3.09});
    m1.insert({4, 5.32});
    map<int, float>::iterator it2 = m1.begin();
    while(it2 != m1.end())
    {
        cout << it2->first << " " << it2->second << endl;
        it2++;
    }
    m1[6] = 6.66;
    it2 = m1.find(6);
    if (it2 != m1.end())
    {
        cout << it2->first << " " << it2->second << endl;
    }
    m1.erase(m1.begin(), m1.end());
    return 0;
}