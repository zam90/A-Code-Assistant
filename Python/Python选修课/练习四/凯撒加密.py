string1 = input()
x = eval(input())
q=0
p=0
string2 = [0 for i in range(len(string1))]
for i in range (0,len(string1)):
    if((string1[i]>='a'and string1[i]<='z')or(string1[i]>='A'and string1[i]<='Z')):
        if((string1[i]>='a'and string1[i]<='z')):
            q=ord(string1[i])+x
            if(q>122):
                q=96+(q-122)
            string2[i]=chr(q)
        if((string1[i]>='A'and string1[i]<='Z')):
            p=ord(string1[i])+x
            if(p>97):
                p=64+(p-90)
            string2[i]=chr(p)
    else:
        string2[i]=string1[i]
for i in range (0,len(string2)):
    print(string2[i],end="")
