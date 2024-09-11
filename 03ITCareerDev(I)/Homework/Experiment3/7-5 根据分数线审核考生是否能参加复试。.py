try :
    stand = [55,55,90,90,310]
    def check():
        l = input().split(" ")
        for i in range(len(l)):
            l[i] = int(l[i])
        l.append(sum(l))
        
        for i in range(5):
            if int(l[i]) < stand[i] :
                return False
        return True
            
    def main():
        t = int(input())
        res = 0 
        for i in range(t) :
            if(check()):
                print("YES")
                res += 1
            else:
                print("NO")
        print("Pass: {}".format(res))
            
    main()
except Exception as e:
    print(e)
    exit()
            