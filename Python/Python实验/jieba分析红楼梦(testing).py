#coding:utf8

#导入jieba库
import jieba

#导入分析文本
txt = open('test (2).txt', 'r')


for line in txt:
    # 去掉每一行两边的空白
    line = line.strip()
    # 如果为空行则跳过该轮循环
    if len(line) == 0:
        continue
    #利用jieba库函数对每行文本进行切分
    words=jieba.lcut(txt)
    count={}    #创建字典
    for word in words:
        if len(word)==1:
            continue
        else:
            count[word]=count.get(word,0)+1
    items=list(count.items())   #转换成列表
    items.sort(key=lambda x:x[-1],reverse=True)
    for i in range(15):
        word,count=items[i]
        print("{0:<10}{1:>5}".format(word,count))
