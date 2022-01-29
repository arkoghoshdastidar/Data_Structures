#include <vector>
#include <iostream>

class PriorityQueue
{
private:
    std::vector<int> data;

public:
    bool isEmpty(void);
    int getSize(void);
    int getMin(void);
    void insert(int);
    int remove(void);
    void print(void);
};

void PriorityQueue::print(void)
{
    for (int i = 0; i < data.size(); i++)
        std::cout << data.at(i) << " ";
    std::cout << std::endl;
}

bool PriorityQueue::isEmpty(void)
{
    return data.size() == 0;
}

int PriorityQueue::getSize(void)
{
    return data.size();
}

int PriorityQueue::getMin(void)
{
    if (isEmpty())
        return 0;
    return data.at(0);
}

void PriorityQueue::insert(int element)
{
    data.push_back(element);
    int childIndex = data.size() - 1;
    int parentIndex = 0;

    while (childIndex > 0)
    {
        parentIndex = (childIndex - 1) / 2;
        if (data.at(parentIndex) > data.at(childIndex))
        {
            int temp = data.at(childIndex);
            data.at(childIndex) = data.at(parentIndex);
            data.at(parentIndex) = temp;
            childIndex = parentIndex;
        }
        else
        {
            break;
        }
    }
}

int PriorityQueue::remove(void)
{
    if (isEmpty())
    {
        return -1;
    }

    int minValue = data.at(0);
    data.at(0) = data.at(data.size() - 1);
    data.pop_back();
    int parentIndex = 0;
    int leftChild = 0;
    int rightChild = 0;
    int nextIndex = data.size();
    int temp = 0;

    while (parentIndex < nextIndex)
    {
        leftChild = 2 * parentIndex + 1;
        rightChild = 2 * parentIndex + 2;
        if (rightChild < nextIndex)
        {
            if (data.at(rightChild) < data.at(leftChild))
            {
                if (data.at(rightChild) < data.at(parentIndex))
                {
                    temp = data.at(rightChild);
                    data.at(rightChild) = data.at(parentIndex);
                    data.at(parentIndex) = temp;
                    parentIndex = rightChild;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (data.at(leftChild) < data.at(parentIndex))
                {
                    temp = data.at(parentIndex);
                    data.at(parentIndex) = data.at(leftChild);
                    data.at(leftChild) = temp;
                    parentIndex = leftChild;
                }
                else
                {
                    break;
                }
            }
        }
        else if (rightChild >= nextIndex && leftChild < nextIndex)
        {
            if (data.at(leftChild) < data.at(parentIndex))
            {
                temp = data.at(parentIndex);
                data.at(parentIndex) = data.at(leftChild);
                data.at(leftChild) = temp;
                parentIndex = leftChild;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    return minValue;
}