#include <iostream>
#include <stack>
using namespace std;

template <class T>
class STACK
{
private:
    stack<T> main_stack;
    stack<T> auxillary_stack;
    int size_of_main_stack;

public:
    STACK()
    {
        size_of_main_stack = 0;
    }
    void push_into_main_stack(T element);
    T pop_main_stack(void);
    bool is_empty_main_stack(void);
    int main_stack_size(void);
    T top_of_main_stack(void);
    T min_of_main_stack(void);
};

template <class T>
bool STACK<T>::is_empty_main_stack(void)
{
    return size_of_main_stack == 0;
}

template <class T>
int STACK<T>::main_stack_size(void)
{
    return size_of_main_stack;
}

template <class T>
T STACK<T> :: top_of_main_stack(void)
{
    if(is_empty_main_stack())
    {
        cout << "StackEmpty!" << endl;
        return 0;
    }
    return main_stack.top();
}

template <class T>
void STACK<T>::push_into_main_stack(T element)
{
    if(is_empty_main_stack())
    {
        main_stack.push(element);
        auxillary_stack.push(element);
        size_of_main_stack++;
        return;
    }
    main_stack.push(element);
    size_of_main_stack++;
    if(element <= auxillary_stack.top())
    {
        auxillary_stack.push(element);
    }
}

template <class T>
T STACK<T>::pop_main_stack(void)
{
    if(is_empty_main_stack())
    {
        cout << "StackEmpty!" << endl;
        return 0;
    }
    int answer = main_stack.top();
    main_stack.pop();
    size_of_main_stack--;
    if(answer == auxillary_stack.top())
    {
        auxillary_stack.pop();
    }
    return answer;
}

template <class T>
T STACK<T>:: min_of_main_stack(void)
{
    if(is_empty_main_stack())
    {
        cout << "StackEmpty!" << endl;
        return 0;
    }
    return auxillary_stack.top();
}

int main(void)
{
    STACK<int> S1;
    S1.push_into_main_stack(10);
    S1.push_into_main_stack(20);
    S1.push_into_main_stack(5);
    S1.push_into_main_stack(-1);
    S1.push_into_main_stack(12);
    S1.push_into_main_stack(17);
    S1.push_into_main_stack(-1);
    
    while(!S1.is_empty_main_stack())
    {
        cout << "TOP OF STACK : " << S1.top_of_main_stack() << ", MINIMUM OF STACK : " << S1.min_of_main_stack() << endl;
        S1.pop_main_stack();
    }
    return 0;
}