template <class T>
class Node
{
    public:
        Node<T> *next;
        T data;
        Node(T element)
        {
            next = NULL;
            data = element;
        }
};

template <class T>
class GenericStackUsingLL
{
    private:
        Node<T> *head;
        int size;
    public:
        GenericStackUsingLL(){
            head = NULL;
            size = 0;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return head == NULL;
        }

        void push(T element){
            Node<T> *tempNode = new Node<T>(element);
            tempNode->next = head;
            head = tempNode;
            size++;
        }

        T top(){
            if(isEmpty()){
                cout << "Stack is empty!" << endl;
                return 0;
            }
            return head->data;
        }

        T pop(){
            if(isEmpty()){
                cout << "Stack is empty!" << endl;
                return 0;
            }
            T retValue = head->data;
            Node<T> *headNext = head->next;
            delete head;
            head = headNext;
            size--;
            return retValue;
        }
};