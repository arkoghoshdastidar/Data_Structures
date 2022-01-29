// ADAQUEUE - Ada and Queue
// Ada the Ladybug has many things to do. She puts them into her queue. Anyway she is very indecisive, so sometime she uses the top, sometime the back and sometime she decides to reverses it.

// Input
// The first line consists of 1 ≤ Q ≤ 106, number of queries. Each of them contains one of following commands

// back - Print number from back and then erase it

// front - Print number from front and then erase it

// reverse - Reverses all elements in queue

// push_back N - Add element N to back

// toFront N - Put element N to front

// All numbers will be 0 ≤ N ≤ 100

// Output
// For each back/front query print appropriate number.

// If you would get this type of query and the queue would be empty, print "No job for Ada?" instead.

// Example Input
// 15
// toFront 93
// front
// back
// reverse
// back
// reverse
// toFront 80
// push_back 53
// push_back 50
// front
// front
// reverse
// push_back 66
// reverse
// front

#include <iostream>
#include <queue>
#include <string>
using namespace std;

void reverse_queue(queue<int> &adaqueue)
{
    if (adaqueue.size() == 0 || adaqueue.size() == 1)
        return;
    int top = adaqueue.front();
    adaqueue.pop();
    reverse_queue(adaqueue);
    adaqueue.push(top);
}

void back(queue<int> &adaqueue)
{
    int queuesize = adaqueue.size();
    queue<int> tempqueue;
    for (int i = 0; i < queuesize - 1; i++)
    {
        tempqueue.push(adaqueue.front());
        adaqueue.pop();
    }
    cout << adaqueue.front() << endl;
    adaqueue = tempqueue;
}

void addFront(queue<int> &adaqueue)
{
    int x;
    cin>>x;
    queue<int> tempqueue;
    tempqueue.push(x);
    int adaSize = adaqueue.size();
    for(int i=0; i<adaSize; i++)
    {
        tempqueue.push(adaqueue.front());
        adaqueue.pop();
    }
    adaqueue = tempqueue;
}

int main(void)
{
    int t;
    cin >> t;
    string query;
    queue<int> adaqueue;
    while (t--)
    {
        cin >> query;
        if (query == "back")
        {
            if(adaqueue.empty())
            {
                cout << "No job for Ada?" << endl;
                continue;
            }
            back(adaqueue);
        }
        else if (query == "front")
        {
            if(adaqueue.empty())
            {
                cout << "No job for Ada?" << endl;
                continue;
            }
            cout << adaqueue.front() << endl;
            adaqueue.pop();
        }
        else if (query == "reverse")
        {
            reverse_queue(adaqueue);
        }
        else if (query == "push_back")
        {
            int x;
            cin >> x;
            adaqueue.push(x);
        }
        else if (query == "toFront")
        {
            addFront(adaqueue);
        }
    }
    return 0;
}