#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int subsequence(string input, string output[])
{
    if(input.size()==0){
        output[0] = " ";
        return(1);
    }
    string smallString = input.substr(1);
    int smallSize = subsequence(smallString, output);

    for(int i=smallSize; i<2*smallSize; i++){
        output[i] = input[0]+output[i-smallSize];
    }
    return(2*smallSize);
}

int main(void)
{
    string input;
    cin >> input;
    int len = pow(2,input.size());
    string output[len];
    int len2 = subsequence(input, output);
    cout << "Number of substrings = " << len << endl;
    cout <<"Return value of subsequence = " << len2 << endl;
    cout << "List of subsequences listed below : " << endl;
    for(int i=0; i<len; i++)
        cout << output[i] << endl;
    cout << "END" << endl;
    return(0);
}