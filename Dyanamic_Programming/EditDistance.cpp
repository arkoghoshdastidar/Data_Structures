#include <cstring>
#include <iostream>
using namespace std;
// Brute-Force Method
int editDistance(string s1, string s2)
{
    if (s1.size() == 0 || s2.size() == 0)
    {
        return ((s1.size() == 0) ? s2.size() : s1.size());
    }
    if (s1.at(0) == s2.at(0))
    {
        return editDistance(s1.substr(1), s2.substr(1));
    }
    int x = editDistance(s1.substr(1), s2);
    int y = editDistance(s1, s2.substr(1));
    int z = editDistance(s1.substr(1), s2.substr(1));
    int answer = 1 + min(x, min(y, z));
    return answer;
}
// UsingMemoization
int editDistance(string s1, string s2, int **output)
{
    int m = s1.size();
    int n = s2.size();
    if (s1.size() == 0 || s2.size() == 0)
    {
        return ((s1.size() == 0) ? s2.size() : s1.size());
    }
    if (output[m][n] != -1)
    {
        return output[m][n];
    }
    if (s1.at(0) == s2.at(0))
    {
        output[m][n] = editDistance(s1.substr(1), s2.substr(1), output);
    }
    else
    {
        int x = editDistance(s1.substr(1), s2, output);
        int y = editDistance(s1, s2.substr(1), output);
        int z = editDistance(s1.substr(1), s2.substr(1), output);
        output[m][n] = 1 + min(x, min(y, z));
    }
    return output[m][n];
}
int editDistance_mem(string s1, string s2)
{
    int m = s1.size() + 1;
    int n = s2.size() + 1;
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    int answer = editDistance(s1, s2, output);
    for (int i = 0; i < m; i++)
    {
        delete[] output[i];
    }
    delete[] output;
    return answer;
}
// DyanamicProgrammingMethod
int editDistance_dp(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    int **output = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        output[i] = new int[n + 1];
    }
    for (int i = 0; i < m + 1; i++)
    {
        output[i][0] = i;
    }
    for (int j = 0; j < n + 1; j++)
    {
        output[0][j] = j;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1.at(m - i) == s2.at(n - j))
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                output[i][j] = 1 + min(output[i - 1][j], min(output[i][j - 1], output[i - 1][j - 1]));
            }
        }
    }
    int answer = output[m][n];
    for (int i = 0; i < m + 1; i++)
    {
        delete[] output[i];
    }
    delete[] output;
    return answer;
}
int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << editDistance_dp(s1, s2) << endl;
}