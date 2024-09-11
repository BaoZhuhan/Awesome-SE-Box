l1 = input().split(" ")
l2 = input().split(" ")
res = []

for i in l1:
    if not i in l2 :
        res.append(i)
for i in l2:
    if not i in l1 :
        res.append(i)
        
for i in range(len(res)):
    if i == len(res)-1 : print(res[i] , end = "")
    else : print(res[i] , end = " ")