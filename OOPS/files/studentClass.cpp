#include<iostream>
#include<cstring>
using namespace std;
// student class
class student {
    private:
        char* name;
        int rollNumber;
    public:
        student();
        student(student const &s);
        student(char* name, int rollNumber);
        void set_student(int rollNumber, char* name);
        void display(void);
        ~student();
};
student :: student(student const &s){   //copy constructor
    this->rollNumber = s.rollNumber;
    // DeepCopy
    this->name = new char[strlen(s.name)+1];
    strcpy(this->name, s.name);
    // ShallowCopy
    // this->name = s.name
} 
// class method
void student :: set_student(int rollNumber, char* name){
    this->rollNumber = rollNumber;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}
// class method
void student :: display(void){
    cout << "Roll Number : " << rollNumber << endl;
    cout << "Name : " << this->name << endl;
}
// default constructor
student :: student(void){

}
// parameterized constructor
student :: student(char* name, int rollNumber){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->rollNumber = rollNumber;
}
// class destructor
student :: ~student(){
    cout << "Destructor called!" << endl;
}

class student_2
{
private:
    int age;
    const int rollNumber;
    int const &x;
public:
    // InitializationList 
    student_2(int age, int rollNumber) : age(age), rollNumber(rollNumber), x(this->rollNumber){
    }
    void display(void){
        cout << age << endl << rollNumber << endl << x << endl;
    }
    ~student_2(){
        cout << "DestructorCalled!" << endl;
    }
};