#include <iostream>
using namespace std;
#include "CBT.h"
#include "heap.h"
#include "minPriorityQueue.h"


int main(void)
{
    PriorityQueue test1;
    test1.insert(12);
    test1.insert(6);
    test1.insert(5);
    test1.insert(100);
    test1.insert(1);
    test1.insert(9);
    test1.insert(0);
    test1.insert(14);
    test1.print();
    test1.remove();
    test1.remove();
    test1.print();
    return 0;
}