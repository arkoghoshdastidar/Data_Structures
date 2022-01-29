/*
The priority_queue class present inside our "queue" header file is by default a max heap.
So, inorder to convert the priority_queue from max heap to min heap we use the following class
declaration. 
------------- ********************************************************************* ------------
priority_queue<int> pq; -----> max priority queue.
priority_queue<int, vector<int>, greater<int>> pq; ----->min priority queue.
------------- ********************************************************************* ------------
*/
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(12);
    pq.push(4);
    pq.push(48);
    pq.push(1);
    pq.push(78);
    pq.push(8);
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}