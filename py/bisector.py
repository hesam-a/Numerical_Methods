def func(x):
    return pow(x,3)-pow(x,2)+2

def bisect(a,b):
    if func(a)*func(b)>=0:
        print("Enter correct a and b values")
        return -1

    c=a
    while (b-a)>=0.01:
        c = (a+b)/2
        if func(c)==0.0:
            break
        if func(c)*func(a)<0:
            b=c
        else:
            a=c
    print(f"The root is {c:<.4f}")

a=-200
b= 300
bisect(a,b)
