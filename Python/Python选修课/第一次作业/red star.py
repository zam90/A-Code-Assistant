from turtle import *

fillcolor('red')  # 设置填充颜色为红色

hideturtle()  # 隐藏箭头显示

begin_fill()  # 开始填充

while True:

    forward(200)  

    right(144)

    if abs(pos())<1:

        break

end_fill()  # 结束填充
