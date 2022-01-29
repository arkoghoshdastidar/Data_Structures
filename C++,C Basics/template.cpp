#include<iostream>
using namespace std;
/*
    Templates are special feature for object orientation.
    Templates are used for generic programming.
    Ex:-
        1. Template Class
        2. Template Function
*/

template<class T>
class arithematic
{
    T a;
    T b;
    public:
        arithematic(){}
        arithematic(T a,T b);
        T add();
        T sub();
};

template<class T>
arithematic<T> :: arithematic(T a,T b)
{
    this->a=a;
    this->b=b;
}

template<class T>
T arithematic<T> :: add()
{
    T c = a+b;
    return(c);
}

template<class T>
T arithematic<T> :: sub()
{
    T c = a-b;
    return(c);
}

int main(void)
{
    arithematic<int> a(2,3);
    cout<<a.add()<<endl<<a.sub()<<endl;
    arithematic<double> d(2.332,5.73);
    cout<<d.add()<<endl<<d.sub()<<endl;
    return(0);
}