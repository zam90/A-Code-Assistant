#Python 3.7 64-bit
#author Zam90


#导入jieba库
import jieba

#导入sklearn库
from sklearn import metrics
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.pyplot as plt

# 数据个数
n = 2000



#导入分析文本
txt1=open("《红楼梦》前80回.txt",'r',encoding="utf-8").read()
#利用jieba库对分析文本进行切词
words1=jieba.lcut(txt1)
#创建字典
count1={}
print ("") 
print ("《红楼梦》前80回")
print ("") 
#分析统计
for word1 in words1:
    if len(word1)==1:
        continue
    else:
        count1[word1]=count1.get(word1,0)+1
#转换成列表
items=list(count1.items())
items.sort(key=lambda x:x[-1],reverse=True)
#循环打印结果
for i in range(40):
    word1,count1=items[i]
    #剔除人名
    if word1=="宝玉" or word1=="贾母" or word1=="凤姐" or word1=="贾琏" or word1=="黛玉" or word1=="宝钗" or word1=="袭人":
        continue
    else:
        print("{0:<10}{1:>5}".format(word1,count1))
        #设置x、y值
        for i in range(40):
            word1,count1=items[i]
            #剔除人名
            if word1=="宝玉" or word1=="贾母" or word1=="凤姐" or word1=="贾琏" or word1=="黛玉" or word1=="宝钗" or word1=="袭人":
                continue
            else:
                x = i
                y = count1
                # 绘制散点图
                plt.scatter(x, y, s = 30, alpha = 0.5)

                # 计算颜色值
                color = np.arctan2(y, x)

                # 设置坐标轴范围
                plt.xlim((0, 40))
                plt.ylim((200, 1100))

                # 不显示坐标轴的值
                #plt.xticks(())
                #plt.yticks(())







print ("")    
print ("《红楼梦》后40回")
print ("")






#导入分析文本
txt2=open("《红楼梦》后40回.txt",'r',encoding="utf-8").read()
#利用jieba库对分析文本进行切词
words2=jieba.lcut(txt2)
#创建字典
count2={}
#分析统计
for word2 in words2:
    if len(word2)==1:
        continue
    else:
        count2[word2]=count2.get(word2,0)+1
#转换成列表
items=list(count2.items())
items.sort(key=lambda x:x[-1],reverse=True)
#循环打印结果
for i in range(40):
    word2,count2=items[i]
    #剔除人名
    if word2=="宝玉" or word2=="贾母" or word2=="凤姐" or word2=="贾琏" or word2=="黛玉" or word2=="宝钗" or word2=="袭人":
        continue
    else:
        print("{0:<10}{1:>5}".format(word2,count2))
        #设置x、y值
        for i in range(40):
            word2,count2=items[i]
            #剔除人名
            if word2=="宝玉" or word2=="贾母" or word2=="凤姐" or word2=="贾琏" or word2=="黛玉" or word2=="宝钗" or word2=="袭人":
                continue
            if word2=="什么" or word2=="一个" or word2=="我们" or word2=="那里" or word2=="你们" or word2=="他们" or word2=="如今" or word2=="一面" or word2=="众人" or word2=="出来" or word2=="姑娘" or word2=="两个" or word2=="知道" or word2=="说道" or word2=="起来" or word2=="这里":
                x = i
                y = count2
                # 绘制散点图
                plt.scatter(x, y, s = 30, alpha = 0.5)

                # 计算颜色值
                #color = np.arctan2(y, x)

                # 设置坐标轴范围
                plt.xlim((0, 40))
                plt.ylim((200, 1100))

                # 不显示坐标轴的值
                #plt.xticks(())
                #plt.yticks(())      

plt.show()

#导入分析文本
txt2=open("《红楼梦》后40回.txt",'r',encoding="utf-8").read()
#利用jieba库对分析文本进行切词
words2=jieba.lcut(txt2)
#创建字典
count2={}
#分析统计
for word2 in words2:
    if len(word2)==1:
        continue
    else:
        count2[word2]=count2.get(word2,0)+1
#转换成列表
items=list(count2.items())
items.sort(key=lambda x:x[-1],reverse=True)
#循环打印结果
for i in range(40):
    word2,count2=items[i]
    #剔除人名
    if word2=="宝玉" or word2=="贾母" or word2=="凤姐" or word2=="贾琏" or word2=="黛玉" or word2=="宝钗" or word2=="袭人":
        continue
    else:
        #设置x、y值
        for i in range(40):
            word2,count2=items[i]
            #剔除人名
            if word2=="宝玉" or word2=="贾母" or word2=="凤姐" or word2=="贾琏" or word2=="黛玉" or word2=="宝钗" or word2=="袭人":
                continue
            else:
                x = i
                y = count2
                # 绘制散点图
                plt.scatter(x, y, s = 30, alpha = 0.5)

                # 计算颜色值
                #color = np.arctan2(y, x)

                # 设置坐标轴范围
                plt.xlim((0, 40))
                plt.ylim((200, 1100))

                # 不显示坐标轴的值
                #plt.xticks(())
                #plt.yticks(())


#导入分析文本
txt1=open("《红楼梦》前80回.txt",'r',encoding="utf-8").read()
#利用jieba库对分析文本进行切词
words1=jieba.lcut(txt1)
#创建字典
count1={}
print ("") 
print ("《红楼梦》前80回")
print ("") 
#分析统计
for word1 in words1:
    if len(word1)==1:
        continue
    else:
        count1[word1]=count1.get(word1,0)+1
#转换成列表
items=list(count1.items())
items.sort(key=lambda x:x[-1],reverse=True)
#循环打印结果
for i in range(40):
    word1,count1=items[i]
    #剔除人名
    if word1=="宝玉" or word1=="贾母" or word1=="凤姐" or word1=="贾琏" or word1=="黛玉" or word1=="宝钗" or word1=="袭人":
        continue
    else:
        #设置x、y值
        for i in range(40):
            word1,count1=items[i]
            #剔除人名
            if word1=="宝玉" or word1=="贾母" or word1=="凤姐" or word1=="贾琏" or word1=="黛玉" or word1=="宝钗" or word1=="袭人":
                continue
            if word1=="什么" or word1=="那里" or word1=="王夫人" or word1=="老太太" or word1=="没有" or word1=="一个" or word1=="说道" or word1=="起来" or word1=="我们" or word1=="这里" or word1=="知道" or word1=="听见" or word1=="姑娘" or word1=="如今":
                x = i
                y = count1
                # 绘制散点图
                plt.scatter(x, y, s = 30, alpha = 0.5)

                # 计算颜色值
                color = np.arctan2(y, x)

                # 设置坐标轴范围
                plt.xlim((0, 40))
                plt.ylim((200, 1100))

                # 不显示坐标轴的值
                #plt.xticks(())
                #plt.yticks(())

plt.show()
