
# IT职业发展训练二（结构化编程）-2024

点击[访问代码仓库](https://github.com/BaoZhuhan/HZCU-SoftwareEngineer-MagicBox/tree/main/ITCareerDev(I)/Homework/Experiment2)

## 6-1 使用函数求特殊a串数列和

### 代码
```python
def fn(a,n):
    res = 0
    for i in range(1,n+1):
        temp = eval(str(a)*i)
        res += temp
    return res
```

### 解题思路
此函数`fn`通过`eval`函数将数字`a`重复`n`次形成的字符串转换为整数，然后计算其数值并累加到结果`res`中。这种方法适用于计算形如`11`, `111`, `1111`等数列的和。

## 6-2 使用函数输出指定范围内Fibonacci数的个数

### 代码
```python
fib_list = [1, 1]  

def fib(n):
    if len(fib_list) > n:
        return fib_list[n]
    
    for i in range(len(fib_list), n + 1):
        fib_list.append(fib_list[i - 1] + fib_list[i - 2])
    
    return fib_list[n]

def PrintFN(m, n):
    i = 0
    res = []
    while(fib(i) <= n ):
        if(fib(i) >= m ):
            res.append(fib(i))
        i += 1

    return res
```

### 解题思路
`fib`函数是一个递归函数，用于生成Fibonacci数列，并通过列表`fib_list`缓存已计算的值。`PrintFN`函数则用于找出在`m`到`n`范围内的Fibonacci数，并存储在列表`res`中。

## 7-1 质数判断

### 代码
```python
import math

def isPrime(n):
    if n < 2 : return False
    if n == 2 :return True
    for i in range(2,int(math.sqrt(n))+1):
        if n%i == 0: return False
    return True

num=int(input())
if isPrime(num):
    print('yes')
else:
    print('no')
```

### 解题思路
`isPrime`函数通过检查一个数是否只能被1和它本身整除来判断其是否为质数。它首先排除了小于2的数，然后检查是否为2（唯一的偶数质数），接着使用平方根优化的算法来减少不必要的检查。

## 7-2 计算三维空间某点距离原点的欧式距离

### 代码
```python
import math

def distance(x,y,z):
    return math.sqrt(x**2+y**2+z**2)

def main():
    x,y,z = input().split(",")
    d = distance(float(x),float(y),float(z))
    print("{:.2f}".format(d))
    
main()
```

### 解题思路
`distance`函数计算三维空间中点`(x, y, z)`到原点的欧式距离。`main`函数从用户获取输入，并调用`distance`函数计算距离，然后格式化输出结果。

## 7-3 特殊生日

### 代码
```python
def check(year, month, day):
    birth = list(str(year * 10000 + month * 100 + day))
    return len(birth) == len(set(birth))

def main(year, month, day):
    while True:
        if check(year, month, day):
            print("小明的生日是{:.0f}年{:02}月{:02}日".format(year, month, day))
            break
        
        day -= 1
        if day == 0:
            month -= 1
            if month == 0:
                month = 12
                year -= 1
            day = 31  

        if year == 1000:
            break

main(2024, 8, 28)
```

### 解题思路
`check`函数用于检查一个日期的所有数字是否都是唯一的。`main`函数通过递减天数，当天数为0时递减月份，月份为0时递减年份，直到找到符合条件的特殊生日。

## 7-4 绩点计算

### 代码
```python
gpaList = ["A" , "A-" , "B+" , "B" , "B-" , "C+" , "C" , "C-" , "D" , "D-" , "F"]
sorceList = [4.0,3.7,3.3,3.0,2.7,2.3,2.0,1.5,1.3,1.0,0]

def debug():
    print(len(gpaList) , len(sorceList))

def main():
    userInput = input()
    userScore = userWeight = 0
        
    while(userInput != "-1"):
        weight = int(input())
        userWeight += weight
        
        if userInput not in gpaList :
            print("data error")
            exit()
        else:
            userScore += sorceList[gpaList.index(userInput)] * weight

        userInput = input()

    print("{:.2f}".format(userScore/userWeight))
    

main()
```

### 解题思路
这段代码首先定义了两个列表，`gpaList`和`sorceList`，分别代表成绩等级和对应的绩点。`main`函数通过循环接收用户输入的成绩和权重，然后计算加权平均绩点。

## 7-5 身份证号处理

### 代码
```python
from datetime import datetime
someday = datetime(2022,10,1)

def main():
    id = input()
    yy = int(id[6:10])
    mm = int(id[10:12])
    dd = int(id[12:14])
    
    age = someday.year - yy
    
    xb = "男" if int(id[16])%2 == 1 else "女"
    
    print("你出生于{:04}年{:02}月{:02}日".format(yy,mm,dd))
    print("你今年{}周岁".format(age))
    print("你的性别为{}".format(xb))

main()
```

### 解题思路
`main`函数通过解析输入的身份证号码来计算年龄和性别。年龄是通过当前年份减去出生年份得到的。性别是根据身份证号码的第17位数字的奇偶性来判断的。

## 7-6 进制转换

### 代码
```python
num = ["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","G"]

def getSign(a):
    return "-" if str(a)[0] == "-" else ""

def getString(absA, b):
    if absA == 0:
        return "0"
    res = ""
    while absA != 0:
        res = num[absA % b ] + res
        absA //= b
    return res

a = int(input())
b = int(input())
mark = getSign(a)
bitString = getString(abs(a), b)
print(mark + bitString)
```

### 解题思路
这段代码实现了一个简单的进制转换功能。`getSign`函数用于获取数字的符号，`getString`函数用于将绝对值的数字转换为给定进制的字符串表示。用户输入一个数字和目标进制，程序输出转换后的字符串。

以上是您提供的文本内容按照Markdown格式重新排版后的完整版，包括代码块和解题思路。
