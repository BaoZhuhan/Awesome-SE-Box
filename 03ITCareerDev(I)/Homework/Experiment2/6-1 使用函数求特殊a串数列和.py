def fn(a,n):
    res = 0
    for i in range(1,n+1):
        temp = 0
        for j in range(i):
            temp *= 10
            temp += a
        res += temp
    return res
# /* 请在这里填写答案 */
         
a,b=input().split()
s=fn(int(a),int(b))
print(s)