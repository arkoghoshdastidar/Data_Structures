#include <unordered_map>
#include "huffman.h"
using namespace std;

int main(void)
{
    min_priority_queue *character_store = new min_priority_queue();
    unordered_map<char, string> CHAR_TO_CODE;
    unordered_map<string, char> CODE_TO_CHAR;
    int alphabet_frequency[26];
    string input;
    cin >> input;
    for (int i = 0; i < 26; i++)
    {
        alphabet_frequency[i] = 0;
    }
    for (int i = 0; i < input.size(); i++)
    {
        char alphabet = input.at(i);
        alphabet_frequency[alphabet - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (alphabet_frequency[i])
        {
            char x = i + 'a';
            int frequency = alphabet_frequency[i];
            node *temp = new node(frequency, x);
            character_store->insert(temp);
        }
    }
    while (character_store->size() != 1)
    {
        node *child1 = character_store->top();
        character_store->pop();
        node *child2 = character_store->top();
        character_store->pop();
        node *parent = new node(child1->frequency + child2->frequency);
        parent->left = child1;
        parent->right = child2;
        character_store->insert(parent);
    }
    node *root = character_store->top();
    character_store->pop();
    for (int i = 0; i < input.size(); i++)
    {
        char character = input.at(i);
        string code = get_code(root, character).second;
        CHAR_TO_CODE.insert({character, code});
        CODE_TO_CHAR.insert({code, character});
    }
    string encoded_string = encode(CHAR_TO_CODE, input);
    cout << encoded_string << endl;
    string decoded_string = decode(CODE_TO_CHAR, encoded_string);
    cout << decoded_string << endl;
    return 0;
}
// aabcabefedccaabe