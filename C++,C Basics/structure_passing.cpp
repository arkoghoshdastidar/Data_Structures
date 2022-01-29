#include<iostream>
using namespace std;

struct _array{
    int arr[5];
    int n=5;
};
// Pass by address.
void insert(struct _array *st){
    for(int i=0;i<5;i++)
        st->arr[i]=i;
    return;
}
// Pass by value.
void print(struct _array st){
    for(int i=0;i<st.n;i++)
        cout<<st.arr[i]<<" ";
    cout<<endl;
    return;
}
// Pass by reference
/*
    void create(struct _array &st){
    }
*/
int main(void)
{
    struct _array strArr;
    insert(&strArr);
    print(strArr);
    return(0);
}