template <class T>
class CBT 
{
private:
    T* data;
    int nextIndex;
    int capacity;
public:
    CBT()
    {
        nextIndex = 0;
        capacity = 5;
        data = new T[capacity];
    }

    void print()
    {
        for(int i=0; i<nextIndex; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    void insert(T element)
    {
        if(nextIndex == capacity)
        {
            T *tempData = new T[2*capacity];
            for(int i=0; i<nextIndex; i++)
                tempData[i] = data[i];
            delete data;
            data = tempData;
            capacity *= 2;
        }
        data[nextIndex++] = element;
    }

    void remove()
    {
        if(!nextIndex)
        {
            cout << "CBT is already empty!" << endl;
            return;
        }
        nextIndex--;
    }

    pair<T, T> child(int index)
    {
        if(2*index+1 >= nextIndex || 2*index+2 >= nextIndex)
        {
            cout << "No children present!" << endl;
            pair<bool, bool> result;
            result.first = false;
            result.second = false;
            return result;
        }
        pair<T, T> result;
        result.first = data[2*index+1];
        result.second = data[2*index+2];
        return result;
    }

    T parent(int index)
    {
        if(index >= nextIndex)
        {
            cout << "Parent not present!" << endl;
            return false;
        }
        return data[(index-1)/2];
    }
};