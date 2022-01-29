class DyanamicStack
{
    private:
        int *data;
        int capacity;
        int nextIndex;
    public:
        DyanamicStack(void)
        {
            capacity = 5;
            nextIndex = 0;
            data = new int[capacity];
        }

        int size(void)
        {
            return nextIndex;
        }

        bool isEmpty(void)
        {
            return nextIndex == 0;
        }

        void push(int element)
        {
            if(nextIndex == capacity)
            {
                int *newData = new int[2*capacity];
                capacity = 2*capacity;

                for(int i=0; i<nextIndex; i++)
                    newData[i] = data[i];
                
                delete [] data;
                data = newData;
            }
            data[nextIndex++] = element;
        }

        int pop(void)
        {
            if(isEmpty())
            {
                cout << "Stack is already empty!" << endl;
                return INT_MIN;
            }
            return data[--nextIndex];
        }

        int top(void)
        {
            if(isEmpty())
            {
                cout << "Stack is already empty!" << endl;
                return INT_MIN;
            }
            return data[nextIndex-1];
        }
};