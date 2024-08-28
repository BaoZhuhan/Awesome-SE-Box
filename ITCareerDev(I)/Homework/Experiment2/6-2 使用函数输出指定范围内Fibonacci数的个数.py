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

# 在这里给出函数被调用进行测试的例子。例如：
# /* 请在这里填写答案 */

m,n,i=input().split()
n=int(n)
m=int(m)
i=int(i)
b=fib(i)
print("fib({0}) = {1}".format(i,b))
fiblist=PrintFN(m,n)
print(len(fiblist))