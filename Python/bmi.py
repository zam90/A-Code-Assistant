print("请输入身高体重")
h,w=eval(input())
bmi=w/(h*h)
def gj(bmi):
    if bmi<18.5:
        return "偏瘦"
    elif bmi<25:
        return "正常"
    elif bmi<30:
        return "偏胖"
    else:
        return "肥胖"
def gn(bmi):
    if bmi<18.5:
        return "偏瘦"
    elif bmi<24:
        return "正常"
    elif bmi<28:
        return "偏胖"
    else:
        return "肥胖"
print("国际标准：{}\n国内标准：{}".format(gj(bmi),gn(bmi)))
