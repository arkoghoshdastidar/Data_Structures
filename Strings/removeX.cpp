// Given a string, compute recursively a new string where all 'x' chars have been removed.
#include <iostream>
using namespace std;

void removeX(char input[]) {
    // Write your code here
	if(input[0] == '\0')
        return;
    if(input[0] == 'x'){
        for(int i=0; input[i] != '\0'; i++){
            input[i] = input[i+1];
        }
        return (removeX(input));
    }
    return(removeX(input+1));
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}