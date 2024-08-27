
# IT职业发展训练一（编程基础）-2024

访问[代码仓库](https://github.com/BaoZhuhan/HZCU-SoftwareEngineer-MagicBox/tree/main/ITCareerDev(I)/Homework/Expriment1)

## 7-1 判断火车票座位

### 代码功能
根据用户输入的字符串，判断并输出座位类型（窗口或过道）。

### 思路
1. 读取用户输入的字符串。
2. 提取字符串的最后一个字符和前面的数字部分。
3. 检查数字是否在1到17之间，字符是否在 "ABCDEF" 范围内。
4. 根据字符判断并输出座位类型：
   - "A" 或 "F" 输出 "窗口"
   - "C" 或 "D" 输出 "过道"
   - 其他情况输出 "输入错误"

```python
userInput = str(input())

userChar = userInput[-1]
userNum = int(userInput[:-1])

if userNum < 1 or userNum > 17 or (not userChar in "ABCDEF") :
    print("输入错误")
elif userChar in "AF":
    print("窗口")
elif userChar in "CD":
    print("过道")
```

## 7-2 天天向上的力量 III

### 代码功能
计算并输出一年内每天增长和减少一定比例后的结果。

### 思路
1. 读取用户输入的浮点数 kernel。
2. 初始化两个变量 pro 和 fall 为 1.0。
3. 循环365次，每次分别按比例增加和减少 pro 和 fall。
4. 输出 pro、fall 和 pro 与 fall 的比值。

```python
kernel = float(input())

pro = fall = 1.0

for i in range(365):
    pro *= (1+kernel/1000)
    fall *= (1-kernel/1000)
    
print("{:.2f},{:.2f},{:.0f}".format(pro,fall,round(pro/fall)))
```

## 7-3 恺撒密码 I

### 代码功能
将用户输入的字符串中的小写字母进行凯撒加密（每个字母向后移动3位）。

### 思路
1. 读取用户输入的字符串并转换为列表。
2. 遍历列表中的每个字符。
3. 如果字符是小写字母，则将其转换为加密后的字符。
4. 将列表转换回字符串并输出。

```python
userInput = list(input())

for i in range(len(userInput)):
    if 'a' <= userInput[i] <= 'z':
        userInput[i] = chr((ord(userInput[i]) - ord('a') + 3 )%26 + ord('a'))
        
print("".join(userInput)) 
```

## 7-4 敏感词过滤

### 代码功能
过滤用户输入中的敏感词，将敏感词替换为 "*"

### 思路
1. 定义敏感词列表。
2. 读取用户输入的字符串。
3. 遍历敏感词列表，查找并替换敏感词。
4. 输出过滤后的字符串。

```python
garbage = ["垃圾","陷阱","山寨","内幕","盗版"]
userInput = str(input())

for i in garbage:
    loc = userInput.find(i)
    while(not loc == -1):
        userInput = userInput[0:loc] + "*" + userInput[loc+len(i):]
        loc = userInput.find(i)

print(userInput)
```

## 7-5 个税计算器

### 代码功能
根据用户输入的工资，计算应缴税款和实发工资。

### 思路
1. 读取用户输入的工资。
2. 计算应纳税所得额。
3. 根据应纳税所得额计算应缴税款。
4. 输出应缴税款和实发工资。

```python
userInput = float(input())
total = userInput-3500 if userInput-3500 > 0 else 0

tax = 0
if total > 80000 :
    tax = total*0.45-13505
elif total > 55000 :
    tax = total*0.35-5505
elif total > 35000 :
    tax = total*0.3-2755
elif total > 9000 :
    tax = total*0.25-1005
elif total > 4500 :
    tax = total*0.2-555
elif total > 1500 :
    tax = total*0.1-105
else :tax = total * 0.03

print("应缴税款{:.2f}元，实发工资{:.2f}元。".format(tax,userInput-tax))
```

## 7-6 快乐的数字

### 代码功能
判断一个数字是否为快乐数字。

### 思路
1. 定义一个函数计算数字各位平方和。
2. 在主函数中读取用户输入的数字。
3. 循环计算数字各位平方和，最多循环100次。
4. 如果结果为1，则输出True，否则输出False。

```python
def cal(num):
    strNum = str(num)
    res = 0
    for i in strNum:
        res += pow(int(i),2)
    return res

def main():
    n = int(input())
    for i in range(100):
        n = cal(n)
        if n == 1: break
        
    if n == 1: print("True")
    else : print("False")
    
main()
```

## 7-7 分类统计字符

### 代码功能
统计用户输入字符串中的小写字母、大写字母、数字、空格和其他字符的数量。

### 思路
1. 读取用户输入的字符串并转换为列表。
2. 初始化计数变量。
3. 遍历列表中的每个字符，根据字符类型增加相应的计数。
4. 输出各类字符的数量。

```python
def main():
    userInput = list(input())
    lowLetter = CapLetter = num = blank = other = 0
    for i in userInput:
        if 'a' <= i <= 'z' : lowLetter += 1
        elif 'A' <= i <= 'Z' : CapLetter += 1
        elif '0' <= i <= '9' : num += 1
        elif i == ' ' : blank += 1
        else: other += 1
    
    print(lowLetter,CapLetter,num,blank,other)
    
main()
```

## 7-8 温度转换异常处理

### 代码功能
将用户输入的温度值在摄氏度和华氏度之间转换，并处理异常情况。

### 思路
1. 读取用户输入的温度值。
2. 根据温度值的最后一个字符判断温度类型并进行转换。
3. 使用try-except块处理可能的异常情况。
4. 输出转换后的温度值或错误信息。

```python
try:
    a = input()
    if a[-1] in "Ff":
        C = (eval(a[0:-1]) -32)/1.8
        print("{:.2f}C".format(C))
    elif a[-1] in "Cc":
        F = 1.8 * eval(a[0:-1]) + 32
        print("{:.2f}F".format(F))
    else:
        print("输入错误，末位只能是'C','c','F','f'")
except NameError:
    print('试图访问的变量名不存在')
except SyntaxError:
    print('存在语法错误')
except Exception as e:
    print(e)
```

## 7-9 判断IP地址合法性

### 代码功能
判断用户输入的IP地址是否合法。

### 思路
1. 读取用户输入的IP地址并按"."分割。
2. 检查分割后的部分数量是否为4。
3. 遍历每个部分，检查其是否为0到255之间的整数。
4. 输出IP地址是否合法。

```python
IP = input().split(".")
if len(IP) != 4:
    print("No")
    exit()
for i in IP:
    try:
        if(255 < int(i) or 0 > int(i)):
            print("No")
            exit()
    except:
        print("No")
        exit()
print("Yes")
```

## 7-10 身份证号校验

### 代码功能
校验用户输入的身份证号码是否合法。

### 思路
1. 定义一个函数校验身份证号码。
2. 在函数中检查身份证号码长度是否为18位。
3. 计算校验位并与身份证号码的最后一位进行比较。
4. 输出身份证号码是否合法。

```python
def check_id(id):
    if len(id) != 18 : return False
    coef = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
    checklist = list("10X98765432")
    check = sum(int(id[i])*int(coef[i]) for i in range(17))
    
    return id[-1] == checklist[check%11]

id = input()
if check_id(id) :
    print("身份证号码校验为合法号码!")
else:
    print("身份证校验位错误!")
```