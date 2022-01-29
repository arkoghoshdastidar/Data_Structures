#include <iostream>

class DynamicArray
{
private:
    int *data;
    int nextIndex;
    int capacity;

public:
    DynamicArray()
    {
        nextIndex = 0;
        capacity = 5;
        data = new int[capacity];
    }
    DynamicArray(DynamicArray const &d)
    {
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
        this->data = new int[d.capacity];
        for (int i = 0; i < nextIndex; i++)
            this->data[i] = d.data[i];
    }
    void operator=(DynamicArray const &d)
    {
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
            this->data[i] = d.data[i];
    }
    void print(void) const
    {
        for (int i = 0; i < nextIndex; i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }
    int get(int i) const
    {
        if (i < nextIndex)
            return data[i];
        else
            return -1;
    }
    void add(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
                newData[i] = data[i];
            delete[] data;
            data = newData;
            data[nextIndex] = element;
            nextIndex++;
            capacity *= 2;
        }
        else
        {
            data[nextIndex++] = element;
        }
    }
    void add(int index, int element)
    {
        if(index < nextIndex)
            data[index] = element;
        else if(index == nextIndex)
            add(element);
    }
};