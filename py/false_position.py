def func(x):
    return pow(x,3)-pow(x,2)+2

def false_point(a,b,max_iter):
    counta = 0
    countb = 0
    if func(a)*func(b)>0:
        print("Enter correct a and b values")
        return -1

    for i in range(max_iter):
        c = (a*func(b)-b*func(a))/(func(b)-func(a))
        if func(c)==0:
            break
        elif func(c)*func(a)<0:
            b=c
            countb += 1
        else:
            a=c
            counta += 1
    print(f"The root is {c:>.4f}")
    print(f"number of a: {counta}")
    print(f"number of b: {countb}")

a=-200
b=300
false_point(a,b,500000)
