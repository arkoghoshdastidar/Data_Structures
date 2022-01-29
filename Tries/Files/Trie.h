#include <iostream>
#include <string>
using namespace std;
class TrieNode
{
public:
    int numChildren;
    char data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        isTerminal = false;
        numChildren = 0;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            delete children[i];
        }
        delete[] children;
    }
};

class Trie
{
private:
    TrieNode *root;
    void insert(TrieNode *root, string word, int index = 0);
    bool search(TrieNode *root, string word, int index = 0);
    TrieNode *remove(TrieNode *root, string word, int index = 0);
    int CHAR_TO_INT(char x)
    {
        return x - 'a';
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insert(string word)
    {
        return insert(root, word, 0);
    }
    bool search(string word)
    {
        return search(root, word, 0);
    }
    void remove(string word)
    {
        remove(root, word, 0);
    }
};

void Trie::insert(TrieNode *root, string word, int index)
{
    if (index == word.size())
    {
        root->isTerminal = true;
        return;
    }
    int childIndex = CHAR_TO_INT(word[index]);
    if (root->children[childIndex] == NULL)
    {
        TrieNode *child = new TrieNode(word[index]);
        root->children[childIndex] = child;
        root->numChildren++;
    }
    insert(root->children[childIndex], word, index + 1);
}

bool Trie::search(TrieNode *root, string word, int index)
{
    if (index == word.size())
    {
        return root->isTerminal;
    }
    int childIndex = CHAR_TO_INT(word[index]);
    if (root->children[childIndex] == NULL)
    {
        return false;
    }
    return search(root->children[childIndex], word, index + 1);
}

TrieNode *Trie::remove(TrieNode *root, string word, int index)
{
    if (index == word.size())
    {
        if (root->numChildren == 0 && root->isTerminal == true)
        {
            delete root;
            return NULL;
        }
        root->isTerminal = false;
        return root;
    }
    int childIndex = word[index] - 'a';
    if (root->children[childIndex] != NULL)
    {
        TrieNode *smallAns = remove(root->children[childIndex], word, index + 1);
        root->children[childIndex] = smallAns;
        if (smallAns == NULL)
        {
            root->numChildren--;
        }
        if (root->numChildren == 0 && root->isTerminal == false)
        {
            delete root;
            return NULL;
        }
        return root;
    }
    else
    {
        return root;
    }
}