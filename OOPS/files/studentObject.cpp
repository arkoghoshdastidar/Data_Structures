#include <iostream>
#include "studentClass.cpp"
using namespace std;

int main(void)
{
    student s1;   // s1 created with default constructor.
    s1.set_student(53, "Arko");
    s1.display();

    student s2("KKBoss", 100);  // s2 created with parameterized constructor.
    s2.display();

    student s3(s1);     // s3 object created with copy constructor. 
    s3.display();

    student *s4 = new student("Acrobat", 120);  // student type pointer created.
    s4->display();

    student s5;
    s5 = *s4;   // assignment operator used to copy the data of *s4 into s5.
    s5.display();

    student s6 = s1;    // object s6 created with copy constructor.
    s6.display();

    delete s4;
    return 0;
}