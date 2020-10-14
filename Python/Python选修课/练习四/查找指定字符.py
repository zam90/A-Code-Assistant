inpw = input()
inpstr = input()
max=999
for i in range (0,len(inpstr)):
    if inpw==inpstr[i]:
        max=i
    else:
        continue
    
if(max==999):
    print("Not Found")
else:
    print("index =",max)
