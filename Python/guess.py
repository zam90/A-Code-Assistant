number=6
numgus=0
i=0
while numgus!=6:
    numgus=eval(input())
    if numgus>6:
        print("猜大了")
    elif numgus<6:
        print("猜小了")
    i=i+1
else:
    print("答对了，共猜测{}次".format(i))
