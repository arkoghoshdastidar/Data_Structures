// Coin Tower
// Send Feedback
// Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
//  Input format :
// The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
// Output format :
// Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
// Constraints :
// 1 <= N <= 10 ^ 6
// 2 <= X <= Y<= 50

// Time Limit: 1 sec
// Sample Input 1 :
// 4 2 3
// Sample Output 1 :
// Whis
// Sample Input 2 :
// 10 2 4
// Sample Output 2 :
// Beerus
#include <iostream>
#include <string>
using namespace std;
string findWinner(int n, int x, int y, int index, string **output)
{
    if (n == 1 || n == x || n == y)
    {
        if (index % 2 == 0)
            return "Whis";
        else
            return "Beerus";
    }
    if (output[n][index].size() != 0)
    {
        return output[n][index];
    }
    string winner;
    if (n > y)
    {
        winner = findWinner(n - y, x, y, (index + 1) % 2, output);
        if (index == 1 && winner == "Beerus")
        {
            output[n][index] = "Beerus";
            return "Beerus";
        }
        if (index == 0 && winner == "Whis")
        {
            output[n][index] = "Whis";
            return "Whis";
        }
    }
    if (n > x)
    {
        winner = findWinner(n - x, x, y, (index + 1) % 2, output);
        if (index == 1 && winner == "Beerus")
        {
            output[n][index] = "Beerus";
            return "Beerus";
        }
        if (index == 0 && winner == "Whis")
        {
            output[n][index] = "Whis";
            return "Whis";
        }
    }
    winner = findWinner(n - 1, x, y, (index + 1) % 2, output);
    output[n][index] = winner;
    return winner;
}

string findWinner(int n, int x, int y)
{
    string **output = new string *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        output[i] = new string[2];
    }
    return findWinner(n, x, y, 1, output);
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y);
}