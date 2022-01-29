// Running Median
// Send Feedback
// You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
// Print only the integer part of the median.
// Input Format :
// The first line of input contains an integer 'N', denoting the number of integers in the stream.

// The second line of input contains 'N' integers separated by a single space.
// Output Format :
// Print the running median for every integer added to the running list in one line (space-separated).
// Input Constraints
// 0 <= N <= 10 ^ 5
// 1 <= ARR[i] <= 10 ^ 5

// Time Limit: 1 sec
// Sample Input 1 :
// 6
// 6 2 1 3 7 5
// Sample Output 1 :
// 6 4 2 2 3 4
// Explanation of Sample Output 1 :
// S = {6}, median = 6
// S = {6, 2} -> {2, 6}, median = 4
// S = {6, 2, 1} -> {1, 2, 6}, median = 2
// S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
// S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
// S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
// Sample Input 2 :
// 5
// 5 4 3 2 1
// Sample Output 2 :
// 5 4 4 3 3

#include <iostream>
using namespace std;

#include <queue>
void findMedian(int *arr, int size)
{
    int maxHeapSize = 0;
    int minHeapSize = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            maxHeapSize++;
            maxHeap.push(arr[i]);
            cout << maxHeap.top() << " ";
            continue;
        }

        if (arr[i] <= maxHeap.top())
        {
            maxHeap.push(arr[i]);
            maxHeapSize++;

            if (maxHeapSize - minHeapSize > 1)
            {
                minHeap.push(maxHeap.top());
                minHeapSize++;
                maxHeap.pop();
                maxHeapSize--;
            }
        }
        else
        {
            minHeap.push(arr[i]);
            minHeapSize++;

            if (minHeapSize - maxHeapSize > 1)
            {
                maxHeap.push(minHeap.top());
                maxHeapSize++;
                minHeap.pop();
                minHeapSize--;
            }
        }

        if ((i + 1) % 2 == 0)
        {
            cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
        }
        else
        {
            if (maxHeapSize > minHeapSize)
                cout << maxHeap.top() << " ";
            else
                cout << minHeap.top() << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    findMedian(arr, n);

    delete[] arr;
}
