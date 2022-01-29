// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. And input string does not contain 0s.
// Input format :
// A numeric string
// Constraints :
// 1 <= Length of String S <= 10

#include <iostream>
#include <string>
using namespace std;

string alpha[] = {" ","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

int INT(char str){
    int x = str - '0';
    return x;
}

int getCodes(string input, string output[10000])
{
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.size() == 0)
        return(0);
    
    if(input.size() == 1){
        output[0] = alpha[INT(input[0])];
        return(1);
    }
    
    int size1 = 0, size2 = 0;
    int size = getCodes(input.substr(2), output);
    
    if(size == 0)
    {
        output[0] = alpha[INT(input[0])] + alpha[INT(input[1])];
        if((INT(input[0])*10 + INT(input[1]) <= 26))
        {
            output[1] = alpha[INT(input[0])*10 + INT(input[1])];
            return(2);
        }
        return(1);
    }
    
    if(input[2] != '\0')
    {
        if((INT(input[1])*10 + INT( input[2]) <= 26 ))
           {
     			for(int i=0; i<size; i++)          
                {
                    if(output[i][0] < 'j' && output[i].size() >= 2)
                    {
                        output[size + i] = alpha[INT(input[0])] + alpha[INT(input[1])*10 + INT(input[2])] + output[i].substr(1);
                        size1++;
                    }
                    else if(output[i][0] < 'j' && output[i].size() == 1)
                    {
                        output[size + i] = alpha[INT(input[0])] + alpha[INT(input[1])*10 + INT(input[2])] + "\0";
                        size1++;
                    }
                }
           }
    }
    
    if(INT(input[0])*10 + INT(input[1]) <= 26)
    {
        for(int i=0; i<size; i++)
        {
            output[size + size1 + i] = alpha[INT(input[0])*10 + INT( input[1])] + output[i];
            size2++;
        }
    }
    
    for(int i=0; i<size; i++)
    {
        output[i] = alpha[INT(input[0])] + alpha[INT(input[1])] + output[i];
    }
    
    return(size + size1 + size2);
}
int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
