def func(x):
    return pow(x,3)+x-1

def secant(x1,x2,err):
    n=0;xm=0;c=0;x0=0;
    if (func(x1)*func(x2)<0):

        while True:
            x0 = (x1*func(x2)-x2*func(x1))/(func(x2)-func(x1))
            c  = func(x1)*func(x0);
            x1 = x2
            x2 = x0
            n += 1
            if (c==0):
                break
            xm = (x1*func(x2)-x2*func(x1))/(func(x2)-func(x1))
            if (abs(xm - x0)<err):
                break  
        print(f"The root is {x0:.6f}")
        print(f"# of iterations = {n}")
    else:
        print("Could not find a root!")

a=0
b=1
err=0.0001
secant(a,b,err)
