#include<stdio.h>
// Structure and Function is the maximum level of object orientation supported by C-language.
// It does not support data hiding.
struct rectangle{
    int length,breadth;
};
int getLength(struct rectangle r){
    return(r.length);
}
int getBreadth(struct rectangle r){
    return(r.breadth);
}
void setLength(struct rectangle *r){
    scanf("%d",&r->length);
}
void setBreadth(struct rectangle *r){
    scanf("%d",&r->breadth);
}
int getArea(struct rectangle r){
    return(r.length*r.breadth);
}
int getPerimeter(struct rectangle r){
    return(2*(r.length+r.breadth));
}
int main(void)
{
    struct rectangle r;
    setLength(&r);
    setBreadth(&r);
    printf("Area = %d\n",(getArea(r)));
    printf("Perimeter = %d\n",(getPerimeter(r)));
    return(0);
}