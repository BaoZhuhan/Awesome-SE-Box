
list1 = input().split()
n = int(list1[0])
m = int(list1[1])

a = []

for i in range(n) :
    b = list(input())
    a.append(b)
    continue

ans = 0

for i in range(n) :
    for j in range(m) :
        if(a[i][j] == '*') :
            flag = True
            x = 1
            while(flag) :
                for k in range(j-x , j+x+1) :
                    if(i+x >= n or k < 0 or k >= m or a[i+x][k] != '*'):  
                        flag = False
                if(flag) : 
                    ans += 1
                    x += 1
                    
print(ans)
