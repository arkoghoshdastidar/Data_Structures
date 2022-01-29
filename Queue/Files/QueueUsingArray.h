template <class T>
class QueueUsingArray
{
    private:
        T* data;
        int frontIndex;
        int nextIndex;
        int size;
        int capacity;
    public:
        QueueUsingArray(int capacity)
        {
            this->capacity = capacity;
            this->size = 0;
            this->nextIndex = 0;
            this->frontIndex = -1;
            data = new T[this->capacity];
        }

        int getSize()
        {
            return size;
        }

        bool isEmpty()
        {
            return getSize() == 0;
        }

        void enqueue(T element)
        {
            if(!size)
            {
                nextIndex = 0;
                frontIndex = -1;
                data[nextIndex] = element;
                nextIndex++;
                frontIndex++;
            }
            else if(size == capacity)
            {
                T* newData = new T[2*capacity];
                nextIndex = 0;
                for(int i=0; i<capacity; i++)
                {
                    frontIndex = frontIndex % capacity;
                    newData[nextIndex++] = data[frontIndex++];
                }
                capacity = 2*capacity;
                frontIndex = 0;
                newData[nextIndex++] = element;
                delete [] data;
                data = newData;
            }
            else
            {
                nextIndex = nextIndex % capacity;
                data[nextIndex] = element;
                nextIndex++;
            }
            size++;
            return;
        }

        T front()
        {
            if(!size)
            {
                cout << "QueueEmpty!" << endl;
                return 0;
            }
            return data[frontIndex];
        }

        T dequeue(void)
        {
           if(!size)
           {
               cout << "QueueEmpty!" << endl;
               return 0;
           } 
           
           frontIndex = frontIndex % capacity;
           T retValue = data[frontIndex];
           frontIndex++;
           size--;
           return retValue;
        }
};