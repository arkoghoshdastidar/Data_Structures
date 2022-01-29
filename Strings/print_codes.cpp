// Print all Codes - String
// Send Feedback
// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. Just print them in different lines.
// Input format :
// A numeric string S
// Output Format :
// All possible codes in different lines
// Constraints :
// 1 <= Length of String S <= 10
// Sample Input:
// 1123
// Sample Output:
// aabc
// kbc
// alc
// aaw
// kw

#include <iostream>
#include <string>
using namespace std;

string alpha_numeric = " abcdefghijklmnopqrstuvwxyz";

int INT(char x)
{
    int t1 = x;
    int t2 = '0';
    return t1-t2;
}

void printAllPossibleCodes(string input, string output)
{
    if(input.size() == 0){
        cout << output << endl;
        return;
    }
    printAllPossibleCodes(input.substr(1), output + alpha_numeric[INT(input[0])]);
    if(INT(input[0])*10 + INT(input[1]) <= 26 && input.size()>=2)
        printAllPossibleCodes(input.substr(2), output + alpha_numeric[INT(input[0])*10 + INT(input[1])]);
}

void printAllPossibleCodes(string input)
{
    string str;
    printAllPossibleCodes(input, str);
    return;
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}