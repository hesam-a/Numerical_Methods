#include <iostream>
#include <stdio.h>
#include <math.h>

// secant method for root-finding

double func(double x){
    double f = pow(x,3)-pow(x,2)+2;

    return f;
}

void secant(double x1, double x2, double err){
    double xm=0,c=0,x0=0;
    int n=0;

    if (func(x1)*func(x2)<0){

        while (true){
            x0 = (x1*func(x2)-x2*func(x1))/(func(x2)-func(x1));
            c  = func(x1)*func(x0);
            x1 = x2;
            x2 = x0;
            n += 1;
            if (c==0)
                break;
            xm = (x1*func(x2)-x2*func(x1))/(func(x2)-func(x1));
            if (abs(xm - x0)<err)
                break;
        }
        printf("The root is %.6f", x0);
        printf("# of iterations = %d \n", n);
    }
    else
        printf("Could not find a root!");

}

int main(){

    double a   = -110;
    double b   = 200;
    double err = 0.0001;
    secant(a,b,err);
}
