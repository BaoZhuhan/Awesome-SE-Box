import jieba
from wordcloud import WordCloud
from PIL import Image
import matplotlib.pyplot as plt
import imageio

with open("ITCareerDev(I)\Homework\BigDeal\政府工作报告.txt", "r", encoding='utf-8') as f:
    txt = f.read()

words = jieba.lcut(txt)
counts = {}


for word in words:
    if len(word) == 1:  
        continue
    counts[word] = counts.get(word, 0) + 1

items = list(counts.items())
items.sort(key=lambda x: x[1], reverse=True)

for word, count in items[:150]:
    print(f"{word}: {count}")