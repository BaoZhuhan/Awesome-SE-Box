import jieba
from wordcloud import WordCloud
import matplotlib.pyplot as plt
import imageio

# 读取《政府工作报告》文本文件
with open("政府工作报告.txt", "r", encoding='utf-8') as f:
    txt = f.read()

# 读取“重点词.txt”文件
with open("重点词.txt", "r", encoding='utf-8') as f:
    key_words = set(line.strip() for line in f)

plt.rcParams['font.sans-serif']=['SimHei']

# 使用 jieba 分词
words = jieba.lcut(txt)
counts = {}

# 统计词频
for word in words:
    if len(word) == 1 or word not in key_words:  # 忽略单个字符的词和非重点词
        continue
    counts[word] = counts.get(word, 0) + 1

# 对统计结果进行排序
items = list(counts.items())
items.sort(key=lambda x: x[1], reverse=True)

# 只输出词频前20的结果
items = items[:20]

# 生成词云
newtxt = " ".join([word for word, count in items])
mask = imageio.imread('baoyu.png')  # 使用适当的背景图片
wordcloud = WordCloud(
    background_color="white",
    width=600,
    height=500,
    font_path="simhei.ttf",
    mask=mask,
    max_words=100,
    max_font_size=80,
    collocations=False,
).generate(newtxt)
wordcloud.to_file("政府工作报告词云.png")

# 显示词云图
plt.figure(figsize=(8, 10))
plt.imshow(wordcloud)
plt.axis('off')
plt.show()

# 生成并显示气泡图
n = [t[0] for t in items]
c = [t[1] for t in items]
sizes = [count * 100 for count in c]  # 调整气泡大小

plt.figure(figsize=(10, 6))
plt.scatter(n, c, s=sizes, alpha=0.5)
plt.title("关键词出现次数气泡图")
plt.xlabel("关键词")
plt.ylabel("出现次数")
plt.xticks(rotation=45)
plt.grid(True)
plt.show()

# 生成并显示柱状图和折线图
n = [t[0] for t in items[:15]]
c = [t[1] for t in items[:15]]
plt.figure(figsize=(10, 6), facecolor='w', edgecolor='y')
plt.title("关键词出现次数")
plt.plot(n, c, color="r", marker="*", linewidth=5)
plt.bar(n, c)
plt.show()

# 生成并显示饼图
n.append("其他")
c.append(sum([t[1] for t in items[15:]]))
plt.figure(figsize=(8, 6))
plt.title("关键词出现次数", x=0.5, y=-0.3, fontsize=20)
plt.pie(c, labels=n, autopct='%.1f%%', radius=1.2, explode=[0.1] + [0] * 15)
plt.show()

