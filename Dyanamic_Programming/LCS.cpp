#include <iostream>
#include <string>
using namespace std;
// Brute-Force Method
int LCS(string a, string b)
{
    if (a.size() == 0 || b.size() == 0)
    {
        return 0;
    }
    if (a.at(0) == b.at(0))
    {
        return 1 + LCS(a.substr(1), b.substr(1));
    }
    int num1 = LCS(a.substr(1), b);
    int num2 = LCS(a, b.substr(1));
    return max(num1, num2);
}
// LCS using Memoization
int LCS_MEM2(string a, string b, int **output)
{
    if (a.size() == 0 || b.size() == 0)
    {
        output[a.size()][b.size()] = 0;
        return output[a.size()][b.size()];
    }
    if (output[a.size()][b.size()] != -1)
    {
        return output[a.size()][b.size()];
    }
    if (a.at(0) == b.at(0))
    {
        output[a.size()][b.size()] = LCS_MEM2(a.substr(1), b.substr(1), output) + 1;
        return output[a.size()][b.size()];
    }
    int val1 = LCS_MEM2(a.substr(1), b, output);
    int val2 = LCS_MEM2(a, b.substr(1), output);
    output[a.size()][b.size()] = max(val1, val2);
    return output[a.size()][b.size()];
}
int LCS_MEM1(string a, string b)
{
    int **output = new int *[a.size() + 1];
    for (int i = 0; i < a.size() + 1; i++)
    {
        output[i] = new int[b.size() + 1];
    }
    for (int i = 0; i < a.size() + 1; i++)
    {
        for (int j = 0; j < b.size() + 1; j++)
        {
            output[i][j] = -1;
        }
    }
    int answer = LCS_MEM2(a, b, output);
    for (int i = 0; i < a.size() + 1; i++)
    {
        delete[] output[i];
    }
    delete[] output;
    return answer;
}
// LCS Dyanamic Programming
int LCS_DP(string a, string b)
{
    int m = a.size() + 1;
    int n = b.size() + 1;
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        output[0][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        output[i][0] = 0;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a.at(i - 1) == b.at(j - 1))
            {
                output[i][j] = 1 + output[i - 1][j - 1];
            }
            else
            {
                output[i][j] = max(output[i - 1][j], output[i][j - 1]);
            }
        }
    }
    int answer = output[m - 1][n - 1];
    for (int i = 0; i < m; i++)
    {
        delete[] output[i];
    }
    delete[] output;
    return answer;
}

// Nidhi Ma'am code
int lcs_mem(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();

    // Base case
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }

    // Check if ans already exists
    if (output[m][n] != -1)
    {
        return output[m][n];
    }

    int ans;
    // Recursive calls
    if (s[0] == t[0])
    {
        ans = 1 + lcs_mem(s.substr(1), t.substr(1), output);
    }
    else
    {
        int a = lcs_mem(s.substr(1), t, output);
        int b = lcs_mem(s, t.substr(1), output);
        ans = max(a, b);
    }

    // Save your calculation
    output[m][n] = ans;

    // Return ans
    return ans;
}

int lcs_mem(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }

    return lcs_mem(s, t, output);
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B;
        cout << LCS_DP(A, B) << " " << lcs_mem(A, B) << endl;
    }
    return 0;
}