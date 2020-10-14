import datetime
strid=input()

y=int(strid[6])
e=int(strid[7])
a=int(strid[8])
r=int(strid[9])
year=y*1000+e*100+a*10+r

mon=int(strid[10])
th=int(strid[11])
month=mon*10+th

d=int(strid[12])
ay=int(strid[13])
day=d*10+ay

print("你出生于{}年{}{}月{}日".format(year,mon,th,day))
yearnow=datetime.datetime.now().year
age=yearnow-year
print("你今年{}周岁".format(age))

fe=int(strid[16])
if(fe%2==0):
    print("你的性别为女")
else:
    print("你的性别为男")
