#include <iostream>
using namespace std;

class student{
    const int rollNumber;
    static int totalStudents;
public:
    student(int rollNumber) : rollNumber(rollNumber){
        totalStudents++;
    }
    void print(void) const{
        cout << "ROLL-NUMBER : " << rollNumber << endl;
    }
    static void displaytotal(void){
        cout << "TOTAL-STUDENTS : " << totalStudents << endl;
    }
};
int student :: totalStudents = 0;
int main(void)
{
    student s1(1), s2(2), s3(3), s4(4);
    s1.print();
    s2.print();
    s3.print();
    s4.print();
    student :: displaytotal();
    return(0);
}