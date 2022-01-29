#include <iostream>
using namespace std;

// Return subsets sum to K
// Send Feedback
// Given an array A of size n and an integer K, return all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important.
// Input format :
// Line 1 : Integer n, Size of input array
// Line 2 : Array elements separated by space
// Line 3 : K 
/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subsetSumToK(int input[], int inputSize, int output[][50], int outputSize, int key, int tempArr[], int tempArrSize)
{
    
//     base case
    
    if(inputSize == 0)
    {
        int sum = 0;
        if(inputSize == 0)
        {
            int sum = 0;
            for(int i=0;i<tempArrSize;i++)
                sum += tempArr[i];
            
            if(sum == key)
            {
                output[outputSize][0] = tempArrSize;
                
                for(int i=1; i<=tempArrSize; i++)
                    output[outputSize][i] = tempArr[i-1];
                return(outputSize+1);
            }
            else
                return(outputSize);
        }
    }
    
//     first function call induction hypothesis
    
    outputSize = subsetSumToK(input+1, inputSize-1, output, outputSize, key, tempArr, tempArrSize);
    tempArr[tempArrSize] = input[0];
    outputSize = subsetSumToK(input+1, inputSize-1, output, outputSize, key, tempArr, tempArrSize+1);
    return(outputSize);
}

int subsetSumToK(int input[], int n, int output[][50], int k)
{
	int tempOutput[20];
    return(subsetSumToK(input, n, output, 0, k, tempOutput, 0));
}

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}