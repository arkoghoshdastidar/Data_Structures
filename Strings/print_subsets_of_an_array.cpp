#include <iostream>
using namespace std;

void printSubsetsOfArray(int input[], int inputSize, int output[], int outputSize)
{
    if(inputSize == 0)
    {
        for(int i = 0; i<outputSize; i++)
            cout << output[i] << " ";
        cout << endl;
        return;
    }
    printSubsetsOfArray(input+1, inputSize-1, output, outputSize);
    output[outputSize] = input[0];
    printSubsetsOfArray(input+1, inputSize-1,output, outputSize+1);
    return;
}


void printSubsetsOfArray(int input[], int size)
{
	// Write your code here
    int output[1000];
    printSubsetsOfArray(input, size, output, 0);
    return;
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
