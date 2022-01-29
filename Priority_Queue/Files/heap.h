// Implementation of min_heap
template <class T>
class min_heap
{
private:
    T *data;
    int nextIndex;
    int capacity;
    void upHeapify();
    void downHeapify();

public:
    min_heap();
    void insert(T element);
    void remove(void);
    T getMin(void);
    void print(void);
};

template <class T>
void min_heap<T>::print(void)
{
    for (int i = 0; i < nextIndex; i++)
        cout << data[i] << " ";
    cout << endl;
}

template <class T>
min_heap<T>::min_heap()
{
    nextIndex = 0;
    capacity = 5;
    data = new T[capacity];
}

template <class T>
T min_heap<T>::getMin(void)
{
    if (nextIndex == 0)
    {
        cout << "Heap is empty!" << endl;
        return false;
    }
    return data[0];
}

template <class T>
void min_heap<T>::insert(T element)
{
    if (nextIndex == capacity)
    {
        capacity = 2 * capacity;
        T *tempData = new T[capacity];
        for (int i = 0; i < nextIndex; i++)
            tempData[i] = data[i];
        delete data;
        data = tempData;
    }
    data[nextIndex] = element;
    nextIndex++;
    upHeapify();
}

template <class T>
void min_heap<T>::remove()
{
    if (nextIndex == 0)
    {
        cout << "Heap is empty!" << endl;
    }
    data[0] = data[nextIndex - 1];
    nextIndex--;
    downHeapify();
}

template <class T>
void min_heap<T>::upHeapify(void)
{
    int childIndex = nextIndex - 1;
    int parentIndex = 0;

    while (childIndex > 0)
    {
        parentIndex = (childIndex - 1) / 2;
        if (data[parentIndex] > data[childIndex])
        {
            int temp = data[parentIndex];
            data[parentIndex] = data[childIndex];
            data[childIndex] = temp;
            childIndex = parentIndex;
        }
        else
        {
            break;
        }
    }
}

template <class T>
void min_heap<T>::downHeapify(void)
{
    int parentIndex = 0;
    int leftChild = 0;
    int rightChild = 0;
    while (parentIndex < nextIndex)
    {
        int temp = 0;
        leftChild = 2 * parentIndex + 1;
        rightChild = 2 * parentIndex + 2;
        if (rightChild < nextIndex)
        {
            if (data[leftChild] < data[rightChild])
            {
                if (data[parentIndex] > data[leftChild])
                {
                    temp = data[parentIndex];
                    data[parentIndex] = data[leftChild];
                    data[leftChild] = temp;
                    parentIndex = leftChild;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (data[parentIndex] > data[rightChild])
                {
                    temp = data[parentIndex];
                    data[parentIndex] = data[rightChild];
                    data[rightChild] = temp;
                    parentIndex = rightChild;
                }
                else
                {
                    break;
                }
            }
        }
        else if (rightChild >= nextIndex && leftChild < nextIndex)
        {
            if (data[leftChild] < data[parentIndex])
            {
                temp = data[parentIndex];
                data[parentIndex] = data[leftChild];
                data[leftChild] = temp;
                parentIndex = leftChild;
            }
            else
            {
                break;
            }
        }
        else if (leftChild > nextIndex)
        {
            break;
        }
    }
}