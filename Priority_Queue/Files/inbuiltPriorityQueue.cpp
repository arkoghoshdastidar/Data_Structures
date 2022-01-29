#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    priority_queue<int> pq;
    pq.push(12);
    pq.push(57);
    pq.push(89);
    pq.push(4);
    pq.push(51);
    pq.push(-78);

    cout << "Size of priority queue pq : " << pq.size() << endl;
    cout << "Is priority queue pq empty : " << pq.empty() << endl;
    cout << "Top of priority queue pq : " << pq.top() << endl;
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}