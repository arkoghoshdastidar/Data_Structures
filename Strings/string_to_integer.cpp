// Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

#include <iostream>
using namespace std;

int length(char str[])
{
    if(str[0] == '\0')
        return(0);
	return(1+length(str+1));
}

int stringToNumber(char input[], int size = -1) {
    // Write your code here
	if(size == 0)
        return(0);
    
    if(size == -1)
    	size = length(input);
    
    int smallAns = stringToNumber(input, size-1);
    smallAns = smallAns*10 + (int)input[size-1] - 48;
    return(smallAns);
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}