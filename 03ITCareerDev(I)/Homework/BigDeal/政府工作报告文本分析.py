import jieba
from wordcloud import WordCloud
from PIL import Image
import matplotlib.pyplot as plt
import imageio

plt.rcParams['font.sans-serif']=['SimHei']
mask=imageio.imread('baoyu.png')

f1 = open("政府工作报告.txt", "r", encoding='utf-8')
# f2 = open('红楼梦人名.txt', 'r', encoding='utf-8')

txt = f1.read()
# names =f2.read().split()

f1.close()
# f2.close()

words = jieba.lcut(txt)
counts = {}
name_str=""

for word in words:
    if len(word) == 1:
        continue
    # elif word == '贾母' or word == '老太太':
    #     word = '贾母'
    # elif word in '紫鹃-鹦哥'.split('-'):
    #     word = '紫鹃'
    # elif word in '翠缕-缕儿'.split('-'):
    #     word = '翠缕'
    # elif word in '香菱-甄英莲'.split('-'):
    #     word = '香菱'
    # elif word in '豆官-豆童'.split('-'):
    #     word = '豆官'
    # elif word in '贾宝玉-宝玉'.split('-'):
    #     word = '贾宝玉'
    # elif word in '林黛玉-林姑娘-黛玉'.split('-'):
    #     word = '林黛玉'
    if word in names:
        name_str+=word+" "
        counts[word] = counts.get(word,0) + 1

items = list(counts.items())

items.sort(key=lambda x:x[1], reverse=True)

for i in range(30):
    word, count = items[i]
    print ("{0:{2}<10}出场次数:{1:{2}<5}".format(word, count,(chr(12288))))

#词云
newtxt=name_str
wordcloud = WordCloud(background_color="white",
width=600,
height=500,
font_path="simhei.ttf",
mask=mask,#背景图片
max_words=100,
max_font_size=80,
collocations=False,
#stopwords=excludes,
).generate(newtxt)

wordcloud.to_file("红楼梦词云.png")

#词云图
plt.figure(figsize=(8,10))
plt.imshow(wordcloud)
plt.axis('off')
plt.show()

#柱状图和折线图
n=[t[0] for t in items[:15]]
c=[t[1] for t in items[:15]]
plt.figure(figsize=(10,6),facecolor='w',edgecolor='y')
plt.title("人物出场次数")
plt.plot(n,c,color="r",marker="*",linewidth=5)
plt.bar(n,c)
plt.show()

#饼图
n.append("其他")
c.append(sum([t[1] for t in items[15:]]))
plt.figure(figsize=(8,6))
plt.title("人物出场次数",x=0.5,y=-0.3,fontsize=20)
plt.pie(c,labels=n,autopct='%.1f%%',radius=1.2,explode=[0.1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0])
plt.show()