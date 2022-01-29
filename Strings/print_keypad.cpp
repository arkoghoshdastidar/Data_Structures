#include <iostream>
#include <string>
using namespace std;

// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
// Input Format :

#include <iostream>
#include <string>
using namespace std;

string str[10] = {
    " ",
    " ",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void printKeypad(int num, string output)
{
    if(num == 0)
    {
        cout << output << endl;
        return;
    }
    int lastNum = num%10;
    for(int i=0; i<str[lastNum].size(); i++)
    {
        string tempStr = str[lastNum][i] + output;
        printKeypad(num/10, tempStr);
    }
    return;
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
	string output;
    printKeypad(num, output);
    return;
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
