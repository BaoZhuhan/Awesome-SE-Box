n = int(input())
mx = 0
mxp = 1
for i in range(n):
    tmp = int(input())
    if(tmp > mx) :
        mx = tmp
        mxp = i + 1 
print(mxp)
print(mx)