#include<iostream>
using namespace std;
int length2(char input[])
{
    if(input[0] == '\0')
        return(0);
    return(1+length2(input+1));
}
// Change in the given string itself. So no need to return or print anything
void replacePi(char input[])
{
	// Write your code here
	if(input[0] == '\0')
        return;
    
    if(input[0] == 'p' && input[1] == 'i')
    {
        input[0] = '3';
        input[1] = '.';
        
        for(int i=length2(input)+2; i>=4 ; i--)
            input[i] = input[i-2];
        input[2] = '1';
        input[3] = '4';
        return(replacePi(input+4));
    }
    else
        return(replacePi(input+1));
    
}



int main(void)
{
    char str[100];
    cin>>str;
    cout<<str<<endl;
    replacePi(str);
    cout<<str<<endl;
    return(0);
}