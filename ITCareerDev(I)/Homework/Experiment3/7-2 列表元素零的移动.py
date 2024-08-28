try:
    def main():
        l = eval(input())
        res = []
        n = 0
        for i in range(len(l)):
            if l[i] != 0:
                res.append(l[i])
            else :
                n += 1  
        for i in range(n):
            res.append(0)
        print(res)
    main()
except:
    print("ERROR")
    exit()
    