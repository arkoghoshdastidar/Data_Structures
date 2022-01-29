// Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move all disks from source rod to destination rod using third rod (say auxiliary). The rules are :
// 1) Only one disk can be moved at a time.
// 2) A disk can be moved only if it is on the top of a rod.
// 3) No disk can be placed on the top of a smaller disk.
// Print the steps required to move n disks from source rod to destination rod.
// Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.

#include<iostream>
using namespace std;

//       disc   from   using   to
void TOH(int n, int A, int B, int C)
{
    if(n > 0)
    {
        TOH(n-1,A,C,B);
        cout << "(" << A << "," << C << ")" << endl;
        TOH(n-1,B,A,C);
    }
}

int main(void)
{
    cout << "TOH algorithm for 3 disk's : " << endl;
    TOH(3,1,2,3);
    cout << "TOH algorithm for 4 disk's : " << endl;
    TOH(4,1,2,3);
    return(0);
}