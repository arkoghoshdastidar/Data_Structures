// Given a string S, find and return all the possible permutations of the input string.
// Note 1 : The order of permutations is not important.
// Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
// Input Format :

#include <iostream>
#include <string>
using namespace std;


int returnPermutations(string input, string output[])
{
 	if(input.size() == 0)   
        return (0);
    else if(input.size() == 1)
    {
        output[0] = input;
        return(1);
    }
    
    int size = returnPermutations(input.substr(1), output);
    int tempSize = 0;
    
    for(int i=0; i<size; i++)
    {
        string tempString = output[i];
        for(int k=1; k <=output[i].size(); k++)
        {
            if(k == output[i].size())
            {
                tempString = output[i] + input[0];
                output[size+tempSize] = tempString;
                tempSize++;
                continue;
            }
            
            for(int j=output[i].size(); j>k; j--)
            {
                if(j==output[i].size())
                    tempString = output[i] + output[i][j-1];
                else
                    tempString[j] = tempString[j-1];
            }
            tempString[k] = input[0];
            output[size+tempSize] = tempString;
            tempSize++;
        }
        output[i] = input[0] + output[i];
        string str = output[i];
    }
    return (size + tempSize);
}

int main(){
    string input;
    cin >> input;
    string output[100000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}