#include <iostream>
#include <cstring>
using namespace std;

class student
{
    int const rollNumber;
    char *name;
public:
    student(int rollNumber, char* name) : rollNumber(rollNumber){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void print(void) const{
        cout << "Name : " << name << endl << "Roll Number : " << rollNumber << endl;
    }
};

int main(void)
{
    const student s1(53, "Rick");
    s1.print();
    return(0);
}