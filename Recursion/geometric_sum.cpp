#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double geometricSum(int k) {
	if(k == 0)
        return(1);
    double ans = geometricSum(k-1);
    ans = 0.5*ans + 1;
    return(ans);
}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}