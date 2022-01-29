#include<iostream>
using namespace std;

int main(void)
{
    int **arr = new int*[5];

    for(int i=0; i<5; i++){
        arr[i] = new int[10];
        for(int j=0; j<10; j++)
            cin >> arr[i][j];
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<10; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return(0);
}