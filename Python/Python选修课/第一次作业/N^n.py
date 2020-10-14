a = input()
try:
    a = int (a)
    print(1,a,a*a,a*a*a,a*a*a*a,a*a*a*a*a)
except:
    a = float(a)
    print(1.0,a,pow(a,2),pow(a,3),pow(a,4),pow(a,5))
