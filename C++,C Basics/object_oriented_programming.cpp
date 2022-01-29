#include<iostream>
using namespace std;
/*
    OOP is special feature of C++.It introduces the concepts of classes,construtor,destructor,
    inheritance,template,friend classes,friend functions,virtual classes,virtual functions and
    abstract base classes.
    It is an upgrade of C-language.The main feature of OOP is data hiding.
*/
class rectangle
{
    private:
        int length;
        int breadth;
    public:
        rectangle(){}
        rectangle(int,int);
        void setLength(int);
        void setBreadth(int);
        int getLength(void);
        int getBreadth(void);
        int getArea(void);
        int getPerimeter(void);
        ~rectangle(){}
};

rectangle::rectangle(int l,int b)
{
    length=l;
    breadth=b;
}

inline void rectangle :: setLength(int l)
{
    length=l;
}

inline void rectangle :: setBreadth(int b)
{
    breadth=b;
}

inline int rectangle :: getLength(void)
{
    return(length);
}

inline int rectangle :: getBreadth(void)
{
    return(breadth);
}

inline int rectangle :: getArea(void)
{
    return(length*breadth);
}

inline int rectangle :: getPerimeter(void)
{
    return(2*(length+breadth));
}

int main(void)
{
    rectangle r(20,32);
    cout<<"Area : "<<r.getArea()<<endl;
    cout<<"Perimeter : "<<r.getPerimeter()<<endl;
    return(0);
}