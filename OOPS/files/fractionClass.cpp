#include <iostream>
#include <cmath>
using namespace std;

class fraction
{
    private:
        int numerator;
        int denominator;
        void simplify(void);
    public:
        fraction(int numerator, int denominator);
        void print(void);
        void add(fraction const &);
        void multiply(fraction const&);
        fraction operator+(fraction const &f2) const;
        fraction operator*(fraction const &f2) const;
        bool operator==(fraction const &f2) const;
        fraction& operator++(void);     //pre-increment operator
        fraction operator++(int);       //post-increment operator
        fraction& operator+=(fraction f2);
};

fraction :: fraction(int numerator, int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
}

void fraction :: print(void){
    cout << this->numerator << " / " << this->denominator << endl;
}

void fraction :: add(fraction const &f2){
    int deno = this->denominator*f2.denominator;
    int numo = f2.denominator*this->numerator + this->denominator*f2.numerator;
    this->numerator = numo;
    this->denominator = deno;
    simplify();
}

void fraction :: simplify(void){
    int gcd = 1;
    for(int i=1; i<=min(this->numerator, this->denominator); i++)
    {
        if(this->denominator%i == 0 && this->numerator%i == 0)
            gcd = i;
    }
    this->numerator /= gcd;
    this->denominator /= gcd;
}

void fraction :: multiply(fraction const &f2){
    this->numerator = this->numerator*f2.numerator;
    this->denominator = this->denominator*f2.denominator;
    simplify();
}

// overloading + operator for fraction class
fraction fraction :: operator + (fraction const &f2) const{
    fraction fnew(0, 0);
    fnew.numerator = this->numerator*f2.denominator + f2.numerator*this->denominator;
    fnew.denominator = this->denominator*f2.denominator;
    fnew.simplify();
    return fnew;
}

// overloading * operator for fraction class
fraction fraction :: operator * (fraction const &f2) const{
    fraction fnew(0, 0);
    fnew.numerator = this->numerator*f2.numerator;
    fnew.denominator = this->denominator*f2.denominator;
    fnew.simplify();
    return fnew;
}

// overloading == operator for fraction class
bool fraction :: operator == (fraction const &f2) const{
    return (this->numerator == f2.numerator && this->denominator == f2.denominator);
}

// overloading ++ operator for fraction class
// We return fraction with reference so that the buffer created points to the current     
// object being updated for multiple nesting
fraction& fraction :: operator ++ (void){
    this->numerator = this->numerator + this->denominator;
    this->simplify();
    return *this;
}

// overloading ++ operator for post incrementing.
// post incrementing is not allowed in post-increment operations.
fraction fraction :: operator ++ (int){
    fraction fnew(numerator, denominator);
    numerator = numerator + denominator;
    return fnew;
}

fraction& fraction :: operator += (fraction f2){
    int num = numerator*f2.denominator + f2.numerator*denominator;
    int den = denominator*f2.denominator;
    this->numerator = num;
    this->denominator = den;
    this->simplify();
    return *this;
}