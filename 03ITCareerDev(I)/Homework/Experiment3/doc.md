# IT职业发展训练三（组合数据类型）-2024

## 7-1 重复元素判定 A

### 代码
```python
def check(l):
    for i in range(len(l)):
        if l[i] in l[i+1:]:
            return True
    return False

str = input()
l = eval(str)
if check(l): 
    print("True")
else :
    print("False")
```

### 解题思路
该问题通过遍历列表`l`，并检查当前元素是否在`l[i+1:]`中出现，如果出现则返回`True`，表示存在重复元素。如果遍历结束都没有发现重复元素，则返回`False`。

## 7-2 列表元素"零"的移动

### 代码
```python
try:
    def main():
        l = eval(input())
        res = []
        n = 0
        for i in range(len(l)):
            if l[i] != 0:
                res.append(l[i])
            else :
                n += 1  
        for i in range(n):
            res.append(0)
        print(res)
    main()
except:
    print("ERROR")
    exit()
```

### 解题思路
此代码段定义了一个`main`函数，它接受一个列表作为输入，遍历列表，将非零元素添加到结果列表`res`中，并计算零元素的数量`n`。然后，将`n`个零添加到`res`的末尾，并打印结果。

## 7-3 第K序元素查找

### 代码
```python
try :
    def main():
        l = eval(input())
        n = int(input())
        
        l.sort(reverse = True)
        
        print(l[n-1])
        
    main()
    
except:
    exit()
```

### 解题思路
该问题定义了一个`main`函数，它首先接收一个列表和一个整数`n`作为输入，然后对列表进行降序排序，并打印第`n`个元素。

## 7-4 找出不是公共的元素

### 代码
```python
l1 = input().split(" ")
l2 = input().split(" ")
res = []

for i in l1:
    if not i in l2 :
        res.append(i)
for i in l2:
    if not i in l1 :
        res.append(i)
        
for i in range(len(res)):
    if i == len(res)-1 : print(res[i] , end = "")
    else : print(res[i] , end = " ")
```

### 解题思路
此代码段首先将输入的两个字符串分割成列表`l1`和`l2`，然后通过两次遍历找出两个列表中不共有的元素，并将它们添加到结果列表`res`中，最后打印出这些元素。

## 7-5 根据分数线审核考生是否能参加复试（二级样题）

### 代码
```python
try :
    stand = [55,55,90,90,310]
    def check():
        l = input().split(" ")
        for i in range(len(l)):
            l[i] = int(l[i])
        l.append(sum(l))
        
        for i in range(5):
            if int(l[i]) < stand[i] :
                return False
        return True
            
    def main():
        t = int(input())
        res = 0 
        for i in range(t) :
            if(check()):
                print("YES")
                res += 1
            else:
                print("NO")
        print("Pass: {}".format(res))
            
    main()
except Exception as e:
    print(e)
    exit()
```

### 解题思路
此代码段定义了两个函数，`check`用于检查输入的成绩列表是否满足分数线要求，`main`用于处理多组成绩数据，并统计满足要求的组数。

## 7-6 四则运算（用字典实现）

### 代码
```python
try:
    def main():
        a = float(input())
        f = input()
        b = float(input())
        res = 0
        
        if f == "+" :
            res = a + b
        elif f == "-" :
            res = a - b
        elif f == "*" :
            res = a * b
        elif f == "/" :
            res = a / b

        print("{:.2f}".format(res))
    main()
except :
    print("divided by zero")
```

### 解题思路
此代码段定义了一个`main`函数，它接收两个浮点数和一个运算符，然后根据运算符执行相应的四则运算，并打印格式化后的运算结果。

## 7-7 字典更新

### 代码
```python
dict1 = {'小明': '13299887777', '特朗普': '814666888', '普京': '522888666', '吴京': '13999887777'}

name = input()
phone = input()

try :
    dict1[name]
    dict1[name] = phone
except :
    print("数据不存在")

for i in dict1.keys():
    print(i,end = ":")
    print(dict1[i])
```

### 解题思路
此代码段首先定义了一个字典`dict1`，然后通过用户输入更新字典中的电话号码。如果用户输入的名称在字典中不存在，则打印“数据不存在”。

## 7-8 两数之和－1

### 代码
```python
l = [int(x) for x in input().split(",")]
tar = int(input())

for i in range(len(l)//2 + 1) :
    if l.count(tar-l[i]) > 0 and l.index(tar-l[i]) != i:
        print(min(i,l.index(tar-l[i])),max(i,l.index(tar-l[i])))
        exit()
print("no answer")
```

### 解题思路
此代码段接收一个整数列表和目标整数`tar`，然后尝试找到列表中两个不同位置的数，它们的和等于`tar`。如果找到，则打印这两个数的索引；如果没有找到，则打印“no answer”。

## 7-9 用户登录D

### 代码
```python
dic1 = {"张三":"123456","李四":"1234567","王五":"password"}

error_time = 0

while error_time < 3:
    username = input()
    userpass = input()

    if username in dic1.keys() and userpass == dic1[username] :
        print("登录成功")
        break
    else :
        print("登录失败")
        error_time += 1
```

### 解题思路
此代码段定义了一个用户登录系统，允许用户有三次尝试机会。如果用户名和密码匹配，则打印“登录成功”并退出循环；如果三次尝试都失败，则退出程序。

## 7-10 单词分组

### 代码
```python
l1 = input().split()
l2 = input().split()
res = []

l2 = [word.upper() for word in l2]

for i in range(len(l1)) :
    if l1[i].upper() not in l2:
        res.append(l1[i])

print(" ".join(res))
```

### 解题思路
此代码段接收两个单词列表，将第二个列表转换为大写形式，然后检查第一个列表中的单词（转换为大写）是否存在于第二个列表中，如果不存在，则添加到结果列表`res`中，最后打印这些单词。

--- 

以上是您提供的文本内容按照Markdown格式重新排版后的完整版，包括代码块和解题思路。
