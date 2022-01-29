#include<iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
	if(size == 0)
        return(0);
    int ans = allIndexes(input+1, size-1, x, output);
    
    if(x == input[0]){
        ans += 1;
        for(int i=ans-1; i>=1; i--)
            output[i] = output[i-1]+1;
        output[0]=0;
        return(ans);
    }
    else{
        for(int i=0; i<ans; i++)
            output[i] +=1;
        return(ans);
    }

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}