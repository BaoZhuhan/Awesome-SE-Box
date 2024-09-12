string = str(input()).split(' ')
n = int(string[0])
b = int(string[1])

a = []

for i in range(n) :
    tmp = int(input())
    a.append(tmp)
    
a.sort(reverse = True)

res = 0
sm = 0
 
for i in range(n) : 
    if(sm >= b) :
        print(res)
        break
    res += 1
    sm += a[i]
    
