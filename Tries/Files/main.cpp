#include "Trie.h"
int main(void)
{
    Trie T1;
    T1.insert("hey");
    T1.insert("arko");
    T1.insert("alpha");
    T1.insert("alphabet");
    T1.insert("babe");
    T1.insert("baby");
    T1.insert("bob");
    T1.insert("none");
    T1.insert("lonely");
    T1.insert("noon");
    T1.remove("ark");
    T1.remove("archer");
    cout << T1.search("arko") << endl;
    T1.remove("arko");
    cout << T1.search("arko") << endl;
    cout << T1.search("alphabet") << endl;
    T1.remove("alphabet");
    cout << T1.search("alphabet") << endl;
    cout << T1.search("alpha") << endl;
    T1.remove("alpha");
    cout << T1.search("alpha") << endl;
    return 0;
}