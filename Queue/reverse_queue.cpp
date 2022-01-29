#include <iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &input)
{
    int inputsize = input.size();
    int *tempArray = new int[inputsize];
    for(int i=0; i<inputsize; i++)
    {
        tempArray[i] = input.front();
        input.pop();
    }
    for(int i=inputsize-1; i>=0; i--)
    {
        input.push(tempArray[i]);
    }
    return;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}