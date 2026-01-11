#include <stdio.h>
#include <stdlib.h>

int main(){
    float *num1,*num2;
    printf("Enter a number: ");
    scanf("%f",num1);
    /*scanf breaks if you enter 2 numbers separated with white space
        and the second scanf if will read the second number immediately
    */
    scanf("%f",num2);
    printf("Number1 is %f ,the address is %p\n",*num1,num1);
    printf("Number2 is %f ,the address is %p\n",*num2,num2);

    //printf("Number is %d ,the address is %p\n",(int)&num,num);
}