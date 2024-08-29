l1 = input().split()
l2 = input().split()
res = []

l2 = [word.upper() for word in l2]

for i in range(len(l1)) :
    if l1[i].upper() not in l2:
        res.append(l1[i])

print(" ".join(res))