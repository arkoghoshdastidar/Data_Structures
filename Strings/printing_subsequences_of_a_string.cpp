#include<iostream>
#include<string>
using namespace std;

void print_subsequence(string input, string output)
{
    if(input.size() == 0)
    {
        cout << output << endl;
        return;
    }
    print_subsequence(input.substr(1), output);
    print_subsequence(input.substr(1), output+input[0]);
    return;
}

int main(void)
{
    string input;
    string output;
    cin >> input;
    print_subsequence(input, output);
    return(0);
}
