#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(-10);
    q.pop();

    cout << q.front() << endl;
    cout << q.back() << endl;
    return 0;
}