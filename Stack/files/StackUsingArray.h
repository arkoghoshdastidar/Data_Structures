class StackUsingArray
{
    private:
        int *data;
        int capacity;
        int nextIndex;

    public:
        StackUsingArray(int totalSize)
        {
            capacity = totalSize;
            data = new int[totalSize];
            nextIndex = 0;
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
            if(size() < capacity)
            {
                data[nextIndex++] = element;
            }
            else
            {
                cout << "Stack is full!" << endl;
            }
        }

        int pop(void)
        {
            if(isEmpty())
            {
                cout << "Stack is empty!" << endl;
                return INT_MIN;
            }
            return data[--nextIndex];
        }

        int top(void)
        {
            if(isEmpty())
            {
                cout << "Stack is empty!" << endl;
                return INT_MIN;
            }
            return data[nextIndex-1];
        }
};