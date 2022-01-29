//+-+++++++++-++-++++++-------+++-++-++++++-++-++++++-++-+++++++++-+++++++++-+++++++++++++++----------
//CALIFORNIA;NIGERIA;CANADA;TELAVIV
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

void print(char crossword[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << crossword[i][j] << " ";
        }
        cout << endl;
    }
}

int checkRight(char crossword[10][10], int x, int y)
{
    int vacancies = 0;
    int i = x;
    int j = y + 1;
    while (j < 10)
    {
        if (crossword[i][j] == '-')
        {
            vacancies += 1;
        }
        else if (crossword[i][j] == '+')
        {
            break;
        }
        j++;
    }
    return vacancies;
}

int checkDown(char crossword[10][10], int x, int y)
{
    int vacancies = 0;
    int i = x + 1;
    int j = y;
    while (i < 10)
    {
        if (crossword[i][j] == '-')
        {
            vacancies += 1;
        }
        else if (crossword[i][j] == '+')
        {
            break;
        }
        i++;
    }
    return vacancies;
}

string leftParent(char crossword[10][10], int x, int y)
{
    int i = y - 1;
    string temp;
    while (i >= 0)
    {
        if (crossword[x][i] == '+')
        {
            break;
        }
        temp = crossword[x][i] + temp;
        i--;
    }
    return temp;
}

string topParent(char crossword[10][10], int x, int y)
{
    int i = x - 1;
    string temp;
    while (i >= 0)
    {
        if (crossword[i][y] == '+')
        {
            break;
        }
        temp = crossword[i][y] + temp;
        i--;
    }
    return temp;
}

int match(string parent, string child)
{
    if (parent.size() == 0)
    {
        return 0;
    }
    int index = 0;
    for (int j = 0, i = 0; i < parent.size(); i++, j++)
    {
        if (parent.at(i) == child.at(j))
        {
            index++;
            continue;
        }
        else
        {
            return -1;
        }
    }
    return index;
}

bool fillRight(char crossword[10][10], string word, int x, int y, int index)
{
    int i;
    for (i = index; i < word.size(); i++, y++)
    {
        if (crossword[x][y] == '+')
        {
            return false;
        }
        else if (crossword[x][y] == '-')
        {
            crossword[x][y] = word[i];
        }
        else
        {
            if (crossword[x][y] != word[i])
            {
                return false;
            }
        }
    }
    return i == word.size();
}

void clearRight(char crossword[10][10], string word, int x, int y, int index)
{
    for (int i = index; i < word.size(); i++)
    {
        if (crossword[x][y] == '+')
        {
            return;
        }
        crossword[x][y] = '-';
        y++;
    }
}

bool fillDown(char crossword[10][10], string word, int x, int y, int index)
{
    int i;
    for (i = index; i < word.size(); i++, x++)
    {
        if (crossword[x][y] == '+')
        {
            return false;
        }
        else if (crossword[x][y] == '-')
        {
            crossword[x][y] = word[i];
        }
        else
        {
            if (crossword[x][y] != word[i])
            {
                return false;
            }
        }
    }
    return i == word.size();
}

void clearDown(char crossword[10][10], string word, int x, int y, int index)
{
    for (int i = index; i < word.size(); i++)
    {
        if (crossword[x][y] == '+')
        {
            return;
        }
        crossword[x][y] = '-';
        x++;
    }
}

bool solvecrossword(char crossword[10][10], queue<string> words, int x = 0, int y = 0)
{
    if (x == 10)
    {
        return true;
    }
    if (crossword[x][y] == '-')
    {
        // check-right for vacancies
        // if right side has vacancies then check for ancestors at the left side
        // if ancestors are present at the right side then start entering data from the new index else enter the complete word from the queue.
        // return
        // if right side has no vacancies then for sure we have to enter data downwards
        // check top for ancestors if ancestors are present the start entering data from the new index
        // else enter the complete word
        // return
        int length = 0;
        if ((length = checkRight(crossword, x, y)))
        {
            string first = words.front();
            string parent = leftParent(crossword, x, y);
            while (!words.empty())
            {
                string child = words.front();
                words.pop();
                int index = match(parent, child);
                if (index == -1)
                {
                    words.push(child);
                }
                else
                {
                    bool ans = fillRight(crossword, child, x, y, index);
                    if (!ans)
                    {
                        words.push(child);
                        clearRight(crossword, child, x, y, index);
                    }
                    bool smallAns;
                    if (ans)
                    {
                        if (y == 9)
                        {
                            smallAns = solvecrossword(crossword, words, x + 1, 0);
                        }
                        else
                        {
                            smallAns = solvecrossword(crossword, words, x, y + 1);
                        }
                        if (smallAns)
                        {
                            return true;
                        }
                        else
                        {
                            clearRight(crossword, child, x, y, index);
                            words.push(child);
                        }
                    }
                }
                if (words.front() == first)
                {
                    break;
                }
            }
        }
        else if ((length = checkDown(crossword, x, y)))
        {
            string first = words.front();
            string parent = topParent(crossword, x, y);
            while (!words.empty())
            {
                string child = words.front();
                words.pop();
                int index = match(parent, child);
                if (index == -1)
                {
                    words.push(child);
                }
                else
                {
                    bool ans = fillDown(crossword, child, x, y, index);
                    if (!ans)
                    {
                        words.push(child);
                        clearDown(crossword, child, x, y, index);
                    }
                    bool smallAns;
                    if (ans)
                    {
                        if (y == 9)
                        {
                            smallAns = solvecrossword(crossword, words, x + 1, 0);
                        }
                        else
                        {
                            smallAns = solvecrossword(crossword, words, x, y + 1);
                        }
                        if (smallAns)
                        {
                            return true;
                        }
                        else
                        {
                            clearDown(crossword, child, x, y, index);
                            words.push(child);
                        }
                    }
                }
                if (words.front() == first)
                {
                    break;
                }
            }
        }
    }
    else
    {
        if (y == 9)
        {
            return solvecrossword(crossword, words, x + 1, 0);
        }
        else
        {
            return solvecrossword(crossword, words, x, y + 1);
        }
    }
    return false;
}

int main()
{
    // Creating 10*10 matrix for the cross word.
    char crossword[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> crossword[i][j];
        }
    }
    // Taking the input of words and separating the input and storing them in the vector words.
    string input, temp;
    queue<string> words;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ';')
        {
            words.push(temp);
            temp = "";
        }
        else if (i == input.size() - 1)
        {
            words.push(temp + input[i]);
            continue;
        }
        else
        {
            temp += input[i];
        }
    }
    solvecrossword(crossword, words);
    print(crossword);
    return 0;
}