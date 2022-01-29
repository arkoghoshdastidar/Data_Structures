#include <iostream>
#include <string>
using namespace std;

#include <string>
#include <iostream>
using namespace std;

string str[10] = {
    " ",
    " ",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"};

int keypad(int num, string output[])
{
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if (num == 0 || num == 1)
    {
        output[0] = str[num];
        return (1);
    }
    else if (num / 10 == 0)
    {
        for (int i = 0; i < str[num].size(); i++)
            output[i] = str[num][i];
        return(str[num].size());
    }

    int smallNumber = num / 10;
    int currentNumber = num % 10;
    int outputSize = keypad(smallNumber, output);

    for (int i = outputSize; i < outputSize * ((int)str[currentNumber].size()); i++)
    {
        output[i] = output[i - outputSize];
    }

    int j = 0;

    for (int i = 0; i < outputSize * ((int)str[currentNumber].size()); i++)
    {
        if (i % outputSize == 0 && i!= 0)
            j = j + 1;
        output[i] = output[i] + str[currentNumber][j];
    }
    return (outputSize * (str[currentNumber].size()));
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}