m = input()
n = input()
try:
    m=int(m)
    n=int(n)
    if m>n:
        max=m
    else:
        max=n
    print(m+n,m*n,pow(m,n),m%n,max)
except:
    m=float(m)
    n=float(n)
    if m>n:
        max=m
    else:
        max=n
    print(m+n,m*n,pow(m,n),m%n,max)
