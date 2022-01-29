// Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

#include <iostream>
using namespace std;

int length(char *input)
{
    if(input[0] == '\0')
        return(0);
    return(1+length(input+1));
}

void pairStar(char input[]) {
    // Write your code here
	if(input[0] == '\0')
       return;
    
    if(input[0] == input[1])
    {
        
        for(int i=length(input)+1; i>=2; i--)
            input[i] = input[i-1];
        
        input[1] = '*';
        return pairStar(input+2);
    }
    
    return pairStar(input+1);
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}