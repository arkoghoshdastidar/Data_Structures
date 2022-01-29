void upHeapify(int arr[], int size)
{
    int parentIndex = 0;
    int childIndex = size - 1;
    int temp = 0;

    while (childIndex > 0)
    {
        parentIndex = (childIndex - 1) / 2;
        if (arr[parentIndex] > arr[childIndex])
        {
            temp = arr[parentIndex];
            arr[parentIndex] = arr[childIndex];
            arr[childIndex] = temp;
            childIndex = parentIndex;
        }
        else
        {
            break;
        }
    }
}

void downHeapify(int arr[], int size)
{
    int temp = 0;
    int parentIndex = 0;
    int leftChildIndex = 0;
    int rightChildIndex = 0;
    while (parentIndex < size)
    {
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = 2 * parentIndex + 2;
        if (rightChildIndex < size)
        {
            if (arr[leftChildIndex] < arr[rightChildIndex])
            {
                if (arr[parentIndex] > arr[leftChildIndex])
                {
                    temp = arr[parentIndex];
                    arr[parentIndex] = arr[leftChildIndex];
                    arr[leftChildIndex] = temp;
                    parentIndex = leftChildIndex;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (arr[parentIndex] > arr[rightChildIndex])
                {
                    temp = arr[rightChildIndex];
                    arr[rightChildIndex] = arr[parentIndex];
                    arr[parentIndex] = temp;
                    parentIndex = rightChildIndex;
                }
                else
                {
                    break;
                }
            }
        }
        else if (rightChildIndex >= size && leftChildIndex < size)
        {
            if (arr[parentIndex] > arr[leftChildIndex])
            {
                temp = arr[parentIndex];
                arr[parentIndex] = arr[leftChildIndex];
                arr[leftChildIndex] = temp;
                parentIndex = leftChildIndex;
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
}

void heapSort(int arr[], int size)
{
    for (int i = 2; i <= size; i++)
    {
        upHeapify(arr, i);
    }
    for (int i = size - 1; i >= 1; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        downHeapify(arr, i);
    }
}