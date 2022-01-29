template<class T>
class Node
{
    public:
        Node<T> *next;
        T data;
        Node(T element)
        {
            this->data = element;
            next = NULL;
        }
};

template<class T>
class QueueUsingLL
{
    private:
        Node<T> *start;
        Node<T> *rear;
        int size;
    public:
        QueueUsingLL()
        {
            start = NULL;
            rear = NULL;
            size = 0;
        }

        int getSize()
        {
            return size;
        }

        bool isEmpty()
        {
            return size == 0;
        }

        T front()
        {
            if(!size)
            {
                cout << "QueueEmpty!" << endl;
                return 0;
            }
            return start->data;
        }

        void enqueue(T element)
        {
            Node<T> *tempNode = new Node<T>(element);
            if(!size)
            {
                start = tempNode;
                rear = tempNode;
                size++;
                return;
            }

            rear->next = tempNode;
            rear = rear->next;
            size++;
            return;
        }

        T dequeue()
        {
            if(isEmpty())
            {
                cout << "QueueEmpty!" << endl;
                return 0;
            }

            T retVal = start->data;
            Node<T> *tempNode = start;
            start = start->next;
            size--;
            delete tempNode;
            return retVal;
        }
};