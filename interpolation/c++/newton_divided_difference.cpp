#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "boost/format.hpp"

// a code for Newton's divided differences method for polynomial interpolation

int main(){

    int n = 8;
    double x[n] = {0, 1, 2, 5.5, 11, 13, 16, 18};
    double y[n] = {0.5, 3.134, 5.9, 9.9, 10.2, 9.35, 7.2, 6.2};

    double p[n][n+1] = {0};

/*    for (int i=0;i<n;i++){
        for (int j=0;j<n+1;j++){
            std::cout << p[i][j] << "  ";
        }
        std::cout << '\n';
    }
*/
    
    for (int i=0;i<n;i++){
        p[i][0] = x[i];  
        p[i][1] = y[i];
    }

    for (int i=2;i<n+1;i++){
        for (int j=0;j<n+1-i;j++){
            p[j][i] =  (p[j+1,i-1] - p[j,i-1]) / (x[j+i-1] - x[j]);
        }
    }
    std::cout << "Enter the intended value for the interpolation: ";
    double givenX;
    std::cin >> givenX;
    double b[n];
    for (int i=1;i<n+1;i++)
        b[i] = p[0][i];

    double* lst=new double[n];
    double t=1;

    for (int i=0;i<n;i++){
        t *= (givenX - x[i]);
        lst[i] = t;
    }

    std::cout << "The list of product elements: ";
    for (int i=0; i<n;i++)
        std::cout << boost::format("%15.6f") %lst[i];

    std::cout <<'\n';

    double f=b[0];

    for (int i=1;i<n+1;i++)
        f += b[i]*lst[i-1];

    printf("The value of polynomial: %.3f \n",f);

    return 0;
}
