#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <stdexcept>
#include <vector>

#define _USE_MATH_DEFINES

// a function for linespace (similar to python)
template<typename T>
std::vector<double> linspace(T start_in, T end_in, int num){

    std::vector<double> linspaced;
  
    double start = static_cast<double>(start_in);
    double end = static_cast<double>(end_in);
  
    if (num == 0)
        return linspaced;
    if (num == 1) {
        linspaced.push_back(start);
        return linspaced;
        }
  
    double delta = (end - start) / (num - 1);
  
    for(int i=0; i < num-1; ++i) {
        linspaced.push_back(start + delta * i);
        }
    linspaced.push_back(end);
                             
    return linspaced;
}


double func(double x){
    return sin(x);
}

double derivative (double x, std::string method, double h = 0.01){

    if (method == "central")
        return (func(x+h) - func(x-h))/(2*h);
    else if (method == "forward")
        return (func(x+h) - func(x))/(h);
    else if (method == "backward")
        return (func(x) - func(x-h))/(h);
    else
        throw " The methods are 'central', 'forward' and 'backward', enter a correct method!";
}

int main(){

    std::vector<double> x = linspace(0.0,5*M_PI,100);
    std::vector<double> y;
    std::cout << '\n';

    FILE * temp = fopen("taylor.dat", "w"); 
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");

    for (int i=0;i<x.size();i++){
        y.push_back(derivative(x[i],"central"));
	fprintf(temp, "%lf  %lf  %lf\n",x[i],derivative(x[i],"central"),cos(x[i]));
    }

    if (gnuplotPipe){
        fprintf(gnuplotPipe, "reset\n");
        fprintf(gnuplotPipe, "set term pngcairo enhanced font 'Arial Black,17' size 15in,12in \n");
        fprintf(gnuplotPipe, "set output 'taylor.png' \n");
        fprintf(gnuplotPipe, "set lmargin 8.0\n");
        fprintf(gnuplotPipe, "set rmargin 4.0\n");
        fprintf(gnuplotPipe, "set tmargin 3.0\n");
        fprintf(gnuplotPipe, "set bmargin 4.0\n");
        fprintf(gnuplotPipe, "set border lw 4.0\n");
        fprintf(gnuplotPipe, "set xrange [-1:17]\n");
        fprintf(gnuplotPipe, "set yrange [-1.5:1.5]\n");
        fprintf(gnuplotPipe, "set xlabel '{/*1.0:Bold x}'\n");
//        fprintf(gnuplotPipe, "set xlabel offset 1.5\n");
        fprintf(gnuplotPipe, "set ylabel '{/*1.0:Bold y(x)}'\n");
        fprintf(gnuplotPipe, "set ylabel offset 0.5 \n");
        fprintf(gnuplotPipe, "set title '{/*1.0:Bold Central difference derivative of sin(x)}'\n");
        fprintf(gnuplotPipe, "set ytics font ',13' \n");
        fprintf(gnuplotPipe, "set xtics font ',13' \n");
        fprintf(gnuplotPipe, "set key at 16.8,1.4 \n");
        fprintf(gnuplotPipe, "plot 'taylor.dat' u 1:2 with lines lw 4 lc 'red' title '{/*0.8:Bold Central difference}',\
'taylor.dat' u 1:3 with points pt 7 ps 1.0 lc 'blue' title '{/*0.8:Bold True value}'\n");  
        fflush(gnuplotPipe);
    }
    fprintf(gnuplotPipe, "e");

    return 0;
}
