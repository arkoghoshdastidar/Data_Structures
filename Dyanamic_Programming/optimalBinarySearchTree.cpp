#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int optimalHelper(int *frequency, int si, int ei){
    if(si>ei){
        return 0;
    }
    int optCst = INT_MAX;
    int sum = 0;
    for(int i=si; i<=ei; i++){
        sum += frequency[i];
    }
    for(int k=si; k<=ei; k++){
        optCst = min(optCst, optimalHelper(frequency, si, k-1)+optimalHelper(frequency, k+1, ei));
    }
    return optCst + sum;
}

int optimalCost(int *keys, int *frequency, int n){
    return optimalHelper(frequency, 0, n-1);
}

int main(void){
    int* keys;
    int* frequency;
    int n;
    cin >> n;
    keys = new int[n];
    frequency = new int[n];
    for(int i=0; i<n; i++){
        cin >> keys[i] >> frequency[i];
    }
    cout << optimalCost(keys, frequency, n);
    return 0;
}