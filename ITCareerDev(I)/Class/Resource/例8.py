import matplotlib.pyplot as plt
y=[41.3,48.9,54.0,59.5,64.4,68.9,74.4]
x=[2010,2011,2012,2013,2014,2015,2016]

fig=plt.figure(figsize=(8,6)) #figsize定义图形大小
ax1=fig.add_subplot(2,1,1)   #创建子图1 
ax1.plot(x,y,color="red",linewidth=2,linestyle='dashed',marker='o',label='GDP')               #用AxesSubplot绘制折线图
plt.title("2010~2016 GDP: Trillion")
ax2=fig.add_subplot(2,2,3)   #创建子图2 
ax2.bar(x,y)#绘柱状图
ax3=fig.add_subplot(2,2,4)   #创建子图3 
ax3.boxplot(y) #绘箱线图
plt.show()
