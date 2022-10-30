#include <iostream>
#include <stdio.h>
#include <math.h>

// false point method for root-finding

double func(double x){
    double f = pow(x,3)-pow(x,2)+2;

    return f;
}

double funcdr(double x){
    double dr = 3*pow(x,2)-2*x;

    return dr;
}

void newton_raphson(double x){

    double h = func(x)/funcdr(x);

    while (abs(h)>=0.0001){
    h = func(x)/funcdr(x);
    x = x - h;
    }

    printf(" The root is %0.4f \n",x);
}

int main(){

    double a = -100;

    newton_raphson(a);
}
