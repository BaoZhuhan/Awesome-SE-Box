l = input().split(",")

for i in range(len(l)) :
    l[i] = int(l[i])
    
tar = int(input())

for i in range(len(l)):
    if l.count(tar-l[i]) >= 1 :
        print("{} {}".format(i,l.index(tar-l[i])))
        exit()
print("no answer")
