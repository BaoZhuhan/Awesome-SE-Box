n = list(map(int,input().split(",")))
m = int(input())

print(n.index(7,1))

for i in n:
    if m-i in n and n.index(i) != n.index(m-i,i+1) :
        print(n.index(i),n.index(m-i,i+1))
        break
else:
    print("no answer")