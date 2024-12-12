list1 = input().split(' ');
n = int(list1[0])
m = int(list1[1])
x = int(list1[2])
y = int(list1[3])

a = []

for i in range(n) :
    b = input()
    b = list(b)
    a.append(b)
    
list2 = input().split(' ')
p = int(list2[0])
q = int(list2[1])

op = []
z = []
for i in range(q):
    list3 = input().split()
    op.append(int(list3[0]))
    z.append(int(list3[1]))

for i in range(p) :
    for j in range(q) :
        
        if(op[j] == 1) :
            tmp = a[z[j] - 1][m-1]
            for k in range(m-1 , 0 , -1):
                a[z[j] - 1][k] = a[z[j] - 1][k-1]
            a[z[j] - 1][0] = tmp
        if(op[j] == 2) :
            tmp = a[n-1][z[j] - 1]
            for k in range(n-1 , 0 , -1):
                a[k][z[j] - 1] = a[k-1][z[j] -1]
            a[0][z[j] - 1] = tmp
            
print(a[x-1][y-1])