#include <iostream>
using namespace std;

bool checkPalindrome(char input[])
{
    int len = 0;
    
    while(input[len] != '\0')
        len += 1;
    
    if(len == 1)
        return (true);
    
    if(len == 2 && input[0] == input[1])
        return(true);
    
    else if(len == 2 && input[0] != input[1])
        return(false);
    
    if(input[0] != input[len-1])
        return (false);
    
    input[len-1] = '\0';
    return(checkPalindrome(input+1));
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}