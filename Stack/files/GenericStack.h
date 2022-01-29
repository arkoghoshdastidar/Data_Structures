template <class T>
class GenericStack
{
    private:
        T *data;
        int nextIndex;
        int capacity;
    public:
        GenericStack(){
            nextIndex = 0;
            capacity = 5;
            data = new T[capacity];
        } 

        int size(){
            return nextIndex;
        }

        bool isEmpty(){
            return nextIndex == 0;
        }

        void push(T element){
            if(nextIndex == capacity){
                T *newData = new T[2*capacity];
                capacity = 2*capacity;

                for(int i=0; i<nextIndex; i++)
                    newData[i] = data[i];
                
                delete []data;
                data = newData;
            }

            data[nextIndex++] = element;
            return;
        }

        T top(){
            if(isEmpty()){
                cout << "Stack is already empty!" << endl;
                return 0;
            }
            return data[nextIndex-1];
        }

        T pop(){
            if(isEmpty()){
                cout << "Stack is already empty!" << endl;
            }
            return data[--nextIndex];
        }
};