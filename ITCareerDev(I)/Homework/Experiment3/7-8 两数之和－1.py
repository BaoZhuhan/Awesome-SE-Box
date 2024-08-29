l = [int(x) for x in input().split(",")]
tar = int(input())

for i in range(len(l)//2 + 1) :
    if l.count(tar-l[i]) > 0 and l.index(tar-l[i]) != i:
        print(min(i,l.index(tar-l[i])),max(i,l.index(tar-l[i])))
        exit()
print("no answer")
