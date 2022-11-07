#include <iostream>
#include <math.h>
#include <stdlib.h>


struct Data{

    double x,y;
};

void readin(int n, Data f[]){

    std::cout << "Type in x values one at a time and hit enter : \n";
    for (int i=0;i<n;i++){
        std::cin >> f[i].x;
    }

    std::cout << "Type in y values one at a time and hit enter : \n";
    for (int i=0;i<n;+i++){
        std::cin >> f[i].y;
    }
}

double lagrange_interpol(int n, Data f[], double givenX){
    double* coeff = new double[n];
    double final_y = 0.0;
    for (int i=0;i<n;i++){
        double numerator=1.0;
        double denominator=1.0;
        for (int j=0;j<n;j++){
            if (f[j].x==f[i].x)
                continue;
            numerator   *= givenX - f[j].x;
            denominator *= f[i].x - f[j].x;
        }
        //std::cout << "numerator: "  << numerator << '\n';
        //std::cout << "denominator: "<< denominator << '\n';
        coeff[i] = f[i].y* numerator/denominator;
        //std::cout << "    coeff["<< i+1 << "]: " << coeff[i] << '\n';
        printf("    coeff[%d]: %+2.2f\n", i+1,coeff[i]);

    }
    for (int i=0;i<n;i++)
        final_y += coeff[i];
    return final_y;
}

int main(){
    int n;
    double givenX; ;
    double int_y;
  
    std::cout << "Enter the # of x or y values: \n";
    std::cin  >> n;
    std::cout << "Enter the intended value of interpolation at x: \n";
    std::cin  >> givenX;
    Data f[n];
  
    readin(n, f);
  
    std::cout << '\n';
    std::cout << " *** You entered: ***\n";
    std::cout << "      x        y \n";
    
    for (int i=0;i<n;i++)
        printf("     %.2f    %5.2f \n", f[i].x, f[i].y);
    std::cout << '\n';
    
    int_y = lagrange_interpol(n,f,givenX);
    std::cout << '\n';
    
    printf("The interpolated value of y from %.1f is %0.3f \n", givenX, int_y);
    std::cout << '\n';

}
