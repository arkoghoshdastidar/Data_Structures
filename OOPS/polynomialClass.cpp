#include<iostream>
using namespace std;

int min(int a, int b){
    if (a<b)
        return a;
    else
        return b;
}

int max(int a,int b){
    if (a>b)
        return a;
    else
        return b;
}

class Polynomial
{
private:
    int capacity;
public:
    int *degCoeff;
    Polynomial();
    Polynomial(Polynomial const &);
    void operator=(Polynomial const &p);
    Polynomial operator+(Polynomial const& p);
    Polynomial operator-(Polynomial const& p);
    Polynomial operator*(Polynomial const& p);
    void addCoeff(int, int);
    void print() const;
    void setCoefficient(int, int);
};

Polynomial :: Polynomial(){
    capacity = 5;
    degCoeff = new int[capacity];
    for(int i=0; i<capacity; i++)
        degCoeff[i] = 0;
}

Polynomial :: Polynomial(Polynomial const &p){
    capacity = p.capacity;
    degCoeff = new int[capacity];
    for(int i=0; i<capacity; i++)
        degCoeff[i] = p.degCoeff[i];
}

void Polynomial :: setCoefficient(int degree, int coeff){
    if(degree < capacity){
        degCoeff[degree] = coeff;
    }
    else{
        int* newDegCoeff = new int[2*capacity];
        //Updating the values of newDegCoeff.
        for(int i=0; i<2*capacity; i++){
            if(i < capacity){
                newDegCoeff[i] = degCoeff[i];
            }
            else{
                newDegCoeff[i] = 0;
            }
        }
        delete [] degCoeff;
        degCoeff = newDegCoeff;
        capacity *= 2;
        setCoefficient(degree, coeff);
    }
}

void Polynomial :: operator=(Polynomial const &p){
    capacity = p.capacity;
    degCoeff = new int[capacity];
    for(int i=0; i<capacity; i++)
        degCoeff[i] = p.degCoeff[i];
}

Polynomial Polynomial :: operator+(Polynomial const& p){
    int minimum = min(this->capacity, p.capacity);
    int maximum = max(this->capacity, p.capacity);
    Polynomial p2;
    for(int i=0; i<maximum; i++)
    {
        if(i<minimum)
            p2.setCoefficient(i, this->degCoeff[i]+p.degCoeff[i]);
        else if(this->capacity > p.capacity)
            p2.setCoefficient(i, degCoeff[i]);
        else if(this->capacity < p.capacity)
            p2.setCoefficient(i, p.degCoeff[i]);
    }
    return p2;
}

Polynomial Polynomial :: operator-(Polynomial const& p){
    int minimum = min(this->capacity, p.capacity);
    int maximum = max(this->capacity, p.capacity);
    Polynomial p2;
    for(int i=0; i<maximum; i++)
    {
        if(i<minimum)
            p2.setCoefficient(i, this->degCoeff[i]-p.degCoeff[i]);
        else if(this->capacity > p.capacity)
            p2.setCoefficient(i, degCoeff[i]);
        else if(this->capacity < p.capacity)
            p2.setCoefficient(i, -1*p.degCoeff[i]);
    }
    return p2;
}

Polynomial Polynomial :: operator*(Polynomial const& p){
    Polynomial p2;
    for(int i=0; i<this->capacity; i++)
    {
        for(int j=0; j<p.capacity; j++)
        {
            p2.addCoeff(i+j, degCoeff[i]*p.degCoeff[j]);
        }
    }
    return p2;
}

void Polynomial :: print() const{
    for(int i=0; i<capacity; i++){
        if(degCoeff[i] != 0)
            cout << degCoeff[i] << "x" << i << " ";
    }
    cout << endl;
}

void Polynomial :: addCoeff(int degree, int coeff){
    if(degree < capacity){
        degCoeff[degree] += coeff;
    }
    else{
        setCoefficient(degree, coeff);
    }
}