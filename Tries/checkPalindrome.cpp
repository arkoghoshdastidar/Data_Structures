// Palindrome Pair
// Send Feedback
// Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
// The function should return either true or false. You don't have to print anything.
// Input Format :
// The first line of the test case contains an integer value denoting 'n'.

// The following contains 'n' number of words each separated by a single space.
// Output Format :
// The first and only line of output contains true if the conditions described in the task are met and false otherwise.
// Constraints:
// 0 <= n <= 10^5
// Time Limit: 1 sec
// Sample Input 1 :
// 4
// abc def ghi cba
// Sample Output 1 :
// true
// Explanation of Sample Input 1:
// "abc" and "cba" forms a palindrome
// Sample Input 2 :
// 2
// abc def
// Sample Output 2 :
// false
// Explanation of Sample Input 2:
// Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'

#include <iostream>
#include <vector>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }
    
    vector<string> getChildren(TrieNode* root){
        if(root->childCount == 0){
            vector<string> result;
            string temp;
            temp += root->data;
            result.push_back(temp);
            return result;
        }
        vector<string> myChildren;
        for(int i=0; i<26; i++){
            vector<string> smallAnswer;
            if(root->children[i] != NULL){
                smallAnswer = getChildren(root->children[i]);
            }
            for(int j=0; j<smallAnswer.size(); j++){
                myChildren.push_back(root->data+smallAnswer[j]);
            }
        }
        return myChildren;
    }
    
    bool checkPalindrome(string word){
        int low = 0;
        int high = word.size()-1;
        while(low < high)
        {
            if(word[low] != word[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    
    bool search(TrieNode* root, string word){
        if(word.size() == 0){
            if(root->childCount == 0){
                return true;
            }
            vector<string> myChildren;
            for(int i=0; i<26; i++){
                vector<string> smallAnswer;
                if(root->children[i] != NULL){
                    smallAnswer = getChildren(root->children[i]);
                }
                for(int j=0; j<smallAnswer.size(); j++){
                    myChildren.push_back(smallAnswer[j]);
                }
            }
            //Check wether the recieved children are palindrome or not!!
            for(int i=0; i<myChildren.size(); i++){
                if(checkPalindrome(myChildren[i])){
                    return true;
                }
            }
            return false;
        }
        else if(word.size() != 0 && root->childCount == 0){
            return checkPalindrome(word);
        }
        int index = word[0]-'a';
        if(root->children[index] != NULL){
            return search(root->children[index], word.substr(1));
        }
        return false;
    }
	
    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        for(int i=0; i<words.size(); i++){
            add(words[i]);
        }
        for(int i=0; i<words.size(); i++){
            string reverseWord;
            for(int j=words[i].size()-1; j>=0; j--){
                reverseWord += words[i][j];
            }
            if(search(root, reverseWord)){
                return true;
            }
        }
        return false;
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}