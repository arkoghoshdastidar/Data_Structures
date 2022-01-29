#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        if (insertWord(root, word))
        {
            this->count++;
        }
    }

    void print(TrieNode *root, string pattern)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->isTerminal == true)
        {
            cout << pattern + root->data << endl;
        }
        for (int i = 0; i < 26; i++)
        {
            print(root->children[i], pattern + root->data);
        }
    }

    void search(TrieNode *root, string pattern, int index = 0)
    {
        if (index == pattern.size())
        {
            if (root->isTerminal == true)
            {
                cout << pattern << endl;
            }
            for (int i = 0; i < 26; i++)
            {
                print(root->children[i], pattern);
            }
            return;
        }
        int childIndex = pattern[index] - 'a';
        if (root->children[childIndex] != NULL)
        {
            search(root->children[childIndex], pattern, index + 1);
        }
        else
        {
            return;
        }
    }

    void autoComplete(vector<string> input, string pattern)
    {
        // Write your code here
        for (int i = 0; i < input.size(); i++)
        {
            insertWord(input[i]);
        }
        search(root, pattern);
    }
};
int main(void)
{
    Trie t;
    ifstream file;
    file.open("dictionary.txt", ios::in);
    vector<string> vect;

    while (!file.eof())
    {
        string word;
        getline(file, word);
        vect.push_back(word);
    }
    file.close();
    string pattern;
    do
    {
        cin >> pattern;
        cout << "Words beginning with " << pattern << " in the english dictionary are as follows : " <<  endl;
        t.autoComplete(vect, pattern);
        cout << endl;
    } while (pattern != "/n");
    return 0;
}