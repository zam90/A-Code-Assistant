import jieba
txt=open("threekingdoms.txt",'r',encoding="utf-8").read()
words=jieba.lcut(txt)   #jieba库函数
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
