#include <iostream>
#include <stdio.h>
#include <math.h>

// false point method for root-finding

double func(double x){
    double f;
    f = pow(x,3)-pow(x,2)+2;

    return f;
}

void false_point(double a, double b, int iter_max){

    if (func(a)*func(b)>0.0)
        std::cout << "Enter correct values of a and b!\n";

    double c;    //c is the root

    for (int i=0;i<iter_max;i++){
        c = (a*func(b)-b*func(a))/(func(b) - func(a));
        if (func(c)==0.0)
            break;

        else if (func(c)*func(a)<0)
            b = c;
        else
            a = c;
    }

    printf(" The root is %0.4f \n",c);
}

int main(){

    double a = -100;
    double b = 200;

    false_point(a,b,500000);
}
