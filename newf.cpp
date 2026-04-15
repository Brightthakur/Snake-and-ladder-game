#include<stdio.h>
#include<stdlib.h>

int xor_mp(int x1,int x2){

    int And_not = 1*x1 + (-1)*x2;
    int theta1 = 1;
    int output1;
    if(And_not>=theta1){
        output1 = 1;
    }
    else output1 = 0;

    int not_And = -1*x1 + x2;
    int theta2 = 1;
    int output2;
    if(not_And>=theta2){
        output2 = 1;
    }
    else output2 = 0;

    int Or = output1 + output2;
    int theta3 = 1;
    int output3;
    if(Or>=theta3){
        output3 = 1;
    }
    else output3 = 0;
    return output3;
}

int main(){
     printf("(x1,x2) -> Output");
     printf("(0,0)-> %d",xor_mp(0,0));
     printf("(0,1)-> %d",xor_mp(0,1));
     printf("(1,0)-> %d",xor_mp(1,0));
     printf("(1,1)-> %d",xor_mp(1,1));


    return 0;
}
