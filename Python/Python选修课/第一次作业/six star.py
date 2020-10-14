import turtle
t=turtle
t.setup(650,350,200,200)
t.pensize(6)
t.pencolor("black")
for i in (270,210,150,90,30,-30):
    t.seth(i)
    t.fd(60)
    t.seth(i-120)
    t.fd(60)
    t.seth(i-240)
    t.fd(120)
