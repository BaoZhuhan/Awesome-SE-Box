list1 = input().split(' ')

t = int(list1[0])
a = int(list1[1])
k = int(list1[2])

r = 0 

ans = 0 
 
if(a >= (r - k) and a <= (t + k)) :
    ans += abs(a - r)
    r = a
else :
    ans += abs(t - r)
    r = t
    
    ans += abs(a - r)
    r = a

ans += abs(t- r)
r = t

print(ans)