def func(x):
    return pow(x,3)-pow(x,2)+2

def funcdr(x):
    return 3*pow(x,2)-2*x

def newton_raphson(x):
    h = func(x)/funcdr(x)

    while abs(h)>=0.0001:
        h = func(x)/funcdr(x)
        x = x-h

    print(f"The root is {x:.4f}")


a=-200
newton_raphson(a)
