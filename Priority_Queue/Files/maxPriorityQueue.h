#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class PriorityQueue
{
    // Declare the data members here
    vector<int> data;

public:
    PriorityQueue()
    {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element)
    {
        // Implement the insert() function here
        data.push_back(element);
        int childIndex = data.size() - 1;
        int parentIndex = 0;

        while (childIndex > 0)
        {
            parentIndex = (childIndex - 1) / 2;
            if (data.at(parentIndex) < data.at(childIndex))
            {
                int temp = data.at(parentIndex);
                data.at(parentIndex) = data.at(childIndex);
                data.at(childIndex) = temp;
                childIndex = parentIndex;
            }
            else
                break;
        }
    }

    int getMax()
    {
        // Implement the getMax() function here
        if (isEmpty())
            return INT_MIN;
        return data.at(0);
    }

    int removeMax()
    {
        if (isEmpty())
            return INT_MIN;
        int maxValue = data.at(0);
        data.at(0) = data.at(data.size() - 1);
        data.pop_back();
        int parentIndex = 0;
        int leftChildIndex = 0;
        int rightChildIndex = 0;
        int temp = 0;
        int nextIndex = data.size();
        while (parentIndex < nextIndex)
        {
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;

            if (rightChildIndex < nextIndex)
            {
                if (data.at(leftChildIndex) > data.at(rightChildIndex))
                {
                    if (data.at(parentIndex) < data.at(leftChildIndex))
                    {
                        temp = data.at(parentIndex);
                        data.at(parentIndex) = data.at(leftChildIndex);
                        data.at(leftChildIndex) = temp;
                        parentIndex = leftChildIndex;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (data.at(parentIndex) < data.at(rightChildIndex))
                    {
                        temp = data.at(parentIndex);
                        data.at(parentIndex) = data.at(rightChildIndex);
                        data.at(rightChildIndex) = temp;
                        parentIndex = rightChildIndex;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if (rightChildIndex >= nextIndex && leftChildIndex < nextIndex)
            {
                if (data.at(parentIndex) < data.at(leftChildIndex))
                {
                    temp = data.at(parentIndex);
                    data.at(parentIndex) = data.at(leftChildIndex);
                    data.at(leftChildIndex) = temp;
                    parentIndex = leftChildIndex;
                }
                else
                {
                    break;
                }
            }
            else if(leftChildIndex >= nextIndex)
            {
                break;
            }
        }
        return maxValue;
    }

    int getSize()
    {
        // Implement the getSize() function here
        return data.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here
        return data.size() == 0;
    }

    void print(void)
    {
        for(int i=0; i<data.size(); i++)
            cout << data.at(i) << " ";
        cout << endl;
    }
};