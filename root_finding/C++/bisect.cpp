#include <iostream>
#include <stdio.h>
#include <math.h>

// bisect method for root-finding 

double func(double x){
    double f;
    f = pow(x,3)-pow(x,2)+2;

    return f;
}

void bisect(double a, double b){

    if (func(a)*func(b)>=0.0)
        std::cout << "Enter correct values of a and b!\n";

    double c = a;    //c is the root

    while ((b-a)>=0.01){
        c = (b+a)/2;
        if (func(c)==0.0)
            break;

        if (func(c)*func(a)<0)
            b = c;
        else
            a = c;
    }

    printf(" The root is %0.4f \n",c);
}

int main(){

    double a = -100;
    double b = 200;

    bisect(a,b);

}
