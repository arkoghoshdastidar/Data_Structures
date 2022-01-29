// Given an input string (STR), print all possible permutations of the input string.
// Note:
// The input string may contain the same characters, so there will also be the same permutations.
// The order of permutations doesn’t matter.
// Input Format:
// The only input line contains a string (STR) of alphabets in lower case
// Output Format:
// Print each permutations in a new line
// Note:
// You do not need to print anything, it has already been taken care of. Just implement the function.  
#include <iostream>
#include <string>
using namespace std;

void printPermutations(string input, string output, int inputSize)
{
    if(inputSize == 1){
        for(int i=0;i<inputSize;i++)
            output = output + input[i];
        cout << output << endl;
        return;
    }
    string tempString;
    
    for(int i=0; i<inputSize; i++){
        tempString = input;
        string tempOutput = output;
        output = output + input[i];
        for(int k=i; k<inputSize; k++){
            tempString[k] = tempString[k+1];
        }
        printPermutations(tempString, output, inputSize-1);
        output = tempOutput;
    }
    return;
}

void printPermutations(string input)
{
	string output;
    printPermutations(input, output, input.size());
    return;
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}