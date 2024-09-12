n = int(input())
b = input().split()

sm = 0 
for i in b :
    i = int(i)
    sm += i
    
if (n == 1) : 
    print(1)
else:
    ans = 0 
    for i in range(1 , (sm//(n - 1))  , 1 ):
        if((sm - (n-1)*i) > 0 and (sm - (n-1)*i) % i == 0) : 
            ans += 1
    
    print(ans)