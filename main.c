#include <stdio.h>
#include <stdlib.h>

int main(){
    float *num;
    printf("Enter a number: ");
    scanf("%f",num);
    printf("Number is %f ,the address is %p\n",*num,num);
    printf("Number is %d ,the address is %p\n",(int)&num,num);
}