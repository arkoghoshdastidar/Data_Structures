#include<iostream>
#include<climits>
using namespace std;
#include "StackUsingLL.h"
#include "StackUsingArray.h"
#include "DyanamicStack.h"
#include "GenericStack.h"
#include <stack>

int main(void)
{
    stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);

    stack<int> s2;
    s2.push('A');
    s2.push('B');
    s2.push('C');
    s2.push('D');
    s2.push('E');

    s1.swap(s2);
    s1.swap(s2);
    s1.emplace(10);
    s1.emplace(-10);

    while(!s1.empty())
    {
        cout << s1.top() << endl;
        s1.pop();
    }
    return 0;
}