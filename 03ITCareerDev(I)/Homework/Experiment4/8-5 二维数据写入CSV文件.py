import csv
# 读取price2016.csv文件
with open('price2016.csv', 'r', encoding='utf-8') as infile:
    reader = csv.reader(infile)
    data = list(reader)
# 计算百分比并保留两位小数
for row in data:
    for i in range(len(row)):
        try:
            # 尝试将字符串转换为浮点数
            num = float(row[i])
            # 计算百分比并保留两位小数
            row[i] = f"{num * 100:.2f}"
        except ValueError:
            # 如果转换失败，保持原值
            continue
# 将结果写入price2016out.csv文件
with open('price2016out.csv', 'w', encoding='utf-8', newline='') as outfile:
    writer = csv.writer(outfile)
    writer.writerows(data)